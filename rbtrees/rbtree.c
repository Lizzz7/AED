#include <stdlib.h>
#include <assert.h>
#include "rbtree.h"

RBNode* createRBNode(int key){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->key = key;
  newNode->color = RED;
  return newNode;
}

RBTree* createRBTree(){
  RBTree* t = malloc(sizeof(RBTree));
  t->root = NULL;
  return t;
}

int isRootBlack(RBTree *t){
  if(!t->root) return 1;
  return t->root->color == BLACK;
}

void rbInsert(RBTree *t, RBNode* z){
  RBNode* x = t->root;
  RBNode* y = NULL;

  while(x){
    y = x;
    if(z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  z->parent = y;

  if(!y)
    t->root = z;
  else{
    if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
  //rbInsertFixUp(t, z);
}

void leftRotate(RBTree *t, RBNode* x){
  RBNode* y = NULL;
  
  y = x->right;
  x->right = y->left;
  
  if(y->left != t->root)
    y->left->parent = x;
  
  y->parent = x->parent;
  
  if(x->parent == t->root)
    t->root = y;
  else if(x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;
  
  y->left = x;
  x->parent = y;
}

void rightRotate(RBTree *t, RBNode* y){
  RBNode* x = t->root;
  
  y = x->left;
  x->left = y->right;

  if(y->right != t->root)
    y->right->parent = x;

  y->parent = x->parent;

  if(x->parent == t->root)
    t->root = y;
  else if(x == x->parent->right)
    x->parent->right = y;
  else
    x->parent->left = y;

  y->right = x;
  x->parent = y;
}


