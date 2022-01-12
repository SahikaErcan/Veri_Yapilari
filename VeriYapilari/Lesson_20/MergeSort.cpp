#include <stdio.h>
#include <stdlib.h>
#include <iostream>
// Par�ala Fethet - Divide and Conqure
// Divide : orta noktan�n bulunmas� O(1)
// Conqure : her iki alt par�an�n s�ralanmas� 2T(n/2)
// Birle�tirme : O(n)
// En k�t� durum analizinde : T(n) = O(nlogn)


int a[] = { 7,3,1,5,2,0,4,6,9,8 };
int b[10];

void merge(int start, int middle, int finish) {
	int i, j, k;
	for (i = start; i <= finish; i++)  // a dizisini b dizisine kopyalad�k...
		b[i] = a[i];
	i = start;
	j = middle + 1;
	k = start;

	while (i <= middle && j <= finish) 
	{
		if (b[i] <= b[j])
			a[k++] = b[i++];
		else
			a[k++] = b[j++];
	}

	// arta kalan say�lar
	while (i <= middle)
		a[k++] = b[i++];
}

void mergeSort(int start, int finish)  // b�l
{
	if (start < finish)
	{
		int middle = (start + finish) / 2;
		mergeSort(start, middle);
		mergeSort(middle + 1, finish);
		merge(start, middle, finish);
	}
}

int main() {

	mergeSort(0, 9);

	for (int i = 0; i <= 9; i++)
		std::cout << a[i] << " ";
	return 0;
}