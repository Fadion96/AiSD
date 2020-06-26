#include "Tree.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n;
    int i;
    int x;
    string operation;
    Tree tree;
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    cin>>n;
    for(i = 0; i < n ; i++) {
        cin >> operation;
        if (operation == "insert") {
            cin >> x;
            tree.insert(x);
        } else if (operation == "delete") {
            cin >> x;
            tree.del(x);
        } else if (operation == "find") {
            cin >> x;
            tree.find(x);
        } else if (operation == "min") {
            tree.min();
        } else if (operation == "max") {
            tree.max();
        } else if (operation == "inorder") {
            tree.inOrder();
        } else {
            cout << "Nieprawidlowa operacja" << endl;
        }
    }
}