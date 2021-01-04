#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int  main ( int argc, char  const * argv []) {
	int medidas [1000], l = 1 , mediamaior [1000], mediamenor [1000], intervalo, i = 0 , j = 1 , k = 0 , mediaMaior = - 999999999 , mediaMenor = 999999999 , divisao, cont_medidas, contteste = 0 , soma = 0 , aux = 1 ;
	do {
		system("cls");
		printf("Informe as variáveis ​​foram tiradas. \n");
		scanf("%d", &cont_medidas);
		while(cont_medidas < 0 || cont_medidas> 800){
			printf("Dado invalido, tente novamente \n");
			scanf("%d",&cont_medidas);
		}
		printf("Relatório o intervalo entre as medidas \n ");
		scanf("%d", &intervalo);
		while(intervalo < 0 || intervalo> 800 || intervalo> cont_medidas) {
			printf("Dado invalido, tente novamente \n");
			scanf ("%d", &intervalo);
		}
		if(cont_medidas == 0 && intervalo == 0 ) {
			goto fim;
		}
		contteste ++; // Contador de testes tem que estar aqui por enquanto para antes do teste acontecer
	    for (i = 1 ; i <cont_medidas + 1 ; i++) { // le o o das medidas
	    	printf ("Informe a % d medida tirada \n" , i);
	    	scanf ("%d" , &medidas [i]);
	    	/*while ((cont_medidas [i] < 200 )|| (medidas [i]> 200 )) {
	    		printf ( " Dado invalido, tente novamente \ n " );
	    		scanf ( " % d " , & medidas [i]);
	    	}*/
            if(i >= intervalo) {
	    		for (k = 1 ; k <= intervalo; k ++) {
		    		    soma = soma + medidas [j]; // soma os valores do intervalo
		    		    j ++; // aumenta o indice minimo
		    		}
		    		divisao = (soma / intervalo);
		    		if (divisao> mediaMaior) {
		    			mediaMaior = divisao;
		    		}
		    		if (divisao <mediaMenor) {
		    			mediaMenor = divisao;
		    		}
		    		soma = 0 ;
			        j = j - intervalo + 1 ;
			}
		}
		mediamenor [l] = mediaMaior;
		mediamaior [l] = mediamMenor;
		l ++;
		j = 1 ; // retorna o indice minimo
		mediaMaior = - 999999999 ; // reseta as media kk
		mediaMenor = 999999999 ;
		system ( " pause " );
	} while ((cont_medidas! = 0 ) && (intervalo! = 0 ));
   // fim: // do jeito que fiz o setup ele so ferificaria depois que o loop terminasse, foi necessaria a adicao do goto
    for ( int i = 1 ; i <= contteste; i++) {
    	printf ( " Teste % d \ n " , i);
        printf ( " % d  " , mediamaior [i]);
        printf ( " % d \ n " , mediamenor [i]);
    }
    system ( " pause " );
	return  0 ;
}
