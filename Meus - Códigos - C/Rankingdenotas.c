
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[50];
    float nota;
    struct Aluno *proximo;
};

// Insere o aluno na posição certa, mantendo a lista em ordem decrescente de nota
struct Aluno* inserir_ordenado(struct Aluno *inicio, char nome[], float nota){
    struct Aluno *novo = (struct Aluno*) malloc(sizeof(struct Aluno));

    // Se o malloc falhar, devolve a lista como estava
    if(novo == NULL){
        printf("Erro de memoria!\n");
        return inicio;
    }

    strcpy(novo->nome, nome);
    novo->nota = nota;

    // Caso 1: lista vazia ou nota maior que a do primeiro
    if(inicio == NULL || nota > inicio->nota){
        novo->proximo = inicio;
        return novo;
    }

    // Caso 2: procura o nó que ficará antes do novo
    struct Aluno *aux = inicio;
    while(aux->proximo != NULL && aux->proximo->nota >= nota){
        aux = aux->proximo;
    }

    novo->proximo = aux->proximo;   // 1º: o novo aponta para o resto
    aux->proximo = novo;            // 2º: o anterior aponta para o novo

    return inicio;
}

// Mostra o ranking com a posição de cada aluno
void imprimir_lista(struct Aluno *inicio){
    struct Aluno *aux = inicio;
    int posicao = 1;

    while(aux != NULL){
        printf("%dº %s - %.2f\n", posicao, aux->nome, aux->nota);
        posicao++;
        aux = aux->proximo;
    }
}

int main(){

    struct Aluno *lista = NULL;
    char nome[50];
    float nota;

    do{
        printf("Nome (ou 'fim' para encerrar): ");
        scanf("%49s", nome);

        if(strcmp(nome, "fim") != 0){
            printf("Nota: ");
            scanf("%f", &nota);

            lista = inserir_ordenado(lista, nome, nota);
        }

    }while(strcmp(nome, "fim") != 0);

    printf("\n--- Ranking ---\n");
    imprimir_lista(lista);

    // Libera a memória alocada
    struct Aluno *atual = lista;
    while(atual != NULL){
        struct Aluno *proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }

    return 0;
}
