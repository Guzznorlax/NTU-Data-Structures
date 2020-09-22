/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

#include "HashTableChained.h"

 /**
  *  Construct a new empty hash table intended to hold roughly sizeEstimate
  *  entries.  (The precise number of buckets is up to you, but we recommend
  *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
  **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {  //建置一個hashtable，load factor=0.75
	int n;
	n = sizeEstimate / 0.75;
	bucket = findprime(n);
	defTable = new list<Entry<K, V>* >[bucket];
	entries = 0;
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {             //defualt constructor
	defTable = new list<Entry<K, V>* >[101];
	entries = 0;
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {            //將hashcode轉成integer 
	int count;
	int a = 23, b = 31, p = findprime(30 * bucket);
	count = (((a*code + b) % p) % bucket);
	return count;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size() {                     // hashcode的size 
	return entries;

}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {    //is hashtable empty or not
	if (entries == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {     //insert data到list
	int a = compFunction(key->hashCode());
	defTable[a].push_front(new Entry<K, V>(key, value));
	entries++;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {       //找data在不在list中
	list<Entry<K, V>* >* find = &defTable[compFunction(key->hashCode())];
	typename list<Entry<K, V>* >::iterator iter;
	for (iter = find->begin(); iter != find->end(); iter++)
	{
		if (key->equals(*(*iter)->getkey()))
		{
			return true;
		}
	}
	return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key) {  //根據key移除指定的list
	list<Entry<K, V>* >* find = &defTable[compFunction(key->hashCode())];
	typename list<Entry<K, V>* >::iterator iter;
	for (iter = find->begin(); iter != find->end(); iter++)
	{
		if (key->equals(*(*iter)->getkey()));
		{
			defTable[compFunction(key->hashCode())].erase(iter);
		}
		entries--;
	}
}
/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {   //清空
	for (int i = 0; i < bucket; i++)
	{
		defTable[i].clear();
	}
	entries = 0;
}


template<typename K, typename V>
void HashTableChained<K, V>::print()       //印出hashtable
{
	int i;
	for (i = 0; i < bucket; i++)
	{
		list<Entry<K, V>* >* deft = &defTable[i];
		cout << "[" << i << "]" << ":";
		typename list<Entry<K, V>* >::iterator iter;
		for (iter = deft->begin(); iter != deft->end(); iter++)
		{
			cout << "( key : " << (*(*iter)->getkey()).getvalue();
			cout << " value : " << (*(*iter)->getvalue()).getvalue() << " ) ";
		}
		cout << endl;
	}
}