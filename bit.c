#include<stdio.h>


int bitcount(unsigned char a);

int main(){
    bitcount('a');
    printf("%d", bitcount('7'));
    getchar();
    return 0;
    }
    
    int bitcount(unsigned char a){
        int count;
        for(count = 0;a!=0;a>>=1)/*przesuwanie w prawo*/
        {
                  if (a&01)  
                  count++;
                  }
        return count;
        }
