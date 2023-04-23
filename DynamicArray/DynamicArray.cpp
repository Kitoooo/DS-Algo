#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP

#include "DynamicArray.h"

template<typename T>
bool DynamicArray<T>::isIndexOutOfRange(int index) {
	if (index >= current_size || index < 0) {
		throw std::out_of_range("Index out of range!");
	}
	else return false;
}

template<typename T>
void DynamicArray<T>::swap(int* value_1, int* value_2)
{
	int temp = *value_1;
	*value_1 = *value_2;
	*value_2 = temp;
}

template<typename T>
DynamicArray<T>::DynamicArray(int max_size) {
	this->max_size = max_size;
	current_size = 0;
	array_p = new T[max_size];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] array_p;
};

template<typename T>
void DynamicArray<T>::add(T value_to_add) {
	if (current_size >= max_size) {

		int new_max_size = max_size * 2;

		T* new_temp_array_p = new T[new_max_size];

		for (int i = 0; i < current_size; i++) {
			new_temp_array_p[i] = array_p[i];
		}

		max_size = new_max_size;
		delete[] array_p;
		array_p = new_temp_array_p;
	}
	array_p[current_size] = value_to_add;
	current_size++;
}

template<typename T>
int DynamicArray<T>::get(int index) {
	if (!isIndexOutOfRange(index)) {
		return array_p[index];
	}
}

template<typename T>
void DynamicArray<T>::set(int index, int value) {
	if (!isIndexOutOfRange(index)) {
		array_p[index] = value;
	}
}

template<typename T>
void DynamicArray<T>::clear() {
	T* new_temp_array_p = new T[max_size];
	current_size = 0;
	delete[] array_p;
	array_p = new_temp_array_p;
}

template<typename T>
void DynamicArray<T>::print() {
	for (int i = 0; i < current_size; i++) {
		std::cout << "array[" << i << "]: " << array_p[i] << std::endl;
	}
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
	if (!isIndexOutOfRange(index)) {
		return *(array_p + index);
	}
}

template<typename T>
int DynamicArray<T>::empty() {
	if (current_size == 0) return 1;
	return 0;
}

template<typename T>
int DynamicArray<T>::size() {
	return current_size;
}

template<typename T>
void DynamicArray<T>::pop_back() {
	current_size--;
}

template<typename T>
void DynamicArray<T>::push_back(T item) {
	add(item);
}



#endif // !DYNAMICARRAY_CPP
