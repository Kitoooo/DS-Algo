#pragma once
#include <iostream>
#include "RedBlackBSTNode.h"


#ifndef REDBLACKBST_H
#define REDBLACKBST_H

static int counter = 0;

template<typename T>
class RedBlackBST {
    RedBlackBSTNode<T>* root = NULL;
    int size = 0;
    int height = 0;
    int(*cmp)(T, T);

    bool is_empty();

    void preorder_print(RedBlackBSTNode<T>* rootNode, int iterations);

    void preorder_print(RedBlackBSTNode<T>* rootNode);

    void postorder_clear(RedBlackBSTNode<T>* rootNode);

    void rotate_left(RedBlackBSTNode<T>* pivot);

    void rotate_right(RedBlackBSTNode<T>* pivot);

    void handle_rotation(RedBlackBSTNode<T>* pivot, RedBlackBSTNode<T>* parent);

    void fixTree(RedBlackBSTNode<T>* item);

    void LeftLeftCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent);

    void LeftRightCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent);

    void RightLeftCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent);

    void RightRightCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent);

public:
    RedBlackBST(int(*cmp)(T, T));

    RedBlackBSTNode<T>* search(T searchValue);

    int insert(T itemToAdd);

    int getHeight(RedBlackBSTNode<T>* rootNode);

    void clear();

    void print();

    void print(int interations);
};

#include "RedBlackBST.cpp"

#endif // !REDBLACKBST_H
