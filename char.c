#include<stdio.h>
int main(){
    char s[] = "string";
    printf("strin is %s\n",s);
    char * cp;
    for ( cp = s;*cp;++cp){
       
        printf("adres  is %x\n",cp);
        printf("char is %c\n",*cp);
        }
    
    getchar();
    return 0;
    }
