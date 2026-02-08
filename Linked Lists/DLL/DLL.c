#include<stdio.h>
#include<stdlib.h>

typedef struct doubly{
    int info;
    struct doubly *prev, *next;
}Dnode;

void create_empty(Dnode **head, Dnode **tail)
{
    *head = *tail = NULL;
}

void Insert_Dbeg(Dnode **head, Dnode **tail, int item)
{
    Dnode *temp;
    temp = (Dnode*)malloc(sizeof(Dnode));
    temp->prev = NULL;
    temp->info = item;

    if(*head == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        *head = *tail = temp;
    }
    else{
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

void Insert_Dend(Dnode **head, Dnode **tail, int item)
{
    Dnode *temp;
    temp = (Dnode*)malloc(sizeof(Dnode));
    temp->info = item;
    if(*head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        *head = *tail = temp;
    }
    else{
        temp->next = NULL;
        temp->prev = *tail;
        (*tail)->next = temp;
        *tail = temp;
    }
}

void Insert_Dafter(Dnode **head, Dnode **tail)
{
    Dnode *temp, *current;
    int item, after;
    if(*head == NULL){
        printf("\n\t List is Empty!\n");
    }
    else{
        printf("\nEnter element to insert after : ");
        scanf("%d",&after);
        printf("\nEnter element to insert : ");
        scanf("%d",&item);

        current = *head;
        while((current != NULL) && (current->info != after)){
            current = current->next;
        }
        if(current == NULL){
            printf("\n\tElement not found in list !\n");
        }
        else{
            if(current->next == NULL){
                Insert_Dend(head,tail,item);
            }else{
                temp = (Dnode*)malloc(sizeof(Dnode));
                temp->info = item;
                temp->next = current->next;
                temp->prev = current;
                (current->next)->prev = temp;
                current->next = temp;
            }
        }
    }
}

void Insert_Dbefore(Dnode **head, Dnode **tail)
{
     Dnode *temp, *current;
    int item, before;
    if(*head == NULL){
        printf("\n\tList is Empty!\n");
    }
    else{
        printf("\nEnter element to insert before: ");
        scanf("%d",&before);
        printf("\nEnter element to insert : ");
        scanf("%d",&item);

        current = *head;
        while((current != NULL) && (current->info != before)){
            current = current->next;
        }
        if(current == NULL){
            printf("\n\tElement not found in list !\n");
        }
        else{
            if(current->prev == NULL){
                Insert_Dbeg(head,tail,item);
            }
            else{
                temp = (Dnode*)malloc(sizeof(Dnode));
                temp->info = item;
                temp->prev = current->prev;
                temp->next = current;
                (current->prev)->next = temp;
                current->prev = temp;
            }
        }
    }
}

void Traverse_Forward(Dnode *head)
{
    Dnode *current;
    if(head == NULL){
        printf("\n\tList is empty !\n");
    }
    else{
        current = head;
        printf("\n\tList Elements :\n");
        while(current != NULL)
        {
            printf("\t%d",current->info);
            current = current->next;
        }
    }
    printf("\n");
}

void Traverse_Backward(Dnode *tail)
{
    Dnode *current;
    if(tail == NULL){
        printf("\n\tList is empty !\n");
    }
    else{
        current = tail;
        printf("\n\tList Elements :\n");
        while(current != NULL)
        {
            printf("\t%d",current->info);
            current = current->prev;
        }
    }
    printf("\n");
}

void Delete_Dstart(Dnode **head, Dnode **tail)
{
    Dnode *ptr;
    if(*head == NULL){
        printf("\n\tList is empty !\n");
    }
    else{
        ptr = *head;
        if(ptr->next == NULL){
            *head = *tail = NULL;
        }
        else{
            (ptr->next)->prev = NULL;
            *head = ptr->next;
        }
    }
    printf("\n\tDeleted element : %d\n",ptr->info);
    free(ptr);
}

void Delete_Dend(Dnode **head, Dnode **tail)
{
    Dnode *ptr;
    if(*head == NULL){
        printf("\n\t List is empty !\n");
    }
    else{
        ptr = *tail;
        if(ptr->prev == NULL){
            *head = *tail = NULL;
        }
        else{
            (ptr->prev)->next = NULL;
            *tail = ptr->prev;
        }
    }
    printf("\n\tDeleted element : %d\n",ptr->info);
    free(ptr);
}

void delete_Dafter(Dnode **head, Dnode **tail)
{
    Dnode *current, *temp;
    int after;
    if(*head == NULL){
        printf("\nList is Empty!!");
    }
    else{
        printf("\nEnter the element to Delete after : ");
        scanf("%d",&after);

        current = *head;
        while((current!=NULL)&&(current->info!=after)){
            current = current->next;
        }
        if(current == NULL){
            printf("\nElement not found in the List!\n");
        }
        else{
            if(current==(*tail)){
                printf("\nOperation not Possible!!");
            }
            else{
                temp = current->next;
                if(temp->next == NULL){
                    current->next = NULL;
                    *tail = current;
                }
                else{
                    current->next = temp->next;
                    (temp->next)->prev = current;
                }
                printf("\nDeleted Item : %d\n",temp->info);
                free(temp);
            }
        }
    }
}

void delete_Dbefore(Dnode **head, Dnode **tail)
{
    Dnode *current, *temp;
    int before;
    if(*head == NULL){
        printf("\nList is Empty!!");
    }
    else{
        printf("\nEnter the element to Delete before : ");
        scanf("%d",&before);

        current = *tail;
        while((current!=NULL)&&(current->info!=before)){
            current = current->prev;
        }
        if(current == NULL){
            printf("\nElement not found in the List!\n");
        }
        else{
            if(current==(*head)){
                printf("\nOperation not Possible!!");
            }
            else{
                temp = current->prev;
                if(temp->prev == NULL){
                    current->prev = NULL;
                    *head = current;
                }
                else{
                    current->prev = temp->prev;
                    (temp->prev)->next = current;
                }
                printf("\nDeleted Item : %d\n",temp->info);
                free(temp);
            }
        }
    }
}

void Delete_DSpec(Dnode **head, Dnode **tail)
{
    Dnode *ptr;
    int spec;

    if(*head == NULL){
        printf("\nList is Empty!!");
    }
    else{
        printf("\nEnter the Specific element to delete : ");
        scanf("%d",&spec);

        ptr = *head;
        while((ptr!=NULL)&&(ptr->info!=spec)){
            ptr = ptr->next;
        }
        if(ptr == NULL){
            printf("\nElement not found in the list!!");
        }
        else{
          if((ptr->next== NULL) && (ptr->prev==NULL)){
             printf("\nDeleted Element : %d",ptr->info);
             free(ptr);
             *head = *tail = NULL;
          }
          else{
              if(ptr == *head){
                (ptr->next)->prev = NULL;
                *head = ptr->next;
            }
            else if(ptr == *tail){
                (ptr->prev)->next = NULL;
                *tail = ptr->prev;
            }
            else{
                (ptr->next)->prev = ptr->prev;
                (ptr->prev)->next = ptr->next;
            }
           printf("\nDeleted Element : %d",ptr->info);
           free(ptr);
          }
        }
    }
}

int main()
{
    Dnode *head, *tail;
    int c, item;

     while(1)
    {
        printf("\n Press 1  : Create Empty List");
        printf("\n Press 2  : Insert at Beginning");
        printf("\n Press 3  : Insert at End");
        printf("\n Press 4  : Insert after a specific element");
        printf("\n Press 5  : Insert before a specific element");
        printf("\n Press 6  : Traverse Forward");
        printf("\n Press 7  : Traverse Backward");
        printf("\n Press 8  : Delete from Start");
        printf("\n Press 9  : Delete from End");
        printf("\n Press 10 : Delete after a Specific Node");
        printf("\n Press 11 : Delete before a Specific Node");
        printf("\n Press 12 : Delete  a Specific Node");
        printf("\n Press 13 : Exit the Program");

        printf("\n\n Enter your choice : ");
        scanf("%d",&c);

        switch (c)
        {
            case 1 : create_empty(&head,&tail);
                     break;

            case 2 : printf("\n Enter the Element to add at Beginning : ");
                     scanf("%d",&item);
                     Insert_Dbeg(&head,&tail,item);
                     break;

            case 3 : printf("\n Enter the Element to add at End : ");
                     scanf("%d",&item);
                     Insert_Dend(&head,&tail,item);
                     break;

            case 4 : Insert_Dafter(&head,&tail);
                     break;

            case 5 : Insert_Dbefore(&head,&tail);
                     break;

            case 6 : Traverse_Forward(head);
                     break;

            case 7 : Traverse_Backward(tail);
                     break;

            case 8 : Delete_Dstart(&head,&tail);
                     break;

            case 9 : Delete_Dend(&head,&tail);
                     break;

            case 10 : delete_Dafter(&head,&tail);
                      break;

            case 11 : delete_Dbefore(&head,&tail);
                      break;

            case 12 : Delete_DSpec(&head,&tail);
                      break;

            case 13 : exit(0);

            default : printf("\n Invalid Choice !!\n\n");
        }
    }

    return 0;
}
