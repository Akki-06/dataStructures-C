//C program to add two matrices
#include<stdio.h>

int main()
 {
     int m1,n1,m2,n2,i,j;

    printf("***********************************************************\n");
    printf("                       ADD MATRICES                        \n");
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

    printf("\n");

    if (m1 != m2 || n1 != n2)
    {
        printf("\nThe matrices are not equal (different dimensions).\n");
        return;
    }


    int Arr1[m1][n1], Arr2[m2][n2], Sum[m1][n1];

    printf("Enter element of 1st Matrix :\n\n");
    for(i=0;i<m1;i++)
    {
        for (j=0;j<n1;j++)
        {
            printf("\tIndex [%d][%d]: ",i,j);
            scanf("%d", &Arr1[i][j]);
        }
    }

    printf("\n\n");

    printf("Enter element of 2nd Matrix :\n\n");
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
        for(j=0;j<n1;j++)
        {
            Sum[i][j] = Arr1[i][j] + Arr2[i][j];
        }
    }

    printf("\n\n");
    printf("Matrix after Addition : \n\n");