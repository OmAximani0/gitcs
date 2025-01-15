#include<stdio.h>
#include<string.h> // strlen
#include<ctype.h> // isalnum

#define MAX 100

char stack[MAX];
int top = -1;

int priority(char);
void push(char);
char pop();
char peek();
int isEmpty();

int main()
{
    char infixExpression[MAX];
    printf("Enter your infix expression: ");
    scanf("%s", infixExpression);

    int len = strlen(infixExpression);

    for (int i=0; i<len; i++) {
	char curr = infixExpression[i];

	if(isalnum(curr)) {
	    printf("%c", curr);
	    continue;
	}

	if(curr == '(') {
	    push(curr);
	    continue;
	}

	if(curr == ')') {
	    while(peek() != '(') printf("%c", pop());
	    pop();
	    continue;
	}

	while(!isEmpty() && priority(peek()) >= priority(curr))	printf("%c", pop());
	push(curr);

    }

    while(!isEmpty()) {
	char curr = pop();
	if (curr != '(' || curr != ')') printf("%c", curr);
    }
    printf("\n");

    return 0;
}

int priority(char ch) {
    if (ch == '^' || ch == '$') return 3;
    if (ch == '/' || ch == '*') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void push(char ch) {

    if(top == isFull()) {
	printf("Stack overflow!\n");
	return;
    }

    stack[++top] = ch;
}

char pop() {

    if(top == isEmpty()) {
	printf("Stack underflow!\n");
	return -1;
    }

    return stack[top--];
}

char peek() {
    if(top == isEmpty()) {
	printf("Stack underflow!\n");
	return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == (MAX-1);
}

