// funcoes/fila.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func/queue.h"
#include "func/stack.h"

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->init = NULL;
    queue->end = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, Paciente *paciente, void *stack, int log) {
    EQueue *new = malloc(sizeof(EQueue));
    new->data = paciente;
    new->next = NULL;

    if (queue->size == 0) {
        queue->init = new;
    } else {
        queue->end->next = new;
    }
    queue->end = new;
    queue->size++;

    if (log) {
        push((Stack *)stack, paciente, 'E');
    }
}

Paciente *dequeue(Queue *queue, void *stack, int log) {
    if (queue->size == 0) return NULL;

    EQueue *removed = queue->init;
    Paciente *paciente = removed->data;
    queue->init = removed->next;

    if (queue->init == NULL) {
        queue->end = NULL;
    }

    free(removed);
    queue->size--;

    if (log) {
        push((Stack *)stack, paciente, 'D');
    }

    return paciente;
}

void printQueue(Queue *queue) {
    if (queue == NULL || queue->init == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Fila Vazia!              ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    EQueue *aux = queue->init;
    printf("\n╔════════════════════════════════════╗");
    printf("\n║      Fila de Atendimento           ║");
    printf("\n╠════════════════════════════════════╣");
    
    while (aux != NULL) {
        Paciente *p = aux->data;
        printf("\n║ Nome: %-28s ║", p->name);
        printf("\n║ Idade: %-27d ║", p->age);
        printf("\n║ RG: %-30s ║", p->rg);
        printf("\n║ Data de entrada: %02d/%02d/%04d        ║", 
               p->entry->day, 
               p->entry->month, 
               p->entry->year);
        printf("\n╠════════════════════════════════════╣");
        aux = aux->next;
    }
    printf("\n╚════════════════════════════════════╝\n");
}

void menuQueue(PacienteList *list, Queue *queue, void *stack) {
    int opcao;
    char rg[20];

    do {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║        Menu de Atendimento         ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║ 1. Adicionar à Fila                ║");
        printf("\n║ 2. Atender Próximo                 ║");
        printf("\n║ 3. Mostrar Fila                    ║");
        printf("\n║ 0. Voltar                          ║");
        printf("\n╚════════════════════════════════════╝");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║        Adicionar à Fila            ║");
                printf("\n╠════════════════════════════════════╣");
                printf("\nRG: ");
                fgets(rg, sizeof(rg), stdin);
                rg[strcspn(rg, "\n")] = 0;

                Paciente *p = searchPacienteByRG(list, rg);
                if (p != NULL) {
                    enqueue(queue, p, stack, 1);
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║      Paciente adicionado com       ║");
                    printf("\n║            sucesso!                ║");
                    printf("\n╚════════════════════════════════════╝\n");
                } else {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║        Paciente não encontrado!    ║");
                    printf("\n╚════════════════════════════════════╝\n");
                }
                break;

            case 2:
                p = dequeue(queue, stack, 1);
                if (p != NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║           Dados do Paciente        ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║ Nome: %-28s ║", p->name);
                    printf("\n║ Idade: %-27d ║", p->age);
                    printf("\n║ RG: %-30s ║", p->rg);
                    printf("\n║ Data de entrada: %02d/%02d/%04d         ║", 
                           p->entry->day, 
                           p->entry->month, 
                           p->entry->year);
                    printf("\n╚════════════════════════════════════╝\n");
                } else {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║           Fila vazia!              ║");
                    printf("\n╚════════════════════════════════════╝\n");
                }
                break;

            case 3:
                printQueue(queue);
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