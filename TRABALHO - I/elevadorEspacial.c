#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
    Elevador Espacial
    Gabriela Marculino da Silva - RGM:41431
*/

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int n1, n2, n3, n4, n5, n6, n7, i, j, n;

    j = 0; //ANDARES
    i = 0;

    do{
        printf("Digite o número do andar: ");
        scanf("%d",&n);

        if((n<1)||( n>1000000)){

            printf("\nO número deve ser MAIOR ou IGUAL a 1 e MENOR ou IGUAL a 10^6.\n");

        }

    }while((n<1) || (n>1000000));

    do{
        i += 1;
        j += 1;

        //SEPARAÇÃO DOS NÚMEROS.
        n7 = (j%10);
        n6 = (j/10)%10;
        n5 = (j/100)%10;
        n4 = (j/1000)%10;
        n3 = (j/10000)%10;
        n2 = (j/100000)%10;
        n1 = (j/1000000)%10;

        //VEFICAÇÃO DO NÚMERO 13.
        if((n1==1) && (n2==3)){
            j += 100000;
        }
        if((n2==1) && (n3==3)){
            j += 10000;
        }
        if((n3==1) && (n4==3)){
            j += 1000;
        }
        if(( n4==1)&&(n5==3)){
            j += 100;
        }
        if((n5==1)&&(n6==3)){
            j += 10;
        }
        if((n6==1)&&(n7==3)){
            j += 1;
        }

        //SEPARAÇÃO DOS NÚMEROS.
        n7 = (j%10);
        n6 = (j/10)%10;
        n5 = (j/100)%10;
        n4 = (j/1000)%10;
        n3 = (j/10000)%10;
        n2 = (j/100000)%10;
        n1 = (j/1000000)%10;

        //VERIFICAÇÃO DO NÚMERO 4.
        if(n7==4){
            j += 1;
        }
        if(n6==4){
            j += 10;
        }
        if(n5==4){
            j += 100;
        }
        if(n4==4){
            j += 1000;
        }
        if(n3==4){
            j += 10000;
        }
        if(n2==4)
        {
            j += 100000;
        }
        if(n1==4){
            j += 1000000;
        }
    }
    while(i<n);

    //SAÍDA DE DADOS...
    printf("\nO número atribuído à esse andar é: %d\n",j);
    system("pause");
    return 0;
}
