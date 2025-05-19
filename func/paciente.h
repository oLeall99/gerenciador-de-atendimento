#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME 100

// Estrutura de Data
typedef struct DATE {
    int day;
    int month;
    int year;
} DATE;

// Estrutura de Paciente
typedef struct Paciente {
    char rg[15];
    char nome[SIZE_NAME];
    int age;
    Data *entry;
} Paciente;

// Estrutura de uma celula da lista encadeada
typedef struct EList {
    Paciente *data;
    struct EList *next;
} EList;

// Lista Encadeada de pacientes
typedef struct PacienteList {
    EList *init;
    int size;
} PacienteList;

// Criar lista encadeada de pacientes
PacienteList *createPacienteList();

// Criar data
Date *createDate(int day, int mouth, int year);

// Criar paciente
Paciente *createPaciente(ListaPacientes* list, char name[], int age, char rg[], int age, int day, int mouth, int year);

// Consultar Paciente pelo RG
Paciente *searchPacienteByRG(ListaPacientes* list, char rg[]);

// Mostrar os dados de todos os pacientes
void printList(ListaPacientes* list);

// Remover paciente pelo RG
void removePacienteByRG(ListaPacientes* list, char rg[]);

// Atualizar os dados de um paciente
void updatePaciente(ListaPacientes* list, char rg[], char newName[], int newAge);

#endif
