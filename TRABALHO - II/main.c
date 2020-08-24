#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <locale.h>

int main()
{
    /*Trabalho 2 - Banco
     Gabriela Marculino da Silva RGM: 41431
     Alexandre Cordeiro RGM: 43551
     Pedro Henrique RGM: 43575
    */
    setlocale(LC_ALL,"Portuguese");

    int menuPrincipal = 0, menuGerente = 0, menuAbastecerCaixa = 0, sair = 0;
    int valorSaque = 0, saquePendente = 0, totalSaque = 0, caixa = 0;
    int verificador1 = 0,verificador2 = 0,spf = 0,valSpf = 0;
    int notas450 = 0, notas250 = 0, notas50 = 0, notas20 = 0, notas10 = 0, notas5 = 0, notas2 = 0, notas1 = 0, notasTotal = 0; //Controle de notas
    int notasAbastecer = 0, diferenca = 0;
    long long  cpf = 0,n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n10 = 0, n11 = 0;  //Números para CPF
    int e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0, e6 = 0; //Controle para números extensos


    do
    {
        printf("---- MENU PRINCIPAL ----\n\n");
        printf("1 - SAQUE\n");
        printf("2 - GERENTE\n");
        printf("3 - FINALIZAR PROGRAMA\n\n");

        printf("Digite o n° da opção que deseja:\n");
        scanf("%d",&menuPrincipal);

        switch(menuPrincipal)

        {
        //início do MENU PRINCIPAL

        case 1:
            printf("VOCÊ ESCOLHEU A OPÇÃO DE SAQUE\n");
            system("pause");
            system("cls");

            printf("DIGITE SEU CPF:\n");
            scanf("%lld",&cpf);

            //Validação de CPF

            n1 = cpf / 10000000000;
            n2 = (cpf / 1000000000) % 10;
            n3 = (cpf / 100000000) % 10;
            n4 = (cpf / 10000000) % 10; //separacao dos numeros
            n5 = (cpf / 1000000) % 10;
            n6 = (cpf / 100000) % 10;
            n7 = (cpf / 10000) % 10;
            n8 = (cpf / 1000) % 10;
            n9 = (cpf / 100) % 10;
            n10 = (cpf / 10) % 10;
            n11 = cpf % 10;

            if ((cpf == 11111111111) || (cpf == 22222222222) || (cpf == 33333333333) || (cpf == 44444444444) || (cpf == 55555555555) || (cpf == 66666666666) || (cpf == 77777777777) || (cpf == 88888888888) || (cpf == 99999999999))
            {
                printf("CPF inválido, números repetidos!\n");
                system("pause");
            }
            else
            {

                verificador1 = ((n1 * 10) + (n2 * 9) + (n3 * 8) + (n4 * 7) + (n5 * 6) + (n6 * 5) + (n7 * 4) + (n8 * 3) + (n9 * 2)) % 11;

                if (verificador1 < 2)
                {
                    verificador1 = 0;
                }
                else
                {
                    verificador1 = 11 - verificador1;
                }

                verificador2 = ((n1 * 11) + (n2 * 10) + (n3 * 9) + (n4 * 8) + (n5 * 7) + (n6 * 6) + (n7 * 5) + (n8 * 4) + (n9 * 3) + (verificador1 * 2)) % 11;

                if (verificador2 < 2)
                {
                    verificador2 = 0;

                }
                else
                {
                    verificador2 = 11 - verificador2;
                }
                //Verificacao SPF
                spf = (n10 * 10) + n11;
                valSpf = (10 * verificador1) + verificador2;

                if (spf != valSpf)
                {
                    printf("CPF inválido! Tente novamente.\n");
                    system("pause");

                }
                else
                {

                    system("cls"); //Para limpar a tela
                    printf("Olá, cliente!\n\n");

                    printf("Informe o valor do saque:\n\n");
                    scanf("%d",&valorSaque);

                    while(valorSaque < 1)
                    {
                        printf("O valor do saque não pode ser menor que 1 real. Informe novamente:\n");
                        scanf("%d",&valorSaque);
                    }

                    saquePendente = valorSaque;

                    //Controle de notas
                    while ((notas450 > 0) && (saquePendente >= 450))
                    {
                        saquePendente -= 450;
                        notas450 -= 1;
                        notasTotal -= 1;
                        totalSaque += 450;
                        caixa -= 450;
                    }

                    while ((notas250 > 0) && (saquePendente >= 250))
                    {
                        saquePendente -= 250;
                        notas250 -= 1;
                        notasTotal -= 1;
                        totalSaque += 250;
                        caixa -= 250;
                    }

                    while ((notas50 > 0) && (saquePendente >= 50))
                    {
                        saquePendente -= 50;
                        notas50 -= 1;
                        notasTotal -= 1;
                        totalSaque += 50;
                        caixa -= 50;
                    }

                    while ((notas20 > 0) && (saquePendente >= 20))
                    {
                        saquePendente -= 20;
                        notas20 -= 1;
                        notasTotal -= 1;
                        totalSaque += 20;
                        caixa -= 20;
                    }

                    while ((notas10 > 0) && (saquePendente >= 10))
                    {
                        saquePendente -= 10;
                        notas10 -= 1;
                        notasTotal -= 1;
                        totalSaque += 10;
                        caixa -= 10;
                    }

                    while ((notas5 > 0) && (saquePendente >= 5))
                    {
                        saquePendente -= 5;
                        notas5 -= 1;
                        notasTotal -= 1;
                        totalSaque += 5;
                        caixa -= 5;
                    }

                    while ((notas2 > 0) && (saquePendente >= 2))
                    {
                        saquePendente -= 2;
                        notas2 -= 1;
                        notasTotal -= 1;
                        totalSaque += 2;
                        caixa -= 2;
                    }

                    while ((notas1 > 0) && (saquePendente >= 1))
                    {
                        saquePendente -= 1;
                        notas1 -= 1;
                        notasTotal -= 1;
                        totalSaque += 1;
                        caixa -= 1;
                    }
                    if(saquePendente > 0)
                    {
                        valorSaque = valorSaque - saquePendente; //Deve abastecer as notas antes de ocorrer o saque
                        printf("Nao é possível sacar o valor de R$ %d! O caixa ainda não foi abastecido.\n\n",saquePendente);
                    }


                    e1 = (caixa % 10);
                    e2 = ((caixa / 10) % 10);
                    e3 = ((caixa / 100) % 10);
                    e4 = ((caixa / 1000) % 10);
                    e5 = ((caixa / 10000) % 10);
                    e6 = ((caixa / 100000) % 10);



                    system("cls");

                    if (notasTotal == 1)
                    {
                        printf("nota.\n");
                    }
                    else if (notasTotal == 0)
                    {
                        printf("\nNão há notas no caixa.\n");
                    }
                    else
                    {
                        printf("\nNOTAS NO CAIXA\n");
                    }

                    printf("\nNotas de 450: %d\n",notas450);
                    printf("\nNotas de 250: %d\n",notas250);
                    printf("\nNotas de 50: %d\n",notas50);
                    printf("\nNotas de 20: %d\n",notas20); //Quantidade de notas disponíveis
                    printf("\nNotas de 10: %d\n",notas10);
                    printf("\nNotas de 5: %d\n",notas5);
                    printf("\nNotas de 2: %d\n",notas2);
                    printf("\nNotas de 1: %d\n",notas1);

                    //Separacao de números para defini - los como extenso
                    e1 = (valorSaque % 10);
                    e2 = ((valorSaque / 10) % 10);
                    e3 = ((valorSaque / 100) % 10);
                    e4 = ((valorSaque / 1000) % 10);
                    e5 = ((valorSaque / 10000) % 10);
                    e6 = ((valorSaque / 100000) % 10);



                    if (valorSaque !=0)
                    {
                        printf("\nO saque foi realizado com sucesso! E o valor que será sacado é de ");
                    }


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
                            switch(e2)
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
                        else if ((e2 > 0 )&& (e1 > 0))
                        {
                            switch(e2)
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
                                switch(e1)
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
                            else if (e1 > 0 )
                            {
                                switch(e1)
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
                    if (valorSaque == 1)
                    {
                        printf("real\n");
                    }
                    else if (valorSaque == 0)   //Caso não haja notas pra sacar
                    {
                        printf("Nao foi possível sacar o dinheiro. Tente novamente mais tarde.\n");
                    }
                    else
                    {
                        printf("reais\n");
                    }
                    break;
                    system("pause");
                case 2:
                    system("cls");

                    do
                    {
                        printf("---- MENU DO GERENTE ----\n\n");
                        printf("1 - VALOR TOTAL SACADO\n");
                        printf("2 - VALOR DO SALDO EXISTENTE\n");
                        printf("3 - QUANTIDADE DE CÉDULAS EXISTENTES\n");
                        printf("4 - ABASTECER O CAIXA ELETRÔNICO\n");
                        printf("5 - VOLTAR AO MENU PRINCIPAL\n\n");

                        printf("Digite o n° da opção que deseja:\n");
                        scanf("%d",&menuGerente);


                        switch(menuGerente)

                        {
                        //Começo do MENU DO GERENTE

                        case 1:
                            printf("Você escolheu a opção VALOR TOTAL SACADO");
                            system("cls");

                            printf("O valor total sacado foi R$ %d \n",valorSaque);

                            e1 = (valorSaque % 10);
                            e2 = ((valorSaque / 10) % 10);
                            e3 = ((valorSaque / 100) % 10);
                            e4 = ((valorSaque / 1000) % 10);
                            e5 = ((valorSaque / 10000) % 10);
                            e6 = ((valorSaque / 100000) % 10);

                            if (totalSaque != 0)
                            {
                                printf("Foi sacado ");
                            }
                            else
                            {
                                printf("Ainda não foi realizado nenhum saque.\n\n");
                            }
                            if (e6 >= 0)
                            {
                                //centena

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
                            //Dezena de milhar
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
                            //Unidade de milhar
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
                            if (((e3 == 0 )&& (e2 == 0 ))&& ((e1 == 0) && (e6 > 0)) || ((e5 > 0 )|| (e4 > 0))) //possibilidades de acontecer numeros "Truncados"
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
                                    switch(e2)
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
                                else if ((e2 > 0 )&& (e1 > 0))
                                {
                                    switch(e2)
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
                                        switch(e1)
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
                                    else if (e1 > 0 )
                                    {
                                        switch(e1)
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

                            if (notasTotal == 1)
                            {
                                printf("nota.\n");
                            }
                            else if (notasTotal == 0)
                            {
                                printf("\nNao há notas no caixa.\n\n");
                            }
                            else
                            {
                                printf("\n\nNOTAS NO CAIXA\n");
                            }

                            printf("\nNotas de 450: %d\n",notas450);
                            printf("\nNotas de 250: %d\n",notas250);
                            printf("\nNotas de 50: %d\n",notas50);
                            printf("\nNotas de 20: %d\n",notas20); //Quantidade de notas disponíveis
                            printf("\nNotas de 10: %d\n",notas10);
                            printf("\nNotas de 5: %d\n",notas5);
                            printf("\nNotas de 2: %d\n",notas2);
                            printf("\nNotas de 1: %d\n",notas1);

                            system("pause");

                            break;
                        case 2:
                            printf("Você escolheu a opção VALOR DO SALDO EXISTENTE");
                            system("cls");

                            printf("\nO valor total existente é R$ %d \n",caixa);

                            e1 = (caixa % 10);
                            e2 = ((caixa / 10) % 10);
                            e3 = ((caixa / 100) % 10);
                            e4 = ((caixa / 1000) % 10);
                            e5 = ((caixa / 10000) % 10);
                            e6 = ((caixa / 100000) % 10);

                            if (caixa !=0)
                            {
                                printf("Há dinheiro no caixa no valor de ");
                            }


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


                            //Dezena de milhar
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
                            //Unidade de milhar
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
                            if (((e3 == 0 )&& (e2 == 0 ))&& ((e1 == 0) && (e6 > 0)) || ((e5 > 0 )|| (e4 > 0)))
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
                                    switch(e2)
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
                                else if ((e2 > 0 )&& (e1 > 0))
                                {
                                    switch(e2)
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
                                        switch(e1)
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
                                    else if (e1 > 0 )
                                    {
                                        switch(e1)
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
                                            printf("três");
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
                                if (caixa == 1)
                                {
                                    printf("real no caixa.\n");
                                }
                                else if (caixa == 0)
                                {
                                    printf("Não há mais dinheiro no caixa, logo zero reais.\n");
                                }
                                else
                                {
                                    printf("reais no caixa.\n");
                                }
                                system("pause");

                                break;

                            case 3:
                                printf("Você escolheu a opção QUANTIDADE DE CÉDULAS EXISTENTES");
                                system("cls");

                                printf("Existem um total de %d notas.\n",notasTotal);

                                e1 = (notasTotal % 10);
                                e2 = ((notasTotal / 10) % 10);
                                e3 = ((notasTotal / 100) % 10);
                                e4 = ((notasTotal / 1000) % 10);
                                e5 = ((notasTotal / 10000) % 10);
                                e6 = ((notasTotal / 100000) % 10);

                                if (notasTotal != 0)
                                {
                                    printf("Há ");
                                }
                                else
                                {
                                    printf("");
                                }
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
                            //Dezena de milhar
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

                            //Unidade de milhar
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
                            if (((e3 == 0 )&& (e2 == 0 ))&& ((e1 == 0) && (e6 > 0)) || ((e5 > 0 )|| (e4 > 0)))
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
                                    switch(e2)
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
                                else if ((e2 > 0 )&& (e1 > 0))
                                {
                                    switch(e2)
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
                                        switch(e1)
                                        {
                                        case 9:
                                            printf("e nove ");
                                            break;
                                        case 8:
                                            printf("e oito ");
                                            break;
                                        case 7:
                                            printf("e ssete ");
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
                                    else if (e1 > 0 )
                                    {
                                        switch(e1)
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
                                if(notasTotal == 0)
                                {
                                    printf("Não há notas no caixa.\n\n");

                                }
                                else if (notasTotal == 1)
                                {
                                    printf("nota.\n");
                                }
                                else
                                {
                                    printf("notas no caixa\n");
                                }

                                printf("Quantidade de notas: \n\n");

                                printf("\nDe 450: %d\n",notas450);
                                printf("\nDe 250: %d\n",notas250);
                                printf("\nDe 50: %d\n",notas50);
                                printf("\nDe 20: %d\n",notas20); //Controle de notas
                                printf("\nDe 10: %d\n",notas10);
                                printf("\nDe 5: %d\n",notas5);
                                printf("\nDe 2: %d\n",notas2);
                                printf("\nDe 1: %d\n",notas1);

                                system("pause");

                                break;
                            case 4:
                                printf("Você escolheu a opção ABASTECER O CAIXA ELETRONICO");
                                system("cls");

                                printf("---- MENU ABASTECER CAIXA ELETRONICO ----\n\n");
                                printf("450 - NOTAS DE 450\n");
                                printf("250 - NOTAS DE 250\n");
                                printf("50 - NOTAS DE 50\n");
                                printf("20 - NOTAS DE 20\n");
                                printf("10 - NOTAS DE 10\n");
                                printf("5 - NOTAS DE 5\n");
                                printf("2 - NOTAS DE 2\n");
                                printf("1 - NOTAS DE 1\n\n");
                                printf("0 - VOLTAR AO MENU GERENTE\n\n");

                                printf("Digite o n° da opção que deseja:\n");
                                scanf("%d",&menuAbastecerCaixa);
                                {
                                    switch(menuAbastecerCaixa)
                                    {

                                    case 450:

                                        printf("Você escolheu abastecer as notas de 450 reais\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas deseja abastecer: \n");
                                        scanf("%d",&notasAbastecer);


                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas450 += notasAbastecer;
                                        while(notas450 > 100)
                                        {
                                            diferenca = notas450 - 100;
                                            printf("\nAs notas de R$ 450,00 não podem ultrapassar de 100! Informe um número que não ultrapasse de %d notas\n",diferenca);
                                            notas450 = notas450 - notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 450);
                                        notasTotal = notasTotal + notasAbastecer;

                                        printf("\nO dinheiro total que há no caixa é: R$ %d \n",caixa);
                                        system("pause");
                                        break;

                                    case 250:
                                        printf("Você escolheu abastecer as notas de 250 reais");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer:\n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas250 += notasAbastecer;

                                        while(notas250 > 200)
                                        {
                                            diferenca = notas250 - 200;
                                            printf("\nAs notas de R$ 250,00 não podem ultrapassar de 200! Informe um número que não ultrapasse de %d notas\n",diferenca);
                                            notas250 -= notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 250);
                                        notasTotal += notasAbastecer;

                                        printf("\nO dinheiro total que há no caixa é: R$ %d \n",caixa);
                                        system("pause");
                                        break;


                                    case 50:
                                        printf("Você escolheu abastecer as notas de 50 reais.\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer: \n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas50 += notasAbastecer;
                                        while(notas50 > 400)
                                        {
                                            diferenca = notas50 - 400;
                                            printf("As notas de R$ 50,00 não podem ultrapassar de 400! Informe um número que não ultrapasse de %d notas: \n",diferenca);
                                            notas50 -= notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 50);
                                        notasTotal += notasAbastecer;

                                        printf("O dinheiro total que há no caixa é: R$ %d \n\n",caixa);
                                        system("pause");
                                        break;

                                    case 20:
                                        printf("Você escolheu abastecer as notas de 20 reais.\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer: \n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas20 += notasAbastecer;
                                        while(notas20 > 800)
                                        {
                                            diferenca = notas20 - 800;
                                            printf("As notas de R$ 20,00 não podem ultrapassar de 800! Informe um número que não ultrapasse de %d notas:\n\n",diferenca);
                                            notas20 -= notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 20);
                                        notasTotal += notasAbastecer;

                                        printf("O dinheiro total que há no caixa á: R$ %d \n\n",caixa);
                                        system("pause");
                                        break;

                                    case 10:
                                        printf("Você escolheu abastecer as notas de 10 reais.\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer:\n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas10 += notasAbastecer;
                                        while(notas10 > 1600)
                                        {
                                            diferenca = notas10 - 1600;
                                            printf("As notas de R$ 10,00 não podem ultrapassar de 1600! Informe um número que não ultrapasse de %d notas:\n\n",diferenca);
                                            notas10 -= notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 10);
                                        notasTotal += notasAbastecer;

                                        printf("O dinheiro total que há no caixa é: R$ %d \n\n",caixa);
                                        system("pause");
                                        break;


                                    case 5:
                                        printf("Você escolheu abastecer as notas de 5 reais.\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer:\n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas5 += notasAbastecer;
                                        while(notas5 > 3200)
                                        {
                                            diferenca = notas5 - 3200;
                                            printf("As notas de R$ 5,00 não podem ultrapassar de 3200! Informe um número que não ultrapasse de %d notas\n\n",diferenca);
                                            notas5 -= notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 5);
                                        notasTotal += notasAbastecer;

                                        printf("\nO dinheiro total que há no caixa é: R$ %d \n",caixa);
                                        system("pause");
                                        break;

                                    case 2:
                                        printf("Você escolheu abastecer as notas de 2 reais.\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer:\n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente Novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas2 += notasAbastecer;
                                        while(notas2 > 6400)
                                        {
                                            diferenca = notas2 - 6400;
                                            printf("As notas de R$ 2,00 não podem ultrapassar de 6400! Informe um número que não ultrapasse de %d notas:\n\n",diferenca);
                                            notas2 = notas2 - notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 2);
                                        notasTotal += notasAbastecer;

                                        printf("O dinheiro total que há no caixa é: R$ %d \n\n",caixa);
                                        system("pause");
                                        break;


                                    case 1:
                                        printf("Você escolheu abastecer as notas de 1 real.\n");
                                        system("cls");

                                        printf("Informe a quantidade de notas que deseja abastecer:\n");
                                        scanf("%d",&notasAbastecer);

                                        if (notasAbastecer == 0)
                                        {
                                            break;
                                        }
                                        while (notasAbastecer < 0)
                                        {
                                            printf("Quantidade de notas inválidas.Tente novamente:\n");
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }
                                        notas1 = notas1 + notasAbastecer;
                                        while(notas1 > 12800)
                                        {
                                            diferenca = notas1 - 12800;
                                            printf("nAs notas de R$ 1,00 não podem ultrapassar de 12800! Informe um número que não ultrapasse de %d notas:\n\n",diferenca);
                                            notas1 = notas1 - notasAbastecer;
                                            scanf("%d",&notasAbastecer);

                                            if (notasAbastecer == 0)
                                            {
                                                break;
                                            }
                                        }

                                        caixa = caixa + (notasAbastecer * 1);
                                        notasTotal += notasAbastecer;

                                        printf("O dinheiro total que há no caixa é: R$ %d \n\n",caixa);
                                        system("pause");
                                        break;



                                    case 0:
                                        printf("Você escolheu voltar ao MENU GERENTE.\n");
                                        system("cls");
                                        break;

                                    }
                                }


                            case 5:

                                printf("Você escolheu a opção VOLTAR AO MENU PRINCIPAL");
                                system("cls");
                                break;

                            default:
                                system("cls");
                                printf("Opção inválida\n\n");
                                break;


                            } //FINAL DO IF QUE VALIDA A DEZENA

                        }//FIM DO MENU GERENTE

                    }
                    while(menuGerente != 5);
                    break;

                case 3:
                    printf("Você decidiu FINALIZAR O PROGRAMA");
                    sair = 3;
                    break;

                default:

                    printf("Opção inválida.\n");
                    system("cls");
                    break;

                }//FIM DO MENU PRINCIPAL
            }
        } //FINAL DO ELSE QUE VALIDA SEU CPF E PERMITE REALIZAR AS OUTRAS
    }//DO-MENU PRINCIPAL
    while(sair != 3); //DO - WHILE DO MENU PRINCIPAL

    return 0;
}
