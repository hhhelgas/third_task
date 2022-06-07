//
// Created by basya on 05.06.2022.
//

#ifndef THIRD_TASK_LIST_H
#define THIRD_TASK_LIST_H

#include <iostream>
#include "AbstractList.h"
#include "ListException.h"

template <typename T> class List : public virtual AbstractList<T> {

private:

    struct Node {

        T data;
        Node* nextNode;
        Node* previousNode;
    };

    Node* root;//points to buffer node
    size_t size;


public:

    class Iterator : public virtual AbstractIterator<T> {

    private:

        Node* root;//points to list buffer node
        Node* current;

    public:

        Iterator() : root(nullptr), current(nullptr) { /*std::cout << "This iterator constrictor" << std::endl;*/ }
        ~Iterator() { /*std::cout << "This is iterator destructor" << std::endl;*/ root = nullptr; current = nullptr; }
        void start() override{ current = root->nextNode; }
        T& getElement() override{ return current->data; }
        void next() override{ current = current->nextNode; }
        bool finish() override{ return current == root; }


        friend class List<T>;
    };

    List();
    List(const List&);
    List(List&&);
    List& operator=(const List&);
    List& operator=(List&&);
    ~List();

    void add(T& data, AbstractIterator<T>* it)override;
    T& pop(AbstractIterator<T>* iterator)override;
    List<T>::Iterator& findFirstInput(T data)override;
    void clear()override;//	make empty
    bool isEmpty()override;// check empty
    size_t getSize()override;//	get size
    List<T>::Iterator& begin() override {
        List<T>::Iterator* it = new Iterator;
        it->current = root;
        it->root = root;
        return *it;
    };// get iterator to first element

    friend class List<T>::Iterator;

};

template <typename T> List<T>::List() {

    size = 0;
    root = new Node();
    root->nextNode = root;
    root->previousNode = root;

}

template <typename T> List<T>::List(const List& other) {

    std::cout << std::endl << "This is copy constructor" << std::endl;
    size = 0;
    root = new Node();
    root->nextNode = root;
    root->previousNode = root;
    Node* temp = other.root->nextNode;
    List<T>::Iterator it = begin();
    it.start();
    while (temp != other.root) {
        add(temp->data, &it);
        temp = temp->nextNode;
        it.next();
    }


}

template <typename T> List<T>::~List() {

    clear();
    delete root;
    std::cout << std::endl << "This is destructor" << std::endl;
}

template <typename T> List<T>::List(List<T>&& other) {

    std::cout << std::endl << "This is move constructor" << std::endl;
    root = other.root;
    size = other.size;
    other.root = nullptr;
}

template <typename T> List<T>& List<T>::operator=(const List& other) {

    std::cout << std::endl << "This is copy =" << std::endl;
    if (this == &other) return *this;
    if (!isEmpty()) { clear(); }
    Node* temp = other.root->nextNode;
    List<T>::Iterator it = begin();
    it.start();
    while (temp != other.root) {
        add(temp->data, &it);
        temp = temp->nextNode;
        it.next();
    }
    return *this;
};

template <typename T> List<T>& List<T>::operator=(List&& other) {

    std::cout << std::endl << "This is move =" << std::endl;
    if (this == &other) return *this;
    if (!isEmpty()) {
        clear();
        delete root;
    }
    root = other.root;
    size = other.size;
    other.root = nullptr;
    other.size = 0;
    return *this;
};

template <typename T> void List<T>::add(T& data, AbstractIterator<T>* it) {

    Node* node = new Node;
    node->data = data;
    node->previousNode = dynamic_cast<Iterator*>(it)->current;
    node->nextNode = dynamic_cast<Iterator*>(it)->current->nextNode;
    dynamic_cast<Iterator*>(it)->current->nextNode->previousNode = node;
    dynamic_cast<Iterator*>(it)->current->nextNode = node;
    size++;
}

template <typename T> T& List<T>::pop(AbstractIterator<T>* it) {

    if (this->isEmpty()) throw ListException("List is empty");

    T& result = dynamic_cast<Iterator*>(it)->getElement();
    dynamic_cast<Iterator*>(it)->current->previousNode->nextNode = dynamic_cast<Iterator*>(it)->current->nextNode;
    dynamic_cast<Iterator*>(it)->current->nextNode->previousNode = dynamic_cast<Iterator*>(it)->current->previousNode;

    Node* temp = dynamic_cast<Iterator*>(it)->current->nextNode;
    delete dynamic_cast<Iterator*>(it)->current;
    dynamic_cast<Iterator*>(it)->current = temp;
    size--;
    return result;
};

template <typename T> typename List<T>::Iterator& List<T>::findFirstInput(T elem) {

    List<T>::Iterator* it = new Iterator(begin());
    it->start();
    while (!it->finish()) {
        if (it->getElement() == elem) return *it;
        it->next();
    }
    return *it;
};//return iterator at finded element or iterator at root if false

template<typename T> void List<T>::clear() {

    if (isEmpty()) return;
    List<T>::Iterator it = begin();
    it.start();
    while (!it.finish()){
        pop(&it);
    }
};//	ñäåëàòü ñïèñîê ïóñòûì,
template<typename T> bool List<T>::isEmpty() { return root == nullptr || (root == root->nextNode && root == root->previousNode); };//	ïðîâåðêà íà ïóñòîòó,
template<typename T> size_t List<T>::getSize() { return size; };//	êîëè÷åñòâî ýëåìåíòîâ â ñïèñêå,

#endif //THIRD_TASK_LIST_H
