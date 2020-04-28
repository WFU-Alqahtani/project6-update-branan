#ifndef NODE_H
#define NODE_H

#include "StockValue.h"

class Node {
public:
    // Node constructor
    Node(StockValue v, Node* n = nullptr)
    {
        value = v;
        next = n;
    }

    //Destructor
    ~Node(){
        delete next;
    }
    friend class LinkedList;

private:
    Node* next;
    StockValue value;

};

#endif //NODE_H
