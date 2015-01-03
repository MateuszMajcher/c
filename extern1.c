#include<stdio.h>
#include "extern2.c"
extern int func();
int main(){
    int i;
    for ( i=1;i<=5;i++){
        register int number = 7;
        printf("numer to %d\n",number);
        }
        func();
        getchar();
    return 0;
    }
