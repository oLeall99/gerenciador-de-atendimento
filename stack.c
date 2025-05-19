#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func/stack.h"
#include "func/paciente.h"
#include "func/queue.h"

Cell *createCell(Paciente *paciente, char operation) {
    Cell *new = malloc(sizeof(Cell));
    if (new == NULL) return NULL;
    
    new->prev = NULL;
    new->next = NULL;
    new->data = paciente;
    new->operation = operation;
    return new;
}

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;
    
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, Paciente *paciente, char operation) {
    if (stack == NULL) return;
    
    Cell *new = createCell(paciente, operation);
    if (new == NULL) return;
    
    if (stack->size != 0) {
        new->next = stack->top;
        stack->top->prev = new;
    }
    stack->top = new;
    stack->size++;
}

Cell *pop(Stack *stack) {
    if (stack == NULL || stack->size == 0) return NULL;

    Cell *top = stack->top;
    stack->top = top->next;
    if (stack->top != NULL)
        stack->top->prev = NULL;

    stack->size--;
    return top;
}

void printStack(Stack *stack) {
    if (stack == NULL || stack->size == 0) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Log de Operações         ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║           Log vazio!               ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    Cell *current = stack->top;
    printf("\n╔════════════════════════════════════╗");
    printf("\n║           Log de Operações         ║");
    printf("\n╠════════════════════════════════════╣");
    
    while (current != NULL) {
        char operacao_desc[20] = "";
        switch(current->operation) {
            case 'E': strcpy(operacao_desc, "Entrada na fila"); break;
            case 'D': strcpy(operacao_desc, "Saída da fila"); break;
            case 'A': strcpy(operacao_desc, "Cadastro"); break;
            case 'R': strcpy(operacao_desc, "Remoção"); break;
            default: strcpy(operacao_desc, "Desconhecida");
        }
        
        printf("\n║ Operação: %-24s ║", operacao_desc);
        printf("\n║ Paciente: %-25s ║", current->data->name);
        printf("\n╠════════════════════════════════════╣");
        current = current->next;
    }
    printf("\n╚════════════════════════════════════╝\n");
}

// Função auxiliar para adicionar um paciente à lista sem registrar na pilha
void addPacienteToList(PacienteList *list, Paciente *paciente) {
    if (list == NULL || paciente == NULL) return;
    
    EList *new = (EList*) malloc(sizeof(EList));
    if (new == NULL) return;
    
    new->data = paciente;
    new->next = list->init;
    list->init = new;
    list->size++;
}

// Função auxiliar para remover um paciente da lista sem registrar na pilha
void removePacienteFromList(PacienteList *list, char rg[]) {
    if (list == NULL || list->init == NULL) return;

    EList *current = list->init;
    EList *previous = NULL;

    while (current != NULL && strcmp(current->data->rg, rg) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;

    if (previous == NULL) {
        list->init = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    list->size--;
}

void undo(Queue *queue, Stack *stack, PacienteList *list) {
    if (stack == NULL || stack->size == 0) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Log de Operações         ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║     Nenhuma operação para desfazer ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    printStack(stack);

    Cell *top = stack->top;
    Paciente *p = top->data;
    
    if (p == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Log de Operações         ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║     Paciente não encontrado!       ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    char operacao_desc[20] = "";
    switch(top->operation) {
        case 'E': strcpy(operacao_desc, "Entrada na fila"); break;
        case 'D': strcpy(operacao_desc, "Saída da fila"); break;
        case 'A': strcpy(operacao_desc, "Cadastro"); break;
        case 'R': strcpy(operacao_desc, "Remoção"); break;
        default: strcpy(operacao_desc, "Desconhecida");
    }

    printf("\n╔════════════════════════════════════╗");
    printf("\n║         Dados do Paciente          ║");
    printf("\n╠════════════════════════════════════╣");
    printf("\n║ Nome: %-28s ║", p->name);
    printf("\n║ Idade: %-27d ║", p->age);
    printf("\n║ RG: %-30s ║", p->rg);
    printf("\n║ Data de entrada: %02d/%02d/%04d        ║", 
           p->entry->day, 
           p->entry->month, 
           p->entry->year);
    printf("\n║ Operação: %-25s║", operacao_desc);
    printf("\n╚════════════════════════════════════╝\n");

    printf("\n╔═════════════════════════════════════╗");
    printf("\n║      Desfazer esta operação?        ║");
    printf("\n╠═════════════════════════════════════╣");
    printf("\n║ Digite 's' para sim ou 'n' para não ║");
    printf("\n╚═════════════════════════════════════╝\n");
    printf("Escolha: ");

    char opcao;
    scanf(" %c", &opcao);

    if (opcao == 's') {
        if (top->operation == 'D') {
            enqueue(queue, top->data, stack, 0);
            Cell *removed = pop(stack);
            free(removed);
            printf("\n╔════════════════════════════════════╗");
            printf("\n║  ! Operação desfeita com sucesso   ║");
            printf("\n╚════════════════════════════════════╝\n");
        } else if (top->operation == 'E') {
            dequeue(queue, stack, 0);
            Cell *removed = pop(stack);
            free(removed);
            printf("\n╔════════════════════════════════════╗");
            printf("\n║  ! Operação desfeita com sucesso   ║");
            printf("\n╚════════════════════════════════════╝\n");
        } else if (top->operation == 'A') {
            // Desfazer adição = remover paciente
            removePacienteFromList(list, p->rg);
            Cell *removed = pop(stack);
            // Liberamos o paciente completamente
            free(removed->data->entry);
            free(removed->data);
            free(removed);
            printf("\n╔════════════════════════════════════╗");
            printf("\n║  ! Operação desfeita com sucesso   ║");
            printf("\n╚════════════════════════════════════╝\n");
        } else if (top->operation == 'R') {
            // Desfazer remoção = adicionar paciente de volta
            addPacienteToList(list, p);
            Cell *removed = pop(stack);
            free(removed);
            printf("\n╔════════════════════════════════════╗");
            printf("\n║  ! Operação desfeita com sucesso   ║");
            printf("\n╚════════════════════════════════════╝\n");
        } else {
            printf("\n╔════════════════════════════════════╗");
            printf("\n║  ! Operação não reconhecida!       ║");
            printf("\n╚════════════════════════════════════╝\n");
        }
    } else {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║  ! Operação mantida!               ║");
        printf("\n╚════════════════════════════════════╝\n");
    }
}