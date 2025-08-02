void printArray(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int dfs(int* nums, int numsSize){
    if( numsSize < 3 ) return 1;

    int* leftNodes = (int*) malloc(sizeof(int) *numsSize);
    int* rightNodes = (int*) malloc(sizeof(int) *numsSize);

    int j = 0;
    int k = 0;
    for( int i = 1; i < numsSize; i++ ){
        if(nums[i] < nums[0]){
            leftNodes[j++] = nums[i];
        } else{
            rightNodes[k++] = nums[i];
        }
    }
    printArray(leftNodes, j);
    printArray(rightNodes, k);

    return dfs(leftNodes, j) * dfs(rightNodes, k);

}

int numOfWays(int* nums, int numsSize) {
    int** table = (int**) malloc(sizeof(int*) * (numsSize + 1));

    for(int i = 0; i < numsSize + 1; i++){
        table[i] = (int*) malloc(sizeof(int) * (numsSize + 1));
        for(int j = 0; j < numsSize + 1; j++){
            table[i][j] = 1;
        }
    }
    
    for(int i = 0; i < numsSize + 1; ++i)    
        for(int j = 1; j < i; ++j){
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }


    for(int i = 0; i < numsSize; i++){
        printArray(table[i], numsSize);
    }

    // dfs(nums, numsSize);

    return 0;
}