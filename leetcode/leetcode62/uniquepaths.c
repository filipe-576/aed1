#include <stdio.h>

int search(int x, int y, int m, int n){
    if( (x + 1 >= n) || (y + 1 >= m) ){
        return 1;
    }
    return search(x + 1, y, m , n) + search(x, y + 1, m, n);
}

int uniquePaths(int m, int n) {
    return search(0, 0, m, n);
}

int main(){
    printf("%d", uniquePaths(3, 7));
}