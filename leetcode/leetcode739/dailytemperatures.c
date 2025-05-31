
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* stack = ( int* ) malloc( sizeof(int) * temperaturesSize );
    int* answer = ( int* ) calloc(temperaturesSize, sizeof(int) );
    int top = -1;

    for( int i = 0; i < temperaturesSize; i++ ){

        while( top != -1 && temperatures[i] > temperatures[stack[top]] ){
            int prevIndex = stack[top--];
            answer[prevIndex] = i - prevIndex;
        }

        stack[++top] = i;
    }

    free(stack);
    *returnSize = temperaturesSize;
    return answer;
}