
#ifndef EX1_NODE_H
#define EX1_NODE_H

class Node{
private:
    Node* parent;
    Node* right;
    Node* left;
    int key;
public:
    Node(int key, Node* parent);
    Node * getParent();
    Node * getRight();
    Node * getLeft();
    int getKey();
    void setParent(Node * node);
    void setChildren(Node * node, bool way);
    void setKey(int key);
    ~Node();
};

#endif //EX1_NODE_H
