
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int main() {

	// 2 tane stack yap�yoruz
	stack* s1 = definition();
	stack* s2 = definition();;

	// 1. stacke 10 eleman ekliyoruz.
	for (int i = 1; i <= 10; i++)  
		push(i * 10, s1);

	show(s1);

	for (int i = 1; i <= 10; i++)		
		push(pop(s1), s2);
	// 1.stack den kald�rd���m�z elemanlar� 2. stack e koyuyoruz. 
	// Tersten yazd�rma �al��malar�nda kullan�labilir.
		
	show(s1); // art�k stack 1 de eleman kalmad�
	show(s2);  // t�m elemanlar stack 2 de tersten yaz�l� �ekilde 
}


