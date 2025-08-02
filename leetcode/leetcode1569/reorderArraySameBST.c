#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
long long table[1000][1000];

void createTable(int rows) {
    for( int i = 0; i < rows; i++ ){
        // printf("\n1 ");
        table[i][0] = 1;
        for( int j = 1; j <= i; j++ ){
            table[i][j] = (table[i-1][j-1] + table[i-1][j]) % MOD;
            // printf("%d ", table[i][j]);
        }
    }
    
}

long long dfs(int* nums, int numsSize){
    if( numsSize < 3 ) return 1;

    int* leftNodes = (int*) malloc(sizeof(int) * numsSize);
    int* rightNodes = (int*) malloc(sizeof(int) * numsSize);

    int j = 0, k = 0;
    for( int i = 1; i < numsSize; i++ ){
        if( nums[i] < nums[0] ){
            leftNodes[j++] = nums[i];
        } else{
            rightNodes[k++] = nums[i];
        }
    }

    long long combinations = table[numsSize-1][j] % MOD;
    long long combLR = dfs(leftNodes, j) * dfs(rightNodes, k) % MOD;
    free(leftNodes);
    free(rightNodes);

    return (combinations * combLR) % MOD;
}

int numOfWays(int* nums, int numsSize) {
    
    createTable(numsSize);
    
    return (dfs(nums, numsSize) - 1) % MOD;
}

int main(){
    int nums[5] = {3, 4, 5, 1, 2};
    printf("%d", numOfWays(nums, 5));
}