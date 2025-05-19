#ifndef SAVE_H
#define SAVE_H

#include "paciente.h"

void savePacientesFile(PacienteList *list);
void loadPacientesFile(PacienteList *list);
void menuSave(PacienteList *list);

#endif