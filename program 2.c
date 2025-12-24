#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x) {
    stack[++top] = x;
}

// Pop operation
char pop() {
    return stack[top--];
}

// Check operator precedence
int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If opening parenthesis, push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If closing parenthesis, pop until '('
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
        // If operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
