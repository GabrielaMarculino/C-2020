#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
    Folha de Pagamentos
    Gabriela Marculino da Silva - RGM:41431
*/
int main()
{
    setlocale(LC_ALL,"Portuguese");

    int m, n, ii, i;
    int soma = 0;

    printf("C�LCULO DE SAL�RIO DOS FUNCION�RIOS\n\n");
    printf("Digite a quantidade de funcionarios:\n\n");
    scanf("%d",&m);

    while((m<1) || (m>10000)){
        printf("\nERRO, Por favor entre com um valor que atenda a exig�ncia  1 <= N <= 10^4 \n\n");
        printf("\nEntre com a quantidade de funcion�rios:\n\n");
        scanf("%d",&m);
    }

    for(ii=1; ii<=m; ii++){

        printf("Entre com o n�mero de matr�cula do funcion�rio:\n\n");
        scanf("%d",&n);

        while((n<1) || (n>30000)){
            printf("\nERRO, Por favor digite um valor que atenda a exig�ncia 1 <= N <= 3*10^4 \n\n");
            printf("\nEntre com o numero de matricula do funcionario:\n\n ");
            scanf("%d",&n);
        }

        for(i=1; i<=n; i++){

            if(n % i == 0){
                soma += i;
            }
        }
        printf("O sal�rio �: %d \n\n",soma);
        soma = 0;
    }
    return 0;
}
