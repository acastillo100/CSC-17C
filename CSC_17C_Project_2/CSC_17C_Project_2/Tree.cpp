/* 
 * File:   Tree.cpp
 * Author: Alex
 *
 * Created on June 4, 2018, 8:00 AM
 */

#include "Tree.h"

//Constructor
Tree::Tree() 
{
    node = NULL;
}

//Destructor
Tree::~Tree() 
{
    clean(node);
}

void Tree::clean(Node *node) 
{
    if (node != NULL) 
    {
        clean(node->left);
        clean(node->right);
        delete node;
    }
}

int Tree::getHeight(Node* n) 
{
    if (n == NULL) return 0;
    return n->height;
}

void Tree::insert(int key) 
{
    //Create a new node for insertion
    Node *newNode = new Node;
    newNode->value = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    
    //Insert with recursion
    insert(node, newNode);
}

//Private insertion
void Tree::insert(Node *&node, Node *&newNode) 
{
    if (node == NULL) 
    {
        node = newNode;
    } else if (newNode->value <= node->value) 
    {
        insert(node->left, newNode);
    } else 
    {
        insert(node->right, newNode);
    }
    
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    //Right case
    if (difference(node)<-1) 
    {
        if (newNode->value >= node->right->value) 
        {
            rotateRR(node);
        } else 
        {
            rotateRL(node);
        }
    }
    if (difference(node) > 1) 
    {
        if (newNode->value <= node->left->value) 
        {
            rotateLL(node);
        } else 
        {
            rotateLR(node);
        }
    }
}

void Tree::prePrnt() 
{
    preOrder(node);
}

void Tree::inPrnt() 
{
    inOrder(node);
}

void Tree::postPrnt() 
{
    postOrder(node);
}

int Tree::difference(Node *node) 
{
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void Tree::delet(int n) 
{
    delet(node, n);
}

void Tree::rotateRR(Node *&parent) 
{
    Node *node = parent->right;
    parent->right = node->left;
    node->left = parent;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    parent = node;
}

void Tree::rotateLL(Node *&parent) 
{
    Node *node = parent->left;
    parent->left = node->right;
    node->right = parent;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    parent = node;
}

void Tree::rotateRL(Node *&z) 
{
    rotateLL(z->right);
    rotateRR(z);
}

void Tree::rotateLR(Node *&z) 
{
    rotateRR(z->left);
    rotateLL(z);
}

void Tree::delet(Node *&node, int key) 
{
    if (node == NULL) return;
    if (key < node->value) 
    {
        delet(node->left, key);
    } 
    else if (key > node->value) 
    {
        delet(node->right, key);
    } 
    else 
    {
        //If less than one child
        if ((node->left == NULL) || (node->right == NULL)) 
        {
            //If 0 child
            if ((node->left == NULL) && (node->right == NULL)) 
            {
                Node *temp = node;
                node = NULL;
                delete temp;
            } 
            //If 1 child
            else 
            {
                Node *temp = node->left ? node->left : node->right;
                Node *temp2 = node;
                node = temp;
                delete temp2;
            }
        } 
        //If 2 children
        else 
        {
            Node *temp = node->left;
            if (temp != NULL) 
            {
                while (temp->right != NULL) 
                {
                    temp = temp->right;
                }
            }
            node->value = temp->value;
            delet(node->left, node->value);
        }
    }
    if (node == NULL) return;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    //Balance tree
    if (difference(node)<-1) 
    {
        if (difference(node->right) < 0) 
        {
            rotateRR(node);
        } 
        else 
        {
            rotateRL(node);
        }
    }
    if (difference(node) > 1) 
    {
        if (difference(node->left) > 0) 
        {
            rotateLL(node);
        } 
        else 
        {
            rotateLR(node);
        }
    }
}

void Tree::prntNode(Node *node) 
{
    cout << node->value << " ";
}

void Tree::preOrder(Node *node) 
{
    if (node != NULL) 
    {
        prntNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void Tree::inOrder(Node *node) 
{
    if (node != NULL) 
    {
        inOrder(node->left);
        prntNode(node);
        inOrder(node->right);
    }
}

void Tree::postOrder(Node *node)
{
    
    if (node != NULL) 
    {
        postOrder(node->left);
        postOrder(node->right);
        prntNode(node);
    }
}

int Tree::max(int a, int b) 
{
    return a >= b ? a : b;
}