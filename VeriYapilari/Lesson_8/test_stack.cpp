
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int main() {

	// 2 tane stack yapýyoruz
	stack* s1 = definition();
	stack* s2 = definition();;

	// 1. stacke 10 eleman ekliyoruz.
	for (int i = 1; i <= 10; i++)  
		push(i * 10, s1);

	show(s1);

	for (int i = 1; i <= 10; i++)		
		push(pop(s1), s2);
	// 1.stack den kaldýrdýðýmýz elemanlarý 2. stack e koyuyoruz. 
	// Tersten yazdýrma çalýþmalarýnda kullanýlabilir.
		
	show(s1); // artýk stack 1 de eleman kalmadý
	show(s2);  // tüm elemanlar stack 2 de tersten yazýlý þekilde 
}


