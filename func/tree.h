#ifndef TREE_H
#define TREE_H

#include "paciente.h"

// Estrutura de nós da arvore
typedef struct Node {
    Paciente *data;
    struct Node *left;
    struct Node *right;
} Node;

// Estrutura da arvore
typedef struct Tree {
    Node *root;
    int size;
} Tree;

// Criar arvore
Tree *createTree();

// Criar nó
Node *createNode(Paciente *paciente);

// Inserir nó na arvore ordernando por idade
Node *insertNodeByAge(Tree *tree, Paciente *paciente);

// Inserir nó na arvore ordernando por ano
Node *insertNodeByYear(Tree *tree, Paciente *paciente);

// Inserir nó na arvore ordernando por mes
Node *insertNodeByMonth(Tree *tree, Paciente *paciente);

// Inserir nó na arvore ordernando por dia
Node *insertNodeByDay(Tree *tree, Paciente *paciente);

// Imprimir arvore
void printTree(Tree *tree);

// Menu de opções de pesquisa
void searchTreeMenu(PacienteList *list);

#endif
