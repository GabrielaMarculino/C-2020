#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
    M�quina de Caf�
    Gabriela Marculino da Silva - RGM:41431
*/
int main()
{
    setlocale(LC_ALL,"Portuguese");

    int primeiroAndar,segundoAndar,terceiroAndar,totalDeMinutos;

    //INICIALIZA��O DAS VARI�VEIS
    primeiroAndar = 0;
    segundoAndar = 0;
    terceiroAndar = 0;

    printf("Digite a quantidade de pessoas do 1� andar: \n");
    scanf("%d",&primeiroAndar);

    printf("Digite a quantidade de pessoas do 2� andar: \n");
    scanf("%d",&segundoAndar);

    printf("Digite a quantidade de pessoas do 3� andar: \n");
    scanf("%d",&terceiroAndar);

    if((primeiroAndar<0) || (primeiroAndar>1000) || (segundoAndar<0) || (segundoAndar>1000) || (terceiroAndar<0) || (terceiroAndar>1000)){

        printf("N�o � poss�vel realizar a an�lise, pois n�o pode haver n�mero negativo ou acima de 1000.");

    }
    else{

        if((primeiroAndar==terceiroAndar) && (segundoAndar==0)){

            totalDeMinutos = (primeiroAndar + terceiroAndar) * 2;
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("M�quina localizada no(s) andar(es): 1 OU 2 OU 3");

        }
        else if((primeiroAndar>segundoAndar) && (primeiroAndar>terceiroAndar)){

            totalDeMinutos = ((segundoAndar * 2) + (terceiroAndar * 4));
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("M�quina localizada no(s) andar(es): 1 OU 2");

        }
        else if((segundoAndar>primeiroAndar) && (segundoAndar>terceiroAndar)){

            totalDeMinutos = ((primeiroAndar * 2) + (terceiroAndar * 2));
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("M�quina localizada no(s) andar(es): 2");

        }
        else if((terceiroAndar>primeiroAndar) && (terceiroAndar>segundoAndar)){

            totalDeMinutos = ((primeiroAndar * 4) + (segundoAndar * 2));
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("M�quina localizada no(s) andar(es): 2 OU 3");

        }
    }
    return 0;
}
