#include <stdio.h>
#include <stdlib.h>
#include "func/stack.h"
#include "func/queue.h"
#include "func/paciente.h"

Cell *createCell(Paciente *paciente, char operation) {
    Cell *new = malloc(sizeof(Cell));
    new->prev = NULL;
    new->next = NULL;
    new->data = paciente;
    new->operation = operation;
    return new;
}

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, Paciente *paciente, char operation) {
    Cell *new = createCell(paciente, operation);
    if (stack->size != 0) {
        new->next = stack->top;
        stack->top->prev = new;
    }
    stack->top = new;
    stack->size++;
}

Cell *pop(Stack *stack) {
    if (stack->size == 0) return NULL;

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
        printf("\n║ Operação: %-24c ║", current->operation);
        printf("\n║ Paciente: %-25s ║", current->data->name);
        printf("\n╠════════════════════════════════════╣");
        current = current->next;
    }
    printf("\n╚════════════════════════════════════╝\n");
}

void undo(Queue *queue, Stack *stack) {
    if (stack->size == 0) {
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
    printf("\n║ Operação: %-25c║", top->operation);
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