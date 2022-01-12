// QUEUE with ARRAY use

#include <stdio.h>
#include <stdlib.h>

int* arr = NULL;
int front = 0, rear = 0, size = 2;

// Delete
int dequeue() {
	if (front == rear)
	{
		printf("Dizi bos. ");
		return -1;
	}

	//  total number of elements in the array : (rear - front) 
	//  let's say  "size = 32"  and  total number of elements 8 in the array. Divide the array size by two
	if ((rear - front) <= (size / 4))
	{
		size /= 2;
		int* new_arr = (int*)malloc(sizeof(int) * size);  // divide the current size by 2

		for (int i = 0; i < (rear - front); i++)
			new_arr[i] = arr[front + i];  // starting "front" position    ->  new_arr[0] = arr[5 + 0], new_arr[1] = arr[5 + 1] ....
		rear -= front; // go backwards like "front"
		front = 0;  //  position update for "front"
		free(arr); // delete ​​to old array
		arr = new_arr;
	}

	return arr[front++];  // "front" is go on and it is gonna next new  "front" 
}

// Add
void enqueue(int data) {
	// array is empty
	if (arr == NULL)
	{
		arr = (int*)malloc(sizeof(int) * 2);
		// arr[rear++] = data;
	}

	//array is full
	if (rear >= size)
	{
		size *= 2;
		int* new_arr = (int*)malloc(sizeof(int) * size);  // array is full so make a new array

		for (int i = 0; i < size / 2; i++)
			new_arr[i] = arr[i];  // move values ​​to new array
		free(arr);  // delete ​​to old array
		arr = new_arr; // for control
		// arr[rear++] = data; 
	}

	arr[rear++] = data;   // add element and go on and  it is gonna new "front"
}

// collect the spaces created by deleting
void collect() {
	if (front == 0)
		return;
	for (int i = 0; i < size; i++)
		arr[i] = arr[front + i];   // starting "front" position    ->  new_arr[0] = arr[5 + 0], new_arr[1] = arr[5 + 1] ....
	rear -= front; // go backwards like "front"
	front = 0; //  position update for "front"
}


int main() {
	for (int i = 0; i < 20; i++)
		enqueue(i * 10);
	printf("\nDURUM:\n Boyut: %d,  Sira: %d,  Sira Basi: %d   ", size, rear, front);
	for (int i = 0; i < 13; i++)
		printf("%d ", dequeue());
	collect();  // Scroll to front so there was no increase in size.
	printf("\nDURUM:\n Boyut: %d,  Sira: %d,  Sira Basi: %d   ", size, rear, front);
	for (int i = 0; i < 20; i++)
		enqueue(i * 10);
	printf("\nDURUM:\n Boyut: %d,  Sira: %d,  Sira Basi: %d   ", size, rear, front);
	for (int i = 0; i < 30; i++)
		printf("%d ", dequeue());
	printf("\DURUM:\n Boyut: %d,  Sira: %d,  Sira Basi: %d   ", size, rear, front);
}