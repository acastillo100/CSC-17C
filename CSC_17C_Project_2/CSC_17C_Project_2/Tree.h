/* 
 * File:   Tree.h
 * Author: Alex
 *
 * Created on June 4, 2018, 8:00 AM
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

#include "BlackjackGame.h"

class Tree 
{
private:

    struct Node 
    {
        int value;
        struct Node *left;
        struct Node *right;
        int height;
    };
    Node *node;
    void insert(Node *&, Node *&);
    void delet(Node *&, int);
    int difference(Node *);
    void clean(Node *);
    int getHeight(Node *);
    int max(int, int);
    
    //Functions for printing
    void preOrder(Node *);
    void inOrder(Node *);
    void postOrder(Node *);
    void prntNode(Node *);
    

    void rotateRR(Node *&);
    void rotateLL(Node *&);
    void rotateRL(Node *&);
    void rotateLR(Node *&);
    
public:
    Tree();
    ~Tree();
    void insert(int);
    void delet(int);
    void prePrnt();
    void inPrnt();
    void postPrnt();
};
#endif /* TREE_H */