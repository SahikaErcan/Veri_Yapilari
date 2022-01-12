#include <stdio.h>
#include <stdlib.h>

// dizi elemanlarý üzerinden ilk elemandan baþlayarak ve her geçiþte yan yana bulunan iki eleman arasýnda sýralama yapýlýr.
// dizi baþtan sona tüm elemanlar bir kez iþleme tabi tutulduðunda dizinin son elemaný EB eleman haline gelir.
// bir sonraki tarama en saðdaki eleman dýþarýda býrakýlarak gerçekleþtirilir.
// Eleman sayýsý - 1 adet iterasyon yapýlýr. 

void bubble_sort(int arr[], int size) {
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main() {
	int arr[10] = { 23,12,54,34,124,3,56,1,7,76 };
	bubble_sort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}