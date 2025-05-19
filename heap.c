#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func/heap.h"
#include "func/paciente.h"

#define MAX_HEAP_SIZE 20

static void swap(Paciente **a, Paciente **b) {
    Paciente *temp = *a;
    *a = *b;
    *b = temp;
}

Heap *createHeap(int capacity) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    if (heap != NULL) {
        heap->size = 0;
        heap->capacity = capacity;
        heap->data = (Paciente**) malloc(capacity * sizeof(Paciente*));
        if (heap->data == NULL) {
            free(heap);
            return NULL;
        }
    }
    return heap;
}

int insertHeap(Heap *heap, Paciente *paciente) {
    if (heap->size >= heap->capacity) return 0;

    int i = heap->size;
    heap->data[i] = paciente;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[i]->age > heap->data[parent]->age) {
            swap(&heap->data[i], &heap->data[parent]);
            i = parent;
        } else {
            break;
        }
    }
    heap->size++;
    return 1;
}

void heapify(Heap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left]->age > heap->data[largest]->age)
        largest = left;

    if (right < heap->size && heap->data[right]->age > heap->data[largest]->age)
        largest = right;

    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        heapify(heap, largest);
    }
}

Paciente *removeHeap(Heap *heap) {
    if (heap->size == 0) return NULL;

    Paciente* removed = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];
    heapify(heap, 0);
    return removed;
}

void printHeap(Heap *heap) {
    if (heap == NULL || heap->size == 0) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║         Fila Prioritária           ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║           Fila vazia!              ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    printf("\n╔════════════════════════════════════╗");
    printf("\n║         Fila Prioritária           ║");
    printf("\n╠════════════════════════════════════╣");
    
    for (int i = 0; i < heap->size; i++) {
        Paciente* p = heap->data[i];
        printf("\n║ Nome: %-28s ║", p->name);
        printf("\n║ Idade: %-27d ║", p->age);
        printf("\n║ RG: %-30s ║", p->rg);
        printf("\n║ Data de entrada: %02d/%02d/%04d        ║", 
               p->entry->day, 
               p->entry->month, 
               p->entry->year);
        printf("\n╠════════════════════════════════════╣");
    }
    printf("\n╚════════════════════════════════════╝\n");
}

void freeHeap(Heap *heap) {
    if (heap != NULL) {
        free(heap->data);
        free(heap);
    }
}

void menuHeap(PacienteList *list, Heap *heap) {
    int opcao;
    char rg[20];
    
    do {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║        Menu Prioritário            ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║ 1. Adicionar à Fila Prioritária    ║");
        printf("\n║ 2. Atender Próximo Prioritário     ║");
        printf("\n║ 3. Mostrar Fila Prioritária        ║");
        printf("\n║ 0. Voltar                          ║");
        printf("\n╚════════════════════════════════════╝");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║     Adicionar à Fila Prioritária   ║");
                printf("\n╠════════════════════════════════════╣");
                printf("\nRG: ");
                fgets(rg, sizeof(rg), stdin);
                rg[strcspn(rg, "\n")] = 0;

                Paciente *p = searchPacienteByRG(list, rg);
                if (p != NULL) {
                    if (insertHeap(heap, p)) {
                        printf("\n╔════════════════════════════════════╗");
                        printf("\n║      Paciente adicionado com       ║");
                        printf("\n║            sucesso!                ║");
                        printf("\n╚════════════════════════════════════╝\n");
                    } else {
                        printf("\n╔════════════════════════════════════╗");
                        printf("\n║         Fila prioritária cheia!    ║");
                        printf("\n╚════════════════════════════════════╝\n");
                    }
                } else {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║        Paciente não encontrado!    ║");
                    printf("\n╚════════════════════════════════════╝\n");
                }
                break;

            case 2:
                p = removeHeap(heap);
                if (p != NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║           Dados do Paciente        ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║ Nome: %-28s ║", p->name);
                    printf("\n║ Idade: %-27d ║", p->age);
                    printf("\n║ RG: %-30s ║", p->rg);
                    printf("\n║ Data de entrada: %02d/%02d/%04d        ║", 
                           p->entry->day, 
                           p->entry->month, 
                           p->entry->year);
                    printf("\n╚════════════════════════════════════╝\n");
                } else {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║         Fila prioritária vazia!    ║");
                    printf("\n╚════════════════════════════════════╝\n");
                }
                break;

            case 3:
                printHeap(heap);
                break;

            case 0:
                break;

            default:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║           Opção inválida!          ║");
                printf("\n╚════════════════════════════════════╝\n");
        }
    } while (opcao != 0);
}