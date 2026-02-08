#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef enum{FALSE, TRUE}Boolean;

typedef struct{
    int sp1,sp2;
    int arr[MAX];
}Stack;


void create_Stack(Stack *s){
    s->sp1 = -1;
    s->sp2 = MAX;
}

void Push1(Stack *s){
    int item;
    if((s->sp1)+1 == s->sp2)
       printf("\nSTACK OVERFLOW!!!");
    else{
        printf("\nEnter the Element to Push : ");
        scanf("%d",&item);

        s->arr[++s->sp1] = item;
    }
    printf("\n");
}

void Push2(Stack *s){
    int item;
    if((s->sp1)+1 == s->sp2)
       printf("\nSTACK OVERFLOW!!!");
    else{
        printf("\nEnter the Element to Push : ");
        scanf("%d",&item);

        s->arr[--s->sp2] = item;
    }
    printf("\n");}

void Pop1(Stack *s){
    if(s->sp1 == -1)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        s->sp1--;
        printf("\nPopped Item : %d",s->arr[s->sp1]);
    }
    printf("\n");
}

void Pop2(Stack *s){
    if(s->sp2 == MAX)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        s->sp2++;
        printf("\nPopped Item : %d",s->arr[s->sp2]);
    }
    printf("\n");
}

void Display1(Stack *s){
    if(s->sp1 == -1)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        for(int i = s->sp1; i > -1; i--)
            printf("%d\t",s->arr[i]);
        printf("\n");
    }
    printf("\n");
}

void Display2(Stack *s){
    if(s->sp1 == MAX)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        for(int i = s->sp2; i < MAX; i++)
            printf("%d\t",s->arr[i]);
        printf("\n");
    }
    printf("\n");
}

void Peek1(Stack *s){
    if(s->sp1 == -1)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        printf("Top Element : %d\n",s->arr[s->sp1]);
    }
    printf("\n");
}

void Peek2(Stack *s){
    if(s->sp2 == MAX)
        printf("\nSTACK UNDERFLOW!!!");
    else{
        printf("Top Element : %d\n",s->arr[s->sp2]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    int c;

    while(1)
    {
        printf("PRESS 1 : Create Empty 2-Way Stack\n");
        printf("PRESS 2 : Push an Element in Stack 1\n");
        printf("PRESS 3 : Push an Element in Stack 2\n");
        printf("PRESS 4 : Pop an Element from Stack 1\n");
        printf("PRESS 5 : Pop an Element from Stack 2\n");
        printf("PRESS 6 : Display the Stack 1\n");
        printf("PRESS 7 : Display the Stack 2\n");
        printf("PRESS 8 : Peek from Stack 1\n");
        printf("PRESS 9 : Peek from Stack 1\n");
        printf("PRESS 10: Exit\n");

        printf("\nEnter your Choice : ");
        scanf("%d",&c);
        printf("\n");

        switch(c)
        {
            case 1 : create_Stack(&s);
                     break;

            case 2 : Push1(&s);
                     break;

            case 3 : Push2(&s);
                     break;

            case 4 : Pop1(&s);
                     break;

            case 5 : Pop2(&s);
                     break;

            case 6 : Display1(&s);
                     break;

            case 7 : Display2(&s);
                     break;

            case 8 : Peek1(&s);
                     break;

            case 9 : Peek2(&s);
                     break;

            case 10: exit(0);

            default: printf("\nINVALID CHOICE!!!");
        }

    }

    return 0;
}
