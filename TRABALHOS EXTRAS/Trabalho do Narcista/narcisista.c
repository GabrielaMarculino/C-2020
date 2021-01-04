/*
Lincoln Amorim
Gabriela Marculino
*/
#include "myList.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int u = 0;
    int c, n, b, op, i = 0;

    inicializa();
    printf("Digite o alcance (9 <n < 1000000) \n");
    scanf("%d", &n);

    while(n < 9 || n> 1000000){
        printf("Entrada inválida, tente novamente \n");
    }

    while(i <= n){
        b = eNarcisismo(i);

        if(b == 1){

            insere(i);

            i++;
        }

        while(u != 666){
            system("Claro");

            b = 0;
            n = 0;

            printf ( " \n ----- Bem-vindo ----- \n\n ");
		    printf ( " 1- Imprimir \n ");
		    printf ( " 2- Buscar \n ");
		    printf ( " 3 - Retirar \n ");
		    printf ( " 0 - Sair \n\n ");
		    printf ( " \n ----------------- \n\n ");
		    scanf ( " % d ", &op);

            switch(op){

                case 1:

                system("Claro");
                imprime();
                printf("Digite qualquer número para sair \n");
                scanf("%d", &c);
                break;

                case 2:

                system("Claro");
                printf("Digite o número de um pedido\t");
                scanf("%d", &n);

                if(busca(n) == 1){
                    printf("O número está na estrutura");
                }else{
                    printf("O número não está na estrutura");
                }
                printf("Digite qualquer número pra sair\n");
                scanf("%d", &c);
                break;

                case 3:

                system("Claro");
                printf("Recomendada uma busca antes da extração...\n");
                printf("Digite o número do serviço desativado\t");
                scanf("%d", &c);
                break;

                case 0:
                u = 666;
                break;

            }
        }
    }
    esvazia();
}