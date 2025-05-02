#include <stdio.h>

#define name_size 100
#define rg_size 10

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Registro {
    char name[name_size];
    int idade;
    char rg[rg_size];
    Data entrada;
} Registro;

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

int main(void) {
    return 0;
}
