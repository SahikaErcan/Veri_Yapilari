
// Dizinin son elemanlar� dizinin ortas�ndaki elemanlar�n �ocuk d���m� olaca��ndan bu i�lem dizinin yar�s�na kadar yap�l�r.
// Heap sort iyi bir algoritmad�r fakat pratikte genelde quick sort daha h�zl�d�r. Bunun sebebi Max Heapify fonksiyonunun ard���k olarak �ok fazla �a��r�lmas�d�r.
// Build Heap O(n), Heapify O(logn), Heap Sort toplam �al��ma zaman� O(nlogn)
// En k�t� durumda en iyi performans� garanti eder. Fakat kar��la�t�rma d�ng�lerinden dolay� yava� �al��acakt�r.

#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
	int maximum = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	//E�er sol alt ��e k�kten b�y�kse
	if (leftChild < n && arr[leftChild] > arr[maximum])
		maximum = leftChild;

	//E�er sa� alt ��e maksimumdan b�y�kse
	if (rightChild < n && arr[rightChild] > arr[maximum])
		maximum = rightChild;

	// max k�k de�ilse
	if (maximum != i)
	{
		int temp = arr[i];
		arr[i] = arr[maximum];
		arr[maximum] = temp;

		//etkilenen alt a�ac� yinelemeli olarak y���nla
		heapify(arr, n, maximum);
	}
}

//Y���n s�ralama yapmak i�in ana fonksiyon
void heapSort(int arr[], int n) {

	// Diziyi yeniden d�zenle (y���n olu�turma)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Elemanlar� birer birer �bekten ay�klay�n
	for (int i = n - 1; i >= 0 ; i--)
	{
		//Ge�erli k�k sona ta��nd�
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// azalt�lm�� y���nda max heapify �a�r�s�
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