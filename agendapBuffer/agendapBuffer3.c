#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 20
#define NAME sizeof(int) * 4
#define EMAIL sizeof(int) * 4 + STRING_SIZE
#define HEADER ( EMAIL + STRING_SIZE )


void addPerson(void **pBuffer);
void listAll(void **pBuffer);
void findPerson(void **pBuffer);
void removePerson(void **pBuffer);

int main(){
    // |menu|size|navigator|tempAge|tempName|tempEmail| |name|email|age|
    void *pBuffer = malloc(HEADER);
    int *menu = ( int* ) pBuffer;
    int *size = menu + 1;
    *size = HEADER;

    while( 1 ){

        do{
            printf("\n===========MENU===========\n");
            printf("1 - Adicionar Pessoa\n");
            printf("2 - Remover Pessoa\n");
            printf("3 - Buscar Pessoa\n");
            printf("4 - Listar Todos\n");
            printf("5 - Sair\n");
            printf("==========================\n");
            scanf("%d", menu);
        } while( *menu < 1 || *menu > 5 );

        system("clear");

        switch( *menu ){
            case 1:
                addPerson(&pBuffer);
                break;

            case 2:
                removePerson(&pBuffer);
                break;

            case 3:
                findPerson(&pBuffer);
                break;
                
            case 4:
                listAll(&pBuffer);
                break;

            case 5:
                free(pBuffer);
                exit(0);
        }

        menu = ( int* ) pBuffer;
        size = menu + 1;
    }

}

void addPerson(void **pBuffer){
    char *tempName = ( char* ) *pBuffer + NAME;
    char *tempEmail = ( char* ) *pBuffer + EMAIL;
    int *tempAge = ( int* ) *pBuffer + 2;
    int *size = ( int* ) *pBuffer + 1;

    printf("\nNome: ");
    getchar();
    fgets(tempName, STRING_SIZE, stdin);

    printf("\bEmail: ");
    fgets(tempEmail, STRING_SIZE, stdin);

    printf("\bIdade: ");
    scanf("%d", tempAge);

    tempName[strcspn(tempName, "\n")] = '\0';
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    void *tempBuffer = realloc(*pBuffer, *size + strlen(tempName) + strlen(tempEmail) + sizeof(int) + 2);
    if ( !tempBuffer ){
        return;
    }
    *pBuffer = tempBuffer;

    tempName = ( char* ) *pBuffer + NAME;
    tempEmail = ( char* ) *pBuffer + EMAIL;
    tempAge = ( int* ) *pBuffer + 2;
    size = ( int* ) *pBuffer + 1;
    
    char *name = ( char* ) *pBuffer + *size;
    char *email = ( char* ) name + strlen(tempName) + 1;
    int *age = ( int* ) ( email + strlen(tempEmail) + 1 );

    strcpy(name, tempName);
    strcpy(email, tempEmail);
    *age = *tempAge;
    
    *size += strlen(name) + strlen(email) + sizeof(int) + 2;

}

void listAll(void **pBuffer){
    int *size = ( int* ) ( *pBuffer + sizeof(int) ); 
    int *navigator = size + 1;
    *navigator = HEADER;

    if( *size == HEADER ){
        printf("==========================\n");
        printf("LISTA VAZIA\n");
        printf("==========================\n");
        return;
    }
    
    char *name, *email;
    int *age;
    
    printf("=========CONTATOS=========\n");

    while( *navigator < *size ){
        name = ( char* ) *pBuffer + *navigator;
        email = name + strlen(name) + 1;
        age = ( int* ) ( email + strlen(email) + 1 );

        printf("==========================\n");
        printf("Nome: %s\n", name);
        printf("Email: %s\n", email);
        printf("Idade: %d\n", *age);
        
        *navigator += strlen(name) + strlen(email) + 2 + sizeof(int);
    }
    printf("==========================\n");
}

void findPerson(void **pBuffer){
    int *size = ( int* ) ( *pBuffer + sizeof(int) ); 
    int *navigator = size + 1;
    *navigator = HEADER;
    
    char *tempName = ( char* ) *pBuffer + NAME;
    char *name, *email;
    int *age;

    printf("\nNome: ");
    getchar();
    fgets(tempName, STRING_SIZE, stdin);
    tempName[strcspn(tempName, "\n")] = '\0';

    while( *navigator < *size ){
        name = ( char* ) *pBuffer + *navigator;
        email = name + strlen(name) + 1;
        age = ( int* ) ( email + strlen(email) + 1 );

        if( strcmp(name, tempName) == 0 ){
            printf("==========================\n");
            printf("Nome: %s\n", name);
            printf("Email: %s\n", email);
            printf("Idade: %d\n", *age);
            printf("==========================\n");
            return;
        }
        
        *navigator += strlen(name) + strlen(email) + 2 + sizeof(int);
        
    }
    
    printf("==========================\n");
    printf("Contato não encontrado\n");
    printf("==========================\n");

}

void removePerson(void **pBuffer){
    int *size = ( int* ) ( *pBuffer + sizeof(int) ); 
    int *navigator = size + 1;
    *navigator = HEADER;
    
    char *tempName = ( char* ) *pBuffer + NAME;
    char *name;

    printf("\nNome: ");
    getchar();
    fgets(tempName, STRING_SIZE, stdin);
    tempName[strcspn(tempName, "\n")] = '\0';

    while( *navigator < *size ){
        name = ( char* ) *pBuffer + *navigator;
        if( strcmp(name, tempName) == 0 ){
            break;
        }

        *navigator += strlen(name) + strlen(name + strlen(name) + 1) + 2 + sizeof(int);
        
    }
    if( *navigator >= *size){
        printf("==========================\n"); 
        printf("Contato não encontrado\n");
        printf("==========================\n");
        return;
    }
    
    *size -= strlen(name) + strlen(name + strlen(name) + 1) + 2 + sizeof(int);
    memcpy(*pBuffer + *navigator,
        *pBuffer + *navigator + strlen(name) + strlen(name+strlen(name) + 1 ) + 2 + sizeof(int),
        *size - *navigator);

    *pBuffer = realloc(*pBuffer, *size);

}