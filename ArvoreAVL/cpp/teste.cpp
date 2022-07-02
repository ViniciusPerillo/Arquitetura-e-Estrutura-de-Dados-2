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
    insert(sla,'D', 4);
    insert(sla,'B', 2);
    insert(sla,'F', 6);
    insert(sla,'A', 1);
    insert(sla,'C', 3);
    //insert(sla,'E', 5);
    insert(sla,'G', 7);
    //insert(sla,'G', 3);
    //insert(sla,'H', 5);
    //insert(sla,'I', 7);
    //insert(sla,'J', 9);
    //insert(sla,'K', 11);
    //insert(sla,'L', 13);
    //insert(sla,'M', 15);

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
        recursivePrintAVL(root->left, totalHeight, scopeHeight-1);
        
        std::cout << '\n';
        for(int i = 0; i < totalHeight - scopeHeight; i++)
            std::cout << "  ";
        std::cout << " " << root->content;

        recursivePrintAVL(root->right, totalHeight, scopeHeight-1);
    }
    else
    {
      if(scopeHeight > -1)
        std::cout << "\n";
    }
}