#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func/paciente.h"

// Cria uma nova lista vazia
PacienteList *createPacienteList() {
    PacienteList *list = (PacienteList*) malloc(sizeof(PacienteList));
    if (list != NULL) {
        list->init = NULL;
        list->size = 0;
    }
    return list;
}

// Cria uma nova data
Date *createDate(int day, int month, int year) {
    Date *newDate = (Date*) malloc(sizeof(Date));
    if (newDate != NULL) {
        newDate->day = day;
        newDate->month = month;
        newDate->year = year;
    }
    return newDate;
}

// Cria um novo paciente e insere no início da lista
Paciente *createPaciente(PacienteList *list, char name[], int age, char rg[], int day, int month, int year) {
    if (list == NULL) return NULL;

    EList *new = (EList*) malloc(sizeof(EList));
    if (new == NULL) return NULL;

    new->data = (Paciente*) malloc(sizeof(Paciente));
    if (new->data == NULL) {
        free(new);
        return NULL;
    }

    new->data->entry = createDate(day, month, year);
    if (new->data->entry == NULL) {
        free(new->data);
        free(new);
        return NULL;
    }

    strcpy(new->data->name, name);
    strcpy(new->data->rg, rg);
    new->data->age = age;

    new->next = list->init;
    list->init = new;
    list->size++;

    return new->data;
}

// Mostra todos os pacientes da lista
void printList(PacienteList *list) {
    if (list == NULL || list->init == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║         Lista de Pacientes         ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║           Lista vazia!             ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    EList *aux = list->init;
    printf("\n╔════════════════════════════════════╗");
    printf("\n║         Lista de Pacientes         ║");
    printf("\n╠════════════════════════════════════╣");
    
    while (aux != NULL) {
        printf("\n║ Nome: %-28s ║", aux->data->name);
        printf("\n║ Idade: %-27d ║", aux->data->age);
        printf("\n║ RG: %-30s ║", aux->data->rg);
        printf("\n║ Data de entrada: %02d/%02d/%04d        ║",
               aux->data->entry->day,
               aux->data->entry->month,
               aux->data->entry->year);
        printf("\n╠════════════════════════════════════╣");
        aux = aux->next;
    }
    printf("\n╚════════════════════════════════════╝\n");
}

// Consulta um paciente pelo RG
Paciente *searchPacienteByRG(PacienteList *list, char rg[]) {
    if (list == NULL) return NULL;

    EList *aux = list->init;
    while (aux != NULL) {
        if (strcmp(aux->data->rg, rg) == 0) {
            return aux->data;
        }
        aux = aux->next;
    }

    printf("\n╔════════════════════════════════════╗");
    printf("\n║         Paciente não encontrado    ║");
    printf("\n║ RG: %-30s ║", rg);
    printf("\n╚════════════════════════════════════╝\n");
    return NULL;
}

// Atualiza os dados de um paciente
void updatePaciente(PacienteList *list, char rg[], char newName[], int newAge) {
    if (list == NULL) return;

    EList *aux = list->init;
    while (aux != NULL) {
        if (strcmp(aux->data->rg, rg) == 0) {
            strcpy(aux->data->name, newName);
            aux->data->age = newAge;
            printf("\n╔════════════════════════════════════╗");
            printf("\n║  ! Dados atualizados com sucesso   ║");
            printf("\n╚════════════════════════════════════╝\n");
            return;
        }
        aux = aux->next;
    }

    printf("\n╔════════════════════════════════════╗");
    printf("\n║         Paciente não encontrado    ║");
    printf("\n╚════════════════════════════════════╝\n");
}

// Remove paciente pelo RG
void removePacienteByRG(PacienteList *list, char rg[]) {
    if (list == NULL || list->init == NULL) return;

    EList *current = list->init;
    EList *previous = NULL;

    while (current != NULL && strcmp(current->data->rg, rg) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║         Paciente não encontrado    ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }

    if (previous == NULL) {
        list->init = current->next;
    } else {
        previous->next = current->next;
    }

    free(current->data->entry);
    free(current->data);
    free(current);
    list->size--;

    printf("\n╔════════════════════════════════════╗");
    printf("\n║  ! Paciente removido com sucesso   ║");
    printf("\n╚════════════════════════════════════╝\n");
}

void menuPacientes(PacienteList* list) {
    int opcao;
    do {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║    GERENCIADOR DE ATENDIMENTO      ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║ 1. Cadastrar novo paciente         ║");
        printf("\n║ 2. Consultar paciente              ║");
        printf("\n║ 3. Listar todos os pacientes       ║");
        printf("\n║ 4. Atualizar dados do paciente     ║");
        printf("\n║ 5. Remover paciente                ║");
        printf("\n║ 0. Sair                            ║");
        printf("\n╚════════════════════════════════════╝");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        char nome[SIZE_NAME];
        int idade;
        char rg[15];
        char entrada[11];
        char *token;
        int dia, mes, ano;

        switch (opcao) {
            case 1:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║         Cadastro de Paciente       ║");
                printf("\n╚════════════════════════════════════╝\n");
                
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                
                printf("Idade: ");
                scanf("%d", &idade);
                getchar();
                
                printf("RG: ");
                fgets(rg, sizeof(rg), stdin);
                rg[strcspn(rg, "\n")] = 0;
                
                printf("Data de entrada (DD/MM/YYYY): ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;

                token = strtok(entrada, "/");
                if (token != NULL) dia = atoi(token);

                token = strtok(NULL, "/");
                if (token != NULL) mes = atoi(token);

                token = strtok(NULL, "/");
                if (token != NULL) ano = atoi(token);
                
                if (createPaciente(list, nome, idade, rg, dia, mes, ano)) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║  ! Paciente cadastrado com sucesso ║");
                    printf("\n╚════════════════════════════════════╝\n");
                }
                break;

            case 2:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║         Consulta de Paciente       ║");
                printf("\n╚════════════════════════════════════╝\n");
                
                printf("Digite o RG: ");
                fgets(rg, sizeof(rg), stdin);
                rg[strcspn(rg, "\n")] = 0;

                Paciente *p = searchPacienteByRG(list, rg);
                if (p != NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║         Paciente Encontrado        ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║ Nome: %-28s ║", p->name);
                    printf("\n║ Idade: %-27d ║", p->age);
                    printf("\n║ RG: %-30s ║", p->rg);
                    printf("\n║ Data de entrada: %02d/%02d/%04d           ║",
                           p->entry->day,
                           p->entry->month,
                           p->entry->year);
                    printf("\n╚════════════════════════════════════╝\n");
                }
                break;

            case 3:
                printList(list);
                break;

            case 4:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║       Atualização de Paciente      ║");
                printf("\n╚════════════════════════════════════╝\n");
                
                printf("RG do paciente: ");
                fgets(rg, sizeof(rg), stdin);
                rg[strcspn(rg, "\n")] = 0;
                
                printf("Novo nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Nova idade: ");
                scanf("%d", &idade);
                getchar();

                updatePaciente(list, rg, nome, idade);
                break;

            case 5:
                printf("\n╔════════════════════════════════════╗");
                printf("\n║         Remoção de Paciente        ║");
                printf("\n╚════════════════════════════════════╝\n");
                
                printf("RG do paciente: ");
                fgets(rg, sizeof(rg), stdin);
                rg[strcspn(rg, "\n")] = 0;

                removePacienteByRG(list, rg);
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
