#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        
        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch;
        }
        
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '\0' && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
       
        else if (isOperator(ch)) {
            while (peek() != '\0' && precedence(peek()) >= precedence(ch) && peek() != '(') {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (peek() != '\0') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression:");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}