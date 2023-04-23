#ifndef LinkedList_CPP
#define LinkedList_CPP

#include "LinkedList.h"

template<typename T>
Node<T>::Node() {
	next = NULL;
	prev = NULL;
}


template<typename T>
bool LinkedList<T>::is_empty() {
	return first == NULL;
}

template<typename T>
void LinkedList<T>::add_first(Node<T>* data) {
	if (is_empty()) {
		first = data;
		last = data;
	}
	else {
		data->next = first;
		first->prev = data;
		first = data;
	}
}

template<typename T>
void LinkedList<T>::add_last(Node<T>* data) {
	data->prev = last;
	last->next = data;
	last = data;
}

template<typename T>
LinkedList<T>::LinkedList() {
	first = NULL;
	last = NULL;
}
template<typename T>
void LinkedList<T>::print(bool minimal) {
	if (this->is_empty()) {
		return;
	}
	Node<T>* temp;
	if (minimal) {
		temp = this->first;
		for (int i = 0; i < 10; i++) {
			if (temp != NULL) {
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}
		std::cout << ".\n.\n.\n";
		temp = this->last;
		Node<T>* tab[10];
		for (int i = 0; i < 10; i++) {
			if (temp != NULL) {
				tab[i] = temp;
				temp = temp->prev;
			}
		}
		int i = sizeof(tab) / sizeof(tab[0]) - 1;
		for (i; i >= 0; i--) {
			std::cout << tab[i]->data << std::endl;
		}
	}
	else {
		temp = this->first;
		int i = 0;
		while (temp != NULL) {
			std::cout << i << ". " << temp->data << std::endl;
			temp = temp->next;
			i++;
		}
	}
};

template<typename T>
void LinkedList<T>::clear() {
	Node<T>* temp = first;
	while (temp != NULL) {
		Node<T>* temp_delete = temp;
		temp = temp->next;
		delete temp_delete;
	}
	first = NULL;
	last = NULL;
}

template<typename T>
void LinkedList<T>::add_last(T item) {
	Node<T>* new_node = new Node<T>;
	new_node->data = item;
	if (is_empty()) {
		first = new_node;
		last = new_node;
	}
	else {
		new_node->prev = last;
		last->next = new_node;
		last = new_node;
	}
}

template<typename T>
void LinkedList<T>::add_first(T item) {
	Node<T>* new_node = new Node<T>;
	new_node->data = item;
	if (is_empty()) {
		first = new_node;
		last = new_node;
	}
	else {
		new_node->next = first;
		first->prev = new_node;
		first = new_node;
	}
}

template<typename T>
void LinkedList<T>::delete_last() {
	if (is_empty()) {
		return;
	}
	else {
		Node<T>* temp_delete = last;
		last = temp_delete->prev;
		last ? last->next = NULL : first = NULL; // potrzebne jezeli jest tylko jedna zmienna
		delete temp_delete;
	}
}

template<typename T>
void LinkedList<T>::delete_first() {
	if (is_empty()) {
		return;
	}
	else {
		Node<T>* temp_delete = first;
		first = temp_delete->next;
		first ? first->prev = NULL : last = NULL;
		delete temp_delete;
	}
}

template<typename T>
Node<T>* LinkedList<T>::get(int index) {
	if (is_empty()) {
		throw std::out_of_range("Can't get element - list is empty!");
	}
	Node<T>* temp = first;
	for (int i = 0; i < index; i++) {
		if (temp->next)
			temp = temp->next;
	}

	return temp;
}

template<typename T>
Node<T>* LinkedList<T>::search(T item) {
	if (is_empty()) {
		return NULL;
	}
	Node<T>* temp = first;
	while (temp != NULL) {
		if (temp->data == item) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

template<typename T>
int LinkedList<T>::search_and_delete(T item) {
	Node<T>* temp_delete = search(item);
	if (!temp_delete) {
		return -1;
	}
	if (is_empty()) {
		throw std::out_of_range("Can't get element - list is empty!");
	}
	if (temp_delete == first) {
		delete_first();
		return 1;
	}
	if (temp_delete == last) {
		delete_last();
		return 1;
	}
	temp_delete->prev->next = temp_delete->next;
	temp_delete->next->prev = temp_delete->prev;
	delete temp_delete;
}

template<typename T>
void LinkedList<T>::set(int index, T item) {
	if (is_empty()) {
		throw std::out_of_range("Can't get element - list is empty!");
	}
	Node<T>* temp = first;
	for (int i = 0; i < index; i++) {
		if (temp->next)
			temp = temp->next;
	}
	temp->data = item;
}

template<typename T>
void LinkedList<T>::add(T item) {
	Node<T>* new_node = new Node<T>;
	new_node->data = item;
	if (is_empty()) {
		add_first(new_node);
		return;
	}
	Node<T>* iter = first;
	while (iter != NULL) {
		if (new_node->data <= iter->data) {
			if (iter == first) {
				add_first(new_node);
				return;
			}
			iter->prev->next = new_node;
			new_node->prev = iter->prev;
			new_node->next = iter;
			iter->prev = new_node;
			return;
		}
		else if (new_node->data == iter->data) {

		}
		else if (iter == last) {
			add_last(new_node);
			return;
		}
		iter = iter->next;
	}
}
#endif // !LinkedList_CPP