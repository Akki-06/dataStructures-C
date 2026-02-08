#include<stdio.h>

void main()
{
    int n,i,se,token=0;

    printf("***********************************************************\n");
    printf("                       LINEAR SEARCH                       \n");
    printf("***********************************************************\n");

    printf("\n\tEnter total no. of Elements : ");
    scanf("%d",&n);
    printf("\n");

    int num[n];

    for(i=0;i<n;i++)
    {
        fflush(stdin);
        printf("\tEnter Element at Index[%d] : ",i);
        scanf("%d",&num[i]);
    }

    printf("\n\tEnter Element to Search : ");
    scanf("%d",&se);

    for(i=0;i<n;i++)
    {
        if(se==num[i])
        {
            token = 1;
            printf("\n\n\tElement found at Index [%d] !!\n",i);
            break;
        }
    }
    if(token==0)
    {
        printf("\n\n\tElement not found!!\n");
    }
}
