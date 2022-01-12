// Linked List ile QUEUE  : son a ekleyip baştan çıkarıyoruz. ilk giren ilk çıkar

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	node* next;
};

node* front = NULL;
node* rear = NULL;

int dequeue() {
	if (front == NULL)
	{
		printf("Kuyruk Bos.");
		return -1;
	}

	int delete_value = front->data;

	node* temp = front;
	front = front->next;
	free(temp);

	return delete_value;
}

void enqueue(int data) {
	if (front == NULL)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = NULL;

		front = rear = temp;
	}
	else {
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = NULL;

		rear->next = temp;

		rear = temp;
	}
}

void display() {
	if (front == NULL)
	{
		printf("Kuyruk Bos.");
		return;
	}
	node* index = front;
	printf("Kuyruk: ");
	while (index != NULL)
	{
		printf("%d  ", index->data);
		index = index->next;
	}
	printf("\n");
}

int main() {

	for (int i = 0; i < 20; i++)
		enqueue(i * 10);

	display();

	printf("Silinenler: ");
	for (int i = 0; i < 13; i++)
		printf("%d  ", dequeue());

	printf("\n\n");
	display();


	for (int i = 0; i < 20; i++)
		enqueue(i * 10);

	printf("\n");
	display();
	printf("\n");

	printf("Silinenler: ");
	for (int i = 0; i < 30; i++)
		printf("%d  ", dequeue());

	printf("\n\nKuyrukdaki Mevcut Veriler: ");
	display();
	printf("\n");
}