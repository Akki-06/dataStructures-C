#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}BST;

void createEmpty(BST **tree){
    *tree = NULL;
}

void InsertNode(BST **tree){
    int item;
    BST *temp, *current, *parent;
    temp = (BST*)malloc(sizeof(BST));
    printf("\nEnter Element to Insert : ");
    scanf("%d",&item);

    temp->info = item;;
    temp->left = temp->right = NULL;
    if(*tree == NULL){
        *tree = temp;
    }else{
        parent = NULL;
        current = *tree;
        while(current != NULL){
            parent = current;
            if(item < current->info)
                current = current->left;
            else
                current = current->right;
        }

        if(item < parent->info)
            parent->left = temp;
        else
            parent->right = temp;
    }
    printf("\n");
}

void InorderTraversal(BST *tree){
    if(tree != NULL){
        InorderTraversal(tree->left);
        printf("%d\t",tree->info);
        InorderTraversal(tree->right);
    }
}

void PreorderTraversal(BST *tree){
     if(tree != NULL){
        printf("%d\t",tree->info);
        PreorderTraversal(tree->left);
        PreorderTraversal(tree->right);
    }
}

void PostorderTraversal(BST *tree){
     if(tree != NULL){
        PostorderTraversal(tree->left);
        PostorderTraversal(tree->right);
        printf("%d\t",tree->info);
    }
}

int DetermineHeight(BST *tree){
    int leftHeight, rightHeight;

    if(tree == NULL)
        return 0;
    else{
        leftHeight = DetermineHeight(tree->left);
        rightHeight = DetermineHeight(tree->right);

        if(leftHeight > rightHeight)
            return(++leftHeight);
        else
            return(++rightHeight);
    }
}

int NodeCount(BST *tree){
    if(tree == NULL)
        return 0;
    else
        return(NodeCount(tree->left) + NodeCount(tree->right) + 1);
}

int InternalNodes(BST *tree){
    if(tree == NULL || (tree->left == NULL) && (tree->right == NULL))
        return 0;
    else
        return(InternalNodes(tree->left) + InternalNodes(tree->right) + 1);
}


int ExternalNodes(BST *tree){
   if(tree == NULL)
        return 0;
   else if(tree->left == NULL && tree->right == NULL)
        return 1;
   else
        return ExternalNodes(tree->left) + ExternalNodes(tree->right);

}

BST *LargestNode(BST *tree){
    if((tree == NULL) || (tree->right == NULL))
        return(tree);
    else
        return(LargestNode(tree->right));
}

BST *SmallestNode(BST *tree){
     if((tree == NULL) || (tree->left == NULL))
        return(tree);
    else
        return(SmallestNode(tree->left));
}

void RemoveTree(BST **tree){
    if(*tree != NULL){
        RemoveTree(&(*tree)->left);
        RemoveTree(&(*tree)->right);
        free(*tree);
    }
}

int main(){
    BST *tree;
    int c;

    while(1){
        printf("PRESS 1 : Create a BST\n");
        printf("PRESS 2 : Insert a Node\n");
        printf("PRESS 3 : InOrder Traverse\n");
        printf("PRESS 4 : PreOrder Traverse\n");
        printf("PRESS 5 : PostOrder Traverse\n");
        printf("PRESS 6 : Calculate Height of BST\n");
        printf("PRESS 7 : Count the No of nodes\n");
        printf("PRESS 8 : Count the No of Internal nodes\n");
        printf("PRESS 9 : Count the No of External nodes\n");
        printf("PRESS 10: Largest Node of BST\n");
        printf("PRESS 11: Smallest Node of BST\n");
        printf("PRESS 12: Delete the BST\n");
        printf("PRESS 13: Exit\n");

        printf("\nEnter your Choice : ");
        scanf("%d",&c);
        printf("\n");

        switch(c)
        {
            case 1 : createEmpty(&tree);
                     break;

            case 2 : InsertNode(&tree);
                     break;

            case 3 : InorderTraversal(tree);
                     printf("\n");
                     break;

            case 4 : PreorderTraversal(tree);
                     printf("\n");
                     break;

            case 5 : PostorderTraversal(tree);
                     printf("\n");
                     break;

            case 6 : printf("\tHeight = %d\n\n", DetermineHeight(tree)); break;
            case 7 : printf("\tTotal Nodes = %d\n\n", NodeCount(tree)); break;
            case 8 : printf("\tInternal Nodes = %d\n\n", InternalNodes(tree)); break;
            case 9 : printf("\tExternal Nodes = %d\n\n", ExternalNodes(tree)); break;
            case 10:
                    {
                        BST* largest = LargestNode(tree);
                        if(largest) printf("\tLargest Node = %d\n\n", largest->info);
                    }
                    break;
            case 11:
                    {
                        BST* smallest = SmallestNode(tree);
                        if(smallest) printf("\tSmallest Node = %d\n\n", smallest->info);
                    }
                    break;

            case 12 : RemoveTree(&tree);
                      break;

            case 13 : exit(0);
        }
    }
    return 0;
}








