#include "BinaryTree.h"
using namespace std;

template<typename K, typename V>
BinaryTree<K, V>::BinaryTree() {
	makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int BinaryTree<K, V>::size() {
	return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool BinaryTree<K, V>::isEmpty() {
	return size() == 0;
}

template<typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V>* entry, const K& key, BinaryTreeNode<K, V>* node) {
	if (key.compareTo(node->entry->getkey()) <= 0) {
		if (node->leftChild == NULL) {
			node->leftChild = new BinaryTreeNode<K, V>(entry, node);
		}
		else {
			insertHelper(entry, key, node->leftChild);
		}
	}
	else {
		if (node->rightChild == NULL) {
			node->rightChild = new BinaryTreeNode<K, V>(entry, node);
		}
		else {
			insertHelper(entry, key, node->rightChild);
		}
	}
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void BinaryTree<K, V>::insert(const K& key, const V& value) {
	Entry<K, V>* entry = new Entry<K, V>(key, value);
	if (root == NULL) {
		root = new BinaryTreeNode<K, V>(entry);
	}
	else {
		insertHelper(entry, key, root);
	}
	tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template<typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findHelper(const K& key, BinaryTreeNode<K, V>* node) {
	if (node == NULL) {
		return NULL;
	}
	else if (key.compareTo(node->entry->getkey()) == 0) {  //找到
		return node;
	}
	else if(key.compareTo(node->entry->getkey()) >0){  
		return findHelper(key,node->rightChild);
	}
	else {
		return findHelper(key,node->leftChild);
	}
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
Entry<K, V>* BinaryTree<K, V>::find(const K& key) {
	BinaryTreeNode<K, V>* node = findHelper(key, root);
	if (node != NULL) {
		return node->entry;
	}
	else {
		return NULL;
	}
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void BinaryTree<K, V>::remove(const K& key) {
	BinaryTreeNode<K, V>* delete_node = findHelper(key, root);
	if (delete_node == NULL) {
		cout << "no data found"<<endl;
	}
	else if (delete_node->parent == NULL) {
		if (delete_node->leftChild == NULL && delete_node->rightChild == NULL) {  //沒有child
			delete delete_node;
			tsize--;
		}
		else if (delete_node->leftChild != 0 && delete_node->rightChild == NULL) {  //當delete_node只有leftchild
			delete_node->leftChild->parent = NULL;
			root = delete_node->leftChild;
			delete delete_node;
			tsize--;
		}
		else if (delete_node->rightChild != NULL && delete_node->leftChild == NULL) {  //當delete_node只有rightchild
			delete_node->rightChild->parent = NULL;
			root = delete_node->rightChild;
			delete delete_node;
			tsize--;
		}
		else { //delete_node有2個Child
			BinaryTreeNode<K, V>*x = delete_node->rightChild;
			while (x->leftChild != NULL) {  //找到x=右邊中min node
				x = x->leftChild;
			}
			if (x->rightChild == NULL) {  //x沒有child
				if (x != delete_node->rightChild) {    //x不是delete_node的rightchild
					delete_node->leftChild->parent = x;
					delete_node->rightChild->parent = x;
					x->leftChild = delete_node->leftChild;
					x->rightChild = delete_node->rightChild;
					x->parent->leftChild = NULL;
					x->parent = NULL;
					root = x;
					delete delete_node;
					tsize--;
				}
				else {      //x是delete_node的rightchild
					delete_node->leftChild->parent = x;
					x->parent = NULL;
					x->leftChild = delete_node->leftChild;
					root = x;
					delete delete_node;
					tsize--;
				}
			}
			else {       //x有rightchild
				if (x != delete_node->rightChild) {    //x不是delete_node的rightchild
					delete_node->leftChild->parent = x;
					delete_node->rightChild->parent = x;
					x->leftChild = delete_node->leftChild;
					x->rightChild->parent = x->parent;
					x->parent->leftChild = x->rightChild;
					x->rightChild = delete_node->rightChild;
					x->parent = NULL;
					root = x;
					delete delete_node;
					tsize--;
				}
				else {    //x是delete_node的rightchild
					delete_node->leftChild->parent = x;
					x->parent = NULL;
					x->leftChild = delete_node->leftChild;
					root = x;
					delete delete_node;
					tsize--;
				}
			}
		}
	}
	
	// node!=root
	else {	
		if (delete_node->leftChild == NULL && delete_node->rightChild == NULL) {
			if (delete_node == delete_node->parent->leftChild) {
				delete_node->parent->leftChild = NULL;
			}
			else {
				delete_node->parent->rightChild = NULL;
			}
			delete delete_node;
			tsize--;
		}
		else if (delete_node->leftChild != NULL && delete_node->rightChild == NULL) {  //當delete_node只有leftchild
			if (delete_node == delete_node->parent->leftChild) {     //case:delete_node是parent的leftchild
				delete_node->parent->leftChild = delete_node->leftChild;  //delete_node的parent的leftchild指向delete_node的leftchild
				delete_node->leftChild->parent = delete_node->parent;
			}
			else {   //case:delete_node是parent的rightchild
				delete_node->parent->rightChild = delete_node->leftChild;  //delete_node的parent的rightchild指向delete_node的leftchild
				delete_node->leftChild->parent = delete_node->parent;
			}
			delete delete_node;
			tsize--;
		}
		else if (delete_node->rightChild != NULL && delete_node->leftChild == NULL) {  //當delete_node只有rightchild
			if (delete_node == delete_node->parent->leftChild) {     //case:delete_node是parent的leftchild
				delete_node->parent->leftChild = delete_node->rightChild;  //delete_node的parent的leftchild指向delete_node的leftchild
				delete_node->rightChild->parent = delete_node->parent;
			}
			else {   //case:delete_node是parent的rightchild
				delete_node->parent->rightChild = delete_node->rightChild;  //delete_node的parent的rightchild指向delete_node的leftchild
				delete_node->rightChild->parent = delete_node->parent;
			}
			delete delete_node;
			tsize--;
		}
		else {  //當delete_node有2個children
			BinaryTreeNode<K, V>*x = delete_node->rightChild;
			while (x->leftChild != NULL) {  //找到x=右邊中min node
				x = x->leftChild;
			}
			if (x->rightChild == NULL) {    //x沒有rightchild
				if (delete_node == delete_node->parent->leftChild) {  //delete_note是delete_note的parent的leftchild
					delete_node->parent->leftChild = x;
				}
				else {  //delete_note是delete_note的parent的rightchild
					delete_node->parent->rightChild = x;
				}
				if (x != delete_node->rightChild) {    //x不是delete_node的rightchild
					delete_node->leftChild->parent = x;
					delete_node->rightChild->parent = x;
					x->leftChild = delete_node->leftChild;
					x->rightChild = delete_node->rightChild;
					x->parent->leftChild = NULL;
					x->parent = delete_node->parent;
					delete delete_node;
					tsize--;
				}
				else {       //x是delete_node的rightchild
					delete_node->leftChild->parent = x;
					x->parent = delete_node->parent;
					x->leftChild = delete_node->leftChild;
					delete delete_node;
					tsize--;
				}
			}
			else {     //x有rightchild
				if (delete_node == delete_node->parent->leftChild) {    //delete_node的parent的leftchild等於x
					delete_node->parent->leftChild = x;
				}
				else {     //delete_node的parent的rightchild等於x
					delete_node->parent->rightChild = x;
				}
				if (x != delete_node->rightChild) {  //x不是delete_node的rightchild
					delete_node->leftChild->parent = x;
					delete_node->rightChild->parent = x;
					x->leftChild = delete_node->leftChild;
					x->rightChild->parent = x->parent;
					x->parent->leftChild = x->rightChild;
					x->rightChild = delete_node->rightChild;
					x->parent = delete_node->parent;
					delete delete_node;
					tsize--;
				}
				else {      //x是delete_node的rightchild
					delete_node->leftChild->parent = x;
					x->parent = delete_node->parent;
					x->leftChild = delete_node->leftChild;
					delete delete_node;
					tsize--;
				}
			}
		}
	}
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void BinaryTree<K, V>::makeEmpty() {
	while (root != NULL) {
		remove(root->entry->getkey());
	}
	tsize = 0;    //set size=0
}

/**
 *  Convert the tree into a string.
 **/
template<typename K, typename V>
std::string BinaryTree<K, V>::toString() {
	if (root == NULL) {
		return "";
	}
	else {
		return root->toString();
	}
}