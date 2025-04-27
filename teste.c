#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 300

void add_name(char *namesList);
void remove_name(char *namesList);
void list_names(char *namesList);
void read_string(char* string);
int menu();

int main(){
    int option;
    char namesList[TAM];
    namesList[0] = '\0';
    
    for(;;){
        option = menu();
        system("cls");
        
        switch(option){
            case 1:
                add_name(namesList);
                break;

            case 2:
                remove_name(namesList);
                break;
            
            case 3:
                list_names(namesList);
                break;

            case 4:
                exit(1);
                break;

        }
    }
    return 0;
}

int menu(){
    int choice = 0;

    do{
        printf("\n=======================\n");
        printf("Escolha uma opção:\n");
        printf("1 | Adicionar nome\n");
        printf("2 | Remover nome\n");
        printf("3 | Listar nomes\n");
        printf("4 | Sair\n");
        printf("=======================\n");
        scanf("%d", &choice);
    }while(choice < 1 || choice > 4);
    
    return choice;
}

void add_name(char *namesList){
    char name[50];
    int i, j;

    printf("Digite o nome a ser adicionado:\n");
    getchar();
    read_string(name);

    // printf("\nname: %s", name);

    for(i = 0; namesList[i] != '\0'; i++);
    
    for(j = 0; name[j] != '\0' && i < TAM; j++, i++){
        namesList[i] = name[j];
    }
    namesList[i] = '\0';

    // printf("\nnamesList: %s\n", namesList);

}

void list_names(char *namesList){
    int i;
    printf("=======================");
    printf("\nNomes:\n");
    for(i = 0; namesList[i] != '\0'; i++){
        if(namesList[i] == ','){
            printf("\n");
            continue;
        }
        printf("%c", namesList[i]);
    }
}

void remove_name(char *namesList){
    char name[50];
    int i, j, firstLetter;
    printf("Digite o nome a ser removido:\n");
    getchar();
    read_string(name);

    for(i = 0, firstLetter = 0; namesList[i] != '\0'; i++){
        if(namesList[i] == ','){
            firstLetter = ++i;
            continue;
        }
        if(namesList[i] == name[j]){
            j++;
        }
    }
}

void read_string(char* string){
    char c;
    int i = 0;

    scanf("%c", &c);

    while(c != '\n'){
        string[i++] = c;
        scanf("%c", &c);
    }
    string[i++] = ',';
    string[i] = '\0';
    

}