#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>





BinaryNode *BinarySearchTree::insert(int x,BinaryNode *t, int& cost)
{
    cost++; // increment cost
    if(t == NULL){
        t = new BinaryNode(x); // new node
        t-> SearchCost = cost; // make search cost equal to cost for root
        totNode++; // increment nodes in tree
        cout<<"Key = " << x <<"  Search Cost = "<<cost<<endl;
    }
    else if(x < t->Key) // go left and insert
        t->left = insert(x, t->left, cost);
    else if(x > t->Key) // go right and insert
        t->right = insert(x, t->right, cost);
    else
        cerr << "error : duplicate " << endl;
    return t;
}




BinaryNode *BinarySearchTree::findMin(BinaryNode *t){
    if(t == NULL)   cerr << "error: empty tree " << endl;
    while(t->left != NULL) t = t->left; // go all the way to left to get min
    return t;
}




BinaryNode *BinarySearchTree::removeMin(BinaryNode *t){
    if(t == NULL) // no nodes so no min
        cerr << "error: not found." << endl;
    if(t->left != NULL) // go left
        t->left = removeMin(t->left);
    else {
        BinaryNode *node = t;
        t = t->right;
        delete node;
    }
    return t;
}



BinaryNode *BinarySearchTree::remove(int x, BinaryNode *t){
    if(t == NULL){ // no nodes so nothing to remove
        cerr << "error: not found." << endl;
        return t;
    }
    if(x < t->Key) // go left
        t->left = remove(x, t->left); // go left
    else if(x > t->Key) // go left
        t->right = remove(x, t->right); // go right
    else if(t->left != NULL && t->right != NULL) // if t has two childs
    {
        t->Key = findMin(t->right)->Key;
        t->right = removeMin(t->right);
        totNode--;
        resetSearchcost(root,1); // reset cost
    }
    else //if only one child
    {
        totNode--;
        BinaryNode *node = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete node;
        resetSearchcost(root,1); // reset cost
    }
    return t;
}





void BinarySearchTree::resetSearchcost(BinaryNode* t, int i){
    if(t == NULL) return;
    resetSearchcost(t->left, i+1);
    resetSearchcost(t->right, i+1);
    t->SearchCost=i; //  reset cost
}





void BinarySearchTree::inOrderTraversal( BinaryNode *t, int& totalCost){
    if(t==NULL)
        cerr << "error: empty Tree." << endl;
    
    if(t->left != NULL)
        inOrderTraversal(t->left,totalCost);
    if (totNode <17) { // only print out if less than 17 elements
        cout << t->Key <<"["<<t->SearchCost << "] ";
    }
    totalCost += t->SearchCost;
    if(t->right !=NULL)
        inOrderTraversal(t->right,totalCost); // recursive call
}



void BinarySearchTree::preOrderTraversal( BinaryNode *t, int& totalCost){
    if(t==NULL)
        cerr << "error: empty Tree." << endl;
    
    if (totNode <17) {
        cout << t->Key <<"["<<t->SearchCost << "] ";
    }
    totalCost += t->SearchCost; // sum up costs
    if(t->left != NULL)
        preOrderTraversal(t->left,totalCost);
    if(t->right !=NULL)
        preOrderTraversal(t->right,totalCost);
}





void BinarySearchTree::postOrderTraversal( BinaryNode *t, int& totalCost){
    if(t==NULL)
        cerr << "error: empty Tree." << endl;
    
    if(t->left != NULL)
        postOrderTraversal(t->left,totalCost);
    if(t->right !=NULL)
        postOrderTraversal(t->right,totalCost);
    if (totNode <17) {
        cout << t->Key <<"["<<t->SearchCost << "] ";
    }
    totalCost += t->SearchCost;
}


// output tree by level

void BinarySearchTree::OutputTreeLevelByLevel() {
    if (!root) return ;
    queue<BinaryNode*> nodes;
    int CurrentLevel = 1;
    int NextLevel = 0;
    nodes.push(root);
    BinaryNode* X = new BinaryNode(-1);
    bool indicator = true;
    vector<int> line;
    while (!nodes.empty()) {
        BinaryNode *nodeCurrent = nodes.front();
        nodes.pop();
        CurrentLevel--;
        if (nodeCurrent) {
            line.push_back(nodeCurrent->Key);
            if (nodeCurrent->left==NULL) nodes.push(X);
            else{
                indicator = false;
                nodes.push(nodeCurrent->left);
            }
            if (nodeCurrent->right==NULL) nodes.push(X);
            else{
                indicator = false;
                nodes.push(nodeCurrent->right);
            }
            NextLevel += 2;
        }
        if (CurrentLevel == 0) {
            
            for (int i=0; i<line.size(); i++) {
                if (line[i] == -1)
                    cout <<"X ";
                else
                    cout << line[i]<<" ";
            }
            cout << endl;
            if (indicator) {
                return ;
            }
            line.clear();
            indicator = true; //initial indicator to true
            CurrentLevel = NextLevel;
            NextLevel = 0;
        }
    }
    delete X;
}




// save tree to file
void BinarySearchTree::outputData(string filename){
    ofstream ofs(filename.c_str());
    if (!root) return ;
    queue<BinaryNode*> nodes;
    int CurrentLevel = 1;
    int NextLevel = 0;
    nodes.push(root);
    BinaryNode* X=new BinaryNode(-1);
    bool indicator = true;
    vector<int> line;
    while (!nodes.empty()) {
        BinaryNode *nodeCurrent = nodes.front();
        nodes.pop();
        CurrentLevel--;
        if (nodeCurrent) {
            line.push_back(nodeCurrent->Key);
            if (nodeCurrent->left==NULL) nodes.push(X);
            else{
                indicator = false;
                nodes.push(nodeCurrent->left);
            }
            if (nodeCurrent->right==NULL) nodes.push(X);
            else{
                indicator = false;
                nodes.push(nodeCurrent->right);
            }
            NextLevel += 2;
        }
        if (CurrentLevel == 0) {
            for (int i=0; i<line.size(); i++) {
                if (line[i] == -1)
                    ofs <<"X "; // X to represent empty node
                else
                    ofs << line[i]<<" ";
            }
            ofs << endl;
            if (indicator)
                return ;
            line.clear();
            indicator = true; //initial set to true
            CurrentLevel = NextLevel; // current to next
            NextLevel = 0;
        }
    }
    delete X;
}