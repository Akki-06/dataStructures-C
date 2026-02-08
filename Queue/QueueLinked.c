#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int info;
    struct Queue *next;
}Queue;

void createQueue(Queue **Front, Queue **Rear){
    *Front = *Rear = NULL;
}

void Enqueue(Queue **Front, Queue **Rear, int item){
    Queue *temp;
    temp = (Queue*)malloc(sizeof(Queue));
    if(!temp){
        printf("\nMemory Allocation Failed!!");
        return;
    }
    temp->info = item;
    if((*Front == NULL)&&(*Rear == NULL))
        *Front = *Rear = temp;
    else{
        (*Rear)->next = temp;
        *Rear = temp;
    }
    temp->next = NULL;
    printf("\n");
}

void Dequeue(Queue **Front, Queue **Rear){
    Queue *temp;
    if(*Front == NULL)
        printf("\nQUEUE UNDERFLOW !!");
    else{
        temp = *Front;
        printf("\nDequeued Element : %d",temp->info);
        *Front = (*Front)->next;
        if(*Front == NULL)
            *Rear = NULL;
        free(temp);
    }
    printf("\n");
}

void Display(Queue **Front, Queue **Rear){
    Queue *temp;
    if(*Front == NULL)
        printf("\nQUEUE UNDERFLOW !!");
    else{
        temp = *Front;
        while (temp != NULL) {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    Queue *Front, *Rear;
    int c,item;

    while(1)
    {
        printf("PRESS 1 : Create Empty Queue\n");
        printf("PRESS 2 : Enqueue an Element\n");
        printf("PRESS 3 : Dequeue an Element\n");
        printf("PRESS 4 : Display the Queue\n");
        printf("PRESS 5 : Exit\n");

        printf("\nEnter your Choice : ");
        scanf("%d",&c);
        printf("\n");

        switch(c)
        {
            case 1 : createQueue(&Front,&Rear);
                     break;

            case 2 : printf("\nEnter the element to Enqueue : ");
                     scanf("%d",&item);
                     Enqueue(&Front,&Rear,item);
                     break;

            case 3 : Dequeue(&Front,&Rear);
                     break;

            case 4 : Display(&Front,&Rear);
                     break;

            case 5 : exit(0);

            default : printf("\nINVALID CHOICE!!!");
        }

    }

    return 0;

}
