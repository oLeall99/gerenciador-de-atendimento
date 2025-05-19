#ifndef QUEUE_H
#define QUEUE_H

typedef struct Stack Stack;

typedef struct EQueue {
    Paciente *paciente;
    struct EQueue *next;
} EQueue;


typedef struct Queue {
    EQueue *head;
    EQueue *tail;
    int size;
} Queue;

// Criar Fila
Queue *createQueue();

// Enfileirar Fila com um valor
int enqueue(Queue *queue, Paciente *paciente, Stack *stack, int flag);

// Desenfileirar um valor da Fila
Paciente *dequeue(Queue *queue, Stack *stack, int flag);

// Imprimir Fila
void printQueue(Queue *queue);


#endif
