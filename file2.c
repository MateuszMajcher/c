#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char tekst[] = "Hello world";
    
    if ((fp=fopen("test1.txt","w+")) == NULL){
    printf("Nie moge otworzyc pliku\n");
    exit(1);
    }
    
    fprintf(fp,"%s",tekst);
    fclose(fp);
                                    
   return 0;
    }
