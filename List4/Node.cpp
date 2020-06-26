#include "Node.h"
Node :: Node(int key, Node *parent) {
        this->parent = parent;
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
};
Node * Node :: getParent(){
    return parent;
}
Node * Node :: getRight(){
    return right;
}
Node * Node :: getLeft(){
    return left;
}
int Node :: getKey(){
    return key;
}

void Node::setParent(Node *node) {
    this->parent = node;
}

void Node::setChildren(Node *node, bool way) {
    if(way){
        this->right = node;
    } else{
        this->left = node;
    }
}

void Node::setKey(int key) {
    this->key = key;
}

Node::~Node() {
    parent = nullptr;
    right = nullptr;
    left = nullptr;
    delete parent;
    delete right;
    delete left;
}
