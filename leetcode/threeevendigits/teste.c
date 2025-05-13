#include <stdio.h>
#include <stdlib.h>

int main(){
    int *returnDigits = NULL;

    returnDigits = (int *) realloc(returnDigits, sizeof(int) * 2);
    returnDigits[0] = 1;
    returnDigits[1] = 2;

    printf("%d %d", returnDigits[0], returnDigits[1]);


    return 0;
}
