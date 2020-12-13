#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
/*
    Gabriela Marculino - RGM: 41431
    Vinicius Balbino - RGM: 43581
    Alexandre Cordeiro Arruda - RGM: 43551
*/

char global[1000][100];


void textoFormatado(char text[],char formataTexto[1000][100])
{

    int i = 0;
    char texto[strlen(text)];
    char vetorAuxiliar[1000];
    char *pch;
    strcpy(texto,text);
    pch = strtok(texto," ");
    strcpy(vetorAuxiliar,pch);
    strcat(vetorAuxiliar," ");
    strcpy(formataTexto[i],pch);
    strcat(formataTexto[i]," ");

    do
    {
        pch = strtok(NULL, " ");
        if(pch!=NULL)
        {
            strcat(vetorAuxiliar,pch);
            strcat(vetorAuxiliar," ");
            if(strlen(vetorAuxiliar)<80)
            {
                strcat(formataTexto[i],pch);
                strcat(formataTexto[i]," ");
            }
            else
            {
                i++;
                strcpy(vetorAuxiliar,"\0");
                strcpy(vetorAuxiliar,pch);
                strcat(vetorAuxiliar," ");
                strcpy(formataTexto[i],pch);
                strcat(formataTexto[i]," ");
            }
        }
    }
    while(pch != NULL);
}
void espacos(char matriz[1000][100], int qtdEspaco[]){

    int count = 0;

    for(int i = 0; i < 1000; i++){

        for(int j =0; j<strlen(matriz[i]); j++){

            if(matriz[i][0]!='!'){

                if(isspace(matriz[i][j])) count++;
            }
        }

        qtdEspaco[i]=count;
        count=0;
    }
}
void centralizar(char text[]){
    int i, cont = 0;;
    int tamanhoEspaco[1000];
    char espaco[1000][2][80], vetorAuxiliar[1000];

    textoFormatado(text, global);

    for(i=0; i<1000; i++){

        espaco[i][0][0]='\0';
        espaco[i][1][0]='\0';

    }
    vetorAuxiliar[0]='\0';

    for(i=0; i<1000; i++){

        tamanhoEspaco[i]=0;
        if(global[i][0]!='!'){
           global[i][strlen(global[i])-1]='\0';
            tamanhoEspaco[i]= 80 - strlen(global[i]);
        }
    }
    i = 0;
    do{
        while(cont!=tamanhoEspaco[i]){

            if(tamanhoEspaco[i]!=0){

                if(cont<tamanhoEspaco[i]/2) strcat(espaco[i][0]," ");

                else strcat(espaco[i][1]," ");
                cont++;
            }
        }
        if(strlen(espaco[i][0]) < strlen(espaco[i][1])){

            strcat(espaco[i][0]," ");
            espaco[i][1][strlen(espaco[i][1])-1]='\0';
        }
        if(global[i][0]!='!'){

            strcat(vetorAuxiliar, espaco[i][0]);
            strcat(vetorAuxiliar, global[i]);
            strcat(vetorAuxiliar, espaco[i][1]);
            strcpy(global[i],vetorAuxiliar);

            if(i+1<10) printf("[LINHA: %d]%s<----[%d]\n",i+1,global[i],strlen(global[i]));

            else printf("[LINHA: %d]%s<---[%d]\n",i+1,global[i],strlen(global[i]));

        }

        vetorAuxiliar[0]='\0';
        i++;
        cont = 0;

    }while(tamanhoEspaco[i]!=0);
    system("pause");
    system("cls");
}

void direita(char text[]){

    char vetorAuxiliar[1000];
    int z, l = 0, tamanho[1000];
    textoFormatado(text,global);

    for (int i = 0; i < 1000; ++i){

        if(global[i][0]!='!')
           global[i][strlen(global[i])-1] = '\0';
    }

    for (int x = 0; x < 1000; x++){

        tamanho[x] = 80 - strlen(global[x]);
    }

    for (int i = 0; i < 1000; ++i){

        if(strlen(global[i])!=80){

            if(global[i][0] != '!'){

                for (z = 0; z < tamanho[l]; z++){

                    if(z==0)
                        {
                        strcpy(vetorAuxiliar," ");
                    }else{

                        strcat(vetorAuxiliar," ");
                    }

                }

                l++;

                strcat(vetorAuxiliar,global[i]);
                strcpy(global[i],vetorAuxiliar);
                vetorAuxiliar[0]='\0';
            }
        }
    }
    for(int i = 0; i < 1000; ++i)

        if(global[i][0]!='!'){

            if(i+1<10) printf("[LINHA: %d]%s<----[%d]\n",i+1,global[i],strlen(global[i]));
            else printf("[LINHA: %d]%s<---[%d]\n",i+1,global[i],strlen(global[i]));
        }

    system("pause");
    system("cls");
}

void upperTexto(char texto[1000][100]){
  int i, j;
  char texto_caixaAlta[1000][100];

  for(i=0;i<1000;i++){
      for(j=0; j <= strlen(texto[i]); j++){
        texto_caixaAlta[i][j] = toupper(texto[i][j]);
      }
  }
  for(i=0; i<1000;i++){
      if(texto_caixaAlta[i][0]!='!'){
          if(i+1 <= 10) printf("[LINHA: %d]%s<----[%d]\n",i+1,texto_caixaAlta[i],strlen(texto_caixaAlta[i]));
          else printf("[LINHA: %d]%s<---[%d]\n",i+1,texto_caixaAlta[i],strlen(texto_caixaAlta[i]));
      }
  }
}

void justificar(char text[]){

    int tamanhoEspaco[1000], contadorEspaco[1000], i, controlador = 0, cont = 0;
    char copiaMatriz[1000][100], vetorAuxiliar[100], copiaLinha[100];
    char *pch;

    vetorAuxiliar[0] = '\0';
    copiaLinha[0] = '\0';
    textoFormatado(text,global);

    for(i = 0; i < 1000; i++){

        tamanhoEspaco[i] = 0;

        if(global[i][0] != '!'){
           global[i][strlen(global[i])-1] = '\0';
            tamanhoEspaco[i] = 80 - strlen(global[i]);
            strcpy(copiaMatriz[i],global[i]);
        }
    }

    espacos(copiaMatriz, contadorEspaco);
    i = 0;

    do{
        do{
            vetorAuxiliar[0] = '\0';
            strcpy(copiaLinha,copiaMatriz[i]);
            pch = strtok(copiaLinha," ");

            while(pch != NULL){

                if(contadorEspaco[i] >= tamanhoEspaco[i]){

                    if(pch != NULL && controlador != contadorEspaco[i]){

                        strcat(vetorAuxiliar,pch);
                        strcat(vetorAuxiliar,"  ");
                        controlador++;

                    }else{

                        strcat(vetorAuxiliar,pch);
                        strcat(vetorAuxiliar," ");
                    }

                }else if (contadorEspaco[i] < tamanhoEspaco[i]){

                    if(pch != NULL){

                        if (controlador != contadorEspaco[i]){

                            strcat(vetorAuxiliar,pch);
                            strcat(vetorAuxiliar,"    ");
                            controlador++;

                        }else{

                            strcat(vetorAuxiliar,pch);
                            strcat(vetorAuxiliar,"  ");
                        }
                    }
                }

                pch = strtok(NULL," ");
            }

            vetorAuxiliar[strlen(vetorAuxiliar)-1] = '\0';

            if(strlen(vetorAuxiliar)>80){

                cont++;
                controlador=cont;
            }

        }while(strlen(vetorAuxiliar) > 80);
        printf("%s<---%d\n",vetorAuxiliar,strlen(vetorAuxiliar));
        i++;
        cont = 0;
        controlador = 0;

    }while(global[i][0]!='!');
}

void complemento(){

    for(int i = 0; i < 1000; i++){
        if(global[i][0] != '!'){
           if(i+1 < 10){
            printf("LINHA: %d]%s <--- [%d]\n",i+1,global[i],strlen(global[i]));
        }else{
            printf("[LINHA: %d]%s <--- [%d]\n",i+1,global[i],strlen(global[i]));
            }
        }
    }
}

void lowerTexto(char texto[1000][100]){
    int i, j;
    char texto_caixaBaixo[1000][100];

    for(i=0;i<1000;i++){
        for(j=0; j <= strlen(texto); j++){
          texto_caixaBaixo[i][j] = tolower(texto[i][j]);
        }
    }
    for(i=0; i<1000;i++){
        if(texto_caixaBaixo[i][0]!='!'){
            if(i+1 <= 10) printf("[LINHA: %d]%s<----[%d]\n",i+1,texto_caixaBaixo[i],strlen(texto_caixaBaixo[i]));
            else printf("[LINHA: %d]%s<---[%d]\n",i+1,texto_caixaBaixo[i],strlen(texto_caixaBaixo[i]));
        }
    }
}

void caracterUpperFrase(char texto[1000][100]){
  char texto_caracterInicioAlta[1000][100];
  for(int i=0;i<1000;i++){
      for(int j=0; j <= strlen(texto[i]); j++){
        if(j==0) {
          texto_caracterInicioAlta[i][j] = toupper(texto[i][j]);
        }else{
          texto_caracterInicioAlta[i][j] = texto[i][j];
        }

      }
  }
  for(int i=0; i<1000;i++){
      if(texto_caracterInicioAlta[i][0]!='!'){
          if(i+1 <= 10) printf("[LINHA: %d]%s<----[%d]\n",i+1,texto_caracterInicioAlta[i],strlen(texto_caracterInicioAlta[i]));
          else printf("[LINHA: %d]%s<---[%d]\n",i+1,texto_caracterInicioAlta[i],strlen(texto_caracterInicioAlta[i]));
      }
  }
}

void encontraPalavra(char texto[1000][100]){
    char palavra[50];
    int haveSpace = 0;
    char * pch;
    do{
      printf("Insira a palavra que deseja buscar:");
      scanf("%s", palavra);
      for(int i=0; i< 50; i++){
        if(palavra[i] == " ") haveSpace= 1;
      }
      if(haveSpace != 0){
        printf("A busca é apenas uma palavra!");
      }
    }while(haveSpace != 0);
    for(int i =0;i<50;i++){
      palavra[i] = tolower(palavra[i]);
    }
    for(int i=0;i<1000;i++){
        for(int j=0; j < strlen(texto[i]); j++){
          texto[i][j] = tolower(texto[i][j]);
        }
    }

    int cont[42];
    for(int i=0;i<42;i++) cont[i]=0;
    int qtdLinhasPalavra=0;
    int i=0;
    do{
      if(texto[i][0]!='!'){
          pch=strtok(texto[i]," ");
          while(pch!=NULL){
              if(pch!=NULL){
                  if(strstr(pch, palavra)!=NULL){
                      cont[i]++;
                      qtdLinhasPalavra++;
                  }
              }
              pch = strtok(NULL," ");
          }
          if(cont[i]!=0) printf("--->A palavra [%s] aparece na [LINHA: %d], %d vez(es)\n",palavra, i+1, cont[i]);
          i++;
      }
    }while( i!=41 );
    printf("\nA palavra [%s] aparece %d vezes\n",palavra,qtdLinhasPalavra);
}



void menuPrincipal(char texto[])
{
    int escolha = 0;
    char texto_c[strlen(texto)];
    char texto_descrip[99999];
    strcpy(texto_c,texto);
    strcpy(texto_descrip, texto);
    textoFormatado(texto, global);
    do
    {
        printf("ESCOLHA ALGUMA DAS OPÇÕES ABAIXO:\n\n");
        printf("1-  IMPRIMIR TEXTO FORMATADO\n");
        printf("2-  QUANTAS VEZES APARECE A PALAVRA X E EM QUAIS LINHAS?\n");
        printf("3-  SUBSTITUIR UMA PALAVRA NO TEXTO POR OUTRA (APENAS UMA PALAVRA)\n");
        printf("4-  SUBSTITUIR UMA PALAVRA NO TEXTO POR OUTRA (NO TEXTO INTEIRO)\n");
        printf("5-  COLOCAR O TEXTO EM CAIXA-ALTA\n");
        printf("6-  COLOCAR O TEXTO EM CAIXA-BAIXA\n");
        printf("7-  COLOCAR A PRIMEIRA LETRA DE CADA PALAVRA EM CAIXA-ALTA\n");
        printf("8-  CRIPTOGRAFAR EM CÓDIGO MORSE\n");
        printf("9-  DESCRIPTOGRAFAR O TEXTO\n");
        printf("10- ALINHAR O TEXTO À ESQUERDA\n");
        printf("11- ALINHAR O TEXTO  À DIREITA\n");
        printf("12- JUSTIFICAR O TEXTO\n");
        printf("13- CENTRALIZAR O TEXTO\n");
        printf("14- IMPRIMIR TEXTO ORIGINAL\n ");
        printf("0-  SAIR\n\n");


        scanf("%d",&escolha);

        switch(escolha)
        {
        case 1:
            textoFormatado(texto,global);
            complemento();
            system("pause");
            system("cls");
            break;
        case 2:
            encontraPalavra(global);
            system("pause");
	        system("cls");
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            upperTexto(global);
            system("pause");
            system("cls");
            break;
        case 6:
            lowerTexto(global);
           	system("pause");
           	system("cls");
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            textoFormatado(texto,global);
            complemento();
            system("pause");
            system("cls");
            break;
        case 11:
            direita(texto);
            system("pause");
            system("cls");
            break;
        case 12:
            justificar(texto);
            system("pause");
            system("cls");
            break;
        case 13:
            centralizar(texto);
            system("pause");
            system("cls");
            break;
        case 14:
            printf("%s\n",texto);
            system("pause");
            system("cls");
            break;
        case 0:
            //sair
            break;
        default:
            printf("Opção errada.\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(escolha != 0);

}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    char text[99999]="William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates,\
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercialização deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia \
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
 Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    //printf("\n\n%s",text);
    for(int i=0; i<1000; i++)
    {
        global[i][0]='!';
        global[i][1]='\0';
    }
    menuPrincipal(text);
    return 0;
}
