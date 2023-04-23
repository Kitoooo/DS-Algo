#ifndef BSTNODE_CPP
#define BSTNODE_CPP

#include "BSTNode.h"

template<typename T>
std::string Node<T>::nodeInfo() {
    std::stringstream ss;
    ss << "\t  (" << id << ": [p: ";
    if (parent_node == nullptr) {
        ss << "NULL ";
    }
    else {
        ss << parent_node->id;
    }
    ss << ", l: ";
    if (left_node == nullptr) {
        ss << "NULL ";
    }
    else {
        ss << left_node->id;
    }
    ss << ", r: ";
    if (right_node == nullptr) {
        ss << "NULL ";
    }
    else {
        ss << right_node->id;
    }
    ss << ", data: " << data << ")";
    return ss.str();
}

#endif // !BSTNODE_CPP