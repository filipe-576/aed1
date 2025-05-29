#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {

    int stackIndex = -1;
    char stack[strlen(s)];

    
    for( int i = 0; s[i] != '\0'; i++){
        
        if ( s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[++stackIndex] = s[i];
            continue;
        }


        if( stackIndex == -1 ||
        (s[i] == ')' && stack[stackIndex] != '(') ||
        (s[i] == ']' && stack[stackIndex] != '[') ||
        (s[i] == '}' && stack[stackIndex] != '{') ){
            return false;
        }
        
        stackIndex--;
        
        
    }

    return stackIndex == -1;
}