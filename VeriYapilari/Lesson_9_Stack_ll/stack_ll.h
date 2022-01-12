#pragma once

#ifndef stack_ll
#define stack_ll

typedef struct node
{
	int data;
	node* next;
};

int pop(node*);
node* push(node* root, int);
void show(node*);

#endif // !stack_ll
