/**
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#include <iostream>
#include "DList.h"
using namespace std;

/* DList invariants:
 *  1)  head != null.
 *  2)  For any DListNode x in a DList, x.next != null.
 *  3)  For any DListNode x in a DList, x.prev != null.
 *  4)  For any DListNode x in a DList, if x.next == y, then y.prev == x.
 *  5)  For any DListNode x in a DList, if x.prev == y, then y.next == x.
 *  6)  size is the number of DListNodes, NOT COUNTING the sentinel,
 *      that can be accessed from the sentinel (head) by a sequence of
 *      "next" references.
 */

 /**
  *  newNode() calls the DListNode constructor.  Use this class to allocate
  *  new DListNodes rather than calling the DListNode constructor directly.
  *  That way, only this method needs to be overridden if a subclass of DList
  *  wants to use a different kind of node.
  *  @param item the item to store in the node.
  *  @param prev the node previous to this node.
  *  @param next the node following this node.
  */
template<typename T>  
DListNode<T>* DList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) {
	return new DListNode<T>(item, prev, next);
}




/**
 *  DList() constructor for an empty DList.
 */
template<typename T>
DList<T>::DList() {
	size = 0;
	head = newNode(0, NULL, NULL);
	head->prev = head;
	head->next = head;
}

/**
 *  isEmpty() returns true if this DList is empty, false otherwise.
 *  @return true if this DList is empty, false otherwise.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
bool DList<T>::isEmpty() {
	if (size == 0 || (head->next == head->prev&&head->prev == head->next)) {
		return true;
	}
	else {
		return false;
	}
}

/**
 *  length() returns the length of this DList.
 *  @return the length of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
int DList<T>::length() {
	return size;
}

/**
 *  insertFront() inserts an item at the front of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertFront(const T& item) {
	DListNode<T> *node = newNode(item, head, head->next);
	(node->next)->prev = node;      //將node之next的prev指向node本身
	head->next = node;        //head的next指向node
	size += 1;
}

/**
 *  insertBack() inserts an item at the back of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBack(const T& item) {
	DListNode<T>* node = newNode(item, head->prev, head);
	(node->prev)->next = node;    //將node的上一個node2的next設為node本身將node之next的prev指向node本身
	head->prev = node;            //head的prev指向node
	size += 1;
}

/**
 *  front() returns the node at the front of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the front of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::front() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		return head->next;
	}
}

/**
 *  back() returns the node at the back of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the back of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::back() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		return head->prev;
	}
}

/**
 *  next() returns the node following "node" in this DList.  If "node" is
 *  null, or "node" is the last node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose successor is sought.
 *  @return the node following "node".
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::next(DListNode<T>* node) {
	if (isEmpty()||node==head->prev) {
		return NULL;
	}
	else {
		return node->next;
	}
}

/**
 *  prev() returns the node prior to "node" in this DList.  If "node" is
 *  null, or "node" is the first node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose predecessor is sought.
 *  @return the node prior to "node".
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::prev(DListNode<T>* node) {
	if (isEmpty() || node== head->next||node==NULL) {
		return NULL;
	}
	else {
		return node->prev;
	}
}

/**
 *  insertAfter() inserts an item in this DList immediately following "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item after.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertAfter(const T& item, DListNode<T>* node) {
	if (isEmpty()||node==NULL) {
	}
	else {
		DListNode<T>*newitem = newNode(item, node, node->next);
		node->next = newitem;    //node的next指向newitem
		(newitem->next)->prev = newitem;  //newitem之next的prev指向newitem
		size += 1;
	}
}

/**
 *  insertBefore() inserts an item in this DList immediately before "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item before.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBefore(const T& item, DListNode<T>* node) {
	if (isEmpty()||node==NULL) {
	}
	else {
		DListNode<T>*newitem = newNode(item, node->prev, node);
		node->prev = newitem;    //node的prev指向newitem
		(newitem->prev)->next = newitem;  //newitem之prev的next指向newitem
		size += 1;
	}
}

/**
 *  remove() removes "node" from this DList.  If "node" is null, do nothing.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::remove(DListNode<T>* node) {
	if (isEmpty()||node==NULL) {
	}
	else {
		(node->prev)->next = node->next;    //將node之prev的next指向node之next
		(node->next)->prev = node->prev;    //將node之next的prev指向node之prev
		delete node;
		size -= 1;
	}
}

/**
 *  toString() prints a string representation of this DList.
 *
 *  DO NOT CHANGE THIS METHOD.
 *
 *  Performance:  runs in O(n) time, where n is the length of the list.
 */
template<typename T>
void DList<T>::toString() {         //將node轉換為string
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	DListNode < T > *current = head->next;
	int i = 1;
	while (current != head) {
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}

