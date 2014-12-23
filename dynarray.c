#include<stdio.h>
#include<stdlib.h>

/*
  Name: talice wielowymiarowe
  Copyright: 
  Author: Mateusz Majcher
  Date: 22-12-14 17:07
  Description: Dynamiczne tablice wielowymiarowe
*/


double** Make2DDoubleArray(int arraySizeX, int arraySizeY) {  
double** theArray;  
int i;
theArray = (double**) malloc(arraySizeX*sizeof(double*));  
for ( i = 0; i < arraySizeX; i++)  
   theArray[i] = (double*) malloc(arraySizeY*sizeof(double));  
   return theArray;  
}  


int main(){
    int i,j,rozmiara,rozmiarb;
    char a;
    printf("Podaj rozmiar tablicy xn: \n");
    scanf("%d",&rozmiara);
    printf("Podaj rozmiar tablicy yn: \n");
    scanf("%d",&rozmiarb);
    double** myArray = Make2DDoubleArray(rozmiara, rozmiarb);
    
     for ( i = 0; i < rozmiara; i++ )
   {
      for ( j = 0; j < rozmiarb; j++ )
      {
         printf("a[%d][%d] podaj wartosc\n", i,j);
         scanf("%f",&myArray[i][j]);
      }
   }
    printf("Podaj rozmiar tablicy yn: %d\n",sizeof(myArray));
    scanf("%d",&rozmiarb);
  
    
    return 0;
    }
