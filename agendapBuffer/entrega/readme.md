# Filipe de Oliveira Soares
# Turma M1

## Trabalho Agenda pBuffer

# Esqueci de mencionar no vídeo, mas sobre a complexidade de tempo do código:

 - O addPerson é O(n) pois o realloc pode precisar mover o buffer para outro local na memória;
 - O restante também é O(n) pois percorre o buffer até no máximo uma vez, escala que cresce linearmente com seu tamanho.