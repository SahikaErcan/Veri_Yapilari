#include <stdio.h>
#include <stdlib.h>

// dizi elemanlar� �zerinden ilk elemandan ba�layarak ve her ge�i�te yan yana bulunan iki eleman aras�nda s�ralama yap�l�r.
// dizi ba�tan sona t�m elemanlar bir kez i�leme tabi tutuldu�unda dizinin son eleman� EB eleman haline gelir.
// bir sonraki tarama en sa�daki eleman d��ar�da b�rak�larak ger�ekle�tirilir.
// Eleman say�s� - 1 adet iterasyon yap�l�r. 

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