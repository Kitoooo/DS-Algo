#ifndef BINARYHEAP_CPP
#define BINARYHEAP_CPP

#include "BinaryHeap.h"

template<typename T>
int BinaryHeap<T>::leftIndex(int parentIndex) {
	int i = 2 * parentIndex + 1;
	if (i < vec.size()) return i;
	return -1;
}

template<typename T>
int BinaryHeap<T>::rightIndex(int parentIndex) {
	int i = 2 * parentIndex + 2;
	if (i < vec.size()) {
		return i;
	}
	return -1;
}

template<typename T>
int BinaryHeap<T>::parentIndex(int childIndex) {
	if (childIndex == 0) {
		return -1;
	}
	return (childIndex - 1) / 2;
}

template<typename T>
void BinaryHeap<T>::heapifyUp(int index) {
	int parent = parentIndex(index);
	if (parent != -1 && cmp(vec[index], vec[parent]) != 1) {
		std::swap(vec[index], vec[parent]);
		heapifyUp(parent);
	}
}

template<typename T>
void BinaryHeap<T>::heapifyDown(int index) {
	int left = leftIndex(index);
	int right = rightIndex(index);
	if (left >= 0) {
		if (right >= 0 && cmp(vec[right], vec[left]) == -1) {
			left = right;
		}
		if (cmp(vec[left], vec[index]) == -1) {
			std::swap(vec[left], vec[index]);
			heapifyDown(left);
		}
	}
}

template<typename T>
BinaryHeap<T>::BinaryHeap(int(*cmp)(T, T)) {
	this->cmp = cmp;
}

template<typename T>
void BinaryHeap<T>::insert(T value) {
	vec.push_back(value);
	heapifyUp(vec.size() - 1);
}

template<typename T>
int BinaryHeap<T>::deleteRoot() {
	if (vec.size() == 0) {
		return -1;
	}
	vec[0] = vec[vec.size() - 1];
	vec.pop_back();
	heapifyDown(0);
}

template<typename T>
void BinaryHeap<T>::clear() {
	vec.clear();
}

template<typename T>
void BinaryHeap<T>::print(bool minimal) {
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (count == 10) return;
		std::cout << to_string(vec[i]) << " ";
		if (minimal) count++;
	}
	if (vec.empty()) std::cout << "Kopiec pusty!";
}

#endif // !BINARYHEAP_CPP
