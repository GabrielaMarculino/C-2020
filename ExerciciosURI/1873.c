#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int T;
  char a[40], b[40];

  scanf("%d", &T);

  while(T--) {
    scanf("%s %s", a, b);
    getchar();

    if(strcmp(a,"tesoura") == 0 && strcmp(b,"papel") == 0) {
     printf("rajesh\n");
   }

   else if(strcmp(a,"papel") == 0 && strcmp(b,"tesoura") == 0) {
     printf("sheldon\n");
   }

   else if(strcmp(a,"papel") == 0 && strcmp(b,"pedra") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"pedra") == 0 && strcmp(b,"papel") == 0) {
        printf("sheldon\n");
      }

    else if(strcmp(a,"lagarto") == 0 && strcmp(b,"pedra") == 0) {
      printf("sheldon\n");
    }

   else if(strcmp(a,"pedra") == 0 && strcmp(b,"lagarto") == 0) {
      printf("rajesh\n");
    }

   else if(strcmp(a,"lagarto") == 0 && strcmp(b,"spock") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"spock") == 0 && strcmp(b,"lagarto") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"spock") == 0 && strcmp(b,"tesoura") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"tesoura") == 0 && strcmp(b,"spock") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"tesoura") == 0 && strcmp(b,"lagarto") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"lagarto") == 0 && strcmp(b,"tesoura") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"lagarto") == 0 && strcmp(b,"papel") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"papel") == 0 && strcmp(b,"lagarto") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"spock") == 0 && strcmp(b,"papel") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"papel") == 0 && strcmp(b,"spock") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"spock") == 0 && strcmp(b,"papel") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"spock") == 0 && strcmp(b,"pedra") == 0) {
      printf("rajesh\n");
    }

    else if(strcmp(a,"pedra") == 0 && strcmp(b,"spock") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"tesoura") == 0 && strcmp(b,"pedra") == 0) {
      printf("sheldon\n");
    }

    else if(strcmp(a,"pedra") == 0 && strcmp(b,"tesoura") == 0) {
      printf("rajesh\n");
    }

    else {
      printf("empate\n");
    }
  }

  return 0;
}
