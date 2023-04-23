#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

template<typename T>
bool BST<T>::is_empty() {
	return root == NULL;
}

template<typename T>
void BST<T>::postorder_deletion(Node<T>* rootNode) {
	if (rootNode == NULL) {
		return;
	}
	postorder_deletion(rootNode->left_node);
	postorder_deletion(rootNode->right_node);
	delete rootNode;
}

template<typename T>
void BST<T>::preorder_print(Node<T>* rootNode, int iterations) {
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
void BST<T>::preorder_print(Node<T>* rootNode) {
	if (rootNode == NULL) {
		return;
	}
	std::cout << rootNode->nodeInfo() << std::endl;
	preorder_print(rootNode->left_node);
	preorder_print(rootNode->right_node);
}
template<typename T>
int BST<T>::getHeight(Node<T>* rootNode) {
	if (rootNode == NULL) {
		return 0;
	}
	int leftNodeHeight = getHeight(rootNode->left_node);
	int rightNodeHeight = getHeight(rootNode->right_node);

	return std::max(leftNodeHeight, rightNodeHeight) + 1;
}
template<typename T>
Node<T>* BST<T>::getRoot() {
	return root;
}

template<typename T>
int BST<T>::insert(T itemToAdd) {
	Node<T>* new_node = new Node<T>();
	new_node->data = itemToAdd;
	if (is_empty()) {
		new_node->id = counter++;
		root = new_node;
		size++;
		return 1;
	}
	Node<T>* iter = new Node<T>();
	Node<T>* iter_parent = new Node<T>();
	iter = root;
	while (iter != NULL) {
		if (*new_node == *iter) {
			//values cant be the same
			return -1;
		}
		else if (*new_node < *iter) {
			iter_parent = iter;
			iter = iter->left_node;
		}
		else if (*new_node > *iter) {
			iter_parent = iter;
			iter = iter->right_node;
		}
	}
	new_node->id = counter++;
	iter = new_node;
	iter->parent_node = iter_parent;

	if (*iter < *iter->parent_node)
		iter->parent_node->left_node = iter;

	else if (*iter > *iter->parent_node)
		iter->parent_node->right_node = iter;
	size++;
	return 1;
}

template<typename T>
Node<T>* BST<T>::search(T searchValue) {
	Node<T>* iter = new Node<T>();
	iter = root;
	while (iter != NULL) {
		if (searchValue == iter->data) {
			return iter;
		}
		else if (searchValue < iter->data) {
			iter = iter->left_node;
		}
		else if (searchValue > iter->data) {
			iter = iter->right_node;
		}
	}

	return NULL;
}
template<typename T>
void BST<T>::delete_node(Node<T>* delete_node) {
	Node<T>* deleteParent = delete_node->parent_node;
	if (delete_node->left_node == NULL && delete_node->right_node == NULL) {
		if (*delete_node < *deleteParent) {
			deleteParent->left_node = NULL;
		}
		else {
			deleteParent->right_node = NULL;
		}
		delete delete_node;
		size--;
		return;
	}

	if (delete_node->left_node == NULL) {
		deleteParent->right_node = delete_node->right_node;
		delete_node->right_node->parent_node = deleteParent;
		delete delete_node;
		size--;
		return;
	}
	if (delete_node->right_node == NULL) {
		deleteParent->left_node = delete_node->left_node;
		delete_node->left_node->parent_node = deleteParent;
		delete delete_node;
		size--;
		return;
	}

	Node<T>* successor = delete_node->right_node;

	while (successor->left_node != NULL) {
		successor = successor->left_node;
	}

	delete_node->data = successor->data;
	successor->right_node->parent_node = successor->parent_node;
	successor->parent_node->left_node = successor->right_node;
	delete successor;
	size--;
}
template<typename T>
void BST<T>::preorder(Node<T>* rootNode, std::vector<Node<T>*>* outputlist) {
	if (rootNode == NULL) {
		return;
	}
	outputlist->push_back(rootNode);

	preorder(rootNode->left_node, outputlist);
	preorder(rootNode->right_node, outputlist);
}
template<typename T>
void BST<T>::inorder(Node<T>* rootNode, std::vector<Node<T>*>* outputlist) {
	if (rootNode == NULL) {
		return;
	}
	inorder(rootNode->left_node, outputlist);
	outputlist->push_back(rootNode);
	inorder(rootNode->right_node, outputlist);
}
template<typename T>
void BST<T>::clear() {
	postorder_deletion(root);
	root = NULL;
}
template<typename T>
void BST<T>::print() {
	std::cout << "binary search tree:\n\tsize: " << size << "\n\theight: " << getHeight(root) << "\n\t{\n";
	preorder_print(root);
	std::cout << "\t}\n";
}
template<typename T>
void BST<T>::print(int iterations) {
	std::cout << "binary search tree:\n\tsize: " << size << "\n\theight: " << getHeight(root) << "\n\t{\n";
	preorder_print(root, iterations);
	std::cout << "\t}\n";
}

#endif // !BST_CPP