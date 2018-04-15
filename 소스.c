#pragma warning (disable :4996)

#include <stdio.h>
#include <stdlib.h>
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
char expr[100];
int top = -1;
typedef struct {
	char x;

}Stack;

Stack stack[100];

int main() {
	scanf("%s", expr);
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

	}


}
precedence getToken(char *symbol, int *n) {
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
	void push(char a) {
		
		if (top >= MAX_STACK_SIZE - 1)
			stackFull();

		stack[++top] = a;
	}
	void stackFull() {
		fprintf(stderr, "Stack is full\n");
		exit(EXIT_FAILURE);
	}

}