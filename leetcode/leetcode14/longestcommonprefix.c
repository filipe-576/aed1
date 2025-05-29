#include <stdio.h>
#include <string.h>

char* longestCommonPrefix( char** strs, int strsSize );

int main(){
    char *w1 = "ab";
    char *w2 = "a";
    char *strs[] = {w1, w2};
    
    char *res = longestCommonPrefix(strs, 2);
    printf("%s", res);

}


char* longestCommonPrefix( char** strs, int strsSize ) {
    char *prefix = strs[0];
    int j;

    for ( int i = 1; i < strsSize; i++ ){
        for( j = 0; strs[i][j] != '\0'; j++ ){
            if ( prefix[j] != strs[i][j] ){
                prefix[j] = '\0';
                break;
            }
        }
        prefix[j] = '\0';
        
    }
    return prefix;
}