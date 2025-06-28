#include <stdlib.h>
#include <string.h>

int maximumGain(char* s, int x, int y) {
    
    if(s[1] == '\0') return 0;

    char* stack = (char *) malloc(strlen(s));
    int top = -1;

    int hs, ls, total = 0;
    char hp, lp;
    if ( x > y ){
        hs = x;
        ls = y;
        hp = 'a';
        lp = 'b';
    }
    else {
        hs = y;
        ls = x;
        hp = 'b';
        lp = 'a';
    }

    for( int i = 0; s[i] != '\0'; i++ ){

        if( top >= 0 && s[i] == lp && stack[top] == hp ){
            total += hs;
            top--;
        } else {
            stack[++top] = s[i];
        }
    }
    if( top == -1 ) return total;

    char* stack2 = (char *) malloc(top+1);
    int top2 = -1;

    while( top >= 0 ){
        if( top2 >= 0 && stack[top] == lp && stack2[top2] == hp ){
            total += ls;
            top2--;
            top--;
        } else {
            stack2[++top2] = stack[top--];
        }
    }

    free(stack);
    free(stack2);
    return total;
}

int main(){
    char s[12] = "cdbcbbaaabab";
    maximumGain(s, 4, 5);

    return 0;
}