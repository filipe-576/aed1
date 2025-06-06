#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int* val;
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = ( MyStack* ) malloc( sizeof(MyStack) );
    stack->val = malloc( sizeof(int) * 100 );
    stack->top = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->val[++obj->top] = x;
}

int myStackPop(MyStack* obj) {
    return obj->val[obj->top--];
}

int myStackTop(MyStack* obj) {
    return obj->val[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->val);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/