#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"

int main(){

    int tamListUser;

    LISTA lista;
    REGISTRO reg;
    
    inicializarLista(&lista);

    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamListUser);
    

        for (int i = 0; i < tamListUser; i++) {
           /* if (i>= lista.alocacao){
                realocLista(&lista);
            }*/
            printf("Digite o valor: ");
            scanf("%d", &reg.chave);
            inserirElemListaOrd(&lista, reg);
            //lista.nroElem+=1;
        }


    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
 //   printf("Tamanho da lista (em bytes): %i.\n", ((sizeof(LISTA) -8)- (tamListUser*4))); //Calculando o tamanho restante da lista supondo o alinhamento de 8bytes para o processador.


    free(lista.A);
    return 0;
}
