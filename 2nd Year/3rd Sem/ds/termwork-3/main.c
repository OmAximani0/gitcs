#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

void push(char);
char pop();
int priority(char);
char peek();
bool isEmpty();
bool isFull();

char stack[SIZE];
int top = -1;

int main() {
	int len, i;
	bool isAlpha;
	bool isNumeric;
	bool isOperend;
	bool isOperator;
	char infix[100], currCharFromExp;

	printf("Enter infix expression: ");
	scanf("%s", infix);
	len = strlen(infix);

	for(i=0; i < len; ++i) {
		currCharFromExp = infix[i];

		isAlpha = (currCharFromExp >= 'a' && currCharFromExp <='z') ||  \
			(currCharFromExp >= 'A' && currCharFromExp <='Z');
		isNumeric = (currCharFromExp >= '0' && currCharFromExp <='9');
		isOperend = isAlpha || isNumeric;

		isOperator = currCharFromExp == '+' || currCharFromExp == '-' ||
			currCharFromExp == '^' || currCharFromExp == '$' ||
			currCharFromExp == '*' || currCharFromExp == '/';

		if(isOperend) printf("%c", currCharFromExp);

		else if(currCharFromExp == '(') push(currCharFromExp);

		else if(currCharFromExp == ')') {
			while (peek() != '(') {
				printf("%c", pop());
			}
			pop();
		}

		else if(isOperator) {
			while (!isEmpty() && priority(peek()) >= priority(currCharFromExp)) {
				printf("%c", pop());
			}
			push(currCharFromExp);
		}
	}

	while(!isEmpty()) {
		char c = pop();
		if(c != '(' || c != ')') printf("%c", c);
	}
	printf("\n");
	return EXIT_SUCCESS;
}

void push(char c) {
	if(isFull()) {
		printf("\nStack Overflow! Exiting the program");
		exit(1);
	}
	stack[++top] = c;
}

char pop() {
	if(isEmpty()) {
		printf("\nStack Underflow!");
		return -1;
	}
	char c = stack[top--];
	return c;
}

int priority(char c) {
	if(c == '^' || c == '$') return 3;
	else if(c == '/' || c == '*') return 2;
	else if (c == '+' || c == '-') return 1;
	else return 0;
}

char peek() {
	return stack[top];
}

bool isEmpty() {
	return top == -1;
}

bool isFull() {
	return top == SIZE - 1;
}

