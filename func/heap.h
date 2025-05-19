#ifdef HEAP_H
#define HEAP_H

#include "paciente.h"

#define  MAX_SIZE_HEAP 200

// Estrutura do HEAP
typedef struct {
    Paciente *pacientes[MAX_SIZE_HEAP];
    int size;
} Heap;

//Cria um novo Heap
Heap *createHeap(int capacidade);

//Insere um valor no heap
int insertHeap(Heap *heap, Paciente *paciente);

//Remove valor do heap
Paciente *removeHeap(Heap *heap);

//Mostra os valores do heap
void showHeap(Heap *heap);

//Libera o Heap
void freeHeap(Heap *heap);

#endif