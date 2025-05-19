#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME 100

// Estrutura de Data
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Estrutura de Paciente
typedef struct {
    char name[SIZE_NAME];
    char rg[20];
    int age;
    Date *entry;
} Paciente;

// Estrutura de uma celula da lista encadeada
typedef struct EList {
    Paciente *data;
    struct EList *next;
} EList;

// Lista Encadeada de pacientes
typedef struct {
    EList *init;
    int size;
} PacienteList;

// Criar lista encadeada de pacientes
PacienteList *createPacienteList();

// Criar data
Date *createDate(int day, int mouth, int year);

// Criar paciente
Paciente *createPaciente(PacienteList* list, char name[], int age, char rg[], int day, int month, int year);

// Consultar Paciente pelo RG
Paciente *searchPacienteByRG(PacienteList* list, char rg[]);

// Mostrar os dados de todos os pacientes
void printList(PacienteList* list);

// Remover paciente pelo RG
void removePacienteByRG(PacienteList* list, char rg[]);

// Atualizar os dados de um paciente
void updatePaciente(PacienteList* list, char rg[], char newName[], int newAge);

void menuPacientes(PacienteList* list);

#endif
