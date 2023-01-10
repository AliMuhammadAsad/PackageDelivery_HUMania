#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.hpp"
#include <fstream>
#include <string>

using namespace std;

BSTNode *root = NULL; // this is the root of BST

// You have to define the functions below
void loadTrucks();
void makeJourney();
void unloadTrucks();

void loadTrucks()
{
    // reading a text file
    string regNum, driver1, regNo1, petrol1, fullMileage1, emptyMileage1;
    ifstream myfile("Input.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof()) //while file is open and not ended, lines are stored in respective
                              // strings and truck object is created after every 5 lines are read from the file
        {
            getline(myfile, driver1);
            getline(myfile, petrol1);
            getline(myfile, regNo1);
            getline(myfile, fullMileage1);
            getline(myfile, emptyMileage1);
            Truck tr(driver1, petrol1, regNo1, fullMileage1, emptyMileage1);
           
            root = root->insert(root, tr); //insert function from BSTNode is called to make BST tree from truck objects
        }
     
        myfile.close();
    }

    else
        cout << "Unable to open file";

}
void makeJourney(BSTNode *root) // SAHI KAAM KARRAHA HAI
{
    double fullmil, emptymil;
    double fuel, change;
    if (root == NULL)
    {
        return;
    }
    makeJourney(root->left);  //recursively in order traversal over the tree
    fuel = root->val.petrol;
    fullmil = root->val.fullMileage;
    emptymil = root->val.emptyMileage;

    change = (fuel) - (60 / (fullmil) + 60 / (emptymil)); //change in fuel calculated
    if (change > 0) //if change>0, only then petrol is getting updated
    {
        fuel = change;
    }
    makeJourney(root->right);
}
void print_func(BSTNode* root, ofstream& MyFile){ // made this helper function to store the bst tree in a .txt file. 
    if (root == NULL)
    {
        return;
    }
    print_func(root->left, MyFile );
    MyFile << root->val.driver << '\n';
    MyFile << root->val.petrol << '\n';
    MyFile << root->val.regNo << '\n';
    MyFile << root->val.emptyMileage << '\n';
    MyFile << root->val.fullMileage << '\n';
    print_func(root->right,MyFile);
          
}
void  unloadTrucks(){ // makes trip.txt file and fills it with the help of helper function print_func
    ofstream MyFile;
    MyFile.open("Trip.txt",ios::app);
    print_func(root,MyFile);
    MyFile.close();
    
}
int main()
{
    loadTrucks();
    makeJourney(root);
    unloadTrucks();
    // the code after this, is used to cout the trip text file. (probably have issues in this part)
    // string line;
    // ifstream youfile("Trip.txt");
    // if (youfile.is_open())
    // {
    // while ( getline (youfile,line) )
    // {
    //   cout << line << '\n';
    // }
    // youfile.close();
    // }

    // else cout << "Unable to open file"; 

    return 0;
}
 
 
