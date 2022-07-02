/* Vinicius G Perillo
** 30-06-2022
** This code is a AVL Data Structure
*/

//include
#include <stdexcept>
#include <iostream>

struct node {
    char content;
    int key;
    short bal;
    struct node *left;
    struct node *right;
    struct node *father;
};


typedef struct node* AVL;

//prototypes

//main functions
AVL newAVL(char, int, AVL);
// char search(AVL, int);
// bool insert(AVL, char, int);
// bool remove(AVL, int);
// void printAVL(AVL );

//auxiliars
bool recursiveInsert(AVL &, AVL &);
// bool recursiveRemove(AVL, int, AVL);
// void leftRotation(AVL);
// void rightRotation(AVL);
// void balance(AVL);

//functions

AVL newAVL(char content, int key)
{
    //creation
    AVL newAVL = new struct node;
    
    //values
    newAVL->content = content;
    newAVL->key = key;
    newAVL->bal = 0;
    newAVL->left = nullptr;
    newAVL->right = nullptr;
    newAVL->father = nullptr;
    
    return newAVL;
}

bool insert(AVL &root, char content, int key)
{
    try
    {
        //New node
        AVL newNode = newAVL(content, key);
        
        //Insert
        recursiveInsert(root, newNode);
    }
    catch(std::invalid_argument& e)
    {
        return false;
    }

    return true;
}

bool recursiveInsert(AVL &root, AVL &newNode)
{   
    // case 0: place to insert is found
    if(root == nullptr)
    {
        root = newNode;
        return true;
    }
    
    // case 1: place to insert is not found
    if(root->key == newNode->key)
        throw std::invalid_argument("Don't repeat keys");

    // case 2: place to insert is on left
    if(newNode->key < root->key)
    {
        if(recursiveInsert(root->left, newNode))
        {   
            //Configuration after adding
            root->left->father = root;
            root->bal--;
        }
    }
    // case 3: place to insert is on right
    else if(newNode->key > root->key)
    {
        if(recursiveInsert(root->right, newNode))
        {   
            //Configuration after adding
            root->right->father = root;
            root->bal++;
        }
    }

    // balance cases

    // case 0: recursiveInsert caused a height increase
    if(abs(root->bal) == 1)
        return true;

    // else 
    // case 1: recursiveInsert did't cause height increase

    // case 2: recursiveInsert caused a height increase and unbalance AVL
    if(abs(root->bal) > 1){}
        //balance(root);

    return false;
}


int getHeight(AVL root)
{
    if(root == nullptr)
        return -1;
    
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);

    return leftH > rightH ? leftH : rightH + 1;
}