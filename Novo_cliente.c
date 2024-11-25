#include <stdio.h>
#include <stdlib.h>
#include "aloc_dinamica/ListaOrdenada.h"
#include "aloc_dinamica/ListaOrdenada.c"

int main(){

    int tamListUser, valorExcluir;

    LISTA lista;
    REGISTRO reg;
    
    inicializarLista(&lista);

    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamListUser);
    

        for (int i = 0; i < tamListUser; i++) {

            printf("Digite o valor: ");
            scanf("%d", &reg.chave);
            inserirElemListaOrd(&lista, reg);

        }

    exibirLista(&lista);

    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

    while(true){
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

    excluirElemListaOrd(&lista, valorExcluir);

    exibirLista(&lista);

    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

    printf("Primeiro elemento da lista: %i.\n", primeiroElem(&lista));

    //printf("Tamanho da lista (em bytes): %i.\n", ((sizeof(LISTA) -8)- (tamListUser*4))); //Calculando o tamanho restante da lista supondo o alinhamento de 8bytes para o processador.

    free(lista.A);

    return 0;
}
