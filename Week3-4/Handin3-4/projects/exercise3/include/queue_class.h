#ifndef _QUEUE_WITH_STACKS_H_
#define _QUEUE_WITH_STACKS_H_

#include "stack_class.h" 

template <typename Object>
class QueueWithStacks {
private:
    Stack<Object> inbox;
    Stack<Object> outbox;

public:
    QueueWithStacks() {}

    bool empty() {
        return inbox.empty() && outbox.empty();
    }

    void put(const Object& x) {
        inbox.push(x); 
    }

    
    Object front() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.pop());
            }
        }
       
        return outbox.top();
    }

    
    Object get() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.pop());
            }
        }
        return outbox.pop();
    }
};

#endif