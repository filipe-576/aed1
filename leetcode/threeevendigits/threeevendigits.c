/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize);

int main(){
    int digits[5] = {2, 1, 3, 4};
    int *returnedDigits;
    int *returnSize = (int *) malloc(sizeof(int));
    returnedDigits = findEvenNumbers(digits, 4, returnSize);

    for(int i = 0; i < *returnSize; i++){
        printf("%d\n", returnedDigits[i]);
    }

    return 0;
}

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int returnSizetemp = 0, temp;
    int *returnDigits = malloc(sizeof(int));

    for(int i = 0; i < digitsSize; i++)
        for(int j = 0; j < digitsSize; j++){
            for(int k = 0; k < digitsSize; k++){
                if(i == j || i == k || j == k)
                    continue;
                if(digits[k] % 2 != 0 || digits[i] == 0)
                    continue;
                // printf("%d %d %d\n", digits[i], digits[j], digits[k]);
                
                returnDigits = (int *) realloc(returnDigits, sizeof(int) * ++returnSizetemp);
                returnDigits[returnSizetemp - 1] = digits[i]*100 + digits[j]*10 + digits[k];
                // printf("%d\n", returnDigits[returnSizetemp - 1]);

            }
        }
    
    // printf("%d", returnSizetemp);

    for (int i = 0, k = 0; i < (returnSizetemp - 1); ++i){
    for (int j = 0; j < returnSizetemp - 1 - i; ++j ){
        if (returnDigits[j] > returnDigits[j+1])
        {
            temp = returnDigits[j+1];
            returnDigits[j+1] = returnDigits[j];
            returnDigits[j] = temp;
        }
    }
        if (digits[i] != digits[k])
            digits[++k] = digits[i];    

    }

    
    *returnSize = returnSizetemp;
    return returnDigits;
}
