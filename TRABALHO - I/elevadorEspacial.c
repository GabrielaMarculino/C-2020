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
        printf("Digite o n�mero do andar: ");
        scanf("%d",&n);

        if((n<1)||( n>1000000)){

            printf("\nO n�mero deve ser MAIOR ou IGUAL a 1 e MENOR ou IGUAL a 10^6.\n");

        }

    }while((n<1) || (n>1000000));

    do{
        i += 1;
        j += 1;

        //SEPARA��O DOS N�MEROS.
        n7 = (j%10);
        n6 = (j/10)%10;
        n5 = (j/100)%10;
        n4 = (j/1000)%10;
        n3 = (j/10000)%10;
        n2 = (j/100000)%10;
        n1 = (j/1000000)%10;

        //VEFICA��O DO N�MERO 13.
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

        //SEPARA��O DOS N�MEROS.
        n7 = (j%10);
        n6 = (j/10)%10;
        n5 = (j/100)%10;
        n4 = (j/1000)%10;
        n3 = (j/10000)%10;
        n2 = (j/100000)%10;
        n1 = (j/1000000)%10;

        //VERIFICA��O DO N�MERO 4.
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

    //SA�DA DE DADOS...
    printf("\nO n�mero atribu�do � esse andar �: %d\n",j);
    system("pause");
    return 0;
}
