#include<stdio.h>

void takeInput(int *base, int *i,int *j,int *m,int *n,int *w)
{
    printf("\tEnter Base Address : ");
    scanf("%d",base);
    printf("\tEnter value of Row(i): ");
    scanf("%d",i);
    printf("\tEnter value of Col(j): ");
    scanf("%d",j);
    printf("\tEnter total no. of Rows(m): ");
    scanf("%d",m);
    printf("\tEnter total no. of Cols(n): ");
    scanf("%d",n);
    printf("\tEnter the Size of data(in Bytes):");
    scanf("%d",w);
}

void ColMajor(int base, int i, int j, int m, int w)
{
    int addr;

    addr = base + w*(m*j+i);
    printf("\n\n\tAddress of location [%d][%d] : %d",i,j,addr);
}

void RowMajor(int base, int i, int j, int n, int w)
{
    int addr;

    addr = base + w*(n*i+j);
    printf("\n\n\tAddress of location [%d][%d] : %d",i,j,addr);
}

int main()
{
   int ch;
   int base, i, j, m, n, w;

   printf("***********************************************************\n");
   printf("                    ADDRESS OF LOCATION                    \n");
   printf("***********************************************************\n");
   printf("\n");
   printf("\t\tPRESS 1 : Col Major Order\n");
   printf("\t\tPRESS 2 : Row Major Order\n");

   printf("\n\tEnter choice : ");
   scanf("%d",&ch);
   printf("\n");

   switch(ch)
   {
       case 1 : takeInput(&base,&i,&j,&m,&n,&w);
                ColMajor(base,i,j,m,w);
                break;

       case 2 : takeInput(&base,&i,&j,&m,&n,&w);
                RowMajor(base,i,j,n,w);
                break;

       default : printf("\n\tInvalid Choice!!");

   }
   return 0;
}
