#pragma once

#include "Link.hpp"
#include "Person.hpp"

class LinkedList
{
public:
    // Il faut réflechir aux prototypes des fonctions-membres ci-dessous, certains ne sont pas corrects.
    friend std::ostream& operator<<(std::ostream& o, const LinkedList& list);

    size_t size() const;
    bool   empty() const;
    void   push_back(const Person&);
    void   push_back(Person&&);
    Person& back() const;
    Person& front() const;

    // void concatenate_back(LinkedList);

    // bool contains(Person);

    // void push_back_if_absent(Person);

    // static void swap(LinkedList, LinkedList);

private:
    Link* _front;
    Link* _back;
    int   _size = 0;
};