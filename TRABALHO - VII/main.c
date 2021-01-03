#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
    Gabriela Marculino RGM: 41431
    Vinicius Balbino RGM: 43581
    Alexandre Arruda RGM: 43551
*/
void flush_in()
{
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n' ) {}
}

int menuPrincipal()
{
    int opcao;

    system("cls");

    printf("1 - Decifra arquivo\n");
    printf("2 - Grava número linha em arquivo\n");
    printf("3 - Quantas linhas o arquivo tem?\n");
    printf("4 - Qual a maior linha?\n");
    printf("5 - Pesquisar uma palavra\n");
    printf("0 - Encerrar\n");
    printf("Informe a opcao:\n");

    scanf("%d",&opcao);
    flush_in();

    return opcao;
}

void decifraArquivo()
{
    char caracter, numberAscii[4], repAscii;
    int repInt, i, j;
    i = 0; // variavel controladora para o numberAscii

    FILE *arqCodificado, *arqDecifrado;
    arqCodificado = fopen("readme.code.txt","r+");
    arqDecifrado = fopen("readme.decifrado.txt","w");
    numberAscii[3] = '\0';// colocando o \0 para que a memoria não fique suja

    if ((arqCodificado == NULL) || (arqDecifrado == NULL))
    {
        printf("Algo deu errado ao abrir os arquivos\n\n");
        exit(0);
    }
    else
    {
        printf("ARQUIVO DECIFRADO.\n");
    }
    //Inicializando o numberAscii para recebe-lo
    for(j = 0; j < 4; j++)
    {
        numberAscii[j] = 0;
    }

    do
    {
        fread(&caracter,1,1,arqCodificado);

        if((caracter != '[') && (caracter != ']'))
        {
            numberAscii[i] = caracter;
            i = i +1;
        }
        else if(caracter == ']')
        {
            //printf("Buffer: %c %c %c \t",numberAscii[0], numberAscii[1], numberAscii[2]);
            //system("pause");
            //trasformarção dos char para inteiro e depois trasformando eles em ascii e salvando no arquivo decifrado
            repInt = atoi(numberAscii);
            repAscii = (char)repInt;
            i=0;
            fprintf(arqDecifrado,"%c", repAscii);
            //Se caso precisar printar o arquivo logo depois de descripitrografar so descomentar a linha abaixo
            //printf("%c", repAscii);
            //reinicializa para o proximo o numberAscii
            for(j= 0; j < 4; j++)
            {
                numberAscii[j] = 0;
            }
        }

    }
    while((!feof(arqCodificado)));
    system("pause");
    fclose(arqCodificado);
    fclose(arqDecifrado);

}

void procurarPalavra()
{

    char search[100];
    char line[1000],str[70];
    int done = 0;
    int i = 0,cont = 0;

    FILE *fl = fopen("readme.nlines.txt", "r");

    if (fl == NULL)
    {
        printf("O arquivo ainda não foi criado\n");
        exit(0);
    }
    else
    {

        printf("Digite a palavra que você deseja pesquisar: ");
        fgets(search, 100, stdin);
        search[strlen(search) -1] = 0;

        while(!feof(fl))
        {
            if(fgets(str, 70, fl) != NULL)
            {
                if(strstr(str,search) != NULL)
                {
                    cont++;
                    printf("%s",str);
                }
            }
        }
        printf("\ne tem %d ocorrencias.\n\n",cont);

        /*printf("\nAs linhas em que a palavra \"%s\" ocorre:\n\n", search);

        do{
        fgets(line, 1000, fl);i++;


        if(strstr(line, search) != NULL){
            printf("[linha: %d] %s", i, line);
            done = 1;
        }
        }
        while(!feof(fl));
        if(done == 0)
            printf("Nao foi encontrada a string");*/
    }


    fclose(fl);
    system("pause");
}

void maiorLinha()
{
    int linha = 0, maiorLinha = 0, maiorCarac = 0, tamanhoLinha = 0;
    char carac;

    FILE *arqLinha = fopen("readme.decifrado.txt","r+");

    if(arqLinha == NULL)
    {

        printf("FALHA AO ABRIR O ARQUIVO. \n");
    }
    else
    {

        while(fscanf(arqLinha,"%c",&carac) != EOF)
        {

            tamanhoLinha++;

            if(carac == '\n')
            {

                linha++;

                if(tamanhoLinha > maiorCarac)
                {
                    maiorCarac = tamanhoLinha;
                    maiorLinha = linha;
                }
                tamanhoLinha = 0;
            }
        }
        printf("A linha [%d] é a maior com (%d) caracteres.\n\n",maiorLinha, maiorCarac);
    }
    fclose(arqLinha);
    system("pause");

}

void inseriLinhasTexto()
{
    char linhaTexto[150], linhaCompleta[200];

    FILE *arqNlinhas, *arqDecifrado;

    arqDecifrado = fopen("readme.decifrado.txt","r+");
    arqNlinhas = fopen("readme.nlines.txt","w");

    if ( arqDecifrado == NULL || arqNlinhas == NULL )
    {
        printf("Algo deu errado ao abrir os arquivos");
        system("pause");
    }
    else
    {
        int i = 1; //Linha
        do
        {
            fgets(linhaTexto, 150, arqDecifrado);
            sprintf(linhaCompleta, "[linha:%d]%s", i,linhaTexto);
            fprintf(arqNlinhas, "%s", linhaCompleta);
            i++;
        }
        while(!feof(arqDecifrado));

        printf("NÚMEROS GRAVADOS NO ARQUIVO\n");
        system("pause");
    }
    fclose(arqDecifrado);
    fclose(arqNlinhas);
}

void printaQtdLinhas()
{
    char linha[100];
    int contLinhas = 0;

    FILE *arqDecifrado;
    arqDecifrado = fopen("readme.decifrado.txt","r");

    if(arqDecifrado == NULL)
    {
        printf("Arquivo ainda não foi decifrado\n\n");
        system("pause");
    }
    else
    {
        do
        {
            if(fgets(linha, 100, arqDecifrado))
            {
                contLinhas = contLinhas + 1;
            }
        }
        while(!feof(arqDecifrado));
        printf("\nO arquivo readme.decifrado.txt tem (%d) linhas.\n", contLinhas);
        system("pause");
    }
    fclose(arqDecifrado);
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    printf("\nPara o programa funcionar coloque o arquivo 'readme.code.txt' na mesma pasta ou local que esta o arquivo .c\n\n");
    system("pause");
    system("cls");

    int opcMenu;


    do
    {
        opcMenu = menuPrincipal();

        switch(opcMenu)
        {
        case 1:
        {
            decifraArquivo();
            break;
        }
        case 2:
        {
            inseriLinhasTexto();
            break;
        }
        case 3:
        {
            printaQtdLinhas();

        }
        break;

        case 4:
        {
            maiorLinha();
        }
        break;

        case 5:
        {
            procurarPalavra();

        }
        break;

        case 0:
        {
            exit(0);
        }
        break;

        default:
        {
            printf("Opção errada.\n");
            system("pause");

        }
        break;
        }
    }
    while(opcMenu!=0);
    //remove("./readme.decifrado.txt");
    //remove("./readme.nlines.txt");
    return 0;
}
