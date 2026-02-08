//C program to multiply two matrices
#include<stdio.h>

int main()
 {

     int m1,n1,m2,n2,i,j,k;

     printf("***********************************************************\n");
     printf("                     MULTIPLY MATRICES                     \n");
     printf("***********************************************************\n");
     printf("\n");

     printf("Enter the no. of Rows of 1st Matrix: ");
     scanf("%d",&m1);
     printf("Enter the no. of Columns of 1st Matrix: ");
     scanf("%d",&n1);
     printf("\n");
     printf("Enter the no. of Rows of 2nd Matrix: ");
     scanf("%d",&m2);
     printf("Enter the no. of Columns of 2nd Matrix: ");
     scanf("%d",&n2);

     if(n1!=m2)
     {
         printf("\n Multiplication not possible because number of Column of Matrix 1 is not Equal to number of Rows of Matrix 2.");
         return 0 ;
     }


     int Arr1[m1][n1], Arr2[m2][n2], Multiply[m1][n2];

     printf("\nEnter element of 1st Matrix :\n\n");
     for(i=0;i<m1;i++)
     {
        for (j=0;j<n1;j++)
        {
            printf("\tIndex [%d][%d]: ",i,j);
            scanf("%d", &Arr1[i][j]);
        }
     }

    printf("\n");

    printf("\nEnter element of 2nd Matrix :\n\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("\tIndex [%d][%d]: ",i,j);
            scanf("%d", &Arr2[i][j]);
        }
    }

    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            Multiply[i][j] = 0;
        }
    }

     for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            for(k=0;k<n1;k++)
            {
                Multiply[i][j] += Arr1[i][k] * Arr2[k][j];
            }
        }
    }

    printf("\n\n Matrix after multiplication: \n\n");

     for(i=0;i<m1;i++)
     {
         for(j=0;j<n2;j++)
         {
             printf("\t%d",Multiply[i][j]);
         }
         printf("\n\n\n");
     }

      return 0;
 }
