#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Node constructor
    Node(int v = 0, Node* n = nullptr)
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
    int value;

};

#endif //NODE_H
