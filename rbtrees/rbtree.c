#include <stdlib.h>
#include <assert.h>
#include "rbtree.h"

RBNode* createRBNode(int key){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->rigth = NULL;
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
