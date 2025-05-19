// main.c
#include <stdio.h>
#include <stdlib.h>
#include "func/paciente.h"
#include "func/queue.h"
#include "func/heap.h"
#include "func/stack.h"
#include "func/tree.h"
#include "func/save.h"

void menu() {
    printf("\n╔════════════════════════════════════╗");
    printf("\n║    GERENCIADOR DE ATENDIMENTO      ║");
    printf("\n╠════════════════════════════════════╣");
    printf("\n║ 1. Cadastrar Paciente              ║");
    printf("\n║ 2. Atendimento                     ║");
    printf("\n║ 3. Atendimento Prioritário         ║");
    printf("\n║ 4. Pesquisar                       ║");
    printf("\n║ 5. Desfazer Operação               ║");
    printf("\n║ 6. Salvar e Carregar Dados         ║");
    printf("\n║ 7. Sobre                           ║");
    printf("\n║ 0. Sair                            ║");
    printf("\n╚════════════════════════════════════╝");
    printf("\n║ ! Escolha: ");
}

void sobre() {
    printf("\n╔════════════════════════════════════╗");
    printf("\n║         Sobre o Projeto            ║");
    printf("\n╠════════════════════════════════════╣");
    printf("\n║ Desenvolvido por:                  ║");
    printf("\n║ Arthur Leal Mussio - 22.223.017-9  ║");
    printf("\n║                                    ║");
    printf("\n║ Estrutura de dados - 4º Semestre   ║");
    printf("\n║ Ciência da Computação - FEI        ║");
    printf("\n║ 2025                               ║");
    printf("\n╚════════════════════════════════════╝\n");
}

int main() {
    int opt;
    PacienteList *list = createPacienteList();
    Queue *queue = createQueue();
    Heap *heap = createHeap(20);
    Stack *stack = createStack();

    do {
        menu();
        scanf("%d", &opt);
        getchar();

        switch (opt) {
            case 1:
                menuPacientes(list);
                break;
            case 2:
                menuQueue(list, queue, stack);
                break;
            case 3:
                menuHeap(list, heap);
                break;
            case 4:
                searchTreeMenu(list);
                break;
            case 5:
                undo(queue, stack);
                break;
            case 6:
                menuSave(list);
                break;
            case 7:
                sobre();
                break;
            case 0:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║           Encerrando...            ║");
                printf("\n╚════════════════════════════════════╝\n");
                break;
            default:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║           Opção inválida!          ║");
                printf("\n╚════════════════════════════════════╝\n");
        }
    } while (opt != 0);

    return 0;
}
