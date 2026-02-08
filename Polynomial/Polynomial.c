#include<stdio.h>
#include<stdlib.h>

typedef struct Poly{
    int coeff, expo;
    struct Polynode *next;
}Polynode;

void create_poly(Polynode **start)
{
    *start = NULL;
}

void Add_Polynode(Polynode **start, int coeff, int expo)
{
    Polynode *temp, *current;
    temp = (Polynode*)malloc(sizeof(Polynode));
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;

    if(*start == NULL){
        *start = temp;
    }
    else{
        current = *start;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = temp;
    }
}

void Read_Poly(Polynode **start)
{
    int coeff, expo;
    printf("Enter From Left to Right\n");
    printf("Enter the Coefficient : ");
    scanf("%d",&coeff);
    printf("Enter the Exponent : ");
    scanf("%d",&expo);

    if(coeff!=0)
        Add_Polynode(start,coeff,expo);
    printf("\n");
}

void Display_Poly(Polynode **start)
{
    Polynode *current;
    if(*start == NULL)
        printf("\nPolynomial is Empty");
    else{
        current = *start;
        while(current!=NULL)
        {
            if((current != *start) && (current->coeff > 0))
                printf("+");

            printf("%dx^%d",current->coeff,current->expo);
            current = current->next;
        }
    }
    printf("\n");
}

int main()
{
    Polynode *Pl;
    int ch;

    while(1)
    {
         printf("\nPRESS 1 : Create a Polynomial");
         printf("\nPRESS 2 : Add term to Polynomial");
         printf("\nPRESS 3 : Display Polynomial");
         printf("\nPRESS 4 : Exit");

         printf("\n\nEnter your Choice : ");
         scanf("%d",&ch);
         printf("\n");

         switch(ch)
         {
             case 1 : create_poly(&Pl);
                      break;

             case 2 : Read_Poly(&Pl);
                      break;

             case 3 : Display_Poly(&Pl);
                      break;

             case 4 : exit(0);

             default : printf("\nInvalid Choice!!\n");
                       break;
         }
    }
    return 0;
}
