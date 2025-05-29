#include <stdio.h>
#define SIZE 10

int threeConsecutiveOdds(int* arr, int arrSize);

int main(){
    int arr[SIZE] = {2, 3, 1, 1, 6, 10, 12, 13, 13, 15};

    printf("%d", threeConsecutiveOdds(arr, SIZE));

    return 0;
}

int threeConsecutiveOdds(int* arr, int arrSize) {
    int consec_odds = 0;

    for(int i = 0; i < arrSize; i++){
        
        if(arr[i] % 2 == 0){
            consec_odds = 0;
            continue;
        }

        consec_odds++;

        if(consec_odds == 3)
            return 1;
    }
    return 0;

    
}