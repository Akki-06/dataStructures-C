#include<stdio.h>
#include<stdlib.h>

typedef struct circular{
    int info;
    struct circular *next;
}Node;

void create_empty(Node **start)
{
    *start = NULL;
}

void Insert_CBeg(Node **start,int item)
{
    Node *temp, *last;
    temp = (Node*)malloc(sizeof(Node));

    if(temp == NULL){
        printf("\n Memory Allocation Failed !!\n\n");
        return;
    }

    temp->info = item;

    if(*start == NULL){
        temp->next = temp;
        *start = temp;
    }else{
        last = *start;
        while(last->next != *start)
        {
            last = last->next;
        }
        temp->next = *start;
        last->next = temp;
    }
    *start = temp;
}

void Insert_CEnd(Node **start,int item)
{
    Node *temp, *current;
    temp = (Node*)malloc(sizeof(Node));

    if(temp == NULL){
        printf("\n Memory Allocation Failed !!\n\n");
        return;
    }

    temp->info = item;

    if(*start == NULL){
        temp->next = temp;
        *start = temp;
    }else{
        current = *start;
        while(current->next != *start)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = *start;
    }
}

void Insert_CAfter(Node **start)
{
    Node *temp, *current;
    int after, item;

    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        printf("\n Enter the specific element to insert after : ");
        scanf("%d",&after);
        printf("\n Enter the element to insert : ");
        scanf("%d",&item);
        current = *start;
        do{
            if(current->info == after)
            {
                temp = (Node*)malloc(sizeof(Node));
                temp->info = item;
                temp->next = current->next;
                current->next = temp;
                return;
            }
            current = current->next;
        } while(current != *start);
        printf("\n Element not found in the list");
    }
}

void Delete_CBeg(Node **start)
{
    Node *ptr, *last;
    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        ptr = *start;
        if(ptr->next == *start) {
            *start = NULL;
        } else {
            last = *start;
            while(last->next != *start)
            {
                last = last->next;
            }
            *start = ptr->next;
            last->next = *start;
        }
        free(ptr);
    }
}

void Delete_CEnd(Node **start)
{
    Node *ptr, *temp;
    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        ptr = *start;
        if(ptr->next == *start)
        {
            *start = NULL;
            free(ptr);
        }
        else
        {
            while(ptr->next->next != *start)
            {
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = *start;
            free(temp);
        }
    }
}

void Search(Node **start,int SE)
{
    Node *current;
    int p = 0, found = 0;

    if (*start == NULL){
        printf("\n List is Empty !!\n\n");
    }else{
        current = *start;
        do{
            p++;
            if(current->info == SE)
            {
                found = 1;
                break;
            }
            current = current->next;
        } while(current != *start);

        if(found){
            printf("\n\n Element found at position %d\n\n",p);
        }else{
            printf("\n\n Element not found in the List.\n\n");
        }
    }
}

void Display(Node **start)
{
    Node *current;
    if(*start == NULL){
        printf("\n\n List is Empty !!");
    }else{
        current = *start;
        printf("\n\nList Elements : \n");
        do{
            printf("\t%d",current->info);
            current = current->next;
        } while(current != *start);
        printf("\n\n\n");
    }
}

int main()
{
    Node *start = NULL;
    int c, item;

    while(1)
    {
        printf("\n Press 1  : Create Empty List");
        printf("\n Press 2  : Insert at Beginning");
        printf("\n Press 3  : Insert at End");
        printf("\n Press 4  : Insert after a specific element");
        printf("\n Press 5  : Delete from Beginning");
        printf("\n Press 6  : Delete from End");
        printf("\n Press 8  : Search an Element");
        printf("\n Press 9  : Display the List");
        printf("\n Press 10 : Exit the Program");

        printf("\n\n Enter your choice : ");
        scanf("%d",&c);

        switch (c)
        {
            case 1 : create_empty(&start);
                     break;
            case 2 : printf("\n Enter the Element to add at Beginning : ");
                     scanf("%d",&item);
                     Insert_CBeg(&start,item);
                     break;
            case 3 : printf("\n Enter the Element to add at End : ");
                     scanf("%d",&item);
                     Insert_CEnd(&start,item);
                     break;
            case 4 : Insert_CAfter(&start);
                     break;
            case 5 : Delete_CBeg(&start);
                     break;
            case 6 : Delete_CEnd(&start);
                     break;
            case 8 : printf("\n Enter the Element to search : ");
                     scanf("%d",&item);
                     Search(&start,item);
                     break;
            case 9 : Display(&start);
                     break;
            case 10 : exit(0);
            default : printf("\n Invalid Choice !!\n\n");
        }
    }
    return 0;
}
