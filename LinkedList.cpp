//
// Created by sarra on 3/30/2020.
//
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList(){ //constructor
    cout << "Constructor called." << endl;
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList  &list){ //copy constructor
    cout << "Copy constructor called." << endl;
    if (list.head == nullptr){ //Checks to make sure there is something in the linked list to copy
        head = nullptr;}
    else {
        head = new Node(list.head -> value); //creates new head for copy
        Node* copyptr = head; //creates new pointer for copy
        //copies elements from original LL to copied LL
        for (Node *origptr = list.head -> next; origptr != nullptr; origptr = origptr ->next) {
            copyptr -> next = new Node(origptr -> value);
            copyptr = copyptr -> next;
        }
        printList();
    }
}

LinkedList& LinkedList::operator=(const LinkedList &rhs){ //Copy Assignment Operator
    cout << "Copy assignment operator called." << endl;
    LinkedList temp;
    swap(temp.head, head);
    return *this;
}

LinkedList::~LinkedList(){ //Destructor
    cout << "Destructor called." << endl;
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}
//Functions. You may not need to use them all
void LinkedList::append(int obj){ //adds element to the end of a list
    Node* tmp = head;
    while (tmp->next != nullptr){ //finds the end of the list
        tmp = tmp->next;}
    tmp->next = new Node(obj, tmp); //establishes new Node at the end of the list
}

bool LinkedList::Delete(int obj){ //finds and deletes object in a linked list
    Node* previous = head; //empty header
    Node* current = head->next; //establishes the first valid node
    bool found = false;//obj hasn't been found
    while(!found && current != nullptr) {
        if(current->value == obj) {//finds the value in the linked list that matches the parameter
            found = true;//updates found
        }
        else {
            previous = current;
            current = current->next; //go to next value
            found = false;
        }
    }
    if(found){
    cout << "Deleting: " << current << endl;
    previous->next = current->next;
    delete current;}
    else{
        cout << "Object not found!" << endl;
    }
    return found;
}

LinkedList LinkedList::find (int obj){//finds an object and its position in the linked list
    Node* current = head;
    int pos = 0;
    while(current->value != obj)//finds the position of the value
    {
        current=current->next;
        pos++;//keeps track of the iterations
    }
    cout << current->value << " has been found at position " << pos << endl;//prints value and position
}

void LinkedList::printList(){//prints the linked list
    Node* current = head;
    while (current != nullptr)//cycles through each element until the end of the list
    {
        cout << current->value << endl;
        current = current->next;
    }
}

void LinkedList::InsertionSort() {
    {
        Node *temp;
        Node *previous = head;
        Node *current = previous->next;

        if (head == nullptr) {
            return;
        }
        if (current == nullptr) {
            return;
        }
        while (current != nullptr) {
            if (current->value >= previous->value) {
                previous = previous->next;
                current = current->next;
            } else {
                if (current->value < head->value) {
                    previous->next = current->next;
                    current->next = nullptr;
                    current->next = head;
                    head = current;
                } else {
                    temp = head;
                    while (current->value > temp->next->value && temp->next != nullptr) {
                        temp = temp->next;
                    }
                    previous->next = current->next;
                    current->next = nullptr;
                    current->next = temp->next;
                    temp->next = current;
                }
            }
            current = previous->next;
        }
    }
}
