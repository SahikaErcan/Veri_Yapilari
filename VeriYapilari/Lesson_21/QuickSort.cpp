#include <stdio.h>
#include <stdlib.h>

// Par�ala Fethet - Divide and Conqure
// dizinin herhangi bir yerinden pivot se�ilir. Elemanlar pivota g�re sa�a yada sola kayarak s�raya dizilir.
// Ortalama durum: O(nlogn)
// En k�t� durum: O(n^2)


void quickSort(double* left, double* right) {
	// pivotu orta eleman se�elim.
	double *i = left, *j = right, temp, pivot = *(left+(right-left >>1));

	// ilk adres ile son adres fark�n� al�p 2 ye b�ld�kten sonra ��kan de�eri tekrar ilk adresle topluyor. adres de�erlerini g�rmek i�in;
	printf("%f  ", *(left + (right - left >> 1)));
	printf("\tr%d", right);
	printf("\tr%d", left);
	printf("\n");

	do {
		while (*i < pivot)
			i++;
		while (*j > pivot)
			j--;
		if (i > j)
			break;
		temp = *i;
		*i = *j;
		*j = temp;

	} while (++i <= --j);

	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i,right);

}
int main() {
	 
	double arr[] = { 23,398,34,100,57,67,55,320 };
	quickSort(&arr[0], &arr[7]);
	
	for (int i = 0; i < 8; i++)
	{
		printf("%0.f ", arr[i]);
	}
}