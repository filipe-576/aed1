// VERSÃO ANTERIOR // AGENDAPBUFFER3 É A FINAL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 10
#define EMAIL_SIZE 20
#define PERSON_SIZE ( sizeof(char) * NAME_SIZE + sizeof(int) + sizeof(char) * EMAIL_SIZE )
#define AGENDA ( sizeof(int) * 3 + sizeof(char) * NAME_SIZE )

void showMenu(int *menu);
void addPerson(void **pBuffer, int **qt, void **agenda);
void listAll(void *pBuffer, int *i, int *qt, void *agenda);
void findPerson(void *pBuffer, int *i, int *qt, char* tempS, void *agenda);
void removePerson(void **pBuffer, int *i, int *qt, char* tempS, void *agenda);

int main(){

    void *pBuffer = calloc(1, sizeof(int) * 3 + sizeof(char) * NAME_SIZE + 1);
    


    while( 1 ){
        int *menu = ( int* ) pBuffer;
        int *qt = ( int* ) pBuffer + 1;
        int *i = ( int* ) pBuffer + 2;
        char *tempS = ( char* ) pBuffer + (sizeof(int) * 3);
        void *agenda = pBuffer + (sizeof(int) * 3) + sizeof(char) * NAME_SIZE;
        
        // printf("buffer:%p\nmenu:%p\nqt:%p\ni:%p\ntempS:%p\nagenda:%p\n", pBuffer, menu, qt, i, tempS, agenda);
        showMenu(menu);
        // system("cls");

        switch( *menu ){
            case 1:
                addPerson(&pBuffer, &qt, &agenda);
                break;
            case 2:
                removePerson(&pBuffer, i, qt, tempS, agenda);
                break;

            case 3:
                findPerson(pBuffer, i, qt, tempS, agenda);
                break;
                
            case 4:
                listAll(pBuffer, i, qt, agenda);
                break;
            case 5:
                free(pBuffer);
                exit(0);
        }

    }

    return 0;
}

void showMenu(int *menu){
    
    do{
        printf("\n==========MENU==========\n");
        printf("1 - Adicionar Pessoa\n");
        printf("2 - Remover Pessoa\n");
        printf("3 - Buscar Pessoa\n");
        printf("4 - Listar Todos\n");
        printf("5 - Sair\n");
        printf("========================\n");
        scanf("%d", menu);
    } while( *menu < 1 || *menu > 5 );
}

void addPerson(void **pBuffer, int **qt, void **agenda){
    **qt += 1;

    void *tempBuffer = realloc(*pBuffer, AGENDA + (**qt * PERSON_SIZE));
    *pBuffer = tempBuffer;
    *qt = (int*)(tempBuffer) + 1;
    *agenda = tempBuffer + (sizeof(int) * 3) + NAME_SIZE;
    // printf("buffer depois: %p\n", *pBuffer);
    // printf("\nqt:%d\n", **qt);
    void *newPerson = *agenda + ( ( **qt - 1 ) * (PERSON_SIZE));
    char *name = ( char* ) newPerson;
    int *age = ( int* ) ( newPerson + NAME_SIZE );
    char *email = ( char* ) ( newPerson + NAME_SIZE + sizeof(int) );

    // printf("%p\n%p\n%p\n%p", newPerson, name, age, email);
    printf("Nome: ");
    getchar();
    fgets(name, NAME_SIZE-1, stdin);
    printf("\nIdade: ");
    scanf("%d", age);
    printf("\nEmail: ");
    getchar();
    fgets(email, EMAIL_SIZE-1, stdin);  
    

    name[strlen(name) - 1] = '\0'; 
    email[strlen(email) - 1] = '\0';


}

void listAll(void *pBuffer, int *i, int *qt, void *agenda){
    if( !*qt ){
        printf("LISTA VAZIA\n");
        return;
    }

    printf("========CONTATOS========\n");
    for( *i = 0; *i < *qt; *i += 1 ){
        printf("Nome: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) ) );
        printf("Idade: %d\n", *( int* ) ( agenda + ( *i * (PERSON_SIZE) ) + NAME_SIZE ) );
        printf("Email: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) + NAME_SIZE + sizeof(int) ) );
        printf("========================\n");
    }
}

void findPerson(void *pBuffer, int *i, int *qt, char *tempS, void *agenda){
    if( !*qt ){
        printf("========================\n");
        printf("LISTA VAZIA\n");
        printf("========================\n");
        return;
    }

    getchar();
    fgets(tempS, NAME_SIZE, stdin);
    tempS[strlen(tempS)-1] = '\0';

    printf("========================\n");
    for( *i = 0; *i < *qt; *i += 1 ){
        if(strcmp(agenda + ( *i * (PERSON_SIZE)), tempS) == 0){
            printf("Nome: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) ) );
            printf("Idade: %d\n", *( int* ) ( agenda + ( *i * (PERSON_SIZE) ) + NAME_SIZE ) );
            printf("Email: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) + NAME_SIZE + sizeof(int) ) );
            printf("========================\n");
            return;
        }
    }
    
    printf("Contato não encontrado\n");
    printf("========================\n");
}

void removePerson(void **pBuffer, int *i, int *qt, char *tempS, void *agenda){
    if( !*qt ){
        printf("========================\n");
        printf("LISTA VAZIA\n");
        printf("========================\n");
        return;
    }
    printf("Nome: ");
    getchar();
    fgets(tempS, NAME_SIZE, stdin);
    tempS[strlen(tempS)-1] = '\0';

    printf("========================\n");
    for( *i = 0; *i < *qt; *i += 1 ){
        if(strcmp(agenda + ( *i * (PERSON_SIZE)), tempS) == 0){
            
            memcpy(agenda + ( *i * (PERSON_SIZE)), agenda + ( (*i + 1) * (PERSON_SIZE)), ( *qt - *i - 1 ) * PERSON_SIZE);
            
            *qt -= 1;
            *pBuffer = realloc( *pBuffer, AGENDA + ( *qt * (PERSON_SIZE) ) );
            printf("Contato removido\n");
            printf("========================\n");

            return;
        }
    }

    printf("Contato não encontrado\n");
    printf("========================\n");
}