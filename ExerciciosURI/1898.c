/*Exercício 1898 - URI
  Leonardo Henrique Correa
  Lincoln Amorim
  Gabriela Marculino
*/
#include <stdio.h>
#include <ctype.h>
#define MAX 64

void caracAleatorio(char *s, char *cpf, char *pt1){
    int tam = 0, tamCPF = 0;
    int depoisPonto = -1;
    for(int i = 0; s[i]; i++){
        if(!(isdigit(s[i]) || s[i] == '.'))
            continue;
        if(tamCPF < 11)
            cpf[tamCPF++] = s[i];
        else{
            if(s[i] == '.' || depoisPonto >= 0) 
                depoisPonto++;
            if(depoisPonto <= 2)
                pt1[tam++] = s[i];
        }
    }
    cpf[11] = pt1[tam] = '\0';
}

void maisCaracteres(char *s, char *pt2){
    int tam = 0;
    int depoisPonto = -1;
    for(int i = 0; s[i]; i++){
        if(isdigit(s[i]) || s[i] == '.'){
            if(s[i] == '.' || depoisPonto >= 0) 
                depoisPonto++;
            if(depoisPonto <= 2)
                pt2[tam++] = s[i];
        }
    }
    pt2[tam] = '\0';
}

int main(){
    char s[MAX], s2[MAX];
    char cpf[MAX], pt1[MAX], pt2[MAX];
    double prop1, prop2;
    while(scanf("%s", s) != EOF){
        scanf("%s", s2);
        caracAleatorio(s, cpf, pt1);
        maisCaracteres(s2, pt2);
        printf("cpf %s\n", cpf);
        sscanf(pt1, "%lf", &prop1);
        sscanf(pt2, "%lf", &prop2);
        printf("%.2lf\n", prop1 + prop2);
    }
    return 0;
}