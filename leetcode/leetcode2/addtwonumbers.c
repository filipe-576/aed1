#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int prev = 0, sum;
    struct ListNode* l3 = ( struct ListNode * ) malloc( sizeof(struct ListNode) );
    struct ListNode* head = l3;
    head->next = NULL;

    while( l1 || l2 ){

        sum = prev;
        if( l1 ){
            sum += l1->val;
            l1 = l1->next;
        }
        if( l2 ){
            sum += l2->val;
            l2 = l2->next;
        }

        prev = sum / 10;
        sum %= 10;

        l3->next = ( struct ListNode * ) malloc( sizeof(struct ListNode) );
        l3->next->val = sum;
        l3->next->next = NULL;
        l3 = l3->next;
        
        // printf( "%d: %d\n", sum, prev );
    }

    if( prev ){
        l3->next = ( struct ListNode * ) malloc( sizeof(struct ListNode) );
        l3->next->val = prev;
        l3->next->next = NULL;
    }



    return head->next;
}