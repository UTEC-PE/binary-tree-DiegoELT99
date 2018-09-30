#include "binarytree.h"
#include <iostream>

using namespace std;

int main()
{
    BinaryTree BeepBoop;
    BeepBoop.insert(1);
    BeepBoop.insert(4);
    BeepBoop.insert(5);
    BeepBoop.insert(3);
    BeepBoop.insert(2);

    BeepBoop.eliminate(5);
    BeepBoop.eliminate(3);

    Iterator Test;

    matenme = BeepBoop.begin();

    cout << *Test;
    return 0;
}