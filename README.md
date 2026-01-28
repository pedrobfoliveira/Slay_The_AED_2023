# Projeto Slay the AED 🎴⚔️

Projeto desenvolvido em equipe como **trabalho semestral da disciplina de Algoritmos e Estruturas de Dados (AED)**.

O jogo é inspirado no estilo do **Slay the Spire**, utilizando mecânicas de combate por turnos, cartas e progressão por fases, com foco principal na **aplicação prática de estruturas de dados** em linguagem **C/C++**.

---

## 👥 Integrantes do Grupo

- João Vitor Cardoso
- Milton Kiefer
- Pedro Oliveira
- Pedro Henrique Fonseca

---

## 🧠 Objetivo do Projeto

O objetivo principal do projeto foi aplicar, de forma integrada, os conceitos de estruturas de dados estudados em aula, utilizando um jogo como contexto para tornar a implementação mais prática e intuitiva.

O foco do trabalho está na lógica, organização e uso correto das estruturas, e não em aspectos gráficos.

---

## 🕹️ Descrição Geral do Jogo

O jogo simula um sistema de combate inspirado em *Slay the Spire*, no qual o jogador enfrenta monstros ao longo de fases, utilizando cartas e recursos estratégicos.

Durante o jogo, são utilizados diferentes tipos de estruturas de dados para gerenciar:
- cartas
- monstros
- combates
- fases
- registros de execução

---

## 🧩 Estruturas de Dados Utilizadas

Ao longo do projeto, foram utilizadas diversas estruturas de dados, incluindo:

- Pilhas
- Filas
- Listas Encadeadas
  - Lista simplesmente encadeada
  - Lista duplamente encadeada
- Estruturas baseadas em `struct`
- Arquivos para registro de informações do jogo

Essas estruturas são aplicadas em diferentes partes da lógica do jogo, como controle de cartas, ordem de combate e progressão.

---

## 🗂️ Estrutura do Projeto

Projeto Slay the AED 2023.2/

├── abstrato.h

├── cartas.h

├── combate.h

├── fila.h

├── filamonstro.h

├── listade.h

├── listase.h

├── mapa.h

├── monstros.h

├── pilha.h

├── struct.h

├── Trabalho Semestral AED - 03.cpp

├── registro_combate.txt

├── registro_fase.txt

└── Trabalho Semestral AED - 03.exe

- Os arquivos `.h` contêm as definições das estruturas e funções.
- O arquivo `.cpp` contém a lógica principal do programa.
- Os arquivos `.txt` armazenam registros da execução.
- O executável é gerado a partir da compilação do código-fonte.

---

## ▶️ Como Executar o Projeto

### Pré-requisitos
- Compilador **C++** (ex: `g++`)
- Sistema operacional compatível com execução em console

### Compilação
```bash
g++ "Trabalho Semestral AED - 03.cpp" -o slay_aed


