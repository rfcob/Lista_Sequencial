# Lista_Sequencial
## Repositório para entrega atividade 1 - Estrutura de dados

- A Atividade tem como objetivo modificar uma esttura de lista sequência definida com alocação de memória estática para uma alocação dinâmica.
- 

### Escolhas:

-  Uma struc do tipo inteiro, a tipo chave no qual definimos uma lista do tipo registo, mas com A como um ponteiro *A. Como tinhamos que dimensionar/alocar dinâmicamente um estrutua do tipo inteiro, como um array, essa escolha pareceu mais natural. Se tivessemos um cadasto do tipo cliente, com telefone, nome, etc, chamar apontar a própria struct com alocação dinâmica poderia ser mais interessante.


~~~C

  // Uma struc do tipo inteiro, a tipo chave no qual definimos uma lista do tipo registo, mas com A como um ponteiro *A
  
  typedef int TIPOCHAVE;

  typedef struct {
      TIPOCHAVE chave;
      // outros campos...
    } REGISTRO;

  typedef struct {
      REGISTRO *A;
      int nroElem;
      int alocacao;
    } LISTA;
~~~
 - A Alocação dinâmica foi feita então:

~~~C
// Inicialização da lista sequencial dinâmica (apontada pelo endereço em l)||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  void inicializarLista(LISTA* l){
      l->A = (REGISTRO*)malloc(MAX * sizeof(REGISTRO));

      if (l->A == NULL) {
      printf("Erro ao alocar memória\n");
      exit(1);
      }

      l->nroElem = 0;
      l->alocacao = MAX; 
  }
~~~
