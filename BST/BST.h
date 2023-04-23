#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BSTNode.h"

#ifndef BST_H
#define BST_H

static int counter = 0;
constexpr auto COUNT = 5;
template<typename T>
class BST {
	Node<T>* root = NULL;
	int size = 0;
	int height = 0;

	bool is_empty();

	void postorder_deletion(Node<T>* rootNode);

	void preorder_print(Node<T>* rootNode, int iterations);

	void preorder_print(Node<T>* rootNode);

	int getHeight(Node<T>* rootNode);
public:
	Node<T>* getRoot();

	int insert(T itemToAdd); 

	Node<T>* search(T searchValue);

	void delete_node(Node<T>* delete_node);

	void preorder(Node<T>* rootNode, std::vector<Node<T>*>* outputlist);

	void inorder(Node<T>* rootNode, std::vector<Node<T>*>* outputlist);

	void clear();

	void print();

	void print(int iterations);

};

#include "BST.cpp"

#endif // !BST_H
