// ListaOrdenada.c
#include "ListaOrdenada.h"


// Inicialização da lista sequencial dinâmica (apontada pelo endereço em l)_____

  void inicializarLista(LISTA* l){
      l->A = (REGISTRO*)malloc(MAX * sizeof(REGISTRO));

      if (l->A == NULL) {
      printf("Erro ao alocar memória\n");
      exit(1);
      }

      l->nroElem = 0;
      l->alocacao = MAX; 
  }

//Realocar espaço caso necessário________________________________________________
  void realocLista(LISTA *l) {

    l->alocacao *= 2;

    l->A = (REGISTRO*) realloc(l->A, l->alocacao * sizeof(REGISTRO));

    if (l->A == NULL){
      printf("Erro ao alocar memória\n");
      exit(1);
  }

}

// Exibir________________________________________________________________________

  void exibirLista(LISTA* l){
      printf("Lista: \" ");

      for (int i=0; i < l->nroElem; i++){
        printf("%i ", l->A[i].chave);
      }
      printf("\"\n");
  } 

// Retornar o tamanho da lista (numero de elementos "validos")___________________

  int tamanho(LISTA* l){
    return l->nroElem;
  } 


//* Retornar o tamanho da lista em bytes_________________________________________ 
  int tamanhoEmBytes(LISTA* l) {
    return l->nroElem * sizeof(REGISTRO);
  } 



/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} /* primeiroElem */

/* Retornar a chave do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} /* ultimoElem */

/* Retornar a chave do elemento que está na posição n da LISTA. Lembre-se que as posicoes do
   arranjo A vao de 0 a MAX-1  */
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

/* Reinicializar a estrutura */
void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
} /* reinicializarLista */


/* Busca sequencial em lista ordenada ou não SEM SENTINELA */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem){
    if(ch == l->A[i].chave) return i; // achou
    else i++;
  }
  return ERRO; // não achou
} /* buscaSequencial */


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições) */
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // não achou
  else return i;
} /* buscaSentinela */

/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições) 
   considerando o arranjo ordenado */
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave < ch) i++;
  if (i == l->nroElem || l->A[i].chave != ch) return ERRO; // não achou
  else return i;
} /* buscaSentinela */

/* Busca binaria em lista ordenada */
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem-1;
  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->A[meio].chave == ch) return meio; // achou
    else {
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return ERRO;
} /* buscaBinaria */


/* Exclusão do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // não existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemLista */


/* Exclusão do elemento cuja chave seja igual a ch em lista ordenada*/
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaBinaria(l,ch);
  if(pos == ERRO) return false; // não existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemListaOrd */


/* Inserção em lista ordenada usando busca binária permitindo duplicação */
/*bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos = l->nroElem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
} /* inserirElemListaOrd */

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    // Verificar se é necessário realocar a lista
    if (l->nroElem >= l->alocacao) {
        realocLista(l); // Realoca a lista se atingir a capacidade
    }

    int pos = l->nroElem;
    while (pos > 0 && l->A[pos - 1].chave > reg.chave) {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
    return true;
} /* inserirElemListaOrd */




/* Inserção em lista ordenada usando busca binária sem duplicação */
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos;
  pos = buscaBinaria(l,reg.chave);
  if(pos != ERRO) return false; // elemento já existe
  pos = l->nroElem-1;
  while(pos>0 && l->A[pos].chave > reg.chave) {
    l->A[pos+1] = l->A[pos];
    pos--;
  }
  l->A[pos+1] = reg;
  l->nroElem++;
  return true;
} /* inserirElemListaOrd */


