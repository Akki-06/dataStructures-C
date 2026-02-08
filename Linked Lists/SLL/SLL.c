#include<stdio.h>
#include<stdlib.h>

typedef struct singly{
    int info;
    struct singly *next;
}Node;

void create_empty(Node **start)
{
    *start = NULL;
}

void Insert_Beg(Node **start,int item)
{
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));

    if(temp == NULL){
        printf("\n Memory Allocation Failed !!\n\n");
        return;
    }

    temp->info = item;

    if(*start == NULL){
        temp->next = NULL;
    }else{
        temp->next = *start;
    }
    *start = temp;
}

void Insert_End(Node **start,int item)
{
    Node *temp,*current;

    temp = (Node*)malloc(sizeof(Node));

    if(temp == NULL){
        printf("\n Memory Allocation Failed !!\n\n");
        return;
    }

    temp->info = item;
    temp->next = NULL;

    if(*start == NULL){
        *start = temp;
     }else{
        current = *start;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
     }
}

void Insert_After(Node **start)
{
    Node *temp,*current;
    int after,item;

    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        printf("\n Enter the specific element to insert after : ");
        scanf("%d",&after);
        printf("\n Enter the element to insert : ");
        scanf("%d",&item);
        current = *start;
        while(current != NULL && current->info != after)
        {
            current = current->next;
        }
        if(current == NULL){
            printf("\n Element not found in the list");
        }else{
            temp = (Node*)malloc(sizeof(Node));
            temp->info = item;
            temp->next = current->next;
            current->next = temp;
        }
    }
}

void Delete_Beg(Node **start)
{
    Node *ptr;
    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        ptr = *start;
        *start = ptr->next;
        free(ptr);
    }
}

void Delete_End(Node **start)
{
    Node *ptr,*temp;
    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        ptr = *start;
        if(ptr->next==NULL)
        {
            *start = NULL;
            free(ptr);
        }
        else
        {
            while(ptr->next != NULL)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            temp->next = NULL;
            free(ptr);
        }
    }
}

void Delete_Specific(Node **start)
{
    Node *temp,*ptr;
    int item;
    if(*start == NULL){
        printf("\n List is Empty");
    }else{
        printf("\n Enter the element to delete after : ");
        scanf("%d",&item);
        ptr = *start;
        while((ptr != NULL) && (ptr->info != item))
        {
            temp = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL)
        {
            printf("\n Element not found in the list");
        }
        else
        {
            if(ptr == *start)
            {
                *start = ptr->next;
            }
            else
            {
                temp->next = ptr->next;
            }
            free(ptr);
        }
    }
}
void Search(Node **start,int SE)
{
    Node *current;
    int p = 0,found = 0;

    if (*start == NULL){
        printf("\n List is Empty !!\n\n");
    }else{
        current = *start;
        while(current != NULL)
        {
            p++;
            if(current->info == SE)
            {
                found = 1;
                break;
            }
            current = current->next;
        }

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
        while(current != NULL)
        {
            printf("\t%d",current->info);
            current = current->next;
        }
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
        printf("\n Press 7  : Delete a specific node");
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
                     Insert_Beg(&start,item);
                     break;
            case 3 : printf("\n Enter the Element to add at End : ");
                     scanf("%d",&item);
                     Insert_End(&start,item);
                     break;
            case 4 : Insert_After(&start);
                     break;

            case 5 : Delete_Beg(&start);
                     break;
            case 6 : Delete_End(&start);
                     break;

            case 7 : Delete_Specific(&start);
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
