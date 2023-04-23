#pragma once
#include <iostream>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename T>
class DynamicArray {
	T* array_p;
	int max_size;
	int current_size;

	bool isIndexOutOfRange(int index);

	void swap(int* value_1, int* value_2);

public:
	DynamicArray(int max_size = 1);

	~DynamicArray();

	void add(T value_to_add);

	int get(int index);

	void set(int index, int value);

	void clear();

	void print();

	T& operator[](int index);

	int empty();

	int size();

	void pop_back();

	void push_back(T item);
};

#include "DynamicArray.cpp"
#endif // !DYNAMICARRAY_H