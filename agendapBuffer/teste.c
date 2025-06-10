#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* pBuffer = NULL;

void addPerson() {
    // Configuração inicial dos ponteiros
    int* count = (int*)pBuffer;
    char* next_pos = (char*)pBuffer + sizeof(int) + (count ? *count * sizeof(void*) : 0);
    
    // Armazenar nome
    printf("Nome: ");
    char* name_ptr = next_pos;
    *name_ptr = getchar();
    while (*name_ptr != '\n') {
        name_ptr++;
        *name_ptr = getchar();
    }
    *name_ptr = '\0';
    
    // Armazenar email
    char* email_ptr = name_ptr + 1;
    printf("Email: ");
    *email_ptr = getchar();
    while (*email_ptr != '\n') {
        email_ptr++;
        *email_ptr = getchar();
    }
    *email_ptr = '\0';
    
    // Armazenar idade
    int* age_ptr = (int*)(email_ptr + 1);
    printf("Idade: ");
    *age_ptr = 0;
    char ch = getchar();
    while (ch != '\n') {
        *age_ptr = *age_ptr * 10 + (ch - '0');
        ch = getchar();
    }
    
    // Atualizar contagem e realocar
    int new_size = (char*)(age_ptr + 1) - (char*)pBuffer;
    if (!count) {
        pBuffer = realloc(pBuffer, new_size);
        *(int*)pBuffer = 1;
    } else {
        (*count)++;
        pBuffer = realloc(pBuffer, new_size);
    }
}

void removePerson() {
    if (!pBuffer || *(int*)pBuffer == 0) {
        printf("Agenda vazia!\n");
        return;
    }
    
    printf("Nome para remover: ");
    char input[100]; // Buffer temporário apenas para entrada
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';
    
    char* current = (char*)pBuffer + sizeof(int);
    char* found = NULL;
    int* count = (int*)pBuffer;
    
    while (current < (char*)pBuffer + *(int*)pBuffer * sizeof(void*)) {
        if (strcmp(current, input) == 0) {
            found = current;
            break;
        }
        current += strlen(current) + 1 + strlen(current + strlen(current) + 1) + 1 + sizeof(int);
    }
    
    if (found) {
        char* next = found + strlen(found) + 1 + strlen(found + strlen(found) + 1) + 1 + sizeof(int);
        memmove(found, next, (char*)pBuffer + *(int*)pBuffer * sizeof(void*) - next);
        (*count)--;
        pBuffer = realloc(pBuffer, (char*)pBuffer + sizeof(int) + *count * sizeof(void*) - (char*)pBuffer);
        printf("Removido!\n");
    } else {
        printf("Não encontrado!\n");
    }
}

void listAll() {
    if (!pBuffer || *(int*)pBuffer == 0) {
        printf("Agenda vazia!\n");
        return;
    }
    
    char* current = (char*)pBuffer + sizeof(int);
    int* count = (int*)pBuffer;
    int i = 0;
    
    while (i < *count) {
        printf("Pessoa %d:\n", i+1);
        printf(" Nome: %s\n", current);
        printf(" Email: %s\n", current + strlen(current) + 1);
        printf(" Idade: %d\n\n", *(int*)(current + strlen(current) + 1 + strlen(current + strlen(current) + 1) + 1));
        
        current += strlen(current) + 1 + strlen(current + strlen(current) + 1) + 1 + sizeof(int);
        i++;
    }
}

void showMenu() {
    printf("\nMenu:\n1. Adicionar\n2. Remover\n3. Listar\n4. Sair\nOpção: ");
}

int main() {
    pBuffer = malloc(sizeof(int));
    *(int*)pBuffer = 0;
    
    while (1) {
        showMenu();
        
        char op[2];
        fgets(op, 2, stdin);
        while (getchar() != '\n');
        
        if (op[0] == '1') addPerson();
        else if (op[0] == '2') removePerson();
        else if (op[0] == '3') listAll();
        else if (op[0] == '4') break;
        else printf("Inválido!\n");
    }
    
    free(pBuffer);
    return 0;
}