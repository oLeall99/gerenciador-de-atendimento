# 🏥 Sistema de Gerenciamento de Atendimento

Projeto desenvolvido para a disciplina **Estrutura de Dados** — 4º semestre de 2025  
Centro Universitário FEI - Ciência da Computação

---

## 📋 Visão Geral

O **Sistema de Gerenciamento de Atendimento** é uma aplicação em C que implementa um sistema completo para controle de pacientes em ambientes médicos. O projeto demonstra a aplicação prática de estruturas de dados fundamentais através de um sistema real e funcional.

O objetivo principal é demonstrar a implementação e utilização eficiente de diferentes estruturas de dados em um contexto prático, permitindo o gerenciamento completo do fluxo de pacientes em um ambiente médico.

---

## ⚙️ Recursos Principais

### 👤 Gestão de Pacientes
- Sistema completo de cadastro utilizando **listas encadeadas**
- Funcionalidades implementadas:
  - Registro de novos pacientes
  - Busca por RG
  - Atualização de informações
  - Exclusão de registros
  - Visualização completa do cadastro

### ⏳ Controle de Atendimento
- Implementação de **fila FIFO** para atendimento regular
- Recursos disponíveis:
  - Adição à fila de espera
  - Chamada para atendimento
  - Visualização da fila atual

### ⚡ Atendimento Prioritário
- Sistema de priorização baseado em **heap máximo**
- Limite de 20 atendimentos prioritários
- Funcionalidades:
  - Registro de atendimento prioritário
  - Chamada de pacientes prioritários
  - Visualização da fila prioritária

### 🔎 Sistema de Busca
- Implementação de **árvore binária de busca**
- Múltiplos critérios de ordenação:
  - Data de entrada (ano/mês/dia)
  - Idade do paciente
- Visualização ordenada por diferentes critérios

### 🔄 Controle de Operações
- Sistema de **pilha** para gerenciamento de operações
- Recursos:
  - Histórico de operações
  - Reversão de última ação

### 💾 Persistência de Dados
- Sistema de arquivos para armazenamento
- Funcionalidades:
  - Importação de dados
  - Exportação de registros

---

## 🏗️ Arquitetura do Sistema

| Componente                 | Estrutura Implementada        |
|----------------------------|-------------------------------|
| Cadastro de pacientes      | Lista encadeada               |
| Fila de atendimento        | Fila FIFO                     |
| Atendimento prioritário    | Heap máximo                   |
| Sistema de busca           | Árvore binária de busca       |
| Controle de operações      | Pilha                         |
| Armazenamento              | Sistema de arquivos           |
---

## 🛠️ Requisitos Técnicos

- Compilador C (GCC ou similar)
- Terminal compatível
- Sistema operacional com suporte a C ANSI

---

## 📂 Estrutura do Projeto

```text
📦 gerenciador-de-atendimento
├── func/                      # Arquivos de cabeçalho
│   ├── paciente.h
│   ├── queue.h
│   ├── heap.h
│   ├── stack.h
│   ├── tree.h
│   └── save.h
├── paciente.c
├── queue.c
├── heap.c
├── stack.c
├── tree.c
├── save.c
├── main.c
├── data.txt
└── README.md
```

---

## 🚀 Instalação e Execução

1. **Clone o repositório:**
```bash
git clone https://github.com/arthurleal/gerenciador-de-atendimento
cd gerenciador-de-atendimento
```

2. **Compile o projeto:**
```bash
gcc *.c -o gerenciador
```

3. **Execute o programa:**
```bash
./gerenciador
```

---

## 👨‍💻 Desenvolvimento

**Desenvolvedor:** Arthur Leal Mussio - 22.223.017-9

**Período:** 4º Semestre

**Curso:** Ciência da Computação

**Disciplina:** Estrutura de Dados

**Instituição:** Centro Universitário FEI

**Ano:** 2025