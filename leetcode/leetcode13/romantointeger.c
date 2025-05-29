#include <stdio.h>

int romanToInt( char* s );
int value( char c );

int main(){

    int res = romanToInt( "VI" );
    printf( "%d", res );

    return 0;
}

int value( char c ){
    int ret;
    switch( c ){
        case 'I':
            ret = 1;
            break;
        case 'V':
            ret = 5;
            break;
        case 'X':
            ret = 10;
            break;
        case 'L':
            ret = 50;
            break;
        case 'C':
            ret = 100;
            break;
        case 'D':
            ret = 500;
            break;
        case 'M':
            ret = 1000;
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

int romanToInt( char* s ) {
    int cur, next, res = 0;

    for ( int i = 0; s[i] != '\0'; i++ ){
        cur = value(s[i]);
        next = value(s[i+1]);

        if ( cur >= next ){
            res += cur; 
        } else {
            res -= cur;
        }
    }

    return res;

}

