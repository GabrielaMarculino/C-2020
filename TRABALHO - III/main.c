#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>
/*
    Vinicius Balbino - 43581
    Alexandre Cordeiro Arruda - 43551
    Gabriela Marculino - 41431
*/

char cpf_clientes[50][15],contaCorrente[50][10];
int saques_clientes[50][999];
int principalMenu,menuCliente,menuRelatorio; //controle dos menus
int notas[8]= {100, 200, 400, 800, 1600, 3200, 6400, 12800}; //controle de notas
int notasTotal = 100 + 200 + 400 + 800 + 1600 + 3200 + 6400 + 12800; //Controla as notas em caixa
int totalSaque = 0, caixa = 173600;
int indice = 0; // controle do cliente


//objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
//parametros: nenhum
//retorno:a letra do alfabeto
char geraAlfabeto()
{
    int i;
    char letras[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    i=rand()%26;
    return(letras[i] - 32);
}
//objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
//parametros: nenhum
//retorno:o numero
char geraNumero()
{
    int i;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i=rand()%9;
    return(numeros[i]);
}
//objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
//parametros: c onde armazera a conta gerada
//retorno:nenhum
void geraContaCorrente(char c[])
{
    int i = 0;
    char contaCorrente[10];
    for(i = 0; i < 7; i++)
    {
        if(i != 3)
        {
            contaCorrente[i] = geraNumero();
        }
        else if(i == 3)
        {
            contaCorrente[i] = '.';
        }
    }
    contaCorrente[i] = '-';
    contaCorrente[i + 1] = geraAlfabeto();

    for(int i=0; i<10; i++)
    {
        c[i] = contaCorrente[i];
    }

    printf("\nCONTA CORRENTE: %s\n",contaCorrente);


}

//objetivo: Remover a pontuacao do cpf no formato 999.999.999-99
//parametros: cpf_pontuado e onde se recebe o valor do cpf pontuado e o cpf_sem_pontuacao e a variavel que recebera o cpf sem pontuacao
//retorno:nenhum
void remove_pontuacao_cpf(char cpf_pontuado[], char cpf_sem_pontuacao[])
{
    int i, cont = 0;
    char novo_cpf[12];
    for(i = 0; i < 14; i++)
    {
        if(cont==3)
        {
            cont=4;
        }
        if(cont==7)
        {
            cont=8;
        }
        if(cont==11)
        {
            cont=12;
        }
        novo_cpf[i] = cpf_pontuado[cont];
        cont++;
    }
    novo_cpf[11]='\0';

    strncpy(cpf_sem_pontuacao, novo_cpf, sizeof(novo_cpf));
}

//objetivo:verifica se um cpf no formato 999.999.999-99 e valido
//parametros: cpf a ser verificado
//retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[])
{
    int valido = 1;
    long long int CPF;
    char cpfsemPontuacao[12];
    remove_pontuacao_cpf(cpf,cpfsemPontuacao);
    int dig[13];
    dig[11] = 0;
    dig[12] = 0;
    CPF = atoll(cpfsemPontuacao);

    if ((CPF == 00000000000)||(CPF == 11111111111)||(CPF == 22222222222)||(CPF == 33333333333)||(CPF == 44444444444)||(CPF == 55555555555)||(CPF == 66666666666)||(CPF == 77777777777)||(CPF == 88888888888)||(CPF == 99999999999))
    {
        valido = 0;
    }
    dig[10] =(CPF%10);
    dig[9] = (CPF/10)%10;
    dig[8] = (CPF/100)%10;
    dig[7] = (CPF/1000)%10;
    dig[6] = (CPF/10000)%10;
    dig[5] = (CPF/100000)%10;
    dig[4] = (CPF/1000000)%10;
    dig[3] = (CPF/10000000)%10;
    dig[2] = (CPF/100000000)%10;
    dig[1] = (CPF/1000000000)%10;
    dig[0] = (CPF/10000000000)%10;
    dig[11]= ((10 * dig[0]) + (9 * dig[1]) + (8 * dig[2]) + (7 * dig[3]) + (6 * dig[4]) + (5 * dig[5]) + (4 * dig[6]) + (3 * dig[7]) + (2 * dig[8]))% 11;
    //printf("\n%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", dig[0], dig[1], dig[2], dig[3], dig[4], dig[5], dig[6], dig[7], dig[8], dig[9], dig[10]);

    if(dig[11]<2)
    {
        dig[11]=0;
    }
    else
    {
        dig[11] = 11 - dig[11];
    }
    if(dig[11] == dig[9])
    {
        dig[12]= ((11 * dig[0]) + (10 * dig[1]) + (9 * dig[2]) + (8 * dig[3]) + (7 * dig[4]) + (6 * dig[5]) + (5 * dig[6]) + (4 * dig[7]) + (3 * dig[8]) + (2 * dig[9]))% 11;
        if(dig[12] < 2)
        {
            dig[12] = 0;
        }
        else
        {
            dig[12] = 11-dig[12];
        }
        if(dig[12] != dig[10])
            valido = 0;
    }
    else
    {
        valido = 0;
    }
    return(valido);

}

//objetivo:insere pontuacoes '.' e '-' em um cpf
//parametros: cpf_origem o cpf recebido no format 99999999999
//cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{
    int i, cont = 0;
    char teste[15];
    for(i = 0; i < 14; i++)
    {
        if(i != 3 && i != 7 && i != 11)
        {
            teste[i] = cpf_origem[cont];
            cont++;
        }
        if(i==3 || i==7)
            teste[i]='.';
        if(i==11)
            teste[i]='-';
    }
    teste[i]='\0';

    strncpy(cpf_destino,teste,sizeof(teste));

}
//objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
//parametros: cpf o cpf sem os digitos verificadores
//retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[])
{
    int digito = 0;
    int dig[10];
    long int cpf1;
    cpf1 = atol(cpf);
    for(int i = 0; i < 9; i++)
    {
        dig[i] = cpf[i] - '0';
    }

    //calculo para obter o digito verificador
    digito = ((10 * dig[0]) + (9 * dig[1]) + (8 * dig[2]) + (7 * dig[3]) + (6 * dig[4]) + (5 * dig[5]) + (4 * dig[6]) + (3 * dig[7]) + (2 * dig[8]))% 11;
    if(digito < 2)
    {
        digito = 0;
    }
    else
    {
        digito = 11 - digito;
    }

    return(digito);
}
//objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
//parametros: cpf sem os digitos verificadores
//retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[])
{

    int digito = 0;
    int dig[10];
    long long int cpf1;
    cpf1 = atoll(cpf);
    for(int i = 0; i < 10; i++)
    {
        dig[i] = cpf[i] - '0';
    }

    //calculo para obter digito verificador
    digito =((11 * dig[0]) + (10 * dig[1]) + (9 * dig[2]) + (8 * dig[3]) + (7 * dig[4]) + (6 * dig[5]) + (5 * dig[6]) + (4 * dig[7]) + (3 * dig[8]) + (2 * dig[9]))% 11;
    if(digito < 2)
    {
        digito = 0;
    }
    else
    {
        digito = 11 - digito;
    }
    return(digito);
}
//objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
//parametros: CPF onde sera armazenado o cpf valido
//retorno: nenhum
void gera_cpf_valido(char cpf[])
{
    int i;
    char cpfOrigem[12];
    char cpfPontuado[15];
    do
    {
        for(i = 0; i < 9; i++)
        {
            cpfOrigem[i] = geraNumero();
        }
        cpfOrigem[9] = '\0';
        cpfOrigem[9]= obtem_primeiro_digito_verificador(cpf) + '0';

        cpfOrigem[10] = '\0';
        cpfOrigem[10] = obtem_segundo_digito_verificador(cpf) + '0';
        cpfOrigem[11] = '\0';
        insere_pontuacao_cpf(cpfOrigem, cpfPontuado);
    }
    while(verifica_cpf_valido(cpfPontuado)!=1);
    insere_pontuacao_cpf(cpfOrigem, cpfPontuado);

    for(int i=0; i<15; i++)
    {
        cpf[i] = cpfPontuado[i];
    }

    printf("\nCPF: %s\n\n", cpfPontuado);
    printf("INCLUINDO...\n");

}
//objetivo:transforma o valor númerico em extenso
//parametros: int valor
//retorno: valor
void saqueExtenso(int valor)
{

    int e1, e2, e3, e4, e5, e6;

    e1 = (valor % 10);
    e2 = ((valor / 10) % 10);
    e3 = ((valor / 100) % 10);
    e4 = ((valor / 1000) % 10);
    e5 = ((valor / 10000) % 10);
    e6 = ((valor / 100000) % 10);

    if (e6 >= 0)
    {
        //Centena

        if ((e6 > 0) && (e5 == 0) && (e4 == 0))
        {
            printf("cem ");

        }
        else if ((e6 > 0)&& (e5 !=0) && (e4 != 0))
        {
            printf("cento e ");
        }
        else
        {
            printf("");
        }
    }
    //Milhar
    if (e5 >= 0)
    {
        if (e5 == 0)
        {
            printf("");
        }
        if ((e5 > 0) && (e4 == 0))
        {
            switch(e5)
            {
            case 9:
                printf("noventa ");
                break;
            case 8:
                printf("oitenta ");
                break;
            case 7:
                printf("setenta ");
                break;
            case 6:
                printf("sessenta ");
                break;
            case 5:
                printf("cinquenta ");
                break;
            case 4:
                printf("quarenta ");
                break;
            case 3:
                printf("trinta ");
                break;
            case 2:
                printf("vinte ");
                break;
            case 1:
                printf("dez ");
                break;
            }
        }
        else if ((e5 > 0) && (e4 > 0))
        {
            switch(e5)
            {
            case 9:
                printf("noventa e ");
                break;
            case 8:
                printf("oitenta e ");
                break;
            case 7:
                printf("setenta e ");
                break;
            case 6:
                printf("sessenta e ");
                break;
            case 5:
                printf("cinquenta e ");
                break;
            case 4:
                printf("quarenta e ");
                break;
            case 3:
                printf("trinta e ");
                break;
            case 2:
                printf("vinte e ");
                break;
            case 1:
                if (e4 > 5)
                {
                    printf("dez");
                }
                else if (e4 == 5)
                {
                    printf("quinze ");
                }
                else if (e4 == 4)
                {
                    printf("quatorze ");
                }
                else if (e4 == 3)
                {
                    printf("treze ");
                }
                else if (e4 == 2)
                {
                    printf("doze ");
                }
                else if (e4 == 1)
                {
                    printf("onze ");
                }
                else
                {
                    printf("dez ");
                }
                break;
            }
        }
    }
    //Unidade
    if (e4 >= 0)
    {
        if (e4 == 0)
        {
            printf("");
        }
        if ((e4 > 0) && (e5 == 1))
        {
            switch(e4)
            {
            case 9:
                printf("e nove ");
                break;
            case 8:
                printf("e oito ");
                break;
            case 7:
                printf("e sete ");
                break;
            case 6:
                printf("e seis ");
                break;
            case 5:
                printf("");
                break;
            case 4:
                printf("");
                break;
            case 3:
                printf("");
                break;
            case 2:
                printf("");
                break;
            case 1:
                printf("");
                break;
            }
        }
        else if (e4 > 0 )
        {
            switch(e4)
            {
            case 9:
                printf("nove ");
                break;
            case 8:
                printf("oito ");
                break;
            case 7:
                printf("sete ");
                break;
            case 6:
                printf("seis ");
                break;
            case 5:
                printf("cinco ");
                break;
            case 4:
                printf("quatro ");
                break;
            case 3:
                printf("três ");
                break;
            case 2:
                printf("dois ");
                break;
            case 1:
                printf("um ");
                break;
            }
        }
    }
    if (((e3 == 0 )&&(e2 == 0 ))&&((e1 == 0)&&(e6 > 0))||((e5 > 0 )||(e4 > 0))) //possibilidades de acontecer numeros "Truncados"
    {
        printf("mil ");
    }
    else
    {
        printf("");
    }//FIM DO MILHAR


    //Centena
    if (e3 >= 0)
    {
        if (e3 == 0)
        {
            printf("");
        }
        if ((e3 > 0) && (e2 == 0) && (e1 == 0))
        {
            switch(e3)
            {
            case 9:
                printf("novecentos ");
                break;
            case 8:
                printf("oitocentos ");
                break;
            case 7:
                printf("setecentos ");
                break;
            case 6:
                printf("seiscentos ");
                break;
            case 5:
                printf("quinhentos ");
                break;
            case 4:
                printf("quatrocentos ");
                break;
            case 3:
                printf("trezentos ");
                break;
            case 2:
                printf("duzentos ");
                break;
            case 1:
                printf("cem ");
                break;
            }
        }
        if (((e3 > 0) && (e2 > 0)) || (e1 >0))
        {
            switch(e3)
            {
            case 9:
                printf("novecentos e ");
                break;
            case 8:
                printf("oitocentos e ");
                break;
            case 7:
                printf("setecentos e ");
                break;
            case 6:
                printf("seiscentos e ");
                break;
            case 5:
                printf("quinhentos e ");
                break;
            case 4:
                printf("quatrocentos e ");
                break;
            case 3:
                printf("trezentos e ");
                break;
            case 2:
                printf("duzentos e ");
                break;
            case 1:
                printf("cento e ");
                break;
            }
        }
    }
    //Dezena
    if (e2 >= 0)
    {
        if (e2 == 0)
        {
            printf("");
        }
        if ((e2 > 0) && (e1 == 0))
        {
            switch (e2)
            {
            case 9:
                printf("noventa ");
                break;
            case 8:
                printf("oitenta ");
                break;
            case 7:
                printf("setenta ");
                break;
            case 6:
                printf("sessenta ");
                break;
            case 5:
                printf("cinquenta ");
                break;
            case 4:
                printf("quarenta ");
                break;
            case 3:
                printf("trinta ");
                break;
            case 2:
                printf("vinte ");
                break;
            case 1:
                printf("dez ");
                break;
            }
        }
        else if ((e2 > 0) && (e1 > 0))
        {
            switch (e2)
            {
            case 9:
                printf("noventa e ");
                break;
            case 8:
                printf("oitenta e ");
                break;
            case 7:
                printf("setenta e ");
                break;
            case 6:
                printf("sessenta e ");
                break;
            case 5:
                printf("cinquenta e ");
                break;
            case 4:
                printf("quarenta e ");
                break;
            case 3:
                printf("trinta e ");
                break;
            case 2:
                printf("vinte e ");
                break;
            case 1:
                if (e1 > 5)
                {
                    printf("dez");
                }
                else if (e1 == 5)
                {
                    printf("quinze ");
                }
                else if (e1 == 4)
                {
                    printf("quatorze ");
                }
                else if (e1 == 3)
                {
                    printf("treze ");
                }
                else if (e1 == 2)
                {
                    printf("doze ");
                }
                else if (e1 == 1)
                {
                    printf("onze ");
                }
                else
                {
                    printf("dez ");
                }
                break;
            }
        }
        //Unidade
        if (e1 >= 0)
        {
            if (e1 == 0)
            {
                printf("");
            }
            if (e1 > 0 && e2 == 1)
            {
                switch (e1)
                {
                case 9:
                    printf("e nove ");
                    break;
                case 8:
                    printf("e oito ");
                    break;
                case 7:
                    printf("e sete ");
                    break;
                case 6:
                    printf("e seis ");
                    break;
                case 5:
                    printf("");
                    break;
                case 4:
                    printf("");
                    break;
                case 3:
                    printf("");
                    break;
                case 2:
                    printf("");
                    break;
                case 1:
                    printf("");
                    break;
                }
            }
            else if (e1 > 0)
            {
                switch (e1)
                {
                case 9:
                    printf("nove ");
                    break;
                case 8:
                    printf("oito ");
                    break;
                case 7:
                    printf("sete ");
                    break;
                case 6:
                    printf("seis ");
                    break;
                case 5:
                    printf("cinco ");
                    break;
                case 4:
                    printf("quatro ");
                    break;
                case 3:
                    printf("três ");
                    break;
                case 2:
                    printf("dois ");
                    break;
                case 1:
                    printf("um ");
                    break;
                }
            }
        }
    }
}
//objetivo: realiza o saque do cliente
//parametros: nenhum
//retorno: valor do saque
void saques_cliente()
{
    //Lendo a conta para ver se existe
    char contaLida[10];
    int contaExiste = 0, result, valorSaque, saquePendente, indiceDeSaque;
    int i=0;
    do
    {
        printf("Insira a conta corrente no formato (999.999-X):\n");
        scanf("%9s", contaLida);

        do
        {
            result = strcmp(contaLida, contaCorrente[i]);
            if(result == 0)
            {
                contaExiste = 1;
                indiceDeSaque = i;
            }
            i++;
        }while(result !=0 && i<indice);

        if(contaExiste == 0){
          printf("Conta não encontrada. Insira uma conta válida\n");
          i=0;
        }

    }while(contaExiste != 1);

    printf("Insira o valor de saque: ");
    scanf("%d",&valorSaque);

    while(valorSaque < 1)
    {
        printf("O valor do saque não pode ser menor que 1 real. Informe novamente:\n");
        scanf("%d",&valorSaque);
    }
    int flag = 1;
    for(int i=0; i<999; i++)
    {
        if(!saques_clientes[indiceDeSaque][i] > 0){
            if(flag){
              saques_clientes[indiceDeSaque][i] = valorSaque;
              flag = 0;
            }
        }
    }
    printf("\n");
    saqueExtenso(valorSaque);
    printf(" reais");
    printf("\n");

    saquePendente = valorSaque;
    caixa = caixa - valorSaque;
    //Controle de notas
    controle_notas(saquePendente);
    system("pause");
    system("cls");
}

//objetivo: faz o controle de notas do caixa eletrônico
//parametros: saque
//retorno: nenhum
void controle_notas(int saque)
{
    int saquePendente = saque;
    int cedulas[8];
    for(int i=0;i<8;i++) cedulas[i]=0;
    //Controle de notas
    while ((notas[0] > 0) && (saquePendente >= 500))
    {
        saquePendente -= 500;
        notas[0] -= 1;
        notasTotal -= 1;
        totalSaque += 500;
        caixa -= 500;
        cedulas[0] = cedulas[0] + 1;
    }

    while ((notas[1] > 0) && (saquePendente >= 150))
    {
        saquePendente -= 150;
        notas[1] -= 1;
        notasTotal -= 1;
        totalSaque += 150;
        caixa -= 150;
        cedulas[1] = cedulas[1] + 1;
    }

    while ((notas[2] > 0) && (saquePendente >= 50))
    {
        saquePendente -= 50;
        notas[2] -= 1;
        notasTotal -= 1;
        totalSaque += 50;
        caixa -= 50;
        cedulas[2] = cedulas[2] + 1;
    }

    while ((notas[3] > 0) && (saquePendente >= 20))
    {
        saquePendente -= 20;
        notas[3] -= 1;
        notasTotal -= 1;
        totalSaque += 20;
        caixa -= 20;
        cedulas[3] = cedulas[3] + 1;
    }

    while ((notas[4] > 0) && (saquePendente >= 10))
    {
        saquePendente -= 10;
        notas[4] -= 1;
        notasTotal -= 1;
        totalSaque += 10;
        caixa -= 10;
        cedulas[4] = cedulas[4] + 1;
    }

    while ((notas[5] > 0) && (saquePendente >= 5))
    {
        saquePendente -= 5;
        notas[5] -= 1;
        notasTotal -= 1;
        totalSaque += 5;
        caixa -= 5;
        cedulas[5] = cedulas[5] + 1;
    }

    while ((notas[6] > 0) && (saquePendente >= 2))
    {
        saquePendente -= 2;
        notas[6] -= 1;
        notasTotal -= 1;
        totalSaque += 2;
        caixa -= 2;
        cedulas[6] = cedulas[6] + 1;
    }

    while ((notas[7] > 0) && (saquePendente >= 1))
    {
        saquePendente -= 1;
        notas[7] -= 1;
        notasTotal -= 1;
        totalSaque += 1;
        caixa -= 1;
        cedulas[7] = cedulas[7] + 1;
    }
    printf("\n");
    if(cedulas[0]>0) printf("Cedulas de 500: %d\n\n", cedulas[0]);
    if(cedulas[1]>0) printf("Cedulas de 150: %d\n\n", cedulas[1]);
    if(cedulas[2]>0) printf("Cedulas de 50: %d\n\n", cedulas[2]);
    if(cedulas[3]>0) printf("Cedulas de 20: %d\n\n", cedulas[3]);
    if(cedulas[4]>0) printf("Cedulas de 10: %d\n\n", cedulas[4]);
    if(cedulas[5]>0) printf("Cedulas de 5: %d\n\n", cedulas[5]);
    if(cedulas[6]>0) printf("Cedulas de 2: %d\n\n", cedulas[6]);
    if(cedulas[7]>0) printf("Cedulas de 1: %d\n\n", cedulas[7]);
}

//objetivo: tratamento para realizar a exclusão do cliente
//parametros: posicao
//retorno:a nenhum
void excluiCliente(int posicao)
{
    for(int i=0; i<9; i++)
    {
        contaCorrente[posicao][i] = '0';
    }
    for(int i=0; i<14; i++)
    {
        cpf_clientes[posicao][i] = '0';
    }
    contaCorrente[posicao][9] = '\0';
    cpf_clientes[posicao][14] = '\0';
}

//objetivo: permite editar a conta corrente e o cpf do cliente
//parametros: posicao, newCpf, newContaCorrente
//retorno: nenhum
void editarCliente(int posicao, char newCpf[], char newContaCorrente[])
{
    if(newCpf != '0')
    {
        for(int i=0; i<14; i++)
        {
            cpf_clientes[posicao][i] = newCpf[i];
        }
        cpf_clientes[posicao][14] = '\0';
    }
    if(newContaCorrente != '0')
    {
        for(int i=0; i<9; i++)
        {
            contaCorrente[posicao][i] = newContaCorrente[i];
        }
        contaCorrente[posicao][9] = '\0';
    }
    printf("\nConta alterada com sucesso\n");
}

//objetivo: permite excluir/inválidar o cliente, trocando seus dados funcionais por "0000"
//parametros: nenhum
//retorno:a nenhum
void apagarCliente()
{
    char numeroConta[10];

    int j=0;
    int result;
    do
    {
        printf("Informe o número da conta corrente a ser excluída (no formato 999.999-X) ou digite * para voltar\n");
        scanf("%9s",numeroConta);
        if(numeroConta[0] == '*')
        {
            printf("\nVoltando...\n");
        }
        else
        {
            do
            {
                result = strcmp(contaCorrente[j], numeroConta);
                j=j+1;
            }
            while((result != 0) && (j < indice));
            if((result != 0) && (j == indice))
            {
                printf("\nConta não encontrada");
            }
            if((result == 0)&&(saques_clientes[j][0] == 0))
            {
                excluiCliente(j);
                indice = indice-1;
                printf("\n\nConta excluída\n");
            }
            if((result == 0)&&(saques_clientes[j][0] > 0))
            {
                printf("\n\nConta não pode ser alterada pois já efetuou saque\n\n");
            }
        }
    }
    while(numeroConta[0] != '*');
    system("pause");
}
//objetivo: altera os dados do cliente deifinitivamente
//parametros: nenhum
//retorno: novo cpf ou conta conta corrente
void alterarCliente()
{

    char numeroConta[10];
    int opAlt, result, result1;
    char newCpf[12];
    char newContaCorrente[15];
    int j=0;
    int posicao, posicao1;

    do
    {
        printf("Informe o número da conta corrente (no formato 999.999-X) ou digite * para voltar\n");
        scanf("%9s",numeroConta);
        if(numeroConta[0] == '*')
        {
            printf("\nVoltando...\n");
        }
        else
        {
            do
            {
                result = strcmp(contaCorrente[j], numeroConta);
                if(result == 0)
                {
                    posicao = j;
                }
                j++;
            }
            while((result != 0) && (j < indice));
            if((result != 0) && (j == indice))
            {
                printf("\nConta não encontrada\n");
            }
            if((result == 0)&&(saques_clientes[posicao][0] == 0))
            {
                printf("\nO que deseja alterar CPF(digite 1) ou Conta Corrente(digite 0) se quiser voltar(digite 2)\n");
                scanf("%d", &opAlt);
                if(opAlt == 1)
                {
                    do
                    {
                        do
                        {
                            printf("Insira o novo CPF (no formato 999.999.999-99)\n");
                            scanf("%15s", newCpf);
                        }
                        while(verifica_cpf_valido(newCpf)!=1);
                        result1 = strcmp(cpf_clientes[j], newCpf);
                    }
                    while( result1 == 0 );
                    if(verifica_cpf_valido(newCpf)==1)
                    {
                        editarCliente(posicao, newCpf, '0');
                    }
                }
                else if(opAlt ==0)
                {
                    printf("\nInsira a nova conta corrente (no formato 999.999-X)\n");
                    scanf("%9s", newContaCorrente);
                    j=0;
                    do
                    {
                        result1 = strcmp(contaCorrente[j], newContaCorrente);
                        if(result == 0)
                        {
                            posicao1 = j;
                        }
                        j=j+1;
                    }
                    while((result1 != 0) && (j < indice));
                    if((result1 == 0)&&(saques_clientes[posicao1][0] == 0))
                    {
                        printf("\nInsira novamente pois ja existe essa conta corrente no sistema\n\n");
                        do
                        {
                            printf("\nInsira a nova conta corrente (no formato 999.999-X)\n");
                            scanf("%9s", newContaCorrente);
                            result1 = 1;
                            for(int i=0; i<indice; i++)
                            {
                                if((strcmp(contaCorrente[i], newContaCorrente)) == 0)
                                {
                                    result1 = strcmp(contaCorrente[i], newContaCorrente);
                                }
                            }
                            if(result1 == 0)
                            {
                                printf("\nInsira novamente pois tambem existe essa conta no sistema\n");
                            }
                        }
                        while(result1 == 0);
                        editarCliente(posicao, '0', newContaCorrente);
                    }
                    if((result1 != 0)&& (saques_clientes[posicao][0] == 0))
                    {
                        editarCliente(posicao, '0', newContaCorrente);
                    }
                }
                else if(opAlt!=2)
                {
                    printf("\nOpção Invalida!!\n");
                }
            }
            if((result == 0)&&(saques_clientes[j][0] > 0))
            {
                printf("\n\nConta não pode ser alterada pois já efetuou saque\n\n");
            }
        }
    }
    while(numeroConta[0] != '*');


    system("pause");
}

//objetivo: mostra o extrato de todos os valores sacados de cada cliente
//parametros: nenhum
//retorno: nenhum
void valores_sacados()
{

    int totalSaque=0;
    int totalCliente =0;
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("RELATÓRIO 'VALORES SACADOS'\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < indice; i++){
        printf("\n%s \t %s \t ", contaCorrente[i], cpf_clientes[i]);
        for(int j=0; j<999; j++){
          if(saques_clientes[i][j] != 0){
            if(j==0){
             printf("\t R$ %d\n", saques_clientes[i][j]);
             totalSaque = totalSaque + saques_clientes[i][j];
             totalCliente = totalCliente + saques_clientes[i][j];
            }else{
              printf("\t \t \t \t \t \t R$ %d\n", saques_clientes[i][j]);
              totalSaque = totalSaque + saques_clientes[i][j];
              totalCliente = totalCliente + saques_clientes[i][j];
            }
          }
        }
        printf("\t \t \t \t \t \t \t \t R$ %d", totalCliente);
        totalCliente=0;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("R$ %ld \t", totalSaque);
    saqueExtenso(totalSaque);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

}

//objetivo: mostra o extrato do saldo existente no caica eletrônico
//parametros: nenhum
//retorno: nenhum
void saldo_existente()
{
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("RELATÓRIO 'VALOR DO SALDO EXISTENTE'\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\nR$ %d    ", caixa);
    saqueExtenso(caixa);
    printf(" reais\n");
    system("pause");
}

//objetivo: mostra o extrato das cédulas do caixa eletrônico
//parametros: nenhum
//retorno:a nenhum
void cedulas_existentes()
{
    system("pause");
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("RELATÓRIOS 'QUANTIDADE DE CÉDULAS EXISTENTES'\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\nNOTA DE 500: %d ",notas[0]);
    saqueExtenso(notas[0]);
    printf("\nNOTA DE 150: %d ",notas[1]);
    saqueExtenso(notas[1]);
    printf("\nNOTA DE 50:  %d ",notas[2]);
    saqueExtenso(notas[2]);
    printf("\nNOTA DE 20:  %d ",notas[3]);
    saqueExtenso(notas[3]);
    printf("\nNOTA DE 10:  %d ",notas[4]);
    saqueExtenso(notas[4]);
    printf("\nNOTA DE 5:   %d ",notas[5]);
    saqueExtenso(notas[5]);
    printf("\nNOTA DE 2:   %d ",notas[6]);
    saqueExtenso(notas[6]);
    printf("\nNOTA DE 1:   %d ",notas[7]);
    saqueExtenso(notas[7]);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

//objetivo: função principal que inclui o cliente, gerando automaticamente um cpf e uma conta corrente
//parametros: nenhum
//retorno: nenhum
void incluir()
{

    if(indice<50)
    {
        geraContaCorrente(contaCorrente[indice]);
        gera_cpf_valido(cpf_clientes[indice]);
        indice++;
    }
    else
    {
        printf("Já existe o maximo de clientes cadastrados");
    }
}
//objetivo: imprimi todos os clientes inclusos no sistema
//parametros: nenhum
//retorno: nenhum
void mostrar()
{
    for(int j = 0; j < indice; j++)
    {
        printf("\nA conta corrente inclusa do %d° cliente é: %s", (j+1), contaCorrente[j]);
        printf("\nO CPF incluso do cliente %d é: %s \n\n", (j+1),cpf_clientes[j]);
        printf("_____________________________________________________\n\n");
    }
}

//objetivo: Mostrar todo a parte visual de menu do sistema
//parametros: nenhum
//retorno: nenhum
void menuPrincipal()
{

    do
    {
        printf("MENU PRINCIPAL\n\n");
        printf("1- CLIENTE\n");
        printf("2- SAQUE\n");
        printf("3- RELATÓRIOS\n");
        printf("4- FINALIZAR\n\n");
        printf("Digite o nº da opção que deseja: \n");

        scanf("%d",&principalMenu);

        switch(principalMenu)
        {

        case 1:
            do
            {
                system("cls");
                printf("Você escolheu a opção CLIENTE\n\n");

                printf("MENU CLIENTE\n\n");
                printf("1- INCLUIR\n");
                printf("2- MOSTRAR\n");
                printf("3- ALTERAR\n");
                printf("4- EXCLUIR\n");
                printf("5- VOLTAR\n\n");
                printf("Digite o nº da opção que deseja: \n");

                scanf("%d",&menuCliente);

                switch(menuCliente)
                {

                case 1:
                    printf("Você escolheu a opção INCLUIR\n\n");
                    incluir();
                    system("pause");
                    break;
                case 2:
                    printf("Você escolheu a opção MOSTRAR\n\n");
                    system("cls");
                    mostrar();
                    system("pause");
                    break;
                case 3:
                    printf("Você escolheu a opção ALTERAR\n\n");
                    alterarCliente();
                    system("cls");
                    break;
                case 4:
                    printf("Você escolheu a opção EXCLUIR\n\n");
                    apagarCliente();
                    break;
                case 5:
                    system("cls");
                    printf("Você escolheu a opção VOLTAR\n");
                    break;
                default:
                    printf("Opção inválida");
                    break;
                }
            }
            while(menuCliente != 5);

            break;
        case 2:
            printf("Você escolheu a opção SAQUE\n");
            saques_cliente();
            break;
        case 3:
            system("cls");
            printf("Você escolheu a opção RELATÓRIOS\n\n");

            printf("MENU RELATÓRIOS\n\n");
            printf("1- VALORES SACADOS\n");
            printf("2- VALOR DO SALDO EXISTENTE\n");
            printf("3- QUANTIDADE DE CÉDULAS EXISTENTES\n");
            printf("4- VOLTAR AO MENU PRINCIPAL\n\n");
            printf("Digite o nº da opção que deseja: \n");

            scanf("%d",&menuRelatorio);

            switch(menuRelatorio)
            {

            case 1:
                printf("Você escolheu a opção VALORES SACADOS\n\n");
                system("cls");
                valores_sacados();
                break;
            case 2:
                printf("Você escolheu a opção VALOR DO SALDO EXISTENTE\n\n");
                saldo_existente();
                break;
            case 3:
                printf("Você escolheu a opção QUANTIDADE DE CÉDULAS EXISTENTES\n\n");
                system("cls");
                cedulas_existentes();
                break;
            case 4:
                system("cls");
                printf("Você escolheu a opção VOLTAR AO MENU PRINCIPAL\n\n");
                break;
            default:
                printf("Opção inválida");
                break;
            }
            break;
        case 4:
            printf("Você escolheu a opção FINALIZAR\n");
            break;
        default:
            printf("Opção inválida");
            break;
        }
    }
    while(principalMenu != 4);

}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    for(int i=0;i<50;i++){
      for(int j=0;j<999;j++){
        saques_clientes[i][j] = 0;
      }
    }
    menuPrincipal();
    return 0;
}
