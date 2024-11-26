# Lista_Sequencial
## Repositório para entrega atividade 1 - Estrutura de dados

- A Atividade tem como objetivo modificar uma esttura de lista sequência definida com alocação de memória estática para uma alocação dinâmica.
- 


~~~C
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
