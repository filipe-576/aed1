#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};



bool search(struct ListNode **stack, int top, struct ListNode *node){
    for( int i = 0; i <= top; i++ ){
        if( node == stack[i] ){
            return true;
        }
    }
    return false;
}
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode **stack = (struct ListNode **) malloc(sizeof(struct ListNode*) * 10000);
    int top = -1;
    struct ListNode *curr;
    for( curr = head; curr != NULL; curr = curr->next ){
        if( search(stack, top, curr) ) return curr;

        stack[++top] = curr;
        
    }
    return NULL;
}