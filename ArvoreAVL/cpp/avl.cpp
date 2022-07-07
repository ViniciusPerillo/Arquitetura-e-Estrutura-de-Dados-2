/* Vinicius G Perillo
** 30-06-2022
** This code is a AVL Data Structure
*/

//include
#include <stdexcept>

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
void rotation(AVL &, int);
void balance(AVL &);

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

            if(root->bal == -1)
                return true;
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

            if(root->bal == 1)
                return true;
        }
    }

    // balance cases

    // case 0: recursiveInsert caused a height increase
    

    // else 
    // case 1: recursiveInsert did't cause height increase

    // case 2: recursiveInsert caused a height increase and unbalance AVL
    if(abs(root->bal) > 1)
        balance(root);

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

void rotation(AVL& root, int direction)
{
    // auxiliar variable
    AVL newRoot;
    
    if(direction < 0){   
        newRoot = root->right;
        
        // changing sons
        root->right = newRoot->left;
        newRoot->left = root;
    }
    else if(direction > 0){
        newRoot = root->left;
        
        // changing sons
        root->left = newRoot->right;
        newRoot->right = root;
    }
    
    // ajusting bal
    root->bal = 0;
    newRoot->bal = 0;  

    // changing father
    newRoot->father = root->father;
    root->father = newRoot;
    
    // changing root
    root = newRoot; 

      
}



void balance(AVL &root)
{
    int weight, rotationCase = 0;

    if(root->bal < 0 )
    {
        weight = root->bal + root->left->bal;

        if(weight == -1)
        {
            rotationCase = root->left->right->bal;
            rotation(root, -1);
        }
            
        
        rotation(root, 1);
    }
    else
    {
        weight = root->bal + root->right->bal;

        if(weight == 1)
        {
            rotationCase = root->right->left->bal;
            rotation(root, 1);
        }
        
        rotation(root, -1); 
    }

    if(rotationCase == -1)
        root->right->bal = 1;
    else if(rotationCase == 1)
        root->left->bal = -1;
}