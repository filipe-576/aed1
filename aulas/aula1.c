#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000
#define MAX_NAME 50

void addName(char *namesList);
void removeName(char *namesList);
void listNames(char *namesList);
void readString(char* string);
int menu();

int main(){
    int option;
    char namesList[MAX_SIZE];

    namesList[0] = '\0';
    
    for(;;){
        option = menu();
        system("cls");
        
        switch(option){
            case 1:
                addName(namesList);
                break;

            case 2:
                removeName(namesList);
                break;
            
            case 3:
                listNames(namesList);
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

void addName(char *namesList){
    char name[MAX_NAME];
    int i, j;

    printf("Digite o nome a ser adicionado:\n");
    getchar();
    readString(name);

    if(strlen(name) < 1)
        return;
        
    strcat(name, ",");
    strcat(namesList, name);


}

void listNames(char *namesList){
    int i;
    if(namesList[0] == '\0'){
        printf("Lista vazia!");
        return;
    }
    printf("=======================");
    // printf("\n%s\n", namesList);
    printf("\nNomes:\n");
    for(i = 0; namesList[i] != '\0'; i++){
        if(namesList[i] == ','){
            printf("\n");
            continue;
        }
        printf("%c", namesList[i]);
    }
}

void removeName(char *namesList){
    int i;
    int subIndex = 0;
    int firstLetter = 0;
    int lastLetter = 0;
    char target[50];
    char namesListTemp[MAX_SIZE];

    if(namesList[0] == '\0'){
        printf("Lista vazia!");
        return;
    }

    printf("Digite o nome a ser removido:\n");
    getchar();
    readString(target);
    if(strlen(target) < 1)
        return;
    // printf("\n%s", target);

    for(i = 0; namesList[i] != '\0'; i++){

        if(namesList[i] == ','){
            if(target[subIndex] == '\0' && target[0] == namesList[firstLetter]){
                lastLetter = i;
                // printf("\n%c %c", namesList[firstIndex], namesList[lastLetter - 1]);
                break;
            }else{
                firstLetter = i + 1;
                subIndex = 0;
            }
            continue;
        }
        
        if(namesList[i] == target[subIndex]){
            subIndex++;
            continue;
        }

        subIndex = 0;

    }
    if (lastLetter == 0){
        printf("\nNome não encontrado!");
        return;
    }

    for(i = 0; i < firstLetter; i++){
        namesListTemp[i] = namesList[i];
    }
    // printf("\n%c\n", namesList[lastLetter]);
    for(i, subIndex = lastLetter + 1; namesList[subIndex] != '\0'; i++, subIndex++){
        namesListTemp[i] = namesList[subIndex];
    }
    namesListTemp[i] = '\0';

    strcpy(namesList, namesListTemp);

}

void readString(char* string){
    char c;
    int i = 0;

    scanf("%c", &c);

    while(c != '\n'){
        string[i++] = c;
        scanf("%c", &c);
    }
    // string[i++] = ',';
    string[i] = '\0';
    

}