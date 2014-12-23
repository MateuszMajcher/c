#include<stdio.h>
typedef struct String_Struct* String;

struct String_Struct
{
       char* (*get)(const void* self);
       void (*set)(const void* self,char* value);
       int (*length)(const void* self);
};
int main(){
    
    
    
   return 0; 
    }
