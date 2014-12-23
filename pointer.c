#include<stdio.h>
int add(int ,int);
int (*function)(int,int);
int main(){
    function = &add;
    int sum = (*function)(2,3);
    printf("adres add to %8x\n",&add);
    printf("adres naszej funkcji to %8x\n",function);
    printf("sum to %d\n",sum);
 return 0; 
    }

int add(int a, int b){
    return a+b;
    }
