#include <stdio.h>
#include <string.h>

int exist(char** board, int boardSize, int* boardColSize, char* word);
int visit_cel(char** board, int boardSize, int* boardColSize, char* word, int i, int j, int k);

int main(){
    int boardSize = 3, _ = 4;
    int *boardColSize;
    boardColSize = &_;
    char word[6] = "ABCCED";
    char board[3][4] = {"ABCE","SFCS","ADEE"};
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++){
            printf("%c ", board[i][j]);
        }

    exist(board, boardSize, boardColSize, word);

    return 0;
}

int exist(char** board, int boardSize, int* boardColSize, char* word){
    for(int i = 0; i < boardSize; i++)
        for(int j = 0; j < boardColSize; j++)
            if(visit_cel(board, boardSize, boardColSize, word, i, j, 0))
                return 1;
return 0;
}

int visit_cel(char** board, int boardSize, int* boardColSize, char* word, int i, int j, int k){
    if(k == strlen(word))
        return 1;

    if(
    visit_cel(board, boardSize, boardColSize, word, i+1, j, k) ||
    visit_cel(board, boardSize, boardColSize, word, i-1, j, k) ||
    visit_cel(board, boardSize, boardColSize, word, i, j+1, k) ||
    visit_cel(board, boardSize, boardColSize, word, i, j-1, k)
    )
        return 1;
    
    return 0;
}