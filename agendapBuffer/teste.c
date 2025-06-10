#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A área de rascunho (tempS) foi aumentada para comportar entradas maiores de nome e email.
// Vamos definir um tamanho genérico para o nome e email temporários.
#define SCRATCH_NAME_SIZE 50
#define SCRATCH_EMAIL_SIZE 50
#define SCRATCH_TOTAL_SIZE (SCRATCH_NAME_SIZE + SCRATCH_EMAIL_SIZE)

// O tamanho do cabeçalho do buffer (as variáveis de controle).
#define HEADER_SIZE (sizeof(int) * 3 + SCRATCH_TOTAL_SIZE)

// PERSON_SIZE foi removido, pois agora é dinâmico.

// Protótipos das funções
void showMenu(int *menu);
void addPerson(void **pBuffer, int **qt, void **agenda);
void listAll(void *pBuffer, int *i, int *qt, void *agenda);
void findPerson(void *pBuffer, int *i, int *qt, void *agenda);
void removePerson(void **pBuffer, int *i, int *qt, void *agenda);

int main() {
    // Aloca o buffer inicial apenas para o cabeçalho (variáveis de controle e rascunho).
    void *pBuffer = calloc(1, HEADER_SIZE + 1);

    while (1) {
        // Os ponteiros de controle são recalculados a cada iteração do loop,
        // pois o endereço de pBuffer pode mudar após um realloc.
        int *menu = (int *)pBuffer;
        int *qt = (int *)pBuffer + 1;
        int *i = (int *)pBuffer + 2;
        // A "agenda" começa logo após o cabeçalho.
        void *agenda = (char *)pBuffer + HEADER_SIZE;

        showMenu(menu);

        switch (*menu) {
            case 1:
                // Passamos o endereço do ponteiro da agenda para que ele possa ser atualizado.
                addPerson(&pBuffer, &qt, &agenda);
                break;
            case 2:
                removePerson(&pBuffer, i, qt, agenda);
                break;
            case 3:
                findPerson(pBuffer, i, qt, agenda);
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

void showMenu(int *menu) {
    do {
        printf("\n==========MENU==========\n");
        printf("1 - Adicionar Pessoa\n");
        printf("2 - Remover Pessoa\n");
        printf("3 - Buscar Pessoa\n");
        printf("4 - Listar Todos\n");
        printf("5 - Sair\n");
        printf("========================\n");
        printf("Escolha: ");
        scanf("%d", menu);
    } while (*menu < 1 || *menu > 5);
}

void addPerson(void **pBuffer, int **qt, void **agenda) {
    // Aponta para a área de rascunho dentro do buffer para entrada temporária.
    char *tempName = (char *)(*pBuffer) + (sizeof(int) * 3);
    char *tempEmail = tempName + SCRATCH_NAME_SIZE;
    int tempAge;

    // Coleta os dados do usuário.
    printf("Nome: ");
    getchar(); // Limpa o buffer de entrada do \n anterior.
    fgets(tempName, SCRATCH_NAME_SIZE, stdin);
    tempName[strcspn(tempName, "\n")] = 0; // Remove o \n do final.

    printf("\nIdade: ");
    scanf("%d", &tempAge);

    printf("\nEmail: ");
    getchar();
    fgets(tempEmail, SCRATCH_EMAIL_SIZE, stdin);
    tempEmail[strcspn(tempEmail, "\n")] = 0;

    // Calcula o tamanho exato necessário para a nova pessoa.
    size_t nameLen = strlen(tempName) + 1;
    size_t emailLen = strlen(tempEmail) + 1;
    size_t newPersonSize = nameLen + sizeof(int) + emailLen;

    // Calcula o tamanho total atual dos dados da agenda.
    size_t currentAgendaSize = 0;
    void *crawler = *agenda;
    for (int j = 0; j < **qt; j++) {
        size_t currentNameLen = strlen((char *)crawler) + 1;
        size_t currentEmailLen = strlen((char *)(crawler + currentNameLen + sizeof(int))) + 1;
        currentAgendaSize += currentNameLen + sizeof(int) + currentEmailLen;
        crawler = (char *)crawler + currentNameLen + sizeof(int) + currentEmailLen;
    }

    // Realoca o buffer para o novo tamanho total.
    void *tempBuffer = realloc(*pBuffer, HEADER_SIZE + currentAgendaSize + newPersonSize);
    if (!tempBuffer) {
        printf("Falha ao alocar memória!\n");
        return;
    }
    *pBuffer = tempBuffer;

    // ** IMPORTANTE: Recalcula os ponteiros após o realloc **
    *qt = (int *)(*pBuffer) + 1;
    *agenda = (char *)(*pBuffer) + HEADER_SIZE;

    // Encontra o local para escrever a nova pessoa (o final da agenda atual).
    void *newPersonLocation = (char *)(*agenda) + currentAgendaSize;

    // Copia os dados para a agenda.
    memcpy(newPersonLocation, tempName, nameLen);
    memcpy(newPersonLocation + nameLen, &tempAge, sizeof(int));
    memcpy(newPersonLocation + nameLen + sizeof(int), tempEmail, emailLen);
    
    // Incrementa a quantidade de pessoas.
    **qt += 1;
    
    printf("\nContato adicionado com sucesso!\n");
}

void listAll(void *pBuffer, int *i, int *qt, void *agenda) {
    if (!*qt) {
        printf("\n========================\n");
        printf("LISTA VAZIA\n");
        printf("========================\n");
        return;
    }

    void *crawler = agenda; // Ponteiro para percorrer a agenda.
    printf("\n========CONTATOS========\n");
    for (*i = 0; *i < *qt; (*i)++) {
        char *name = (char *)crawler;
        int *age = (int *)(crawler + strlen(name) + 1);
        char *email = (char *)(crawler + strlen(name) + 1 + sizeof(int));
        
        printf("Nome: %s\n", name);
        printf("Idade: %d\n", *age);
        printf("Email: %s\n", email);
        printf("========================\n");

        // Avança o ponteiro para o próximo registro.
        crawler = (char *)crawler + (strlen(name) + 1) + sizeof(int) + (strlen(email) + 1);
    }
}

void findPerson(void *pBuffer, int *i, int *qt, void *agenda) {
    if (!*qt) {
        printf("\n========================\n");
        printf("LISTA VAZIA\n");
        printf("========================\n");
        return;
    }
    
    // Usa a área de rascunho para obter o nome a ser buscado.
    char *tempS = (char*)pBuffer + sizeof(int) * 3;
    printf("Nome para buscar: ");
    getchar();
    fgets(tempS, SCRATCH_NAME_SIZE, stdin);
    tempS[strcspn(tempS, "\n")] = 0;

    void *crawler = agenda;
    for (*i = 0; *i < *qt; (*i)++) {
        char *currentName = (char *)crawler;
        if (strcmp(currentName, tempS) == 0) {
            int *age = (int *)(crawler + strlen(currentName) + 1);
            char *email = (char *)(crawler + strlen(currentName) + 1 + sizeof(int));
            
            printf("\n======CONTATO ENCONTRADO======\n");
            printf("Nome: %s\n", currentName);
            printf("Idade: %d\n", *age);
            printf("Email: %s\n", email);
            printf("==============================\n");
            return;
        }
        // Avança para o próximo.
        crawler = (char *)crawler + (strlen(currentName) + 1) + sizeof(int) + (strlen((char *)(crawler + strlen(currentName) + 1 + sizeof(int))) + 1);
    }

    printf("\n========================\n");
    printf("Contato não encontrado\n");
    printf("========================\n");
}

void removePerson(void **pBuffer, int *i, int *qt, void *agenda) {
    if (!*qt) {
        printf("\n========================\n");
        printf("LISTA VAZIA\n");
        printf("========================\n");
        return;
    }

    char *tempS = (char*)(*pBuffer) + sizeof(int) * 3;
    printf("Nome para remover: ");
    getchar();
    fgets(tempS, SCRATCH_NAME_SIZE, stdin);
    tempS[strcspn(tempS, "\n")] = 0;

    void *crawler = agenda;
    size_t traversedSize = 0; // Tamanho percorrido até agora.
    
    for (*i = 0; *i < *qt; (*i)++) {
        char *currentName = (char *)crawler;
        size_t nameLen = strlen(currentName) + 1;
        int* agePtr = (int *)(crawler + nameLen);
        char* emailPtr = (char *)(agePtr) + 1;
        size_t emailLen = strlen(emailPtr) + 1;
        size_t currentPersonSize = nameLen + sizeof(int) + emailLen;

        if (strcmp(currentName, tempS) == 0) {
            // Calcula o tamanho total da agenda antes da remoção.
            size_t totalAgendaSize = 0;
            void *sizeCrawler = agenda;
            for (int j = 0; j < *qt; j++) {
                size_t cNameLen = strlen((char*)sizeCrawler) + 1;
                size_t cEmailLen = strlen((char*)(sizeCrawler + cNameLen + sizeof(int))) + 1;
                totalAgendaSize += cNameLen + sizeof(int) + cEmailLen;
                sizeCrawler = (char*)sizeCrawler + cNameLen + sizeof(int) + cEmailLen;
            }

            // Ponteiro para o início do próximo registro.
            void *nextPerson = (char *)crawler + currentPersonSize;
            // Tamanho do bloco de memória a ser movido (do próximo até o fim).
            size_t remainingSize = totalAgendaSize - traversedSize - currentPersonSize;
            
            // Move o bloco de memória para sobreescrever o registro atual.
            // memmove é mais seguro para regiões de memória que se sobrepõem.
            if(remainingSize > 0){
                memmove(crawler, nextPerson, remainingSize);
            }

            // Decrementa a quantidade e realoca para um tamanho menor.
            *qt -= 1;
            *pBuffer = realloc(*pBuffer, HEADER_SIZE + totalAgendaSize - currentPersonSize);
            
            printf("\n========================\n");
            printf("Contato removido\n");
            printf("========================\n");
            return;
        }

        // Avança para o próximo.
        crawler = (char *)crawler + currentPersonSize;
        traversedSize += currentPersonSize;
    }

    printf("\n========================\n");
    printf("Contato não encontrado\n");
    printf("========================\n");
}