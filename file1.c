#include<stdio.h>

int main(){
    FILE* fp;
    
    fp = fopen("test.txt","w+");
    fprintf(fp,"to jest test\n");
    fputs("test fputs\n",fp);
    fclose(fp);
    
    return 0;
    }
