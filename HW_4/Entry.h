#pragma once
/**
 *  A class for dictionary entries.
 *
 *  DO NOT CHANGE THIS FILE.  It is part of the interface of the
 *  Dictionary ADT.
 **/

#ifndef ENTRY_H
#define ENTRY_H

template<typename K, typename V>
class Entry {
protected:
	K key;
	V value;

public:
	Entry(K k, V v) {
		key = k;
		value = v;
	}

	const K& getkey() const {
		return key;
	}

	const V& getvalue() const {
		return value;
	}

};

#endif
