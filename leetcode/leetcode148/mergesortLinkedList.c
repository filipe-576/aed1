#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode Node;

Node* merge(Node* left, Node* right){
    Node head;
    Node *curr = &head;

    while( left != NULL && right != NULL ){
        if( left->val <= right->val ){
            curr->next = left;
            left = left->next;
        } else{
            curr->next = right;
            right = right->next;
        }

        curr = curr->next;
    }

    if( left != NULL ){
        curr->next = left;
    }

    if( right != NULL ){
        curr->next = right;
    }

    return head.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if( head == NULL || head->next == NULL ) return head;
    
    Node* slow = head;
    Node* fast = head->next;

    while( fast != NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = NULL;

    Node* left = sortList(head);
    Node* right = sortList(mid);

    return merge(left, right);

}