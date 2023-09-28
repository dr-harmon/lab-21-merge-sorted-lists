#pragma once

template <typename E>
class DLinkedList;

template <typename E>
class DNode {                                 // doubly linked list node
private:
    E elem;                                   // linked list element value
    DNode<E>* prev;                           // prev item in the list
    DNode<E>* next;                           // next item in the list
    friend class DLinkedList<E>;              // provide DLinkedList access
};

template <typename E>
class DLinkedList {                           // a doubly linked list
public:
    DLinkedList() {                           // empty list constructor
        header = new DNode<E>();	          // create sentinels
        trailer = new DNode<E>();
        header->next = trailer;			      // have them point to each other
        trailer->prev = header;
    }
    ~DLinkedList() {                          // destructor
        while (!empty()) removeFront();	      // remove all but sentinels
        delete header;                        // remove the sentinels
        delete trailer;
    }
    bool empty() const                        // is list empty?
    { return header->next == trailer; }
    const E& front() const                    // return front element
    { return header->next->elem; }
    const E& back() const                     // return back element
    { return trailer->prev->elem; }
    void addFront(const E& e) {               // add to front of list
        add(header->next, e);
    }
    void addBack(const E& e) {                // add to back of list
        add(trailer, e);
    }
    void removeFront() {                      //  remove from front
        remove(header->next);
    }
    void removeBack() {                       //  remove from back
        remove(trailer->prev);
    }
private:
    DNode<E>* header;                         // head sentinel
    DNode<E>* trailer;                        // tail sentinel
protected:
    void add(DNode<E>* v, const E& e) {       // insert new node before v
        auto u = new DNode<E>();       	      // create a new node for e
        u->elem = e;
        u->next = v;	                      // link u in between v
        u->prev = v->prev;		              // ...and v->prev
        v->prev->next = u;
        v->prev = u;
    }
    void remove(DNode<E>* v) {			      // remove node v
        auto u = v->prev;			          // predecessor
        auto w = v->next;				      // successor
        u->next = w;				          // unlink v from list
        w->prev = u;
        delete v;
    }
};
