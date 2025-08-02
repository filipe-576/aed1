#include <stdio.h>

int solution(int settings[3], int *bags){
    int bagsSize = settings[0];
    int competitors = settings[1];
    int popPerS = settings[2];

    int totalPop = 0;

    for(int i = 0; i < bagsSize; i++ ){
        totalPop += bags[i];
    }

    // printf("%d", maxPop);
    
    int maxPop;
    do{
        maxPop = totalPop / competitors;
        competitors = settings[1];


        int currentTotal = 0;
        for( int i = 0; i < bagsSize; i++ ){
            if( currentTotal + bags[i] < maxPop ){
                currentTotal += bags[i];

            } else{ // currentTotal + bags[i] >= maxPop
                competitors -= 1;
                currentTotal = 0;
            }
        }

    } while( competitors < 0 );

    return maxPop / popPerS + 1;

}

int main(){
    int settings[3] = {5, 3, 4};
    int bags[5] = {5, 8, 3, 10, 7};

    printf("\n=%d=", solution(settings, bags));
}