#include<stdio.h>

int main(){
    unsigned int a = 65530;
    unsigned int* a_wsk;
    
    unsigned char * c_wsk;
    
    a_wsk = &a;
    printf("wartosc wsk to %d\n",*a_wsk);
    c_wsk = &a;
    printf("wartosc wsk to %d\n",*c_wsk);
    getchar();
   return 0; 
    }
