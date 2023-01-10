#pragma once
#include "truck.hpp"

class BSTNode
{
public:
    Truck val;
    BSTNode *left;
    BSTNode *right;
    
    BSTNode *getnewNode(Truck data) //kind of a constructor function used to make new node and assign respective values to its attributes
    {
        BSTNode *newNode = new BSTNode();
        newNode->val = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    BSTNode *insert(BSTNode *root, Truck val) //inserts truct ojects named as val in the respective positions as per BST tree phenomenon
    //the trucks are compared on basis of registration numbers
    {
        if (root == NULL)
        {
            root = getnewNode(val);
        }
        if (val.regNo < root->val.regNo)
        {
            root->left = insert(root->left, val);
        }
        else if (val.regNo > root->val.regNo)
        { //
            root->right = insert(root->right, val);
        }
        return root;
    }

    void inorder(BSTNode* root){                                      //Inorder traversal function to check the BST
        if (root==NULL){
            return;
        }
        inorder(root->left);                                            //Recursive call to left subtree
        cout<<root->val.driver<<" ";                               
        inorder(root->right);                                           //Recursive call to right subtree
    }

};
