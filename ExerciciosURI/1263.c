//Trabalho 6 - 1263
//Alunos:
//Lincoln Amorim, RGM: 41443
//Gabriela Marculino, RGM: 41431
//Leonardo Henrique, RGM: 41440

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main (void){

int firstvalue = 5;
int secondvalue = 15;
int *p1, *p2;

p1 = &firstvalue;
p2 = &secondvalue;
 
*p1 = 10;
*p2 = *p1;
p1 = p2;
*p1 = 20;

printf("\nfirstvalue is %d",firstvalue);
printf("\nsecondtvalue is %d",secondvalue);

}