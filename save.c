#include <stdio.h>
#include <stdlib.h>
#include "func/save.h"

void savePacientesFile(PacienteList *list) {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Erro no Sistema          ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║    Erro ao abrir arquivo para      ║");
        printf("\n║            escrita!                ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    EList *current = list->init;
    while (current != NULL) {
        Paciente *p = current->data;
        fprintf(file, "%s;%s;%d;%d;%d;%d\n",
                p->name, p->rg, p->age,
                p->entry->day, p->entry->month, p->entry->year);
        current = current->next;
    }

    fclose(file);
    printf("\n╔════════════════════════════════════╗");
    printf("\n║           Sistema de Dados         ║");
    printf("\n╠════════════════════════════════════╣");
    printf("\n║    Dados salvos com sucesso em     ║");
    printf("\n║            data.txt                ║");
    printf("\n╚════════════════════════════════════╝\n");
}

void loadPacientesFile(PacienteList *list) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Erro no Sistema          ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║    Erro ao abrir arquivo para      ║");
        printf("\n║            leitura!                ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Paciente *p = malloc(sizeof(Paciente));
        p->entry = malloc(sizeof(Date));

        sscanf(line, "%99[^;];%19[^;];%d;%d;%d;%d",
               p->name, p->rg, &p->age,
               &p->entry->day, &p->entry->month, &p->entry->year);

        // Insere no início (para manter a ordem de inserção)
        EList *new = malloc(sizeof(EList));
        new->data = p;
        new->next = list->init;
        list->init = new;
        list->size++;
    }

    fclose(file);
    printf("\n╔════════════════════════════════════╗");
    printf("\n║           Sistema de Dados         ║");
    printf("\n╠════════════════════════════════════╣");
    printf("\n║    Dados carregados com sucesso    ║");
    printf("\n║         do arquivo data.txt        ║");
    printf("\n╚════════════════════════════════════╝\n");
}

void menuSave(PacienteList *list) {
    int opcao;
    do {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║    GERENCIADOR DE ATENDIMENTO      ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║ 1. Salvar dados em um arquivo      ║");
        printf("\n║ 2. Carregar dados de um arquivo    ║");
        printf("\n║ 0. Sair                            ║");
        printf("\n╚════════════════════════════════════╝");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                savePacientesFile(list);
                break;
            case 2:
                loadPacientesFile(list);
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
    } while (opcao != 0);
}