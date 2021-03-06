// linkedlist.h
// Linked list header file 

#ifndef LINKEDLIST_H
#define LINKEDTLIST_H

#include <iterator>
template <class Item>
class list_iterator;

template <class Item>
class LinkedList {

public:
    // ctor, dtor and 3 methods already done in intlist.cpp:
    typedef list_iterator<Item> iterator;
    friend class list_iterator<Item>;
    LinkedList();              // constructor
    ~LinkedList();             // destructor
    void append(Item value); // append value at end of list
    void print() const;     // print values separate by ' '
    int count() const;      // return count of values

    //  METHODS YOU MUST IMPLEMENT IN intlist.cpp:
    Item sum() const;                 // sum of all values
    bool contains(Item value) const;  // true if value in list
    Item max() const;                 // maximum value
    void insertFirst(Item value);     // insert new first value

    //begin and end methods for the iterator
    iterator begin(){ return iterator(first);}
    iterator end(){ return iterator(0);}



private:

    // definition of Node structure (DO NOT CHANGE):
    struct Node {
        Item info;
        Node *next;
    };

    Node *first; // pointer to first node
};

template <class Item>
class list_iterator: public std::iterator <std::forward_iterator_tag, Item>
{
    public:
        typedef typename LinkedList<Item>::Node Node;

        list_iterator(Node* mycurr=0){ curr = mycurr;}
        Item operator*(){ return curr->info;}
        void operator++(){ if(curr) curr = curr->next;}
        bool operator!=(list_iterator other){ return curr != other.curr;}
    private:
        Node  * curr;
};







#include "linkedlist.template"
#endif
