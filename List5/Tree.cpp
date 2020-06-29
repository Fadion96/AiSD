#include <iostream>
#include "Tree.h"

Tree::Tree() {
    this->root = nullptr;
}
void Tree::insertSec(int value, Node *parent) {
    parent->setSize(parent->getSize()+1);
    if(value < parent->getKey()){
        if(parent->getLeft() != nullptr){
            insertSec(value,parent->getLeft());
        }
        else{
            parent->setChildren(new Node(value,parent), false);
        }
    }
    else{
        if(parent->getRight() != nullptr){
            insertSec(value,parent->getRight());
        }
        else{
            parent->setChildren(new Node(value,parent),true);
        }
    }
}

void Tree::insert(int value) {
    if (root == nullptr){
        root = new Node(value, nullptr);
    }
    else {
        insertSec(value, root);
    }
}

void Tree::delSec(Node *node, int value) {
    if(node != nullptr){
        node->setSize(node->getSize()-1);
        if(value == node->getKey()){
            if(node->getLeft() == nullptr && node->getRight() == nullptr){
                if(node == root){
                    root = nullptr;
                } else{
                    node->getParent()->setChildren(nullptr, node->getParent()->getRight() == node);
                }
                delete node;
            }
            else if(node->getLeft() != nullptr && node->getRight() == nullptr){
                if(node == root){
                    root = node->getLeft();
                    node->getLeft()->setParent(node->getParent());

                } else {
                    node->getParent()->setChildren(node->getLeft(), node->getParent()->getRight() == node);
                    node->getLeft()->setParent(node->getParent());
                }
                delete node;
            }
            else if(node->getLeft() == nullptr && node->getRight() != nullptr){
                if(node == root){
                    root = node->getRight();
                    node->getRight()->setParent(node->getParent());
                } else{

                    node->getParent()->setChildren(node->getRight(), node->getParent()->getRight() == node);
                    node->getRight()->setParent(node->getParent());
                }
                delete node;
            }
            else{
                node->setKey(minSec(node->getRight()));
                delSec(node->getRight(),node->getKey());
            }
        }
        else if( value < node->getKey()){
            delSec(node->getLeft(),value);
        }
        else{
            delSec(node->getRight(),value);
        }
    }
}

void Tree::del(int value) {
    if(root != nullptr){
        delSec(root,value);
    }
}

void Tree::inOrder() {
    if (root == nullptr){
        std::cout<<std::endl;
    }
    else {
        inOrderSec(root);
        std::cout<<std::endl;
    }
}

void Tree::inOrderSec(Node *node) {
    if(node->getLeft() != nullptr){
        inOrderSec(node->getLeft());
    }
    std::cout<<node->getKey()<<": "<<node->getSize()<<std::endl;
    if(node->getRight() != nullptr){
        inOrderSec(node->getRight());
    }
}

void Tree::findSec(Node *node, int key) {
    if(node != nullptr){
        if(key == node->getKey()){
            std::cout<<1<<std::endl;
        }
        else if( key < node->getKey()){
            findSec(node->getLeft(),key);
        }
        else{
            findSec(node->getRight(),key);
        }
    }
    else {
        std::cout<<0<<std::endl;
    }
}

void Tree::find(int key) {
    if (root == nullptr){
        std::cout<<0<<std::endl;
    }
    else {
        findSec(root,key);
    }
}

int Tree::findSec2(Node *node, int key) {
    int x = 0;
    if (node != nullptr) {
        x++;
        if (key == node->getKey()) {
            return x;
        } else if (key < node->getKey()) {
            x++;
            return x + findSec2(node->getLeft(), key);
        } else {
            x++;
            return x + findSec2(node->getRight(), key);
        }
    } else {
        return x;
    }
}

int Tree::find2(int key) {
    if (root == nullptr) {
        return 0;
    } else {
        return findSec2(root, key);
    }
}

int Tree::minSec(Node *node) {
    if(node->getLeft() != nullptr){
        return minSec(node->getLeft());
    }
    else{
        return node->getKey();
    }
}

void Tree::min() {
    if (root == nullptr){
        std::cout<<std::endl;
    }
    else {
        std::cout<<minSec(root)<<std::endl;
    }
}

int Tree::maxSec(Node *node) {
    if(node->getRight() != nullptr){
        return maxSec(node->getRight());
    }
    else{
        return node->getKey();
    }
}

void Tree::max() {
    if (root == nullptr){
        std::cout<<std::endl;
    }
    else {
        std::cout<<maxSec(root)<<std::endl;
    }
}

Tree::~Tree() {
    while (root != nullptr) {
        delSec(root, root->getKey());
    }
    root = nullptr;
    delete root;
}

int Tree::OSRank(Node *node) {
    int r;
    if(node->getLeft()== nullptr){
        r = 1;
    } else{
        r = node->getLeft()->getSize()+1;
    }
    Node *tmp = node;
    while(tmp != root){
        if(tmp == tmp->getParent()->getRight()){
            if(tmp->getParent()->getLeft()== nullptr){
                r = r + 1;
            } else{
                r = r + tmp->getParent()->getLeft()->getSize() + 1;
            }
        }
        tmp = tmp->getParent();
    }
    return r;
}


int Tree::OSSelectSec(Node *node,int index) {
    if(node != nullptr){
        int k = OSRank(node);
        if(index == k){
            return node->getKey();
        } else if(index < k){
            return OSSelectSec(node->getLeft(),index);
        } else{
            return OSSelectSec(node->getRight(),index); // return OSSelectSec(node->getRight(),index - k) without OSRank
        }
    } else{
        return 0;
    }
}

void Tree::OSSelect(int index) {
    if(root != nullptr && index > 0){
        std::cout<<index<<": "<<OSSelectSec(root,index)<<std::endl;
    }
}

int Tree::OSSelectSec2(Node *node, int index) {
    if(node != nullptr){
        int x = 0;
        int k = OSRank(node);
        x++;
        if(index == k){
            return x;
        } else if(index < k){
            x++;
            return x + OSSelectSec(node->getLeft(),index);
        } else{
            x++;
            return x + OSSelectSec(node->getRight(),index); // return OSSelectSec(node->getRight(),index - k) without OSRank
        }
    } else{
        return 0;
    }
}

int Tree::OSSelect2(int index) {
    if(root != nullptr && index > 0){
        return OSSelectSec2(root,index);
    } else{
        return 0;
    }
}


