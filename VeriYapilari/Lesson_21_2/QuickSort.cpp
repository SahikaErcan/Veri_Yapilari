#include <stdio.h>
#include <stdlib.h>

//  pivotu ilk eleman seçelim.

void quickSort(int arr[], int first, int last) {
	int i; // ilk elemaný tutacak sayaç deðiþkeni
	int j; // son elemaný tutacak sayaç deðiþkeni
	int pivot = first;  // Pivotu ilk eleman olarak seçiyoruz.
	int temp;
	/* Son eleman ilk elemandan büyük olduðu sürece baþtan 
	ve sondan pivottan büyük olan ve pivottan küçük olan 
	bir eleman seçilip yer deðiþtirilir.
	*/
	if (last > first)
	{
		pivot = first;
		i = first+1;
		j = last;
		while (i < j) {
			// Baþtan pivottan büyük olan bir eleman bulunur
			while (arr[i] <= arr[pivot] && i < last && j > i)
				i++;
			// Sondan pivottan küçük olan bir eleman bulunur
			while (arr[j] >= arr[pivot] && j >= first && j >= i)
				j--;
			// Swap iþlemi yapýlýr.
			if (j > i)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		// Yeniden pivot seçilir ve bölünen baðlý listenin diðer parçalarý tekrar quick sort fonksiyonuna gönderilir.
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