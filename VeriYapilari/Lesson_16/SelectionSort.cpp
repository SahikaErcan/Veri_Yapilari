#include <stdio.h>
#include <stdlib.h>

// Her adýmda dizideki en küçük elemaný bulup bu sayi ile dizinin baþýndaki sayýyý yer deðiþtirerek diziyi küçükten büyüðe doðru sýralar.
// Karmaþýklýðý O(n^2) 'dir.

void selection_sort(int arr[], int size) {
	
	for (int i = 0; i < size-1; i++)
	{
		int min = i;

		for (int j = i+1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main() {

	int arr[9] = {23,34,54,124,3,56,1,7,76};
	selection_sort(arr, 9);

	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
}