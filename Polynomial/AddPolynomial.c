#include<stdio.h>
#include<stdlib.h>

typedef struct Poly{
    int coeff, expo;
    struct Polynode *next;
}Polynode;

void create_poly(Polynode **Poly1, Polynode **Poly2)
{
    *Poly1 =NULL;
    *Poly2 = NULL;
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

void Add_Polynomial(Polynode **Poly1, Polynode **Poly2, Polynode **Poly3)
{
    int coeff, expo;
    Polynode *p1, *p2;

    p1 = *Poly1;
    p2 = *Poly2;

    while((p1!=NULL)&&(p2!=NULL))
    {
        if(p1->expo > p2->expo)
        {
            coeff = p1->coeff;
            expo = p1->expo;
            p1 = p1->next;
        }
         else if(p2->expo > p1->expo)
        {
            coeff = p2->coeff;
            expo = p2->expo;
            p2 = p2->next;
        }
        else
        {
            coeff = p1->coeff + p2->coeff;
            expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        }
        Add_Polynode(Poly3,coeff,expo);
    }

    if(p1 == NULL)
    {
        while(p2!=NULL)
        {
            Add_Polynode(Poly3,p2->coeff,p2->expo);
            p2 = p2->next;
        }
    }
     if(p2 == NULL)
    {
        while(p1!=NULL)
        {
            Add_Polynode(Poly3,p1->coeff,p1->expo);
            p1 = p1->next;
        }
    }
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
    Polynode *Pl1,*Pl2,*Pl3;
    Pl3 = NULL;
    int ch;

    while(1)
    {
         printf("\nPRESS 1 : Create a Polynomial 1&2");
         printf("\nPRESS 2 : Add term to Polynomial 1");
         printf("\nPRESS 3 : Add term to Polynomial 2");
         printf("\nPRESS 4 : Add Polynomial 1&2");
         printf("\nPRESS 5 : Display Polynomial 1");
         printf("\nPRESS 6 : Display Polynomial 2");
         printf("\nPRESS 7 : Display Polynomial 3");
         printf("\nPRESS 8 : Exit");

         printf("\n\nEnter your Choice : ");
         scanf("%d",&ch);
         printf("\n");

         switch(ch)
         {
             case 1 : create_poly(&Pl1,&Pl2);
                      break;

             case 2 : Read_Poly(&Pl1);
                      break;

             case 3 : Read_Poly(&Pl2);
                      break;

             case 4 : Add_Polynomial(&Pl1,&Pl2,&Pl3);
                      break;

             case 5 : Display_Poly(&Pl1);
                      break;

             case 6 : Display_Poly(&Pl2);
                      break;

             case 7 : Display_Poly(&Pl3);
                      break;

             case 8 : exit(0);

             default : printf("\nInvalid Choice!!\n");
                       break;
         }
    }
    return 0;
}
