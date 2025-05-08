#include <stdio.h>

int isPalindrome(int x);


int main(){
    int res = isPalindrome(1005001);

    printf("\nres:%d", res);
    
    return 0;
}

int isPalindrome(int x){
    if (x < 0)
        return 0;
    if(x < 10)
        return 1;
    char digits[11];
    int left = 0, right, half;

    snprintf(digits, 11, "%d", x);

    
    for(right = 0; digits[right+1] != '\0'; right++)
    
    half = (right / 2);

    for(; left <= half; left++, right--)
        if(digits[left] != digits[right])
            return 0;
    
    return 1;


}