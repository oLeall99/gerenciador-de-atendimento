#include <stdio.h>

#define CHAR_SIZE 100
#define rg_size 10

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Registro {
    char name[CHAR_SIZE];
    int idade;
    char rg[rg_size];
    struct Data entrada;
} Registro;

typedef struct Lista {
    struct Elista *inicio;
    int qtd;
} Lista;

typedef struct Elista {
    Registro dados;
    struct Elista *prox;
} Elista;

typedef struct Efila {
    Registro dados;
    struct Efila *prox;
} Efila;

typedef struct Fila{
    Efila *head;
    Efila *tail;
    int qtd;
} Fila;

typedef struct Heap{
    Registro dados[20];
    int qtd;
} Heap;

typedef struct EABB{
    Registro dados;
    struct EABB *esq;
    struct EABB *dir;
} EABB;

typedef struct ABB{
    EABB *raiz;
    int qtd;
} ABB;

typedef struct Pilha{
    char operacao[CHAR_SIZE];
    struct Data data;
} Pilha;

int main(void) {
    return 0;
}
