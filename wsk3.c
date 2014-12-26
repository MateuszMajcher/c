#include<stdio.h>
#define max(a,b)((a)>(b) ? (a) : (b))
int main(){
   short int a=320;
    char* wsk;
    wsk =(char*)&a;
        printf("r %d",*wsk);
        printf("r %d",max(6,8));
    getchar();
    return 0;
    }
