#pragma once
#include <iostream>

#ifndef LinkedList_H
#define LinkedList_H

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;
	Node();
};

template<typename T>
class LinkedList {
	Node<T>* first;
	Node<T>* last;
	bool is_empty();
	void add_first(Node<T>* data);
	void add_last(Node<T>* data);
public:
	LinkedList();
	void print(bool minimal = true);
	void clear();
	void add_last(T item);
	void add_first(T item);
	void delete_last();
	void delete_first();
	Node<T>* get(int index);
	Node<T>* search(T item);
	int search_and_delete(T item);
	void set(int index, T item);
	void add(T item);
};

#include "LinkedList.cpp"

#endif // !LinkedList_H
