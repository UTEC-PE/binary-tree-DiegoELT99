#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
#include <iostream>

using namespace std;

struct Iterator
{
    Node* current;
    stack<Node*> stackTree;

    Iterator(){current = nullptr;}
    Iterator(Node* _current){current = _current;}
    Iterator(Node* _current, stack<Node*> stackGo){current = _current, stackTree = stackGo;}

    double operator*(){ return (current -> data); }

    Iterator operator=(Iterator node)
    {
        stackTree = node.stackTree;
        current = node.current;
    }

    bool operator!=(Iterator node)
    {
        return (current != node.current);
    }

    void LastVisited()
    {
        current = stackTree.top();
    }

    void Right()
    {
        current = current -> right;
    }

    void Left()
    {
        current = current -> left;
    }

    Iterator operator++()
    {
        stackTree.pop();
        if(current -> right)
        {
            Right();
            stackTree.push(current);
            while(current -> left)
            {
                Left();
                stackTree.push(current);
            }
        }
        else
            LastVisited();
        return *this;
    }
};

#endif