#include <iostream>
#include "LockDList.h"
using namespace std;

template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) //繼承DListNode的member function 
{
	return new LockDListNode<T>(item, prev, next); //回傳lockDListNode的指標，因為父類別的指標可指向子類別 
}
template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) //鎖定node的函式 
{
	if (node != NULL)
	{
		LockDListNode<T>* n = dynamic_cast<LockDListNode<T>*>(node); //將父類別的指標轉型為子類別的指標 
		n->lock = true;
	}
}
template<typename T>
void LockDList<T>::remove(DListNode<T>* node) //override remove 函式當node為locked則無法移除 
{
	LockDListNode<T>* n = dynamic_cast<LockDListNode<T>*>(node);
	if (n->lock == 0)
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;
	}
}

