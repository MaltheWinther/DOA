#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

template <typename Object>
class ArrayStack {
private:
    Object* arr;      
    int capacity;     
    int topIndex;     

public:
    
    ArrayStack(int initSize = 100)
        : arr(new Object[initSize]), capacity(initSize), topIndex(-1) {}

    ~ArrayStack() { delete[] arr; }

    bool empty() const {
        return topIndex == -1;
    }

    Object top() const {
        if (empty()) throw std::out_of_range("Stack is empty!");
        return arr[topIndex];
    }

    Object pop() {
        if (empty()) throw std::out_of_range("Stack is empty!");
        return arr[topIndex--];
    }

    
    void push(const Object& x) {
        if (topIndex + 1 == capacity) { 
            int newCapacity = capacity * 2;
            Object* newArr = new Object[newCapacity];
            for (int i = 0; i <= topIndex; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[++topIndex] = x;
    }
};

#endif