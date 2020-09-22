#pragma once
#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "DList.h"
#include "LockDListNode.h"

template <typename T>
class LockDList : public DList<T>
{
protected:
	DListNode<T> *newNode(const T &item, DListNode<T> *prev, DListNode<T> *next);

public:
	LockDList() { ; }
	void lockNode(DListNode<T> *node);
	void remove(DListNode<T> *node);
};

#endif
