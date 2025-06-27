#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int val;
    struct N *next;
}Node;

typedef struct H{
    Node *first;
    Node *last;
}Heap;

void push(Heap *hp, int val){
    Node *new = (Node *) malloc(sizeof(Node));
    new->val = val;

    if( !hp->first ){
        hp->first = new;
        hp->last = new;
        new->next = NULL;
        return;
    }

    Node *curr = hp->first, *next = curr->next;
    while( next && val > next->val ){
        curr = next;
        next = next->next;
    }

    curr->next = new;
    new->next = next;

}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {

    Heap *hp = (Heap *) malloc( sizeof(Heap) );
    hp->first = NULL;
    hp->last = NULL;

    for( int i = 0; i < matrixSize; i++ ){
        for( int j = 0; j < matrixColSize[i]; j++ ){
            push(hp, matrix[i][j]);
            }
        }


    return hp->first->val;
}

int main() {
    // Exemplo: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
    int n = 3;
    
    // Aloca a matriz dinamicamente
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Aloca e preenche o array de tamanhos das colunas
    int *matrixColSize = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        matrixColSize[i] = n;
    }

    // Preenche a matriz com os valores do exemplo
    matrix[0][0] = 1;  matrix[0][1] = 5;  matrix[0][2] = 9;
    matrix[1][0] = 10; matrix[1][1] = 11; matrix[1][2] = 13;
    matrix[2][0] = 12; matrix[2][1] = 13; matrix[2][2] = 15;
    
    int k = 8;
    
    // Chama a sua função e imprime o resultado
    int result = kthSmallest(matrix, n, matrixColSize, k);
    printf("O %d-esimo menor elemento e: %d\n", k, result); // O resultado esperado é 13

    // Libera a memória da matriz
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}