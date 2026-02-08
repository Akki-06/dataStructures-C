#include <stdio.h>
#include <string.h>

void lengthStr() {
    char str[200];
    printf("\n\tEnter the String : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("\n\tLength of String : %lu\n", strlen(str));
}

void concatStr() {
    char str1[100], str2[100];
    printf("\n\tEnter first String : ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("\n\tEnter second String : ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    strcat(str1, str2);
    printf("\n\tConcatenated String : %s\n", str1);
}

void revStr() {
    char str[200];
    printf("\n\tEnter the String : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("\n\tReversed String : %s\n", strrev(str));
}

void compStr() {
    char str1[100], str2[100];
    printf("\n\tEnter first String : ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("\n\tEnter second String : ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    int cmp = strcmp(str1, str2);
    if (cmp < 0)
        printf("\n\tString 2 is Greater than String 1\n");
    else if (cmp > 0)
        printf("\n\tString 1 is Greater than String 2\n");
    else
        printf("\n\tBoth Strings are Equal\n");
}

int main() {
    int ch;

    printf("***********************************************************\n");
    printf("                    STRING OPERATIONS                      \n");
    printf("***********************************************************\n");
    printf("\n");
    printf("\t\tPRESS 1 : Calculate Length of String\n");
    printf("\t\tPRESS 2 : Concatenate two Strings\n");
    printf("\t\tPRESS 3 : Reverse a String\n");
    printf("\t\tPRESS 4 : Compare Two Strings\n");

    printf("\n\tEnter choice : ");
    scanf("%d", &ch);
    while (getchar() != '\n');

    switch (ch) {
        case 1: lengthStr(); break;
        case 2: concatStr(); break;
        case 3: revStr(); break;
        case 4: compStr(); break;
        default: printf("\n\tInvalid Choice!!\n");
    }

    return 0;
}
