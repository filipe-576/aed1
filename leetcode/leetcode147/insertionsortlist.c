#include <stdio.h>
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
typedef struct ListNode Node;

void insertSort( Node *head, int val ){
    Node *new = (Node*) malloc(sizeof(Node));

    Node *curr;
    for( curr = head; curr->next != NULL && curr->next->val < val; curr = curr->next );
    new->val = val;
    new->next = curr->next;
    curr->next = new;

}
struct ListNode* insertionSortList(struct ListNode* head) {

    Node *curr;
    Node dummy;
    dummy.next = NULL;

    for( curr = head; curr != NULL; curr = curr->next ){
        insertSort( &dummy, curr->val );
    }

    return dummy.next;
}