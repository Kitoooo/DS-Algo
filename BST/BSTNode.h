#pragma once
#include <iostream>
#include <string>
#include <sstream>

#ifndef BSTNODE_H
#define BSTNODE_H


template<typename T>
class Node
{
public:
	int id;
	T data;
	Node<T>* parent_node = NULL;
	Node<T>* left_node = NULL;
	Node<T>* right_node = NULL;

	std::string nodeInfo();

	friend bool operator<(const Node<T>& left, const Node<T>& right) {
		return left.data < right.data;
	}
	friend bool operator==(const Node<T>& left, const Node<T>& right) {
		return left.data == right.data;
	}
	friend bool operator>(const Node<T>& left, const Node<T>& right) { 
		return left.data > right.data; 
	}
	friend std::ostream& operator<<(std::ostream& os, const Node<T>& nodeData) {
		os << nodeData.data;
		return os;
	}
};

#include "BSTNode.cpp"
#endif // !BSTNODE_H