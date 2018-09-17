#include "BinaryNode.h"
#include <stdexcept>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

class BinarySearchTree {
private:
    int totNode;
    BinaryNode *root;
    BinaryNode *insert(int x, BinaryNode *t, int& cost); // insert into tree
    BinaryNode *findMin(BinaryNode *t); // find minimum
    BinaryNode *removeMin (BinaryNode *t); //remove minimum
    BinaryNode *remove(int x, BinaryNode *t); // remove node

    void resetSearchcost(BinaryNode* t, int i);    
    void inOrderTraversal( BinaryNode *t, int& totalCost);
    void preOrderTraversal( BinaryNode *t, int& totalCost);
    void postOrderTraversal( BinaryNode *t, int& totalCost);
public:
    // constructor
    BinarySearchTree() { root = NULL; totNode = 0; } // make totnode 0 as well
    bool isEmpty(){return root == NULL;}
    void remove(int x){ root = remove(x, root); } // remove Key
    void insert(int x) {
        int cost = 0;
        root=insert(x, root, cost);
    }
    //return search cost total in each traversal
    int inOrderTraversal()
    {
        int totalCost = 0;
        inOrderTraversal(root,totalCost); // using void function from above
        cout << endl;
        return totalCost;
    }
    int preOrderTraversal()
    {
        int totalCost = 0;
        preOrderTraversal(root,totalCost);
        cout << endl;
        return totalCost;
    }
    int postOrderTraversal()
    {
        int totalCost = 0;
        postOrderTraversal(root,totalCost);
        cout << endl;
        return totalCost;
    }
    
    void OutputTreeLevelByLevel(); // defined in cpp
    void outputData(string filename); // defined in cpp
};