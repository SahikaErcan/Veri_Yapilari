
// Dizinin son elemanlarý dizinin ortasýndaki elemanlarýn çocuk düðümü olacaðýndan bu iþlem dizinin yarýsýna kadar yapýlýr.
// Heap sort iyi bir algoritmadýr fakat pratikte genelde quick sort daha hýzlýdýr. Bunun sebebi Max Heapify fonksiyonunun ardýþýk olarak çok fazla çaðýrýlmasýdýr.
// Build Heap O(n), Heapify O(logn), Heap Sort toplam çalýþma zamaný O(nlogn)
// En kötü durumda en iyi performansý garanti eder. Fakat karþýlaþtýrma döngülerinden dolayý yavaþ çalýþacaktýr.

#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
	int maximum = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	//Eðer sol alt öðe kökten büyükse
	if (leftChild < n && arr[leftChild] > arr[maximum])
		maximum = leftChild;

	//Eðer sað alt öðe maksimumdan büyükse
	if (rightChild < n && arr[rightChild] > arr[maximum])
		maximum = rightChild;

	// max kök deðilse
	if (maximum != i)
	{
		int temp = arr[i];
		arr[i] = arr[maximum];
		arr[maximum] = temp;

		//etkilenen alt aðacý yinelemeli olarak yýðýnla
		heapify(arr, n, maximum);
	}
}

//Yýðýn sýralama yapmak için ana fonksiyon
void heapSort(int arr[], int n) {

	// Diziyi yeniden düzenle (yýðýn oluþturma)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Elemanlarý birer birer öbekten ayýklayýn
	for (int i = n - 1; i >= 0 ; i--)
	{
		//Geçerli kök sona taþýndý
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// azaltýlmýþ yýðýnda max heapify çaðrýsý
		heapify(arr, i, 0);
	}
}

void display(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {

	int arr[] = { 11,34,9,5,16,10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Orjinal Dizi:  ");
	display(arr, n);
	heapSort(arr, n);

	printf("Siralanmis Dizi:  ");
	display(arr, n);
}