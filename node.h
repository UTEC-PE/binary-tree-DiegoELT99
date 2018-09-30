#ifndef NODE_H
#define NODE_H

struct Node
{
    double data;
    Node* left;
    Node* right;

    Node(double value){data = value; left = nullptr; right = nullptr;}
    Node(Node* basis){data = basis -> data; left = basis -> left; right = basis -> right;}

};

#endif