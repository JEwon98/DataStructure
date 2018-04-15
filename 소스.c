#pragma warning (disable :4996)
#define MAX_STACK_SIZE 100
#define $ eos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
char expr[100];
int top = -1;

int stack[100];
int eval(void);
precedence getToken(char *symbol, int *n);
void push(char a);
void stackFull();
char pop();
char stackEmpty();

int main() {
	gets(expr);
	printf("%d\n", eval());
}
int eval(void) {
	precedence token;

	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand)
			push(symbol - '0');
		else {
			op2 = pop();
			op1 = pop();

			switch (token) {
			case plus: push(op1 + op2);
				break;
			case minus: push(op1 - op2);
				break;
			case times: push(op1*op2);
				break;
			case divide: push(op1 / op2);
				break;
			case mod: push(op1%op2);

			}

		}
		token = getToken(&symbol, &n);
	}
	return pop();
}
precedence getToken(char *symbol, int *n) {
	if (*n >= strlen(expr))
		return $;

	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case'*': return times;
	case ' ': return eos;
	default: return operand;

	}
}
void push(char a) {
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();

	stack[++top] = a;
}
void stackFull() {
	fprintf(stderr, "Stack is full\n");
	exit(EXIT_FAILURE);
}
char pop() {
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}
char stackEmpty() {
	fprintf(stderr, "Stack is empty\n");
	exit(EXIT_FAILURE);
}
