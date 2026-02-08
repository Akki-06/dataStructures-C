#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int info;
    struct Stack *next;
}Stack;

void create_Stack(Stack **sp){
    *sp = NULL;
}

void Push(Stack **sp){
    Stack *temp;
    int item;

    temp = (Stack*)malloc(sizeof(Stack));
    if(!temp){
        printf("\nMemory Allocation Failed!!");
        return;
    }
    printf("\nEnter the Element to Push : ");
    scanf("%d",&item);

    temp->info = item;
    temp->next = *sp;
    *sp = temp;

    printf("\n");
}

void Pop(Stack **sp){
    Stack *temp;
    if(*sp == NULL)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        temp = *sp;
        printf("\nPopped Item : %d",temp->info);
        *sp = (*sp)->next;
        free(temp);
    }
    printf("\n");
}

void Display(Stack **sp){
    Stack *temp;
    if(*sp == NULL)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        temp = *sp;
        printf("\nStack Elements: ");
        while(temp != NULL){
            printf("\t%d",temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

void Peek(Stack **sp){
    if(*sp == NULL)
        printf("\nStack is Empty!!");
    else
        printf("\nTop Element : %d\n",(*sp)->info);
    printf("\n");
}

int main()
{
    Stack *sp;
    int c;

    while(1)
    {
        printf("PRESS 1 : Create Empty Stack\n");
        printf("PRESS 2 : Push an Element\n");
        printf("PRESS 3 : Pop an Element\n");
        printf("PRESS 4 : Display the Stack\n");
        printf("PRESS 5 : Peek the Element\n");
        printf("PRESS 6 : Exit\n");

        printf("\nEnter your Choice : ");
        scanf("%d",&c);
        printf("\n");

        switch(c)
        {
            case 1 : create_Stack(&sp);
                     break;

            case 2 : Push(&sp);
                     break;

            case 3 : Pop(&sp);
                     break;

            case 4 : Display(&sp);
                     break;

            case 5 : Peek(&sp);
                     break;

            case 6 : exit(0);

            default : printf("\nINVALID CHOICE!!!");
        }

    }

    return 0;
}


