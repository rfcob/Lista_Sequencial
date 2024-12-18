#include <stdio.h>
#include <stdlib.h>
#include "../include/ListaOrdenadaDinamica.h"
#include "ListaOrdenadaDinamica.c"



int main(){

    int valorExcluir;

    LISTA lista;
    REGISTRO reg;
    
    inicializarLista(&lista); //-------------------------------------iniciar a lista com alocação dinâmica

    preencher_lista(&lista, reg); //---------------------------------------------------------------popular

    exibirLista(&lista);//--------------------------------------------------------------------primeira vez

    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista preenchida (em bytes): %i.\n", tamanhoEmBytes(&lista));
    printf("Tamanho da lista, alocada, (em bytes): %i.\n", tamanhoEmBytesAlocado(&lista));

    while(true){//-----------------------------------para testar inlcusão e exclusão de maneira "dinamica"
        int escolha;
        printf("Digite 1 par exluir elementos ou 0 para sair:\n");
        scanf("%d", &escolha);
       if(escolha==1){
            int quantidade;
            printf("Digite quantos elementos deseja excluir: \n"); 
            
            scanf("%d", &quantidade);

            for(int k = 0; k<quantidade; k++){
                scanf("%d", &valorExcluir);
                excluirElemListaOrd(&lista, valorExcluir);
            }
        }else{
            break;
        }
    }

    exibirLista(&lista);//---------------------------------------------------------------------segunda vez

    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista, preenchida, (em bytes): %i.\n", tamanhoEmBytes(&lista));
    printf("Tamanho da lista, alocada, (em bytes): %i.\n", tamanhoEmBytesAlocado(&lista));

    printf("Primeiro elemento da lista: %i.\n", primeiroElem(&lista));
    printf("Chave 6 do elemento lista - retorna: %i.\n", enesimoElem(&lista, 6));
    printf("O numero 6 está na posicão da lista: %i.\n", buscaSequencial(&lista, 6));
    //printf("Tamanho da lista (em bytes): %i.\n", ((sizeof(LISTA) -8)- (tamListUser*4))); //Calculando o tamanho restante da lista supondo o alinhamento de 8bytes para o processador.

    free(lista.A);

    return 0;
}
