#ifndef STACK_H
#define STACK_H

#include "paciente.h"
#include "queue.h"

// Estrutura da celula da pilha
typedef struct cell {
    struct cell *next;
    struct cell *prev;
    Paciente *paciente;
    char operation;
} Cell;

// Estrutura da pilha
typedef struct {
    Cell *top;
    int size;
} Stack;

// Insere na pilha
void *push(Stack *stack, Paciente *paciente, char operation);

// Remove da pilha
void *pop(Stack *stack);

// Desfaz a ultima operacao
void *undo(Stack *stack);

// Imprime a pilha
void printStack(Stack *stack);

#endif
