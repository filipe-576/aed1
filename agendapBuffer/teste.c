#include <stdio.h>
#include <stdlib.h>

int main(){
    int *x = ( int* ) malloc(sizeof(int) * 4);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    for(int i = 0; i < 4; i++){
        printf("%d ", x[i]);
    }

    free(x);

}