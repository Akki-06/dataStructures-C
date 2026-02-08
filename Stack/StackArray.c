#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef enum{FALSE, TRUE}Boolean;

typedef struct{
    int sp;
    int arr[MAX];
}Stack;

void create_Stack(Stack *s){
    s->sp = -1;
}


Boolean IsEmpty(Stack *s){
    if(s->sp == -1)
        return TRUE;
    else
        return FALSE;
}

Boolean IsFull(Stack *s){
    if(s->sp == (MAX-1))
        return TRUE;
    else
        return FALSE;
}

void Push(Stack *s){
    int item;
    if(IsFull(s))
        printf("\nSTACK OVERFLOW!!!");
    else{
        printf("\nEnter the Element to Push : ");
        scanf("%d",&item);

        s->arr[++s->sp] = item;
    }
    printf("\n");
}

void Pop(Stack *s){
    int item;
    if(IsEmpty(s))
        printf("\nSTACK UNDERFLOW!!!");
    else{
        item = s->arr[s->sp];
        s->sp--;
        printf("\nPopped Item : %d",item);
    }
}

void Display(Stack *s){
    if(IsEmpty(s))
        printf("\nSTACK UNDERFLOW!!!");
    else{
        for(int i = s->sp; i>=0; i--)
            printf("%d\t",s->arr[i]);
        printf("\n");
    }
    printf("\n");
}

void Peek(Stack *s){
    if(IsEmpty(s))
        printf("\nSTACK UNDERFLOW!!!");
    else{
        printf("Top Element : %d\n",s->arr[s->sp]);
    }
    printf("\n");
}

int main()
{
    Stack s;
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
            case 1 : create_Stack(&s);
                     break;

            case 2 : Push(&s);
                     break;

            case 3 : Pop(&s);
                     break;

            case 4 : Display(&s);
                     break;

            case 5 : Peek(&s);
                     break;

            case 6 : exit(0);

            default : printf("\nINVALID CHOICE!!!");
        }

    }

    return 0;
}

