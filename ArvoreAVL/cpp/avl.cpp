/* Vinicius G Perillo
** 30-06-2022
** This code is a AVL Data Structure
*/


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
// AVL newAVL(char, int, AVL);
// char search(AVL, int);
// bool insert(AVL, char, int);
// bool remove(AVL, int);
// void printAVL(AVL );

//auxiliars
// bool recursiveInsert(AVL, AVL, AVL);
// bool recursiveRemove(AVL, int, AVL);
// void leftRotation(AVL);
// void rightRotation(AVL);
// void balance(AVL);

//functions

AVL newAVL(char content, int key, AVL father = nullptr)
{
    //creation
    AVL newAVL = new struct node;
    
    //values
    newAVL->content = content;
    newAVL->key = key;
    newAVL->bal = 0;
    newAVL->left = nullptr;
    newAVL->right = nullptr;
    newAVL->father = father;
    
    return newAVL;
}