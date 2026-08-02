#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global variables
char stk[MAX_SIZE];
char postfix[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top = top + 1;
        stk[top] = item;
    }
}

char pop() {
    if (top == -1) {
        return '\0'; 
    }
    char item = stk[top];
    top = top - 1;
    return item;
}

// Function to find Precedence
int precedence(char n) {
    switch (n) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '-':
        case '+':
            return 1;
        default:
            return 0;   
    }
}

int main() {
    int i, j = 0;
    char infix[MAX_SIZE];
    
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    
    for (i = 0; i < strlen(infix); i++) {
        switch (infix[i]) {
            case '(':
                push(infix[i]);
                break;
                
            case ')':
                while (top != -1 && stk[top] != '(') {
                    postfix[j++] = pop();
                }
                pop(); // Pop '(' from stack
                break;
                
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                // Check right-associativity for '^' vs left-associativity for others
                if (infix[i] == '^') {
                    while (top != -1 && precedence(infix[i]) < precedence(stk[top])) {
                        postfix[j++] = pop();
                    }
                } else {
                    while (top != -1 && precedence(infix[i]) <= precedence(stk[top])) {
                        postfix[j++] = pop();
                    }
                }
                push(infix[i]);
                break;
                
            default:
                postfix[j++] = infix[i];
                break;
        }
    }
    
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    // Null-terminate the string so printf knows where it ends
    //postfix[j] = '\0';
    
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
