#ifndef REDBLACKBSTNODE_CPP
#define REDBLACKBSTNODE_CPP

#include "RedBlackBSTNode.h"

template<typename T>
std::string RedBlackBSTNode<T>::nodeInfo() {
    std::stringstream ss;
    ss << "\t  (" << id << ": [c: ";
    switch (color) {
    case red: ss<< "red"; break;
    case black: ss<<"black"; break;
    }
    ss << ", p: ";
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

#endif // !REDBLACKBSTNODE_CPP