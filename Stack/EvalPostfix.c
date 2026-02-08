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

int evaluatePostfix(char *expr){
    int i=0, num;

    while(expr[i] != '\0'){
        if(expr[i] == ' '){
            i++;
            continue;
        }

        if(is_digit(expr[i])){
            num = 0;
            while(is_digit(expr[i])){
                num = num*10 + ((int)(expr[i])-48);
                i++;
            }
            push(num);
        }
        else{
            int op2 = pop();
            int op1 = pop();

            switch(expr[i]){
                case '+': push(op1+op2);break;
                case '-': push(op1-op2);break;
                case '*': push(op1*op2);break;
                case '/': push(op1/op2);break;
                case '^': push(pow(op1,op2));break;
            }
            i++;
        }
    }
    return pop();
}

int main()
{
    char expr[MAX];

    printf("Enter Postfix expression (with spaces): ");
    gets(expr);

    int result = evaluatePostfix(expr);
    printf("Result : %d\n",result);

    return 0;
}
