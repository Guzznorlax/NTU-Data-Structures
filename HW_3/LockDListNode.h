#pragma once
#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

#include "DListNode.h"

template <typename T>
class LockDList;

template <typename T>
class DList;

template <typename T>
class LockDListNode : public DListNode<T>
{
protected:
	bool lock;
	friend class LockDList<T>;
	friend class DList<T>;

public:
	LockDListNode(const T &i, DListNode<T> *p, DListNode<T> *n) : DListNode<T>(i, p, n) { lock = false; } //�~��DListNoed��constructor �W�[�@�ܼ�
};

#endif
