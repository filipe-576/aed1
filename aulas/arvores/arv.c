#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

node *createNode(int key);
void addNode(int key, node **root);
void inorder(node *root);
void freeTree(node *root);
void smallestNode(node *root, node **aux);
void removeNode(node **root, int key);


int main(){
    node *root = createNode(10);
    // printf("%d", nodeA->key);
    int nums[9] = {8, 22, 5, 9, 13, 30, 1, 7, 25};

    for( int i = 0; i < 9; i++ ){
        addNode(nums[i], &root);
    }
    inorder(root);
    printf("\n");
    removeNode(&root, 10);
    inorder(root);

    freeTree(root);
}

node *createNode(int key){
    node *newNode = ( node* ) malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(int key, node **root){
    if( *root == NULL ){
        *root = createNode(key);

    } else if( key < (*root)->key ){
        addNode(key, &(*root)->left);
    } else if( key > (*root)->key ){
        addNode(key, &(*root)->right);
    } else{
        printf("Nodo já existe na árvore");
    }
}

void inorder(node *root){
    if( root->left != NULL ){
        inorder(root->left);
    }
    printf("%d ", root->key);
    if ( root->right != NULL ){
        inorder(root->right);
    }
}

void freeTree(node *root){
    if( root->left != NULL ){
        freeTree(root->left);
    }
    if ( root->right != NULL ){
        freeTree(root->right);
    }
    free(root);
}

void smallestNode(node *root, node **aux){
    
    if( (*aux)->left != NULL ){
        smallestNode(root, &(*aux)->left);
        return;
    }

    root->key = (*aux)->key;
    node *aux2 = *aux;
    *aux = (*aux)->right;
    free(aux2);

}

void removeNode(node **root, int key){
    if( *root == NULL ){
        printf("Chave não encontrada\n");
        return;
    }

    if( key < (*root)->key ){ // busca binaria
        removeNode(&(*root)->left, key); 
        return;
    } else if( key > (*root)->key ){
        removeNode(&(*root)->right, key);
        return;
    } // sai se encontrar
    
    
    if( (*root)->left == NULL && (*root)->right == NULL ){ // se não tem filhos
        node *aux = *root;
        free(aux);
        *root = NULL;
    } else if( (*root)->left == NULL ){ // se tem só na direita
        node *aux = *root;
        *root = (*root)->right;
        free(aux);
    } else if ( (*root)->right == NULL ){ // se tem só na esquerda
        node *aux = *root;
        *root = (*root)->left;
        free(aux);
    } else{ // tem 2 filhos
        smallestNode(*root, &(*root)->right);
    }

}