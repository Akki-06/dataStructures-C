#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef enum{FALSE,TRUE}boolean;

typedef struct{
    int Front,Rear;
    int arr[SIZE];
}Queue;

void createQueue(Queue *q){
    q->Front = q->Rear = -1;
}

boolean IsEmpty(Queue *q){
    if((q->Front == -1)&&(q->Rear == -1))
        return TRUE;
    else
        return FALSE;
}

boolean IsFull(Queue *q){
    if((q->Rear+1)%SIZE == q->Front)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *q,int item){
    if(IsFull(q))
        printf("\nQUEUE OVERFLOW !!");
    else{
        if((q->Front == -1)&&(q->Rear == -1)){
            q->Front = q->Rear = 0;
        }else{
            q->Rear = (q->Rear+1)%SIZE;
        }
        q->arr[q->Rear] = item;
    }
    printf("\n");
}

void Dequeue(Queue *q){
    if(IsEmpty(q))
        printf("\nQUEUE UNDERFLOW !!");
    else{
        printf("\nDequeued Element : %d",q->arr[q->Front]);
        if(q->Front == q->Rear)
            q->Front = q->Rear = -1;
        else
            q->Front = (q->Front+1)%SIZE;
    }
    printf("\n");
}

void Display(Queue *q){
    if(IsEmpty(q))
        printf("\nQUEUE UNDERFLOW !!");
    else{
        int i = q->Front;
        printf("\nQueue Elements : \n");
        while(i!= q->Rear){
            printf("%d\t",q->arr[i]);
            i = (i+1)%SIZE;
        }
        printf("%d\t",q->arr[i]);
    }
    printf("\n\n");
}

int main()
{
    Queue q;
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
            case 1 : createQueue(&q);
                     break;

            case 2 : printf("\nEnter the element to Enqueue : ");
                     scanf("%d",&item);
                     Enqueue(&q,item);
                     break;

            case 3 : Dequeue(&q);
                     break;

            case 4 : Display(&q);
                     break;

            case 5 : exit(0);

            default : printf("\nINVALID CHOICE!!!");
        }

    }

    return 0;

}
