#include <stdbool.h>

bool isValidSerialization(char* preorder) {
    int counter = 0;

    for( int i = 0; preorder[i] != '\0'; i++ ){
        if ( preorder[i+1] != ',' && preorder[i+1] != '\0') continue;

        if ( counter < 0 ) return false;

        if ( preorder[i] != '#' ){
            counter++;
        } else{
            counter--;
        }
        
        // printf("%d ", counter);

    }
   
    return counter == -1;
}