#pragma once
#include <iostream>
#include <string>
#include <sstream>

#ifndef REDBLACKBSTNODE_H
#define REDBLACKBSTNODE_H

enum COLOR { red, black };

template<typename T>
class RedBlackBSTNode {
public:
    int id;
    T data;
    COLOR color;
    RedBlackBSTNode<T>* parent_node = NULL;
    RedBlackBSTNode<T>* left_node = NULL;
    RedBlackBSTNode<T>* right_node = NULL;

    std::string nodeInfo();

};

#include "RedBlackBSTNode.cpp"

#endif // !REDBLACKBSTNODE_H
