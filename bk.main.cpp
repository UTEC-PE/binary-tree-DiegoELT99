#include "binarytree.h"
#include <iostream>

using namespace std;

int main()
{
    BinaryTree BeepBoop;

    BeepBoop. print();

    BeepBoop.insert(1);
    BeepBoop.insert(4);
    BeepBoop.insert(5);
    BeepBoop.insert(3);
    BeepBoop.insert(2);

    BeepBoop.eliminate(2);
    BeepBoop.eliminate(3);

    BeepBoop.print();
    return 0;
}