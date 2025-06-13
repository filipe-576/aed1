#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

node *createNode(int key);
void addNode(node *newNode, node **root);


int main(){
    node *root = ( node* ) malloc(sizeof(node));
    root->key = 10;
    root->left = NULL;
    root->right = NULL;
    node *nodeA = createNode(5);
    node *nodeB = createNode(12);
    node *nodeC = createNode(11);
    // printf("%d", nodeA->key);

    addNode(nodeA, &root);
    addNode(nodeB, &root);
    addNode(nodeC, &root);
    // printf("%d", root->left->key);
    
}

node *createNode(int key){
    node *newNode = ( node* ) malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(node *newNode, node **root){
    if( *root == NULL ){
        *root = newNode;
        (*root)->left = NULL;
        (*root)->right = NULL;

    } else if( newNode->key < (*root)->key ){
        addNode(newNode, &(*root)->left);
    } else if( newNode->key > (*root)->key ){
        addNode(newNode, &(*root)->right);
    } else{
        printf("Nodo já existe na árvore");
    }
}

void removeNode()