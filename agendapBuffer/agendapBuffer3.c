#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_SIZE 20
#define PERSON_SIZE ( sizeof(char) * STRING_SIZE + sizeof(int) + sizeof(char) * STRING_SIZE )
#define INFO ( sizeof(int) * 4 + STRING_SIZE * 2 )

void showMenu(int *menu);
void addPerson(void **pBuffer, int **qt, int **tempAge, char **tempS, void **agenda);
// void listAll(void *pBuffer, int *i, int *qt, void *agenda);
// void findPerson(void *pBuffer, int *i, int *qt, char* tempS, void *agenda);
// void removePerson(void **pBuffer, int *i, int *qt, char* tempS, void *agenda);

int main(){

    void *pBuffer = calloc(1, INFO);
    int *menu = ( int* ) pBuffer;
    int *qt = ( int* ) pBuffer + 1;
    int *i = ( int* ) pBuffer + 2;
    int *tempAge = ( int* ) pBuffer + 3;
    char *tempS = ( char* ) pBuffer + (sizeof(int) * 4);
    void *agenda = pBuffer + INFO;

    while( 1 ){
        
        printf("buffer:%p\nmenu:%p\nqt:%p\ni:%p\ntempAge:%p\ntempS:%p\nagenda:%p\n", pBuffer, menu, qt, i, tempAge, tempS, agenda);
        printf("%s\n%s\n%d\n", tempS, tempS + STRING_SIZE, *tempAge);
        showMenu(menu);
        // system("cls");

        switch( *menu ){
            case 1:
                addPerson(&pBuffer, &qt, &tempAge, &tempS, &agenda);
                break;
            // case 2:
            //     removePerson(&pBuffer, i, qt, tempS, agenda);
            //     break;

            // case 3:
            //     findPerson(pBuffer, i, qt, tempS, agenda);
            //     break;
                
            // case 4:
            //     listAll(pBuffer, i, qt, agenda);
            //     break;
            case 5:
                free(pBuffer);
                exit(0);
        }

        menu = ( int* ) pBuffer;
        qt = ( int* ) pBuffer + 1;
        i = ( int* ) pBuffer + 2;
        tempAge = ( int* ) pBuffer + 3;
        tempS = ( char* ) pBuffer + (sizeof(int) * 4);
        agenda = pBuffer + INFO;

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

void addPerson(void **pBuffer, int **qt, int **tempAge, char **tempS, void **agenda){
    **qt += 1;

    char *tempName = *tempS;
    char *tempEmail = tempName + STRING_SIZE;


    printf("%p\n%p\n%p\n%p", *tempS, tempName, tempEmail, *tempAge);
    printf("Nome: ");
    getchar();
    fgets(tempName, STRING_SIZE, stdin);
    printf("\nIdade: ");
    scanf("%d", *tempAge);
    printf("\nEmail: ");
    getchar();
    fgets(tempEmail, STRING_SIZE, stdin);  
    
    // printf("%s\n%s\n%d\n", tempName, tempEmail, **tempAge);

    tempName[strcspn(tempName, "\n")] = '\0';
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    


}

// void listAll(void *pBuffer, int *i, int *qt, void *agenda){
//     if( !*qt ){
//         printf("LISTA VAZIA\n");
//         return;
//     }

//     printf("========CONTATOS========\n");
//     for( *i = 0; *i < *qt; *i += 1 ){
//         printf("Nome: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) ) );
//         printf("Idade: %d\n", *( int* ) ( agenda + ( *i * (PERSON_SIZE) ) + STRING_SIZE ) );
//         printf("Email: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) + STRING_SIZE + sizeof(int) ) );
//         printf("========================\n");
//     }
// }

// void findPerson(void *pBuffer, int *i, int *qt, char *tempS, void *agenda){
//     if( !*qt ){
//         printf("========================\n");
//         printf("LISTA VAZIA\n");
//         printf("========================\n");
//         return;
//     }

//     getchar();
//     fgets(tempS, STRING_SIZE, stdin);
//     tempS[strlen(tempS)-1] = '\0';

//     printf("========================\n");
//     for( *i = 0; *i < *qt; *i += 1 ){
//         if(strcmp(agenda + ( *i * (PERSON_SIZE)), tempS) == 0){
//             printf("Nome: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) ) );
//             printf("Idade: %d\n", *( int* ) ( agenda + ( *i * (PERSON_SIZE) ) + STRING_SIZE ) );
//             printf("Email: %s\n", ( char* ) ( agenda + ( *i * (PERSON_SIZE) ) + STRING_SIZE + sizeof(int) ) );
//             printf("========================\n");
//             return;
//         }
//     }
    
//     printf("Contato não encontrado\n");
//     printf("========================\n");
// }

// void removePerson(void **pBuffer, int *i, int *qt, char *tempS, void *agenda){
//     if( !*qt ){
//         printf("========================\n");
//         printf("LISTA VAZIA\n");
//         printf("========================\n");
//         return;
//     }
//     printf("Nome: ");
//     getchar();
//     fgets(tempS, STRING_SIZE, stdin);
//     tempS[strlen(tempS)-1] = '\0';

//     printf("========================\n");
//     for( *i = 0; *i < *qt; *i += 1 ){
//         if(strcmp(agenda + ( *i * (PERSON_SIZE)), tempS) == 0){
            
//             memcpy(agenda + ( *i * (PERSON_SIZE)), agenda + ( (*i + 1) * (PERSON_SIZE)), ( *qt - *i - 1 ) * PERSON_SIZE);
            
//             *qt -= 1;
//             *pBuffer = realloc( *pBuffer, agenda + ( *qt * (PERSON_SIZE) ) );
//             printf("Contato removido\n");
//             printf("========================\n");

//             return;
//         }
//     }

//     printf("Contato não encontrado\n");
//     printf("========================\n");
// }