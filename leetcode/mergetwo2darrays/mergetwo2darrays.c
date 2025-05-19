#include <stdio.h>

int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, 
    int* nums2ColSize, int* returnSize, int** returnColumnSizes);

int main(){

    return 0;
}

int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, 
int* nums2ColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = nums1Size > nums2Size ? nums1Size : nums2Size;

    }