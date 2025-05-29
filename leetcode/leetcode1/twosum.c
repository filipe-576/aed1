/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum( int* nums, int numsSize, int target, int* returnSize );

int main(){
    
    int a[10] = {3,2,4}, target = 6;
    int *ans, *returnSize;

    returnSize = ( int * ) malloc( sizeof(int) );

    ans = twoSum(a, 10, target, returnSize);

    printf("%d %d", ans[0], ans[1]);


    return 0;
}

int* twoSum( int* nums, int numsSize, int target, int* returnSize ){
    *returnSize = 2;
    int *result = ( int * ) malloc( sizeof( int ) * *returnSize );

    for(int i = 0; i < numsSize; i++)
        for(int j = i + 1; j < numsSize; i++){
            if( (nums[i] + nums[j]) == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
        return result;
}