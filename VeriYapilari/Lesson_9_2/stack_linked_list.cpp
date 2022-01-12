#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	node* next;
};

node* top = NULL;

int pop() {
	// Stack is empty
	if (top == NULL)
	{
		printf("Stack bos. \n");
		return 1;
	}

	node* temp = top;
	top = top->next;
	free(temp);
	return 1;
}

void push(int data) {
	// Stack is empty
	if (top == NULL)
	{
		node* root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->data = data;
		top = root;
	}
	// Stack is not empty
	else
	{
		node* root = (node*)malloc(sizeof(node));
		root->data = data;
		root->next = top;
		top = root;
	}

}

void display() {
	// Stack is empty
	if (top == NULL)
		printf("Stack bos. \n");

	node* index = top;
	while (index != NULL)
	{
		printf("%d  ", index->data);
		index = index->next;
	}
	printf("\n");
}



int main() {

	for (int i = 1; i <= 5; i++)
		push(i * 10);
	display();

	for (int i = 0; i < 3; i++)
		pop();
	display();


	pop();
	pop();
	pop();

	push(60);
	push(70);
	push(80);
	display();

}