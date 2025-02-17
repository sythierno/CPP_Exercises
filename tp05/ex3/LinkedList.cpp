#include "LinkedList.hpp"

size_t LinkedList::size() const {
    return _size;
}

bool LinkedList::  empty() const {
    return _size == 0;
}

void  LinkedList:: push_back(const Person& p1) {
    auto newBack = new Link(_back, p1);
    _back = newBack;
    if( _size == 0) {
        _front = _back;
    }
    _size++;
}

void  LinkedList:: push_back(Person&& p1) {
    auto newBack = new Link(_back, std::move(p1));
    _back = newBack;
    if( _size == 0) {
        _front = _back;
    }
    _size++;
}

Person& LinkedList::back() const {
    return _back->value();
}

Person& LinkedList::front() const {
    return _front->value();
}

std::ostream& operator<<(std::ostream& o, const LinkedList& list) {
    o << "{";
    auto parcours = list._front;
    for(;parcours!=nullptr; parcours = parcours->_next) {
        o << " " << parcours->value();
    }
    o << " }";
    return o;
}
