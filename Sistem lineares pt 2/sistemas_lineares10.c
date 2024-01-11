#include <stdio.h>  
#include <stdlib.h>
#include <math.h>

 main()
{    

float  A[10][10], B[10][11];
float  b[10], x[10], Laux[10]; 
int i=0,j=0,k=0,n,l; 
float m, S;
/* leitura da ordem da matriz */
printf("\n Entre com a ordem da matriz de coeficientes do sistema linear.\n");
printf("\n n = ");scanf("%d", &n);

/* leitura dos dados da matriz */
printf(" \n Entre com os elementos da matriz de coeficientes do sistema linear.\n");
printf("\n Entre com as linhas.\n");
for(i=0; i < n; i++)
{
 printf("\n");
 for (j=0; j < n; j++)
 {
   printf(" A=[%d][%d] = " , i,j); scanf("%f", &A[i][j]);
 }
}
 /* leitura do vetor */ 
printf("\n Entre com os elementos dos termos independentes de cada equação.\n");
  for(i=0; i < n; i++)
  {
    printf("b[%d] = ", i); scanf("%f", &b[i]);
  }
 /* Montando a matriz expandida */
  
for(i=0; i<n; i++)
{
 for (j=0; j<n; j++)
 {
   B[i][j] = A[i][j];
 }
}

for (i=0; i<n; i++)
 {
   B[i][n] = b[i];
 }

/* impressão da matriz expandida */

for(i=0; i<n; i++)
{
 printf("\n");
 for (j=0; j<=n; j++)
 {
   printf(" B=[%d][%d] = %2.5f " , i,j, B[i][j]);
 }
}

fflush(stdin);
getchar();
 
/* escalonamento da matriz expandida */

for(k=0;k<n-1;k++)
 {                                 
     for(i=k+1;i<n; i++)
     {
        m = B[i][k]/B[k][k];
        B[i][k]=0;
        for(j=k+1;j<=n;j++)
         { 
           B[i][j] =(B[i][j]) - (m*B[k][j]);
          
         }
      }  
 }
 
  
/* Impressão Matriz escalonada */

printf("\n Matriz escalonada.\n");
for(i=0; i<n; i++)
{
 printf("\n");
 for (j=0; j<=n; j++)
 {
   printf(" B=[%d][%d] = %2.5f " , i,j, B[i][j]);
 }
}
 
fflush(stdin);
getchar();

/* Resolução do sistema triangular */

x[n-1]= B[n-1][n]/B[n-1][n-1];

for(i=n-2; i>-1; i--)
{
  S=0;         
  for(k=i+1; k<n; k++)
  {
   S = S + B[i][k]*x[k];
  }
  x[i]= (-S + B[i][n])/B[i][i];

}

/* Impressão da solucao */

printf("\n Solucao do sistema.\n");
 for (i=0; i<n; i++)
 {
   printf(" x=[%d] = %f " , i, x[i]);
 }

fflush(stdin);
getchar();

}

