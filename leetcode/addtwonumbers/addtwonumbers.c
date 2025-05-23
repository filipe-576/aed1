#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(){


    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num = 0, prev = 0, sum;

    for(int i = 1; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next){
        sum = l1->val + l2->val + prev;
        num += (sum % 10) * i;

        prev = sum > 9 ? (sum - sum % 10) / 10 : 0;
        
        printf( "%d: %d: %d\n", num, sum, prev );
    }
    return NULL;
}