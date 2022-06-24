#include "doubly-linked-list.h"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if (size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DoublyLinkedList::full() const
{
    if (size_ >= CAPACITY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    Node *currentNode = head_;
    int count = 0;
    if (index < 0 || index > size_)
    {
        return tail_ -> value;
    }
    while (count != index)
    {
        if (count == index)
        {
            return currentNode -> value;
        }
        else
        {
            currentNode = currentNode -> next;
            count++;
        }
    }
    return currentNode -> value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node *currentNode = head_;
    int count = 0;
    while (currentNode != NULL)
    {
        if (currentNode -> value == value)
        {
            return count;
        }
        else
        {
            currentNode = currentNode -> next;
            count++;
        }
    }
    return size_;
}

void DoublyLinkedList::print() const
{
    Node *currentNode = head_;
    int count = 0;
    while (count < size_)
    {
        cout << currentNode << " ";
        currentNode = currentNode -> next;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    Node *newNode = new Node(value);
    Node *currentNode = head_;

    if (index < 0 || index > size_ || size_ >= CAPACITY)
    {
        return false;
    }
    else if (head_ == NULL)
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else if (index == 0)
    {
        return insert_front(value);
    }
    else if (index == size_)
    {
        return insert_back(value);
    }
    else
    {
        int count = 0;
        while (currentNode != NULL)
        {
            if (count == index)
            {
                newNode -> prev = currentNode -> prev;
                newNode -> next = currentNode;
                currentNode -> prev -> next = newNode;
                currentNode -> prev = newNode;
            }
            currentNode = currentNode -> next;
            count++;
        }
    }
    size_++;
    return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node *newNode = new Node(value);
    if (size_ >= CAPACITY)
    {
        return false;
    }
    else if (size_ == 0)
    {
        head_ = newNode;
        tail_ = head_;
    }
    else
    {
        head_ -> prev = newNode;
        newNode -> next = head_;
    }
    head_ = newNode;
    size_++;
    return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    Node *newNode = new Node(value);
    if (size_ >= CAPACITY)
    {
        return false;
    }
    else if (size_ == 0)
    {
        head_ = newNode;
        tail_ = head_;
    }
    else
    {
        tail_ -> next = newNode;
        newNode -> prev = tail_;
        tail_ = newNode;
    }
    size_++;
    return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
    Node *currentNode = head_;
    if (index < 0 || index > size_ || currentNode == NULL)
    {
        return false;
    }
    else if (index == size_ - 1)
    {
        return remove_back();
    }
    else if (index == 0)
    {
        if (currentNode -> next == NULL)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            head_ = currentNode -> next;
            head_ -> prev = nullptr;
            currentNode = nullptr;
            delete currentNode;
        }
        size_--;
        return true;
    }
}

bool DoublyLinkedList::remove_front()
{
    if (size_ == 1)
    {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else if (size_ == 0)
    {
        return false;
    }
    else
    {
        Node *currentNode = head_;
        head_ = currentNode -> next;
        head_ -> next = nullptr;
        delete currentNode;
    }
    size_--;
    return true;
}

bool DoublyLinkedList::remove_back()
{
    if (size_ == 1)
    {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else if (size_ == 0)
    {
        return false;
    }
    else
    {
        Node *currentNode = tail_;
        tail_ = currentNode -> prev;
        tail_ -> next = nullptr;
        delete currentNode;
    }
    size_--;
    return true;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    Node *currentNode = head_;
    int count = 0;
    if (index > size_ || index < 0)
    {
        return false;
    }
    while (currentNode != NULL)
    {
        if (count == index)
        {
            currentNode -> value = value;
            return true;
        }
        else
        {
            currentNode = currentNode -> next;
            count++;
        }
    }
    return false;
}

