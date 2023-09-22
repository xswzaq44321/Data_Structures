#ifndef SELECTIVEPRIORITYQUEUE_H
#define SELECTIVEPRIORITYQUEUE_H

#include <iostream>
#include <set>

template <class Key, class Compare = std::less<Key>>
class SelectivePriorityQueue : public std::multiset<Key, Compare>
{
public:
    // inherit constructors
    using std::multiset<Key, Compare>::multiset;

    using typename std::multiset<Key, Compare>::const_reference;
    using typename std::multiset<Key, Compare>::iterator;
    using typename std::multiset<Key, Compare>::const_iterator;

    template <class T = Key>
    iterator push(T&& value)
    {
        return this->insert(std::forward<T>(value));
    }
    template <class T = Key>
    iterator push(const_iterator pos, T&& value)
    {
        return this->insert(pos, std::forward<T>(value));
    }
    const_reference top() { return *prev(this->end()); }
    void pop() { (void) this->erase(prev(this->end())); }
};

#endif  // SELECTIVEPRIORITYQUEUE_H
