#include <stdio.h>
#include <stdlib.h>
#include "func/tree.h"
#include "func/paciente.h"

// Cria um novo nó da árvore
Node *createNode(Paciente *paciente) {
    Node *new = malloc(sizeof(Node));
    new->data = paciente;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Inicializa uma nova árvore vazia
Tree *createTree() {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

// Insere um novo nó na árvore ordenado pela idade
Node *insertNodeByAge(Tree *tree, Paciente *paciente) {
    Node *new = createNode(paciente);
    Node *previous = NULL;
    Node *current = tree->root;

    while (current != NULL) {
        previous = current;
        if (paciente->age <= current->data->age) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (previous == NULL) {
        tree->root = new;
    } else if (paciente->age <= previous->data->age) {
        previous->left = new;
    } else {
        previous->right = new;
    }

    tree->size++;
    return new;
}

// Insere um novo nó na árvore ordenado pelo ano
Node *insertNodeByYear(Tree *tree, Paciente *paciente) {
    Node *new = createNode(paciente);
    Node *previous = NULL;
    Node *current = tree->root;

    while (current != NULL) {
        previous = current;
        if (paciente->entry->year <= current->data->entry->year) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (previous == NULL) {
        tree->root = new;
    } else if (paciente->entry->year <= previous->data->entry->year) {
        previous->left = new;
    } else {
        previous->right = new;
    }

    tree->size++;
    return new;
}

// Insere um novo nó na árvore ordenado pelo mês
Node *insertNodeByMonth(Tree *tree, Paciente *paciente) {
    Node *new = createNode(paciente);
    Node *previous = NULL;
    Node *current = tree->root;

    while (current != NULL) {
        previous = current;
        if (paciente->entry->month <= current->data->entry->month) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (previous == NULL) {
        tree->root = new;
    } else if (paciente->entry->month <= previous->data->entry->month) {
        previous->left = new;
    } else {
        previous->right = new;
    }

    tree->size++;
    return new;
}

// Insere um novo nó na árvore ordenado pelo dia
Node *insertNodeByDay(Tree *tree, Paciente *paciente) {
    Node *new = createNode(paciente);
    Node *previous = NULL;
    Node *current = tree->root;

    while (current != NULL) {
        previous = current;
        if (paciente->entry->day <= current->data->entry->day) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (previous == NULL) {
        tree->root = new;
    } else if (paciente->entry->day <= previous->data->entry->day) {
        previous->left = new;
    } else {
        previous->right = new;
    }

    tree->size++;
    return new;
}

// Percorre a árvore pela raiz e exibe os nós ordenados
void printInOrder(Node *root) {
    if (root != NULL) {
        printInOrder(root->left);

        printf("\n╔════════════════════════════════════╗");
        printf("\n║           Dados do Paciente        ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║ Nome: %-28s ║", root->data->name);
        printf("\n║ RG: %-30s ║", root->data->rg);
        printf("\n║ Idade: %-27d ║", root->data->age);
        printf("\n║ Data de entrada: %02d/%02d/%04d        ║",
               root->data->entry->day,
               root->data->entry->month,
               root->data->entry->year);
        printf("\n╚════════════════════════════════════╝\n");

        printInOrder(root->right);
    }
}

// Imprime a árvore
void printTree(Tree *tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║         Árvore de Pacientes        ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║           Árvore vazia!            ║");
        printf("\n╚════════════════════════════════════╝\n");
        return;
    }
    printInOrder(tree->root);
}

// Libera a memória da árvore
void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Menu de opções de pesquisa
void searchTreeMenu(PacienteList *list) {
    int opcao;
    do {
        printf("\n╔════════════════════════════════════╗");
        printf("\n║    GERENCIADOR DE ATENDIMENTO      ║");
        printf("\n╠════════════════════════════════════╣");
        printf("\n║ 1. Pesquisar por idade             ║");
        printf("\n║ 2. Pesquisar por ano de entrada    ║");
        printf("\n║ 3. Pesquisar por mês de entrada    ║");
        printf("\n║ 4. Pesquisar por dia de entrada    ║");
        printf("\n║ 0. Sair                            ║");
        printf("\n╚════════════════════════════════════╝");
        printf("\nEscolha: ");
        
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                Tree *tree = createTree();
                EList *aux = list->init;
                
                if (aux == NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║         Lista de Pacientes         ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║           Lista vazia!             ║");
                    printf("\n╚════════════════════════════════════╝\n");
                    break;
                }
                
                while (aux != NULL) {
                    insertNodeByAge(tree, aux->data);
                    aux = aux->next;
                }
                
                printf("\n╔════════════════════════════════════╗");
                printf("\n║    Pacientes por Ordem de Idade    ║");
                printf("\n╚════════════════════════════════════╝\n");
                printTree(tree);
                freeTree(tree->root);
                free(tree);
                break;
            }

            case 2: {
                Tree *tree = createTree();
                EList *aux = list->init;
                
                if (aux == NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║         Lista de Pacientes         ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║           Lista vazia!             ║");
                    printf("\n╚════════════════════════════════════╝\n");
                    break;
                }
                
                while (aux != NULL) {
                    insertNodeByYear(tree, aux->data);
                    aux = aux->next;
                }
                
                printf("\n╔════════════════════════════════════╗");
                printf("\n║   Pacientes por Ano de Entrada     ║");
                printf("\n╚════════════════════════════════════╝\n");
                printTree(tree);
                freeTree(tree->root);
                free(tree);
                break;
            }

            case 3: {
                Tree *tree = createTree();
                EList *aux = list->init;
                
                if (aux == NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║         Lista de Pacientes         ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║           Lista vazia!             ║");
                    printf("\n╚════════════════════════════════════╝\n");
                    break;
                }
                
                while (aux != NULL) {
                    insertNodeByMonth(tree, aux->data);
                    aux = aux->next;
                }
                
                printf("\n╔════════════════════════════════════╗");
                printf("\n║   Pacientes por Mês de Entrada     ║");
                printf("\n╚════════════════════════════════════╝\n");
                printTree(tree);
                freeTree(tree->root);
                free(tree);
                break;
            }

            case 4: {
                Tree *tree = createTree();
                EList *aux = list->init;
                
                if (aux == NULL) {
                    printf("\n╔════════════════════════════════════╗");
                    printf("\n║         Lista de Pacientes         ║");
                    printf("\n╠════════════════════════════════════╣");
                    printf("\n║           Lista vazia!             ║");
                    printf("\n╚════════════════════════════════════╝\n");
                    break;
                }
                
                while (aux != NULL) {
                    insertNodeByDay(tree, aux->data);
                    aux = aux->next;
                }
                
                printf("\n╔════════════════════════════════════╗");
                printf("\n║   Pacientes por Dia de Entrada     ║");
                printf("\n╚════════════════════════════════════╝\n");
                printTree(tree);
                freeTree(tree->root);
                free(tree);
                break;
            }

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