#include <iostream>
#include "LockDList.h"
using namespace std;

template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) //�~��DListNode��member function 
{
	return new LockDListNode<T>(item, prev, next); //�^��lockDListNode�����СA�]�������O�����Хi���V�l���O 
}
template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) //��wnode���禡 
{
	if (node != NULL)
	{
		LockDListNode<T>* n = dynamic_cast<LockDListNode<T>*>(node); //�N�����O�������૬���l���O������ 
		n->lock = true;
	}
}
template<typename T>
void LockDList<T>::remove(DListNode<T>* node) //override remove �禡��node��locked�h�L�k���� 
{
	LockDListNode<T>* n = dynamic_cast<LockDListNode<T>*>(node);
	if (n->lock == 0)
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;
	}
}

