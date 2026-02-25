#ifndef _SIMPLE_SET_H_
#define _SIMPLE_SET_H_

#include "simple_linked_list.h"

template <typename Object>
class SimpleSet
{
private:
    LinkedList<Object> *list;

public:
    SimpleSet() { list = new SimpleLinkedList<Object>(); }
    ~SimpleSet() { delete list; }

    void insert(const Object &x)
    {
        if (!contains(x))
        {
            list->push_front(x);
        }
    }

    bool contains(const Object &x) const
    {
        return list->contains(x);
    }

    void remove(const Object &x)
    {
        int n = list->size();
        for (int i = 0; i < n; i++)
        {
            if (list->find_kth(i) == x)
            {
                list->remove(i);
                break;
            }
        }
    }
};

#endif
