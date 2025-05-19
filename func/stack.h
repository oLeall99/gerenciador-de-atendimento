#ifndef STACK_H
#define STACK_H

#include "paciente.h"
#include "queue.h"

// Estrutura da celula da pilha
typedef struct Cell {
    Paciente *data;
    char operation;
    struct Cell *prev;
    struct Cell *next;
} Cell;

// Estrutura da pilha
typedef struct {
    Cell *top;
    int size;
} Stack;

// Insere na pilha
void push(Stack *stack, Paciente *paciente, char operation);

// Remove da pilha
Cell *pop(Stack *stack);

// Desfaz a ultima operacao
void undo(Queue *queue, Stack *stack);

// Imprime a pilha
void printStack(Stack *stack);

Stack *createStack();

#endif
