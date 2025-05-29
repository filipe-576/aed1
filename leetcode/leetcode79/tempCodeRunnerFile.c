 findWord(board, boardSize, boardColSize, word, i+1, j, k+1) || findWord(board, boardSize, boardColSize, word, i, j+1, k+1)){
        return true;
    }

    board[i][j] = aux;
    return true;
}
