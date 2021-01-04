//Trabalho 3 - Vampiros
//Alunos:
//Lincoln Amorim, RGM: 41443
//Gabriela Marculino, RGM: 41431
//Leonardo Henrique, RGM: 41440

#include <stdio.h>
#include <stdlib.h>

//declaração das variáveis
int bat[100];
int ev1;
int ev2;
int at;
int d;
int t;
int pause;
int tamanho;
int comb;
int duel = 1;
int dado;
int i;
int fim = 1;

//módulo de execução da batalha
int batalha(int ev1, int ev2, int at, int d, int t){
    printf("EV1     EV2     AT      D       T       DADO        VENCEDOR\n");
    printf("%d       %d       %d       %d       %d       \n", ev1, ev2, at, d, t);
        do{
            dado = (rand()%5)+1; //dado aleatório de 1 a 6

            //critério para definir o vencedor de cada turno
            if (dado<=at){
                ev1 = ev1+d;
                ev2 = ev2-d;
                printf("%d       %d       %d       %d       %d       %d           VAMPIRO 1\n", ev1, ev2, at, d, duel, dado);
            }else{
                ev2 = ev2+d;
                ev1 = ev1-d;
                printf("%d       %d       %d       %d       %d       %d           VAMPIRO 2\n", ev1, ev2, at, d, duel, dado);
            }

            //critério para definir o vencedor antes do final dos turnos
            if (ev1<=0){
                return(2);
            }
            if (ev2<=0){
                return(1);
            }
            duel = duel+1;
        }while(duel<=t);

        //critério para definir o vencedor no final dos turnos
        if (ev1<ev2){
           return (2);
        }
        if(ev2<ev1){
            return(1);
        }

        //caso não entre em nenhum critério será definido como empate
        return (0);
}


int main(){
    srand(time(NULL));  //zerando o "time" do dado

    //entrada dos valores
    printf("\nDefina os valores do combate:\n");
    i=0;  //contador do próximo "do"
    do{
        i = i+1;
        scanf("%d", &bat[i]);
        if (i>1){
            if (bat[i]==0){
                if (bat[i-1]==0){
                    fim=0;
                }
            }
        }
        tamanho = i-1;
    }while(fim!=0);

    //transforma o tamanho do vetor num inteiro múltiplo de 6
    tamanho = (tamanho/6)*6;

    i=1;  //contador do próximo "do"
    do{
        //definindo o valor das variáveis
        ev1 = bat[i];
        ev2 = bat[i+1];
        at = bat[i+2];
        d = bat[i+3];
        t = bat[i+4];
        pause = bat[i+5];
        printf("\n");

        //restrições de valores
        if ((ev1<1)||(ev2>10)||(at<1)||(at>5)||(d<1)||(d>10)||(t<1)||(t>100)||(pause!=0)){
            printf("valor invalido, duelo cancelado\n");
        }else{
            //caso os valores estejam corretos, chamada do módulo "batalha"
            comb = batalha(ev1, ev2, at, d, t);
            //teste do vencedor e saída
            if (comb==1){
                printf("Vitoria Vampiro 1!\n");
            }
            if (comb==2){
                printf("Vitoria Vampiro 2!\n");
            }
            if (comb==0){
                printf("Empate!\n");
            }
        }
        i=i+6;
    }while(i<=tamanho);

   return 0;
}