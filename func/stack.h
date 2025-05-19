#ifndef STACK_H
#define STACK_H

// Forward declaration to avoid circular dependency
struct PacienteList;
struct Queue;
struct Paciente;

// Renamed the struct to avoid conflict with the typedef
typedef struct StackCell {
    struct Paciente *data;
    char operation;
    struct StackCell *prev;
    struct StackCell *next;
} Cell;

// Changed to use named struct to match forward declaration in paciente.h
typedef struct Stack {
    Cell *top;
    int size;
} Stack;

// Cria uma pilha
Stack *createStack();

// Cria uma célula para a pilha
Cell *createCell(struct Paciente *paciente, char operation);

// Insere na pilha
void push(Stack *stack, struct Paciente *paciente, char operation);

// Remove da pilha
Cell *pop(Stack *stack);

// Adiciona paciente à lista sem registrar na pilha
void addPacienteToList(struct PacienteList *list, struct Paciente *paciente);

// Remove paciente da lista sem registrar na pilha
void removePacienteFromList(struct PacienteList *list, char rg[]);

// Desfaz a ultima operacao
void undo(struct Queue *queue, Stack *stack, struct PacienteList *list);

// Imprime a pilha
void printStack(Stack *stack);

#endif
