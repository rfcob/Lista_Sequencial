// listaSequencialOrdenada.h // (indef) checa de lista_sequencial já foi defiida // defdefine a lista
#ifndef LISTA_SEQUENCIAL_ORDENADA_H 
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdio.h>
#define MAX 50
#define ERRO -1
#define bool int
#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct { //define uma lista A de 50 do tipo inteiro + 4 bytes (depende do computador) para armazenar um espaço para SENTINELA.
  REGISTRO A[MAX+1];
  int nroElem;
} LISTA;

// Declaração das funções
void inicializarLista(LISTA* l); // parece o 1 mas é um l de lista
void exibirLista(LISTA* l);
int tamanho(LISTA* l);
int tamanhoEmBytes(LISTA* l);
TIPOCHAVE primeiroElem(LISTA* l);
TIPOCHAVE ultimoElem(LISTA* l);
TIPOCHAVE enesimoElem(LISTA* l, int n);
void reinicializarLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
int buscaSentinela(LISTA* l, TIPOCHAVE ch);
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch);
int buscaBinaria(LISTA* l, TIPOCHAVE ch);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg);

#endif // LISTA_SEQUENCIAL_ORDENADA_H