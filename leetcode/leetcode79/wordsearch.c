#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool exist( char** board, int boardSize, int* boardColSize, char* word );
bool findWord( char** board, int boardSize, int* boardColSize, char* word, int i, int j, int k);

int main(){
    char row1[] = {'A', 'B', 'C', 'E'};
    char row2[] = {'S', 'F', 'C', 'S'};
    char row3[] = {'A', 'D', 'E', 'E'};
    char* board[] = {row1, row2, row3};
    int boardSize = 3;
    int boardColSize[] = {4, 4, 4};
    char* word = "ABCE";

    if( exist( board, boardSize, boardColSize, word ) ){
        printf( "\nsim" );
    } else  {
        printf( "\nnão" );
    }

    return 0;
}

bool findWord( char** board, int boardSize, int* boardColSize, char* word, int i, int j, int k ){
    if( strlen( word ) == k ){
        return true;
    }

    if( i < 0 || j < 0 || i >= boardSize || j >= *boardColSize || board[i][j] != word[k] ){
        return false;
    }

    board[i][j] = '0';

    if( findWord( board, boardSize, boardColSize, word, i - 1, j, k + 1 ) || // baixo
        findWord( board, boardSize, boardColSize, word, i, j - 1, k + 1 ) || // esquerda
        findWord( board, boardSize, boardColSize, word, i + 1, j, k + 1 ) || // cima
        findWord( board, boardSize, boardColSize, word, i, j + 1, k + 1 ) )  // direita
    {
        return true;
    }

    board[i][j] = word[k];
    return false;
}

bool exist( char** board, int boardSize, int* boardColSize, char* word ){
    for( int i = 0; i < boardSize; i++ ){
        for( int j = 0; j < *boardColSize; j++ ){
            if( board[i][j] == word[0] && findWord( board, boardSize, boardColSize, word, i, j, 0 ) ){
                return true;
            }
        }
    }
    return false;
}
