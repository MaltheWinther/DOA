#pragma once

#include <cassert>
#include "simple_list.h"

template <typename Object>
class LinkedList : public List<Object> {
private:
    struct Node {
        Object data;
        Node *next;
    };

    int theSize;
    Node *head;
    Node *tail;

public:
    LinkedList() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->next = nullptr;
    }

    ~LinkedList() {
        clear();
        delete head;
        delete tail;
    }

    int size() const override  { return theSize; }
    bool empty() const override { return (size() == 0); }

    void clear() override{
        Node *p = head->next;
        while (p != tail) {
            Node *t = p->next;
            delete p;
            p = t;
        }
        head->next = tail;
        theSize = 0;
    }

    void push_front(const Object& x) override {
        Node *p = new Node;
        p->data = x;
        p->next = head->next;
        head->next = p;
        theSize++;
    }

    void push_back(const Object& x) override {
        
        Node *last = head;
        while (last->next != tail) {
            last = last->next;
        }
        Node *p = new Node;
        p->data = x;
        p->next = tail;
        last->next = p;
        theSize++;
    }

    Object pop_front() override {
        Node *p = head->next;
        Object x = p->data;
        head->next = p->next;
        theSize--;
        delete p;
        return x;
    }

    Object pop_back() override{
        assert(theSize > 0);
        if (theSize == 1) {
            return pop_front();
        }
        assert(theSize >= 2);
        Node *second_to_last = head;
        while (second_to_last->next->next != tail) {
            second_to_last = second_to_last->next;
        }
        Node *last = second_to_last->next;
        Object x = last->data;
        second_to_last->next = tail;
        theSize--;
        delete last;
        return x;
    }

    Object find_kth (int pos) const override{
        assert(pos >= 0 && pos < theSize);
        Node *p = head->next;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        return p->data;
    }

    Object remove(int pos){
        assert(pos >= 0 && pos < theSize);
        Node *p = head;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        Node *q = p->next;
        Object x = q->data;
        p->next = q->next;
        theSize--;
        delete q;
        return x;
    }

    void insert (const Object &x, int pos){
        assert(pos >= 0 && pos <= theSize);
        Node *p = head;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = p->next;
        p->next = newNode;
        theSize++;
    }

    bool contains(const Object &x) const{
        Node *p = head->next;
        while (p != tail) {
            if(p->data == x){
                return true;
            }
            p = p ->next;
        }
        return false;
    }

    void print() const{
        Node *p = head->next;
        while (p != tail){
            std::cout << "Data: " << p->data << std::endl;
            p = p->next;
        }
    }

    void reverse() {
    Node* prev = tail; 
    Node* curr = head->next; 
    while (curr != tail) {
        Node* next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
}
};