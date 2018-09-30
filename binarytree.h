#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "iterator.h"
#include "node.h"

struct BinaryTree
{
    Node* root;
    int nodes;

    BinaryTree(){root = nullptr; nodes = 0;}
    bool find(double number, Node**& temp)
    {
        if (nodes == 0)
        {
            temp = nullptr;
            return false;
        }

        else
        {
            temp = &root;
            while(*temp)
            {
                if((*temp) -> data == number) return true;
                else if ((*temp) -> data > number)
                    temp = &((*temp) -> right);
                else temp = &((*temp) -> left);
            }
        }
    return false;
    }

    void insert(double value)
    {
        Node** temp;
        if (!find(value, temp))
        {
            Node* newValue = new Node(value);
            if (nodes == 0)
            {
                root = newValue;
            }
            else
            {
                *temp = newValue;
            }
            nodes++;
        }
    };

    void eliminate(double value)
    {
        Node** temp;
        if(find(value, temp))
        {
            Node* lefty = (*temp) -> left;
            Node* righty = (*temp) -> right;

            delete *temp;

            if(lefty && righty)
            {
                *temp = lefty;
                while (lefty -> right)
                    lefty = lefty -> right;
            }

            else if (lefty || righty)
            {
                if(lefty) *temp = lefty;
                else *temp = righty;
            }
            else *temp = nullptr;
            nodes--;
        }
    }

    Iterator begin()
    {
        Node* temp = new Node(root);
        stack<Node*> originStack;
        originStack.push(root);

        while(temp -> left)
        {
            temp = temp -> left;
            originStack.push(temp);
        }
        return Iterator(temp, originStack);
    }

    Iterator finish()
    {
        return Iterator(nullptr);
    }

};

#endif