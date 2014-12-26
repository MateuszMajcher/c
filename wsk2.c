#include<stdio.h>

int main(){
    int* var;
    int const** wsk = &var;  //wskazuje na wskaznik
     
    int const fixed = 20;
    /*wsk** -> *var  ||  *wsk = *var = fixedx*/
    *wsk = &fixed;   
      printf("x=%x \n", *wsk);
   
    *var = 30;
    
     
    printf("x=%i y=%i\n", fixed, *var);
    getchar();
    return 0;
    }
/*http://www.eskimo.com/~scs/cclass/int/sx8.html*/
