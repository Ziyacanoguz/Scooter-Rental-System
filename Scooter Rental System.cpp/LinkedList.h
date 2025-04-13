#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Library.h"

template <typename T>
class LinkedList 
{
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() 
    {
        clear();
    }

    void add(const T& data) 
    {
        Node<T>* newNode = new Node<T>(data);
        if (!head) 
        {
            head = newNode;
        } 
        else 
        {
            Node<T>* current = head;
            while (current->next)
                current = current->next;
            current->next = newNode;
        }
    }

    bool remove(int id) 
    {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current) 
        {
            if (current->data.getId() == id) 
            {
                if (previous)
                {
                    previous->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        }

        return false;
    }

    T* find(int id) 
    {
        Node<T>* current = head;
        while (current) 
        {
            if (current->data.getId() == id)
            {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr;
    }

    void displayAll() const 
    {
        Node<T>* current = head;
        while (current) 
        {
            current->data.display();
            current = current->next;
        }
    }

    void clear() 
    {
        Node<T>* current = head;
        while (current) 
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    Node<T>* getHead() const 
    {
        return head;
    }
};

#endif