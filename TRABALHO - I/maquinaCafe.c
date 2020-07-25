#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
    Máquina de Café
    Gabriela Marculino da Silva - RGM:41431
*/
int main()
{
    setlocale(LC_ALL,"Portuguese");

    int primeiroAndar,segundoAndar,terceiroAndar,totalDeMinutos;

    //INICIALIZAÇÃO DAS VARIÁVEIS
    primeiroAndar = 0;
    segundoAndar = 0;
    terceiroAndar = 0;

    printf("Digite a quantidade de pessoas do 1º andar: \n");
    scanf("%d",&primeiroAndar);

    printf("Digite a quantidade de pessoas do 2º andar: \n");
    scanf("%d",&segundoAndar);

    printf("Digite a quantidade de pessoas do 3º andar: \n");
    scanf("%d",&terceiroAndar);

    if((primeiroAndar<0) || (primeiroAndar>1000) || (segundoAndar<0) || (segundoAndar>1000) || (terceiroAndar<0) || (terceiroAndar>1000)){

        printf("Não é possível realizar a análise, pois não pode haver número negativo ou acima de 1000.");

    }
    else{

        if((primeiroAndar==terceiroAndar) && (segundoAndar==0)){

            totalDeMinutos = (primeiroAndar + terceiroAndar) * 2;
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("Máquina localizada no(s) andar(es): 1 OU 2 OU 3");

        }
        else if((primeiroAndar>segundoAndar) && (primeiroAndar>terceiroAndar)){

            totalDeMinutos = ((segundoAndar * 2) + (terceiroAndar * 4));
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("Máquina localizada no(s) andar(es): 1 OU 2");

        }
        else if((segundoAndar>primeiroAndar) && (segundoAndar>terceiroAndar)){

            totalDeMinutos = ((primeiroAndar * 2) + (terceiroAndar * 2));
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("Máquina localizada no(s) andar(es): 2");

        }
        else if((terceiroAndar>primeiroAndar) && (terceiroAndar>segundoAndar)){

            totalDeMinutos = ((primeiroAndar * 4) + (segundoAndar * 2));
            printf("TEMPO: %d\n",totalDeMinutos);
            printf("Máquina localizada no(s) andar(es): 2 OU 3");

        }
    }
    return 0;
}
