#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val){
    if(top >= MAX)
        printf("Stack Overflow !!");
    else
        stack[++top] = val;
}

int pop(){
    if(top < 0){
        printf("Stack Underflow !!");
        return -1;
    }
    return stack[top--];
}

int is_digit(char ch){
    return ch >= '0' && ch <= '9';
}

int evaluatePrefix(char *expr){
    int i, num;
    int len = strlen(expr);

    for(i = len - 1; i >= 0; i--){

        if(expr[i] == ' ')
            continue;

        if(is_digit(expr[i])){
            num = 0;
            int base =  1;

            while(i >= 0 && is_digit(expr[i])){
                num = num + ((int)(expr[i])-48) * base;
                base *= 10;
                i--;
            }
            i++;
            push(num);
        }
        else{
            int op1 = pop();
            int op2 = pop();

            switch(expr[i]){
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
            }
        }
    }
    return pop();
}

int main()
{
    char expr[MAX];

    printf("Enter Prefix expression (with spaces): ");
    gets(expr);

    int result = evaluatePrefix(expr);
    printf("Result : %d\n",result);

    return 0;
}
