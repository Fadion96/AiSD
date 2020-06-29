
#ifndef EX1_TREE_H
#define EX1_TREE_H

#include "Node.h"

class Tree{
private:
    Node* root;
    int minSec(Node* node);
    int maxSec(Node* node);
    void findSec(Node* node,int key);
    int findSec2(Node* node,int key);
    void inOrderSec(Node* node);
    void delSec(Node* node,int value);
    void insertSec(int value, Node* parent);
    int OSSelectSec(Node* node,int index);
    int OSSelectSec2(Node* node,int index);
    int OSRank(Node* node);
public:
    Tree();
    void insert(int value);
    void del(int value);
    void inOrder();
    void find(int key);
    int find2(int key);
    void min();
    void max();
    void OSSelect(int index);
    int OSSelect2(int index);
    ~Tree();
};

#endif //EX1_TREE_H
