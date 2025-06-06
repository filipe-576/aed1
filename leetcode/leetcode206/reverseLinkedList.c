#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    typedef struct ListNode node;

    if( head == NULL ){
        return NULL;
    }

    node* answer = NULL;
    node* nextNode;
    node* current = head;

    while( current != NULL ){
        nextNode = current->next;

        current->next = answer;
        answer = current;

        current = nextNode;

    }

    return answer;

}