

#pragma once

#ifndef stack_arr
#define stack_arr

typedef struct stack {
	int size;
	int top;
	int* arr;
};

stack* definition();
int pop(stack*);
void push(int, stack*);
void show(stack*);

#endif // !stack_arr

