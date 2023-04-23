#pragma once

#include <vector>
#include <iostream>

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

template <typename T>
class BinaryHeap {
	std::vector<T> vec;
	int(*cmp)(T, T);
	int leftIndex(int parentIndex);
	int rightIndex(int parentIndex);
	int parentIndex(int childIndex);
	void heapifyUp(int index);
	void heapifyDown(int index);
public:
	BinaryHeap(int(*cmp)(T, T));
	void insert(T value);
	int deleteRoot();
	void clear();
	void print(bool minimal = true);
};

#include "BinaryHeap.cpp"
#endif // !BINARYHEAP_H
