/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

void reorderList(Node *head) {
    if(!head || !head->next || !head->next->next) return;

    Node *slow = head, *fast = head;

    while( fast->next && fast->next->next ){ // slow = metade da lista
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *curr = slow->next, *next, *reversed = NULL;
    while( curr ){ // reverto metade da lista
        next = curr->next;
        curr->next = reversed;
        reversed = curr;
        curr = next;
    }
    slow->next = NULL;

    Node *nextA = head, *nextB = reversed;
    while( reversed ){ // insiro os nodos da lista revertida a direita de cada nodo da primeira metade
        nextA = nextA->next;
        nextB = nextB->next;

        head->next = reversed;
        reversed->next = nextA;
        
        head = nextA;
        reversed = nextB;
    }
    

}
