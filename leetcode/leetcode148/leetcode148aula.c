#include <stdlib.h>
#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct Tree {
    int val;
    struct Tree *left;
    struct Tree *right;
};


void insertTree(struct Tree *root, int val){
    
    if( val < root->val ){
        if(root->left != NULL){
            insertTree(root->left, val);
        } else{
            struct Tree *new = malloc(sizeof(struct Tree));
            new->val = val;
            root->left = new;
            return;
        }

    } else{ // val > root->val
        if(root->right != NULL){
            insertTree(root->right, val);
        } else{
            struct Tree *new = malloc(sizeof(struct Tree));
            new->val = val;
            root->right = new;
        }
    }

}

void inFixTraversal(struct Tree *root, struct ListNode* node){
    
    
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL) return NULL;
    
    struct Tree *root;
    root->val = head->val;
    root->left = NULL;
    root->right = NULL;
    
    struct ListNode *curr;

    for(curr = head->next; curr != NULL; curr = curr->next){
        insertTree(root, curr->val);
    }

    

    return NULL;
}