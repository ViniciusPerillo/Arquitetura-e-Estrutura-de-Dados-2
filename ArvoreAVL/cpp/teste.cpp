/* Vinicius G Perillo
** 30-06-2022
** This code tests AVL Data Structure
*/

//includes
#include "avl.cpp"
#include <iostream>

void printAVL(AVL);
void recursivePrintAVL(AVL, int, int);


int main(){
    
    AVL sla = nullptr;
    
    for(int i = 0; i < 511 ; i++)
    {
        insert(sla, (char)(i%26 + 65), i);
        insert(sla, (char)((1023-i)%26 + 65), i);
        printAVL(sla);
        std::cout << "\n\n";
    }

    printAVL(sla);
    
    return 0;
}

/*
1_2_4_
3_| |
5_6_|
7_|

4 2 1
    3  
  6 5
    7

*/

void printAVL(AVL root){
    int height = getHeight(root);
    recursivePrintAVL(root, height, height);
    std::cout << '\n';
}

void recursivePrintAVL(AVL root, int totalHeight, int scopeHeight){
    
    if(root != nullptr)
    {
        recursivePrintAVL(root->right, totalHeight, scopeHeight-1);
        
        std::cout << '\n';
        for(int i = 0; i < totalHeight - scopeHeight; i++)
            std::cout << "  ";
        std::cout << " " << root->content;

        recursivePrintAVL(root->left, totalHeight, scopeHeight-1);
    }
    else
    {
      if(scopeHeight > -1)
        std::cout << "\n";
    }
}