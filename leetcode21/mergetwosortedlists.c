/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    typedef struct ListNode node;
    node dummy;
    dummy.next = NULL;
    node* list3 = &dummy;

    while( list1 && list2 ){

        if ( list1->val < list2->val ){
            list3->next = list1;
            list1 = list1->next;
        } else {
            list3->next = list2;
            list2 = list2->next;
        }
        list3 = list3->next;
    }

    list3->next = list1 ? list1: list2;

    return dummy.next;

}