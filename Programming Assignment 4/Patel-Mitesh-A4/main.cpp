//
//  main.cpp
//  PA4
//
//  Created by Mitesh Patel on 10/24/15.
//  Copyright (c) 2015 TAMU. All rights reserved.
//

#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    try
    {
    //ask user to input the file name they want to open must be followed by .txt
    
        cout <<"Please enter the file you want to open (1l - 12l, 1p - 12p, 1r - 12r) \n";
        string input;
        cin >>input;
    
        cout << endl;
        //open file, read from file, output file contents, insert into tree, output total nodes in tree
        ifstream read;
        read.open(input);
        int data;
        int totalNodes = 0;
        vector<int> inputData;
        if (read.is_open())
        {
            
            cout << "Input Data: \n";
            while(read >> data) {
                totalNodes++;
                inputData.push_back(data);
                cout << data << endl;
            }
            read.close();
        }
        else
            throw 1;
        
        cout << endl;
        cout << "Create a binary search tree: \n";
    
        BinarySearchTree tree;
        for(int i = 0; i<inputData.size(); ++i)
            tree.insert(inputData[i]); //insert the input data
        
        cout << "Total number of nodes is " << totalNodes << endl;
        cout << endl;
        
        cout << "Pre Order traversal: \n";
        tree.preOrderTraversal();
        
        cout << "In Order traversal: \n";
        int totalCost = tree.inOrderTraversal();
        
        cout << "Post Order traversal: \n";
        tree.postOrderTraversal();
        
        cout << endl;
        double averageCost = (double)totalCost / (double)totalNodes;
        cout << "Average search cost is " << averageCost << endl;
        
        cout << endl;
        
        if(totalNodes <= 16)
        {
            cout << "File has less than 16 nodes, check OutputTreeLevelByLevels.txt file to see output level by level.";
            tree.outputData("OutputTreeLevelByLevels.txt");
            // add another output to print out each traversals into a file
        }
        
        cout << endl;
        int remove;
        cout << "Please enter the key to remove: \n";
        cin >> remove;
        
        tree.remove(remove); // remove element from tree
        
        int newtotalCost = tree.inOrderTraversal();
        totalNodes--;
        double newaverageCost = (double)newtotalCost / (double)totalNodes;
        cout << "Total number of nodes is " << totalNodes << endl;
        cout << "Average search cost is " << newaverageCost << endl;
        cout << endl;
        //if(totalNodes <= 16) // commented because you will get a seg fault on linux server when you for example: input file name 4r or 4p and then try to remove any number greater than 2 because there will be alot of stuff to print on screen. Or if you decide to remove anything from file 4l. There will be also alot of stuff to print if you do so. However, it works on my xcode which I will show you in office hours.
        //{
            
        //    tree.OutputTreeLevelByLevel();
        //}
        
    }
    catch(int &e)
    {
        if (e == 1)
            cerr << "error: no file of that input exists \n";
    }
}
