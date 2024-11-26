# Lista_Sequencial

## Repositório para entrega atividade 1 - Estrutura de dados 

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

- A Atividade tem como objetivo modificar uma esttura de lista sequência definida com alocação de memória estática para uma alocação dinâmica.

**O arquivo ListaOrdenadaDinamica contem uma definição para máximo (MAX=10). Isso está assim para fins de teste, uma vez que o usuário isere manualmente os dados, caso desejar, modifique esse valor**


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
 - A Alocação dinâmica foi feita então seguindo essa escolha como mostra o recorte abaixo:

~~~C
// Inicialização da lista sequencial dinâmica (apontada pelo endereço em l)|||||||||||||
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

- Para exemplificar, em um outro caso, poderíamos ter feito a escolha:

~~~C

struct cadastro_funcionario {
    char nome[50];
    int idade;
    float salario;
}Funcionario;

int main() {
    int q = 50; //Podemos modificar o tamanho para quantos funcionário queremos. Podemos colocar na header.
    struct Funcionario *PtrFUncionario;
    PtrFUncionario = (Funcionario*)malloc(q * sizeof(Funcionario));
.
.
.

~~~
### Implementação:

- Para realizar a implementação foi criada uma função para  inicializar a lista de maneira dinâmica.
- Feita uma modificação na exibir lista, usando a comparação com o tamanho alocado e com o numero de elementos da lista.
- Uma função preencher foi adicionada ao .h para que o cliente não precise realizar essa operação
- duas funções, para alocar e realocar espaço foram criadas. Para expandiar (realocLista) e para diminur (dasalocLista)
- Uma pequanda modificação se tornou necessária para exiber o tamanho da lista em bytes com as realocaçõe.

  
~~~C
  void inicializarLista(LISTA* l);
  void exibirLista(LISTA* l);
  void preencher_lista(LISTA* l, REGISTRO reg);
  void realocLista(LISTA *l)
  void desalocLista(LISTA *l)
  int tamanhoEmBytes(LISTA* l)
~~~

- As demais funções foram testadas e não apresentaram necessidade de modificações até a atual data 11/24

### Considerações:

- Mesmo havendo formas mais simples e mais diretas, a escolha levou a essas modificações e construções. A opção foi começar a recriar todas as funções e conforme se desenvolveu o trabalho foi-se percebendo as semelhanças e diferenças. Isso permitiu  visualizar de forma mais ampla onde devería ser alterado o codigo ( inicialmente com alocação estática) para servir para a dinâmica



