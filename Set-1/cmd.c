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

// function for evaluating postfix
int evaluatePostfix(char postfix[]) {
    int i, a, b, res;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) 
    {
        ch = postfix[i];

        if (ch >= '0' && ch <= '9') 
        {
            push(ch - '0'); // Convert char to int
        }
        else 
        {
            b = pop();
            a = pop();
            switch (ch) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
            }
            push(res);
        }
    }
    return pop();
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"expression\"\n", argv[0]);
        return 1;
    }

    char infix[MAX] = "";
    char postfix[MAX];
    int i;

    // Combine command-line arguments into one string (in case expression has spaces)
    for (i = 1; i < argc; i++) {
        strcat(infix, argv[i]);
    }

    infixToPostfix(infix, postfix);
    int result = evaluatePostfix(postfix);
    printf("%d\n", result);

    return 0;
}