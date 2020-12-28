#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define TAM 50

/*
    Gabriela Marculino RGM: 41431
    Vinicius Balbino RGM: 43581
    Alexandre Arruda RGM: 43551
*/

char opcionais[][TAM]= { {"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"},
    {"banco.couro"}, {"sensor.estacionamento"}
};

char nomes[][TAM] = { {"Vinicius"}, {"Alexandre"}, {"Gabriela"}, {"Pedro"}, {"Stefany"}, {"Irineu"},
    {"João"}, {"Matheus"}, {"Ednaldo"}, {"Enzo"}, {"Maria"}
};

char sobrenomes[][TAM] = { {"Balbino"}, {"Arruda"}, {"Marculino"}, {"Ribeiro"}, {"Silva"}, {"Pereira"}, {"Santos"},
    {"Souza"}, {"Rodrigues"}, {"Ferreira"}, {"Oliveira"}
};

struct CARRO
{
    char placa[9];  //AAA-1234
    char modelo[TAM];  //gol, celta, palio, ...
    char fabricante[TAM]; //chevrolet, fiat, ...
    int ano_fabricacao;  //1980 à 2016
    int ano_modelo;  //1980 à 2017
    char combustivel[TAM];  //alcool, gasolina, flex, diesel
    char cor[TAM];  //branca, prata, preta
    int opcional[8];  //ver matriz opcionais
    float preco_compra;
};

struct ENDERECO
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11]; //99.999-999
};

struct TELEFONE
{
    char telefone[14]; //99 99999-9999
};

struct CLIENTE
{
    char nome[TAM];
    char cpf[15]; //999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};

struct DATA
{
    int dia, mes, ano;
};

struct VENDA_CARRO
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
};

struct CLIENTE VetorClientes[TAM];
int auxCliente=0;
struct CARRO VetorCarros[TAM];
int auxCarros=0;
struct VENDA_CARRO VetorVendas[TAM];
int auxVendas=0;

//objetivo: gerar as letras do alfabeto aleatoriamente de A - Z
//parametros: nenhum
//retorno: uma letra
char geraAlfabeto()
{
    int i;
    char letras[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

    i = rand()%26;
    return(letras[i]);
}

//objetivo: escolher dentre os numeros ('0'..'9') uma numero aleatoriamente
//parametros: nenhum
//retorno: um numero
char geraNumero()
{
    int i;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i = rand()%10;
    return(numeros[i]);
}

//objetivo: gerar a placa de um carro aleatoriamente no formato AAA-1234
//parametros: char *placa
//retorno: nenhum
void geraPlacaCarro(char *placa)
{
    int i;
    char placaCopy[9];
    for(i = 0; i < 3; i++)
    {
        placaCopy[i] = geraAlfabeto();
    }
    placaCopy[3] = '-';
    for(i = 4; i < 8; i++)
    {
        placaCopy[i] = geraNumero();
    }
    placaCopy[8] = '\0';
    strcpy(placa, placaCopy);

}

//objetivo: gerar o modelo do carro aleatoriamente
//parametros: char *modelo
//retorno: nenhum
void geraModelo(char *modelo)
{

    int i;
    char modelos[][10] = {{"Celta"}, {"Palio"}, {"Gol"}, {"HB20"}, {"Uno"},{"Corsa"},{"Jetta"},{"Corolla"},{"Hilux"},{"Creta"} };

    i = rand() % 10;
    strcpy(modelo, modelos[i]);
}

//objetivo: utilizar o digito que é retornado para ajudar na verificação de CPF (se é valido ou não)
//parametros: char *cpf
//retorno: digito
int primeiroDigitoVerificador(char *cpf)
{
    int dig[9];
    int digito;
    for(int i=0; i<9; i++)
    {
        dig[i]= cpf[i] - '0';
    }
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

//objetivo: utilizar o digito que é retornado para ajudar na verificação de CPF (se é valido ou não)
//parametros: char *cpf
//retorno: digito
int segundoDigitoVerificador(char *cpf)
{
    int dig[9];
    int digito;
    for(int i=0; i<10; i++)
    {
        dig[i]= cpf[i] - '0';
    }
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

//objetivo: inserir a pontuação do CPF (000.000.000-00)
//parametros: char *cpf, char *cpfPontuado
//retorno: nenhum
void inserePontuacao(char *cpf, char *cpfPontuado )
{
    int pointer = 0;
    for(int i=0; i<14; i++)
    {
        if(i != 3 && i != 7 && i != 11)
        {
            cpfPontuado[i] = cpf[pointer];
            pointer++;
        }
        if(i==3 || i==7)
            cpfPontuado[i]='.';
        if(i==11)
            cpfPontuado[i]='-';
    }
    cpfPontuado[14] = '\0';
}

//objetivo: faz a verificação do CPF
//parametros: char *cpf
//retorno: valido
int cpfValido(char *cpf)
{
    int valido=1;
    int dig[11];
    int cpfNum[12];

    for(int i=0; i < 11; i++)
    {
        cpfNum[i] = cpf[i] - '0';
    }
    for(int i = 0; i < 11; i++)
    {
        dig[i] = cpf[i] - '0';
    }
    int digito1 = ((10 * dig[0]) + (9 * dig[1]) + (8 * dig[2]) + (7 * dig[3]) + (6 * dig[4]) + (5 * dig[5]) + (4 * dig[6]) + (3 * dig[7]) + (2 * dig[8]))% 11;
    if(digito1 == cpfNum[9] )
    {
        int digito2 = ((11 * dig[0]) + (10 * dig[1]) + (9 * dig[2]) + (8 * dig[3]) + (7 * dig[4]) + (6 * dig[5]) + (5 * dig[6]) + (4 * dig[7]) + (3 * dig[8]) + (2 * dig[9]))% 11;
        if(digito2 == cpfNum[10])
        {
            valido = 0;
        }
        else
        {
            valido = 1;
        }
    }
    else
    {
        valido = 1;
    }
    return(valido);
}

//objetivo: gerar o CPF aleatoriamente
//parametros: char *CPF
//retorno: nenhum
void geraCPFCliente(char *CPF)
{
    char cpf[12];
    char cpfPontuado[15];
    do{
        for(int i = 0; i < 9; i++)
        {
            cpf[i] = geraNumero();
        }
        cpf[9]  = primeiroDigitoVerificador(cpf) + '0';
        cpf[10] = segundoDigitoVerificador(cpf) + '0';
        cpf[11] = '\0';
        inserePontuacao(cpf, cpfPontuado);
    }while( (cpfValido(cpf)!=1));
    strcpy( CPF, cpfPontuado );
}

//objetivo: gerar o nome do fabricante aleatoriamente
//parametros: char *fabricante, char *modelo
//retorno: nenhum
void geraFabricante(char *fabricante, char *modelo)
{
    char modeloCarro[][11] = {{"Fiat"}, {"Chevrolet"}, {"Volkswagen"}, {"Toyota"}, {"Hyundai"}};
    if(strcmp(modelo,"Palio") == 0) strcpy(fabricante, modeloCarro[0]);
    if(strcmp(modelo,"Uno") == 0) strcpy(fabricante, modeloCarro[0]);
    if(strcmp(modelo,"Celta") == 0) strcpy(fabricante, modeloCarro[1]);
    if(strcmp(modelo,"Corsa") == 0) strcpy(fabricante, modeloCarro[1]);
    if(strcmp(modelo,"Jetta") == 0) strcpy(fabricante, modeloCarro[2]);
    if(strcmp(modelo,"Gol") == 0) strcpy(fabricante, modeloCarro[2]);
    if(strcmp(modelo,"Corolla") == 0) strcpy(fabricante, modeloCarro[3]);
    if(strcmp(modelo,"Hilux") == 0) strcpy(fabricante, modeloCarro[3]);
    if(strcmp(modelo,"HB20") == 0) strcpy(fabricante, modeloCarro[4]);
    if(strcmp(modelo,"Creta") == 0) strcpy(fabricante, modeloCarro[4]);
}

//objetivo: gerar o nome do combustível aleatorimente
//parametros: char *combustivel
//retorno: nenhum
void geraCombustivel(char *combustivel)
{
    int i;
    char tipoCombustive[][10] = {{"Gasolina"}, {"Álcool"}, {"Flex"}, {"Diesel"}};

    i = rand() % 4;
    strcpy(combustivel, tipoCombustive[i]);
}

//objetivo: gerar a cor do carro automaticamente
//parametros: char *cor
//retorno: nenhum
void geraCor(char *cor)
{

    int i;
    char carroCor[][10] = {{"Preto"}, {"Verde"}, {"Azul"}, {"Vermelho"},{"Branco"},{"Prata"}};

    i = rand() % 6;
    strcpy(cor, carroCor[i]);
}

//objetivo: gerar o nome da rua aleatoriamente
//parametros: char *rua
//retorno: nenhum
void geraRua(char *rua)
{
    char Rua[20];
    char letraRua[2];
    letraRua[0] = geraAlfabeto();
    letraRua[1] = '\0';
    strcpy(Rua,"Rua Projetada ");
    strcat(Rua, letraRua);
    strcpy(rua, Rua);
}

//objetivo: gerar o nome do bairro aleatoriamente
//parametros: char *bairro
//retorno: nenhum
void geraBairro(char *bairro)
{
    char Bairro[20];
    char letraBairro[2];
    letraBairro[0] = geraAlfabeto();
    letraBairro[1] = '\0';
    strcpy(Bairro,"Bairro ");
    strcat(Bairro, letraBairro);
    strcpy(bairro, Bairro);
}

//objetivo: gerar o estado aleatoriamente
//parametros: char *estado
//retorno: nenhum
void geraEstado(char *estado)
{
    int i;
    char estados[][3] = { {"AC"}, {"AL"}, {"AP"}, {"AM"}, {"BA"}, {"CE"}, {"DF"},{"ES"}, {"GO"}, {"MA"}, {"MT"},{"MS"},{"MG"},{"PA"},{"PB"}, {"PR"}, {"PE"}, {"PI"}, {"RJ"}, {"RN"}, {"RS"},{"RO"},{"RR"}, {"SC"}, {"SP"}, {"SE"}, {"TO"}};

    i = rand()%26;
    strcpy(estado, estados[i]);
}

//objetivo: atribuir cidade de acordo com o estado
//parametros: char *estado, char *cidade
//retorno: nenhum
void geraCidade(char *estado, char *cidade)
{
    if(strcmp(estado, "AC") == 0) strcpy(cidade, "Rio Branco");
    if(strcmp(estado, "AL") == 0) strcpy(cidade, "Maceió");
    if(strcmp(estado, "AP") == 0) strcpy(cidade, "Macapá");
    if(strcmp(estado, "AM") == 0) strcpy(cidade, "Manaus");
    if(strcmp(estado, "BA") == 0) strcpy(cidade, "Salvador");
    if(strcmp(estado, "CE") == 0) strcpy(cidade, "Fortaleza");
    if(strcmp(estado, "DF") == 0) strcpy(cidade, "Brasília");
    if(strcmp(estado, "ES") == 0) strcpy(cidade, "Vitória");
    if(strcmp(estado, "GO") == 0) strcpy(cidade, "Goiânia");
    if(strcmp(estado, "MA") == 0) strcpy(cidade, "São Luís");
    if(strcmp(estado, "MT") == 0) strcpy(cidade, "Cuiabá");
    if(strcmp(estado, "MS") == 0) strcpy(cidade, "Campo Grande");
    if(strcmp(estado, "MG") == 0) strcpy(cidade, "Belo Horizonte");
    if(strcmp(estado, "PA") == 0) strcpy(cidade, "Belém");
    if(strcmp(estado, "PB") == 0) strcpy(cidade, "João Pessoa");
    if(strcmp(estado, "PR") == 0) strcpy(cidade, "Curitiba");
    if(strcmp(estado, "PE") == 0) strcpy(cidade, "Recife");
    if(strcmp(estado, "PI") == 0) strcpy(cidade, "Teresina");
    if(strcmp(estado, "RJ") == 0) strcpy(cidade, "Rio de Janeiro");
    if(strcmp(estado, "RN") == 0) strcpy(cidade, "Natal");
    if(strcmp(estado, "RS") == 0) strcpy(cidade, "Porto Alegre");
    if(strcmp(estado, "RO") == 0) strcpy(cidade, "Porto Velho");
    if(strcmp(estado, "RR") == 0) strcpy(cidade, "Boa Vista");
    if(strcmp(estado, "SC") == 0) strcpy(cidade, "Florianópolis");
    if(strcmp(estado, "SP") == 0) strcpy(cidade, "São Paulo");
    if(strcmp(estado, "SE") == 0) strcpy(cidade, "Aracaju");
    if(strcmp(estado, "TO") == 0) strcpy(cidade, "Palmas");
}

//objetivo: gerar CEP automaticamente
//parametros: char *cep
//retorno: nenhum
void geraCep(char *cep)
{
    char cepCopy[11];
    for(int i=0; i<11; i++)
    {
        cepCopy[i]= geraNumero();
    }
    cepCopy[2] = '.';
    cepCopy[6] = '-';
    cepCopy[10] = '\0';
    strcpy(cep, cepCopy);
}

//objetivo: gerar o nome completo do cliente
//parametros: char *nome
//retorno: nenhum
void geraNomeCompleto(char *nome)
{
    char nomeCompleto[TAM];
    int i,j;
    i = rand()%11;
    j = rand()%11;
    strcpy(nomeCompleto, nomes[i]);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenomes[j]);
    strcpy(nome, nomeCompleto);
}

//objetivo: gerar telefone automaticamente para cliente
//parametros: struct TELEFONE *telefone
//retorno: nenhum
void geraTelefone(struct TELEFONE *telefone)
{
    char telefoneCopy[14];
    for(int i = 0; i < 13; ++i)
    {
        telefoneCopy[i] = geraNumero();
    }
    telefoneCopy[2] = ' ';
    telefoneCopy[8] = '-';
    telefoneCopy[13] = '\0';//99 99999-9999
    strcpy(telefone->telefone, telefoneCopy);
}

//objetivo: gerar o endereco aleatoriamente e automaticamente
//parametros: struct ENDERECO *enderecoCliente
//retorno: nenhum
void geraEnderecoCliente(struct ENDERECO *enderecoCliente)
{
    geraRua(enderecoCliente->rua);
    geraBairro(enderecoCliente->bairro);
    geraEstado(enderecoCliente->estado);
    geraCidade(enderecoCliente->estado, enderecoCliente->cidade);
    geraCep(enderecoCliente->cep);
    enderecoCliente->numero = rand() % 2999 + 1;
}

//objetivo: gerar ano aleatoriamente entre 1980 e 2016
//parametros: nenhum
//retorno: nenhum
int geraAno(){
  int ano= rand() % 36 + 1979;
  return(ano);
}

//objetivo: gerar o ano do modelo do carro automaticamente
//parametros: int anoFabricacao
//retorno: anosPermitidos[i]
int geraAnoModelo(int anoFabricao){
  int anosPermitidos[2];
  anosPermitidos[0] = anoFabricao;
  anosPermitidos[1] = anoFabricao+1;
  int i = rand() % 2;
  return(anosPermitidos[i]);
}


void printaCarro(struct CARRO carro){
  printf("DADOS DO CARRO \n");
  printf("----------------------------------\n");
  printf("Placa: %s\n", carro.placa);
  printf("Modelo: %s\n", carro.modelo);
  printf("Fabricante: %s\n", carro.fabricante);
  printf("Ano Fabricacao: %d\n", carro.ano_fabricacao);
  printf("Ano Modelo: %d\n", carro.ano_modelo);
  printf("Combustível: %s\n", carro.combustivel);
  printf("Cor: %s\n", carro.cor);
  printf("Opcionais:\n");
  for(int i=0; i<8; i++){
      if(carro.opcional[i] == 1){
        printf("\t%s\n", opcionais[i]);
      }
  }
  printf("----------------------------------\n");
}

//objetivo: gerar as informações automaticamente do carro para facilitar a inclusão no sistema
//parametros: nenhum
//retorno: nenhum
void geraCarro()
{
    int escolha = 0;
    do{
      struct CARRO carro;
      geraPlacaCarro(carro.placa);
      geraCombustivel(carro.combustivel);
      geraModelo(carro.modelo);
      geraFabricante(carro.fabricante, carro.modelo);
      geraCor(carro.cor);
      carro.ano_fabricacao = geraAno();
      carro.ano_modelo = geraAnoModelo(carro.ano_fabricacao);
      for(int i=0;i<8;i++){
          carro.opcional[i] = rand() % 2;
      }
      system("cls");
      printaCarro(carro);
      memcpy( &VetorCarros[auxCarros], &carro, sizeof(VetorCarros[auxCarros]));
      printf("Deseja Adicionar este carro?\n");
      printf("Digite 1- SIM e 2- NÃO\n\n");
      scanf("%d", &escolha);
      while(escolha!=2 && escolha!=1){
        printf("Escolha Invalida! insira 1 - SIM ou 2 - NÃO\n\n");
        scanf("%d", &escolha);
      }
    }while(!(escolha!=2));
    auxCarros = auxCarros + 1;
}


void printaCliente(struct CLIENTE cliente){
    printf("DADOS DO CLIENTE \n");
    printf("----------------------------------\n");
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("CEP: %s\n", cliente.endereco.cep);
    printf("CIDADE: %s\n", cliente.endereco.cidade);
    printf("ESTADO: %s\n", cliente.endereco.estado);
    printf("BAIRRO: %s\n", cliente.endereco.bairro);
    printf("RUA: %s\n", cliente.endereco.rua);
    printf("Numero: %d\n", cliente.endereco.numero);
    printf("Renda Mensal: %.2f\n", cliente.renda_mensal);
    printf("Telefone Residencial: %s\n", cliente.residencial.telefone);
    for(int i=0;i<5;i++){
        printf("Celular %d: %s\n", i+1, cliente.celular[i].telefone);
    }
    printf("----------------------------------\n");
}


//objetivo: chamar o menu principal, onde mostra todas as opções disponíveis
//parametros: nenhum
//retorno: nennum
void menuPrincipal()
{

    int opcaoMenuPrincipal = 0;
    int opcaoMenuCarro = 0;
    int opcaoMenuCliente = 0;
    int opcaoMenuVenda = 0;

    do
    {
        system("cls");
        printf("ESCOLHA UMA DAS OPÇÕES ABAIXO:\n\n");
        printf("1- CARRO\n");
        printf("2- CLIENTE\n");
        printf("3- VENDA\n");
        printf("4- SAIR DO PROGRAMA\n\n");
        scanf("%d",&opcaoMenuPrincipal);

        switch(opcaoMenuPrincipal)
        {

        case 1:

            do
            {
                system("cls");
                printf("Você está no MENU CARRO\n\n");
                printf("ESCOLHA UMA DAS OPÇÕES ABAIXO:\n\n");
                printf("1- INSERIR UM CARRO NO CADASTRO\n");
                printf("2- EXCLUIR UM CARRO DO CADASTRO\n");
                printf("3- LISTAR OS CARROS DISPONÍVEIS PARA A VENDA ORDENADOS CRESCENTEMENTE POR FABRICANTE E MODELO\n");
                printf("4- LISTAR OS CARROS DISPONÍVEIS PARA A VENDA POR SELEÇÃO DE UM OU MAIS OPCIONAIS\n");
                printf("5- LISTAR OS CARROS DISPONÍVEIS PARA A VENDA POR SELEÇÃO DA FAIXA DE ANO DE FABRICAÇÃO\n");
                printf("6- VOLTAR\n\n");

                scanf("%d",&opcaoMenuCarro);

                switch(opcaoMenuCarro)
                {

                case 1:
                    //INSERIR UM CARRO NO CADASTRO
                    geraCarro();
                    //system("pause");
                    //system("cls");
                    break;

                case 2:
                    //EXCLUIR UM CARRO DO CADASTRO
                    //system("pause");
                    //system("cls");
                    break;

                case 3:
                    //LISTAR OS CARROS DISPONÍVEIS PARA A VENDA ORDENADOS CRESCENTEMENTE POR FABRICANTE E MODELO
                    //system("pause");
                    //system("cls");
                    break;

                case 4:
                    //LISTAR OS CARROS DISPONÍVEIS PARA A VENDA POR SELEÇÃO DE UM OU MAIS OPCIONAIS
                    //system("pause");
                    //system("cls");
                    break;

                case 5:
                    //LISTAR OS CARROS DISPONÍVEIS PARA A VENDA POR SELEÇÃO DA FAIXA DE ANO DE FABRICAÇÃO
                    //system("pause");
                    //system("cls");
                    break;

                case 6:
                    //VOLTAR
                    //system("pause");
                    //system("cls");
                    break;

                default:
                    printf("Você escolheu uma opção que não existe.\n");
                    //system("pause");
                    //system("cls");
                    break;

                }
                break;


            case 2:

                do
                {
                    system("cls");
                    printf("Você está no menu CLIENTE\n\n");
                    printf("1- INSERIR UM CLIENTE NO CADASTRO\n");
                    printf("2- EXLUIR UM CLIENTE DO CADASTRO\n");
                    printf("3- LISTAR OS CLIENTES DO CADASTRO ORDENADOS CRESCENTEMENTE PELO NOME\n");
                    printf("4- LISTAR OS CLIENTES DO CADASTRO ORDENADOS CRECENTEMENTE PELO NOME POR SELEÇÃO DE FAIXA DE RENDA SALARIAL MENSAL\n");
                    printf("5- VOLTAR\n\n");

                    scanf("%d",&opcaoMenuCliente);

                    switch(opcaoMenuCliente){
                      case 1: {
                      //INSERIR UM CLIENTE NO CADASTRO
                      int escolha =0;
                      do{
                        struct CLIENTE cliente;
                        struct ENDERECO enderecoCliente;
                        struct TELEFONE telefone;
                        struct TELEFONE celulares[5];
                        geraNomeCompleto(cliente.nome);
                        geraCPFCliente(cliente.cpf);
                        geraEnderecoCliente(&enderecoCliente);
                        geraTelefone(&telefone);
                        for(int i=0;i<5;i++){
                          geraTelefone(&celulares[i]);
                        }
                        memcpy( &cliente.endereco, &enderecoCliente, sizeof(enderecoCliente));
                        memcpy( &cliente.residencial, &telefone, sizeof(telefone));
                        for(int i=0;i<5;i++){
                            memcpy( &cliente.celular[i], &celulares[i], sizeof(celulares));
                        }
                        cliente.renda_mensal = rand() % 80000 + 500;
                        system("cls");
                        printaCliente(cliente);

                        memcpy( &VetorClientes[auxCliente], &cliente, sizeof(VetorClientes[auxCliente]));
                        printf("Deseja Adicionar este cliente?\n");
                        printf("Digite 1- SIM e 2- NÃO\n\n");
                        scanf("%d", &escolha);
                        while(escolha!=2 && escolha!=1){
                          printf("Escolha Invalida! insira 1 - SIM ou 2 - NÃO\n\n");
                          scanf("%d", &escolha);
                        }
                      }while(!(escolha!=2));
                      auxCliente = auxCliente + 1;
                      system("cls");
                    } break;


                      case 2:
                          //EXLUIR UM CLIENTE DO CADASTRO
                          //system("pause");
                          //system("cls");
                          break;

                      case 3:
                          //LISTAR OS CLIENTES DO CADASTRO ORDENADOS CRESCENTEMENTE PELO NOME
                          //system("pause");
                          //system("cls");
                          break;

                      case 4:
                          //LISTAR OS CLIENTES DO CADASTRO ORDENADOS CRECENTEMENTE PELO NOME POR SELEÇÃO DE FAIXA DE RENDA SALARIAL MENSAL
                          //system("pause");
                          //system("cls");
                          break;

                      case 5:
                          //VOLTAR
                          //system("pause");
                          //system("cls");
                          break;

                      default:
                          printf("Você escolheu uma opção que não existe.\n");
                          //system("pause");
                          //system("cls");
                          break;

                      }
                }
                while(opcaoMenuCliente != 5);
                break;

            case 3:

                do
                {
                    system("cls");
                    printf("você está em menu VENDA\n\n");
                    printf("1- INSERIR UMA VENDA\n");
                    printf("2- EXCLUIR UMA VENDA\n");
                    printf("3- LISTAR OS CARROS VENDIDOS DE UM DETERMINADO FABRICANTE, ORDENADOS CRESCENTEMENTE PELO MODELO\n");
                    printf("4- LISTAR OS CARROS VENDIDOS DE UM DETERMINADO MODELO, ORDENADOS CRESCENTEMENTE PELO ANO DE FABRICAÇÃO\n");
                    printf("5- INFORMAR A QUANTIDADE DE CARROS VENDIDOS COM O VALOR TOTALIZADO DOS PREÇOS VENDIDOS\n");
                    printf("6- INFORMAR O LUCRO TOTAL DAS VENDAS\n");
                    printf("7- VOLTAR\n\n");
                    scanf("%d",&opcaoMenuVenda);
                    switch(opcaoMenuVenda)
                    {

                    case 1:
                        //INSERIR UMA VENDA
                        //system("pause");
                        //system("cls");
                        break;

                    case 2:
                        //EXCLUIR UMA VENDA
                        //system("pause");
                        //system("cls");
                        break;

                    case 3:
                        //LISTAR OS CARROS VENDIDOS DE UM DETERMINADO FABRICANTE, ORDENADOS CRESCENTEMENTE PELO MODELO
                        //system("pause");
                        //system("cls");
                        break;

                    case 4:
                        //LISTAR OS CARROS VENDIDOS DE UM DETERMINADO MODELO, ORDENADOS CRESCENTEMENTE PELO ANO DE FABRICAÇÃO
                        //system("pause");
                        //system("cls");
                        break;

                    case 5:
                        //INFORMAR A QUANTIDADE DE CARROS VENDIDOS COM O VALOR TOTALIZADO DOS PREÇOS VENDIDOS
                        //system("pause");
                        //system("cls");
                        break;

                    case 6:
                        //INFORMAR O LUCRO TOTAL DAS VENDAS
                        //system("pause");
                        //system("cls");
                        break;
                    case 7:
                        //VOLATR
                        //system("pause");
                        //system("cls");
                        break;

                    default:
                        printf("Você escolheu uma opção que não existe.\n");
                        //system("pause");
                        //system("cls");
                        break;

                    }
                }
                while(opcaoMenuVenda != 7);
                break;

            case 4:
                //SAIR
                break;

            default:
                printf("Você escolheu uma opção que não existe.\n");
                //system("pause");
                //system("cls");
                break;
            }
            while(opcaoMenuCarro != 6);
        }

    }
    while(opcaoMenuPrincipal != 4);
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    menuPrincipal();
    return 0;
}
