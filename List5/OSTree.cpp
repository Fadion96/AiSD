#include "Tree.h"

int main(){
    Tree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(8);
    tree.insert(11);
    tree.insert(7);
    tree.inOrder();
    tree.OSSelect(10);
    tree.OSSelect(6);
}