/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// void printl(struct ListNode* head){
//     if( head == NULL){
//         printf("NULL\n");
//         return;
//     }
//     for( struct ListNode* current = head; current != NULL; current = current->next ){
//         printf("%d -> ", current->val);
//     }
//     printf("NULL\n");
// }

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    typedef struct ListNode node;
    if ( left == right ){
        return head;
    }

    node *preLeft = head;
    node *firstReversed;

    if( left == 1 ){
        preLeft = NULL; 
        firstReversed = head;
    }
    else{
        for( int i = left - 2; i > 0; preLeft = preLeft->next, i-- );
        firstReversed = preLeft->next;
    }
    
    node *current = firstReversed;
    node *nextNode = current;
    node *reversed = NULL;

    for( int i = right - left; i >= 0; i-- ){
        current = nextNode;
        nextNode = nextNode->next;
        current->next = reversed;
        reversed = current;
    }

    firstReversed->next = nextNode;

    if( preLeft == NULL ){
        return reversed;
    }

    preLeft->next = reversed;
    return head;
}