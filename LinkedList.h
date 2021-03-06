//
// Created by sarra on 3/30/2020.
//

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#include "Node.h"
#include "StockValue.h"
#include <iostream>
#include <vector>
using namespace std;

class LinkedList{
public:
    //Constructors
    LinkedList();
    LinkedList(const LinkedList& list);

    //Assignment Operator
    LinkedList &operator=(const LinkedList & rhs);

    //Destructor
    ~LinkedList();

    //Functions. You may not need to use them all
    void append(StockValue obj); //adds object to end of linked list
    bool Delete (int obj); //deletes object from linked list - not used
    LinkedList find (int obj); //finds an object in a linked list - not used
    void printList(); //print the linked list
    void InsertionSort(); //sorts the linked list

private:
    Node* head;

};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H