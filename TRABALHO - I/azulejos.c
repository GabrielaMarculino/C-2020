#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
    Azulejos
    Gabriela Marculino da Silva - RGM:41431
*/

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int n, a, b, i, pint;

    n = 0;
    a = 0;
    b = 0;
    pint = 0;

    printf("\nDefine quantos azulejos serão pintados com base nos múltiplos de A e B\n\n");
    printf("\nDefina o total de azulejos:\n\n");
    scanf("%d",&n);

    while((n<3) || (n>10000)){
        printf("\nErro, N deve atender 3 <= N <= 10000: \n\n");
        scanf("%d", &n);
    }

    printf("\nDefina A:\n\n ");
    scanf("%d",&a);

    while(a<2){
        printf("\nErro, A deve atender 2 <= A:\n\n ");
        scanf("%d",&a);
    }

        printf("\nDefina B:\n\n ");
        scanf("%d",&b);

    while(b>n){
        printf("\nErro, B deve atender B <= N:\n\n ");
        scanf("%d",&b);
    }

    for (i=1; i<=n; i++){
        if ((i % a == 0) || (i % b == 0)){
            pint += 1;
        }
    }
    printf("\nSerão pintados %d azulejos",pint);
    return 0;
}
