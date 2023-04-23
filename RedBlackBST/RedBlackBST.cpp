#ifndef REDBLACKBST_CPP
#define REDBLACKBST_CPP
#include "RedBlackBST.h"

template<typename T>
bool RedBlackBST<T>::is_empty() {
    return root == NULL;
}

template<typename T>
void RedBlackBST<T>::preorder_print(RedBlackBSTNode<T>* rootNode, int iterations) {
    --iterations;
    if (iterations <= 0) {
        return;
    }
    if (rootNode == NULL) {
        return;
    }
    std::cout << rootNode->nodeInfo() << std::endl;
    preorder_print(rootNode->left_node, iterations);
    preorder_print(rootNode->right_node, iterations);
}

template<typename T>
void RedBlackBST<T>::preorder_print(RedBlackBSTNode<T>* rootNode) {
    if (rootNode == NULL) {
        return;
    }
    std::cout << rootNode->nodeInfo() << std::endl;
    preorder_print(rootNode->left_node);
    preorder_print(rootNode->right_node);
}

template<typename T>
void RedBlackBST<T>::postorder_clear(RedBlackBSTNode<T>* rootNode) {
    if (rootNode == NULL) {
        return;
    }
    postorder_clear(rootNode->left_node);
    postorder_clear(rootNode->right_node);
    delete rootNode;
    size--;
}

template<typename T>
void RedBlackBST<T>::rotate_left(RedBlackBSTNode<T>* pivot) {
    RedBlackBSTNode<T>* parent = pivot->parent_node;
    handle_rotation(pivot, parent);

    if (pivot->left_node) pivot->left_node->parent_node = parent;
    parent->right_node = pivot->left_node;
    pivot->left_node = parent;
}

template<typename T>
void RedBlackBST<T>::rotate_right(RedBlackBSTNode<T>* pivot) {
    RedBlackBSTNode<T>* parent = pivot->parent_node;
    handle_rotation(pivot, parent);

    if (pivot->right_node) pivot->right_node->parent_node = parent;
    parent->left_node = pivot->right_node;
    pivot->right_node = parent;
}

template<typename T>
void RedBlackBST<T>::handle_rotation(RedBlackBSTNode<T>* pivot, RedBlackBSTNode<T>* parent) {
    if (parent->parent_node) {
        if (parent->parent_node->left_node == parent) {
            parent->parent_node->left_node = pivot;
        }
        else {
            parent->parent_node->right_node = pivot;
        }
    }
    else {
        root = pivot;
    }
    pivot->parent_node = parent->parent_node;
    parent->parent_node = pivot;
}

template<typename T>
void RedBlackBST<T>::fixTree(RedBlackBSTNode<T>* item) {
    RedBlackBSTNode<T>* parent = NULL;
    RedBlackBSTNode<T>* grandparent = NULL;
    RedBlackBSTNode<T>* uncle = NULL;
    while ((item != root) && (item->color != black) && (item->parent_node->color == red)) {
        parent = item->parent_node;
        grandparent = parent->parent_node;

        if (grandparent->left_node == parent) {
            uncle = grandparent->right_node;
            if (uncle != NULL && uncle->color == red) {
                grandparent->color = red;
                parent->color = black;
                uncle->color = black;
                item = grandparent;
            }
            else {
                if (item == parent->right_node) {
                    rotate_left(item);
                    item = parent;
                    parent = item->parent_node;
                }
                rotate_right(parent);
                std::swap(parent->color, grandparent->color);
                item = parent;
            }
        }
        else {
            uncle = grandparent->left_node;
            if ((uncle != NULL) && (uncle->color == red)) {
                grandparent->color = red;
                parent->color = black;
                uncle->color = black;
                item = grandparent;
            }
            else {
                if (item == parent->left_node) {
                    rotate_right(item);
                    item = parent;
                    parent = item->parent_node;
                }
                rotate_left(parent);
                std::swap(parent->color, grandparent->color);
                item = parent;
            }
        }
    }
    root->color = black;
}

template<typename T>
void RedBlackBST<T>::LeftLeftCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent) {
    rotate_right(parent);
    swap(parent->color, grandparent->color);
    item = parent;
}

template<typename T>
void RedBlackBST<T>::LeftRightCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent) {
    rotate_left(item);
    item = parent;
    parent = item->parent_node;
}

template<typename T>
void RedBlackBST<T>::RightLeftCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent) {
    rotate_right(item);
    item = parent;
    parent = item->parent_node;
}

template<typename T>
void RedBlackBST<T>::RightRightCase(RedBlackBSTNode<T>* item, RedBlackBSTNode<T>* parent, RedBlackBSTNode<T>* grandparent) {
    rotate_left(parent);
    swap(parent->color, grandparent->color);
    item = parent;
}

template<typename T>
RedBlackBST<T>::RedBlackBST(int (*cmp)(T, T)) {
	this->cmp = cmp;
}
template<typename T>
RedBlackBSTNode<T>* RedBlackBST<T>::search(T searchValue) {
    RedBlackBSTNode<T>* iter = new RedBlackBSTNode<T>();
    iter = root;
    while (iter != NULL) {
        switch (cmp(iter->data, searchValue)) {
        case -1:
            iter = iter->left_node;
            break;
        case 0:
            return iter;
        case 1:
            iter = iter->right_node;
            break;
        }
    }
    return NULL;
}

template<typename T>
int RedBlackBST<T>::insert(T itemToAdd) {
    RedBlackBSTNode<T>* new_node = new RedBlackBSTNode<T>();
    new_node->data = itemToAdd;
    if (is_empty()) {
        new_node->id = counter++;
        root = new_node;
        root->color = black;
        size++;
        return 1;
    }
    RedBlackBSTNode<T>* iter = new RedBlackBSTNode<T>();
    RedBlackBSTNode<T>* iter_parent = new RedBlackBSTNode<T>();
    iter = root;
    while (iter != NULL) {
        switch (cmp(iter->data, new_node->data)) {
        case -1:
            iter_parent = iter;
            iter = iter->left_node;
            break;
        case 0:
            return -1;
        case 1:
            iter_parent = iter;
            iter = iter->right_node;
            break;
        }
    }
    new_node->id = counter++;
    iter = new_node;
    iter->parent_node = iter_parent;

    if (cmp(iter->data, iter->parent_node->data) == 1)
        iter->parent_node->left_node = iter;

    else if (cmp(iter->data, iter->parent_node->data) == -1)
        iter->parent_node->right_node = iter;
    size++;

    fixTree(iter);
    return 1;
}

template<typename T>
int RedBlackBST<T>::getHeight(RedBlackBSTNode<T>* rootNode) {
    if (rootNode == NULL) {
        return 0;
    }
    return 1;
    int leftNodeHeight = getHeight(rootNode->left_node);
    int rightNodeHeight = getHeight(rootNode->right_node);
    return 1;
    return std::max(leftNodeHeight, rightNodeHeight) + 1;
}

template<typename T>
void RedBlackBST<T>::clear() {
    postorder_clear(root);
    root = NULL;
}

template<typename T>
void RedBlackBST<T>::print() {
    std::cout << "binary search tree:\n\tsize: " << size << "\n\theight: " << getHeight(root) << "\n\t{\n";
    preorder_print(root);
    std::cout << "\t}\n";
}

template<typename T>
void RedBlackBST<T>::print(int iterations) {
    std::cout << "binary search tree:\n\tsize: " << size << "\n\theight: " << getHeight(root) << "\n\t{\n";
    preorder_print(root, iterations);
    std::cout << "\t}\n";
}
#endif // !REDBLACKBST_CPP
