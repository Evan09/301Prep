#pragma once
#include <iostream>
using std::cout;


enum traversalOrder{PREORDER, INORDER, POSTORDER};

template<typename T>
class BinarySearchTree;

template<typename T>
class BNode {
	T data;
	BNode<T>* left;
	BNode<T>* right;
	friend class BinarySearchTree<T>;
	BNode() : left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    int size();
    bool isEmpty();
    bool insert(const T&);
    bool remove(const T&);
    bool retrieve(const T&, T&);
    bool removeAll();
    void print(traversalOrder);

private:
    BNode<T>* root;
    int numOfNodes;


    int heightHelper(BNode<T>*);
    bool insertHelper(BNode<T>*&, const T&);
    bool removeHelper(BNode<T>*&, const T&);
    void removeNode(BNode<T>*&);
    bool retrieveHelper(BNode<T>*&, const T&, T&);
    void printHelper(BNode<T>*, traversalOrder);
    void removeAllHelper(BNode<T>*&);

    bool isLeafNode(BNode<T>*);
    bool onlyOneChild(BNode<T>*);
    BNode<T>* getMinPtr(BNode<T>*); // find pointer that points to min value
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
    numOfNodes = 0;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    removeAllHelper(root);
}

template <typename T>
int BinarySearchTree<T>::size() {
    return numOfNodes;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() {
    return root == nullptr;
}

template <typename T>
bool BinarySearchTree<T>::insert(const T& element) {
    return insertHelper(root, element)

}

template <typename T>
bool BinarySearchTree<T>::remove(const T&) {
    if (isEmpty()) {
        return false;
    }

    return removeHelper(root, element);
}

template <typename T>
bool BinarySearchTree<T>::retrieve(const T &element, T &retrievedElement) {
    if (isEmpty()) {
        return false;
    }

    return retrieveHelper(root, element, retrievedElement);
}

template <typename T>
bool BinarySearchTree<T>::removeAll() {
    if (isEmpty()) {
        return false;
    }
    removeAllHelper(root);

    return true;
}

template <typename T>
void BinarySearchTree<T>::print(traversalOrder order) {
    printHelper(root, order);
    cout.flush();

}

template <typename T>
int BinarySearchTree<T>::heightHelper(BNode<T>* ptr) {
    int leftHeight = 0;
    int rightHeight = 0;

    if (ptr == NULL) {
        return -1;
    }
    
    leftHeight = heightHelper(ptr->left);
    rightHeight = heightHelper(ptr->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }

}

template <typename T>
bool BinarySearchTree<T>::insertHelper(BNode<T>* &ptr, const T &element) {
    if (ptr == nullptr) {
        BNode<T>* newNode = new BNode<T>;
        newNode->data = element;
        ++numOfNodes;
        return true;
    }

    if (element < ptr->data) {
        return insertHelper(ptr->left, element);
    }
    else if (element > ptr->data) {
        return insertHelper(ptr->right, element);
    }
    else {
        return false;
    }

}

template <typename T>
bool BinarySearchTree<T>::removeHelper(BNode<T>* &ptr, const T &element) {
    if (ptr == nullptr) {
        return false;
    }

    if (ptr->data == element) {
        --numOfNodes;
        removeNode(ptr);
        return true;
    }
    else if (element < ptr->data) {
        return removeHelper(ptr->left, element);
    }
    else {
        return removeHelper(ptr->right, element);
    }

}

template <typename T>
void BinarySearchTree<T>::removeNode(BNode<T>* &ptr) {
    if (isLeafNode(ptr)) {
        delete ptr;
        ptr = nullptr;
    }
    else if (onlyOneChild(ptr)) {
        if (ptr->left == nullptr) {
            BNode<T>* toRemove = ptr;
            ptr = ptr->right;
            delete toRemove;
            toRemove = nullptr;
        }
        else if (ptr->right == nullptr) {
            BNode<T>* toRemove = ptr;
            ptr = ptr->left;
            delete toRemove;
            toRemove = nullptr;
        }
    }
    else {
        BNode<T>* min = getMinPtr(ptr->right);
        ptr->data = min->data;
        removeHelper(ptr->right, min->data);
    }

}

template <typename T>
bool BinarySearchTree<T>::retrieveHelper(BNode<T>* &ptr, const T &element, T &retrievedElement) {
    if (ptr == nullptr) {
        return false;
    }

    if (ptr->data == element) {
        retrievedElement = ptr->data;
        return true;
    }
}

template <typename T>
void BinarySearchTree<T>::printHelper(BNode<T>* ptr, traversalOrder order) {
    if (ptr == nullptr) {
        return;
    }

    if (order == PREORDER) {
        cout << ptr->data;
        printHelper(ptr->left, PREORDER);
        printHelper(ptr->right, PREORDER);
    }
    else if (order == INORDER) {
        printHelper(ptr->left, INORDER);
        cout << ptr->data;
        printHelper(ptr->right, INORDER);
    }
    else {
        printHelper(ptr->left, POSTORDER);
        printHelper(ptr->right, POSTORDER);
        cout << ptr->data;
    }

}

template <typename T>
void BinarySearchTree<T>::removeAllHelper(BNode<T>* &ptr) {
    if (ptr == nullptr) {
        return;
    }

    removeAllHelper(ptr->left);
    removeAllHelper(ptr->right);
    delete ptr;
    ptr = nullptr;
    numOfNodes = 0;

}

template <typename T>
bool BinarySearchTree<T>::isLeafNode(BNode<T>* ptr) {
    if (ptr->left == nullptr && ptr->right == nullptr) {
        return true;
    }
    
    return false;
}

template <typename T>
bool BinarySearchTree<T>::onlyOneChild(BNode<T>* ptr) {
    if (ptr->left == nullptr && ptr->right != nullptr) {
        return true;
    }
    if (ptr->right == nullptr && ptr->left != nullptr) {
        return true;
    }
    
    return false;
}

template <typename T>
BNode<T>* BinarySearchTree<T>::getMinPtr(BNode<T>* ptr) {
    if (ptr->left == nullptr) {
        return ptr;
    }

    return getMinPtr(ptr->left);
}