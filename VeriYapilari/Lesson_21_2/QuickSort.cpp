#include <stdio.h>
#include <stdlib.h>

//  pivotu ilk eleman se�elim.

void quickSort(int arr[], int first, int last) {
	int i; // ilk eleman� tutacak saya� de�i�keni
	int j; // son eleman� tutacak saya� de�i�keni
	int pivot = first;  // Pivotu ilk eleman olarak se�iyoruz.
	int temp;
	/* Son eleman ilk elemandan b�y�k oldu�u s�rece ba�tan 
	ve sondan pivottan b�y�k olan ve pivottan k���k olan 
	bir eleman se�ilip yer de�i�tirilir.
	*/
	if (last > first)
	{
		pivot = first;
		i = first+1;
		j = last;
		while (i < j) {
			// Ba�tan pivottan b�y�k olan bir eleman bulunur
			while (arr[i] <= arr[pivot] && i < last && j > i)
				i++;
			// Sondan pivottan k���k olan bir eleman bulunur
			while (arr[j] >= arr[pivot] && j >= first && j >= i)
				j--;
			// Swap i�lemi yap�l�r.
			if (j > i)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		// Yeniden pivot se�ilir ve b�l�nen ba�l� listenin di�er par�alar� tekrar quick sort fonksiyonuna g�nderilir.
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;

		quickSort(arr, first, j - 1);
		quickSort(arr, j + 1, last);
	}
}

int main() {
	
	int arr[] = { 23,398,34,100,57,67,55,320 };
	quickSort(arr, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
}