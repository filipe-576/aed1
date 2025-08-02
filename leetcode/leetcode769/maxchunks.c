int maxChunksToSorted(int* arr, int arrSize) {
    int prefixSum = 0;
    int sortedSum = 0;
    int chunks = 0;
    
    for( int i = 0; i < arrSize; i++ ){
        prefixSum += arr[i];
        sortedSum += i;

        if( prefixSum == sortedSum ){
            chunks++;
        }
        
    }

    return chunks;
}