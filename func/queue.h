#ifndef QUEUE_H
#define QUEUE_H

#include "paciente.h"

typedef struct Queue Queue;
typedef struct EQueue EQueue;

struct EQueue {
    Paciente *data;
    EQueue *next;
};

struct Queue {
    EQueue *init;
    EQueue *end;
    int size;
};

Queue *createQueue();
void enqueue(Queue *queue, Paciente *paciente, void *stack, int log);
Paciente *dequeue(Queue *queue, void *stack, int log);
void printQueue(Queue *queue);
void menuQueue(PacienteList *list, Queue *queue, void *stack);

#endif
