

#include <stdio.h>
#include <stdlib.h>

// Worst Case = O(n^2)
// Avarage Case = O(n^2)
// Best Case (if sequential)= O(n)

void insertion_sort(int arr[], int size) {
	
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0  && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main() {
	int arr[10] = { 23,12,54,34,124,3,56,1,7,76 };
	insertion_sort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}