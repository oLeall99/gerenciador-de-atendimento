#ifndef HEAP_H
#define HEAP_H

#include "paciente.h"

typedef struct {
    Paciente **data;
    int size;
    int capacity;
} Heap;

Heap *createHeap(int capacity);
void menuHeap(PacienteList *list, Heap *heap);

#endif