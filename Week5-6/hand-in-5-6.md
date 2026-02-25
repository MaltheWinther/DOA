# Exercise 1

```cpp
#include <iostream>

bool contains(int *A, int x, int size)
{

    if (*A == x)
    {
        return true;
    }

    else if (size == 0)
    {
        return false;
    }

    return contains(A + 1, x, size - 1);
}

int findMax(int *array, int size){
    if (size == 1){
        return *array;
    }
    int MaxOfRest = findMax(array+1,size-1);
    return (*array > MaxOfRest) ? *array : MaxOfRest;


}

int findMin(int*array, int size){
    if (size == 1){
        return *array;
    }
    int MinOfRest = findMin(array+1,size-1);
    return (*array < MinOfRest) ? *array : MinOfRest;


}
int main()
{

    int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "1.A: " << std::endl;

    std::cout << contains(array, 8, size) << std::endl;  // Outputs 1 for true
    std::cout << contains(array, 12, size) << std::endl; // Outputs 0 for false


    std::cout << "1.B" << std::endl;

    std::cout << findMax(array,size) << std::endl; // Outputs 10
    std::cout << findMin(array,size) << std::endl; // Outputs 1

    return 0;
}

```

Worst case time complexity for 1.A:

In the worst case, the algorithm checks every element of the array exactly once, resulting in O(N) time complexity for an array of N elements.

Worst case time complexity for 2.A:

In the worst case, the algorithm checks every element of the array exactly once, resulting in O(N) time complexity for an array of N elements.

# Exercise 2

```cpp

#include <iostream>

void triangle(int m, int n){
    if (m > n){
    return;
    }
    else {
        for (int i = 0; i < m; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
        triangle(m+1,n);
        for (int i = 0; i < m; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {


    triangle(3,6);
    return 0;
}

```

Output:

![alt text](image.png)

# Exercise 3

```cpp

#include <iostream>

void bookletPrint(int startpage, int endpage, int originalStartpage){

    if(startpage > endpage){
        return;
    }
    std::cout << "Sheet " << (startpage-originalStartpage)/2+1 << " contains pages: " << startpage << ", " << startpage+1 << ", " << endpage-1 << ", " << endpage << std::endl;
    bookletPrint(startpage+2,endpage-2,originalStartpage);

}


int main() {

    bookletPrint(5,12,5);

    return 0;
}
```

# Exercise 4

```cpp
#include <iostream>

bool solve_maze(char maze[5][6],char checked_maze[5][6], int y, int x){
    if (maze[y][x] == 'X' || checked_maze[y][x] == 'X' ){
        return false;
    }
    else if (maze[y][x] == 'E'){
        return true;
    }

    checked_maze[y][x] = 'X';

    if(solve_maze(maze,checked_maze, y-1, x)){ //Checks field above
        return true;
    }
      if(solve_maze(maze,checked_maze, y, x+1)){ //Checks field to the right
        return true;
    }
     if(solve_maze(maze,checked_maze, y+1, x)){ //Checks field below
        return true;
    }
    if(solve_maze(maze,checked_maze, y, x-1)){ //Checks field to the left
        return true;
    }

    return false;
    }


int main() {


    char maze[5][6] = {
    {'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', 'X', ' ', 'X'},
    {'X', ' ', 'X', 'E', ' ', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X'}
};

char checked_maze[5][6] = {
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}
};

std::cout << solve_maze(maze,checked_maze,1,1) << std::endl; //Output = 1

    return 0;
}
```

# Exercise 5

Recursion recipe:

1. State problem in terms of it's size / complexity

   Given a linked list, find the position (index) of a node whose data equals x. The size/complexity is determined by the number of nodes left to inspect in the list.

2. Find Base Case of problem and show how it can be solved without recursion

   Base case for the search:

   If the current node is null, meaning the end of the list, then x is not in the list: return -1.
   If the current node's data matches x, we have found the element: return the current position (index).

3. Based on the inductive hypothesis (or recursive leap of faith), find the recursive case of the problem and show how it can be solved using recursion that makes progress towards the base case

   If we are not at the end (and have not found x), assume we can find x in the rest of the list by recursively calling search on the next node, incrementing the position.

   If the recursive call finds x further in the list, return that position.
   Otherwise, return -1.

4. Ensure that the recursive case makes progress towards and eventually reaches the BC

   In each recursive call, we move one node forward (node->next) and increment the position — this means we are always progressing towards either finding x or reaching the end (null), so we are guaranteed to reach the base case eventually.

```cpp

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


    int search(const Object x) {
    return search_helper(x, head->next, 0);
    }

    int search_helper(const Object x, Node* curr, int pos) {
    if (curr == tail)
        return -1;
    if (curr->data == x)
        return pos;
    return search_helper(x, curr->next, pos+1);
    }


};




#include <iostream>
#include <simple_linked_list.h>


int main() {

   LinkedList<int> testlist;


    // Test push_front and push_back
    testlist.push_back(1); // List: 1
    testlist.push_back(3);  // List: 1 3
    testlist.push_back(5); // List: 1 3 5
    testlist.push_back(7);  // List: 1 3 5 7

    std::cout << testlist.search(5) << std::endl; //Output = 2
    std::cout << testlist.search(10) << std::endl; //Output = -1


    return 0;
}
```

# Exercise 6

# Exercise 7

# Exercise 8
