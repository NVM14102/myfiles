// Conversion of  Infix to Postfix Expressions 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to return precedence of operators
int prec(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Push an element onto the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}

// Pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Peek at the top of the stack
char peek() {
    return stack[top];
}

// Function to convert infix to postfix
void infixtopostfix(char *ex) {
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; ex[i] != '\0'; i++) {
        char ch = ex[i];

        // Skip whitespace
        if (ch == ' ') continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid Expression: Mismatched parentheses\n");
                exit(1);
            }
            pop(); // Remove '('
        } else if (strchr("+-*/%^", ch)) {
            while (top != -1 && peek() != '(' &&
                   (prec(peek()) > prec(ch) || 
                   (prec(peek()) == prec(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        } else {
            printf("Invalid character in expression: %c\n", ch);
            exit(1);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        if (peek() == '(') {
            printf("Invalid Expression: Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix expression is: %s\n", postfix);
}

int main() {
    char expression[MAX];

    printf("Enter a valid infix expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Remove newline

    infixtopostfix(expression);

    return 0;
}

/*Enter a valid infix expression:		 a+b*(c^d-e)^(f+g*h)-i

Postfix expression is: 			abcd^e-fgh*+^*+i-

*/

<------------------------------------------------------------------------------------------------------------------------------------------>
// Postfix Expression Evaluation 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push an integer onto the stack
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

// Pop an integer from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // Skip whitespace
        if (ch == ' ') continue;

        if (isdigit(ch)) {
            // Convert char digit to int and push
            push(ch - '0');
        } else if (strchr("+-*/%^", ch)) {
            // Pop two operands
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    result = val1 / val2;
                    break;
                case '%': result = val1 % val2; break;
                case '^': result = (int)pow(val1, val2); break;
                default:
                    printf("Unknown operator: %c\n", ch);
                    exit(1);
            }

            // Push result back to stack
            push(result);
        } else {
            printf("Invalid character in postfix expression: %c\n", ch);
            exit(1);
        }
    }

    // Final result should be the only value in the stack
    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter a valid postfix expression (single-digit numbers): ");
    fgets(postfix, MAX, stdin);

    // Remove newline or carriage return from input
    postfix[strcspn(postfix, "\r\n")] = '\0';

    int result = evaluatePostfix(postfix);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}

/*
Enter a valid postfix expression (single-digit numbers): 82/3-
Result of postfix evaluation: 1

*/






