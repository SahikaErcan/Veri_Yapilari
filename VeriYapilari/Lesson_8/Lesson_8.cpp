 // ARRAY STACK

#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

/* Dolu bir y���na yeni bir nesne eklemeye �al��mak istisnai durumlara sebep olabilir.push i�lemi esnas�nda dizi dolu ise
bir istisnai durum bildirimi geri d�ndermektense y���n�n tutuldu�u dizi daha b�y�k bir dizi ile yer de�i�tirilir.Dizi 
boyutu ya y���n b�y�kl��� kadar sabit bir x de�eri kadar artt�r�l�r ya da �nceki dizi boyutu ikiye katlan�r.Ba�l� liste 
ile stack i�lemlerinde bu t�r problemler yoktur.
*/
stack* definition() {
	stack* s = (stack*)malloc(sizeof(stack)); // RAM de bir tane stack olu�turuyoruz
	s->arr = NULL;
	s->size = 2;  // depolanan nesne say�s�n� geri d�nd�r�r. Ba�lang��ta dizi boyutu 2 
	s->top = 0;  // en �stteki de�eri tutar. en son eklenen nesneyi ��karmadan geri d�nd�r�r.
	return s;
}

int pop(stack* s)   // en son eklenen nesneyi ��kart�r.
{
	if (s->top <= 0 ||  s->arr == NULL) 
	{
		printf("dizi bo�");
		return -1;
	}		

	/* dizi i�inde silme i�lemi ger�ekle�tik�e dizi boyutunun k���lmesi laz�m. Dizi belli bir boyutun alt�na girdi�i anda dizinin 
	fazla olan k�sm�n� bo� yere yer kaplamas�n diye RAM den silmemiz gerekiyor. �rne�in dizi boyutu dizinin 4 de 1 ine indi�i anda 
	dizi boyutu 4 de 2 olsun yani 8 eleman oldu�unu d���nelim 6 eleman silindi�inde dizi boyutu 4 olsun. ��indeki de�erin 2 kat� kadar.
	*/
	if (s->top <= s->size / 4)
	{
		int* arr2 = (int*)malloc(sizeof(int) * s->size / 2);
		for (int i = 0; i < s->top; i++) { // tepe ye kadar ald�k ��nk� tepe bize dolu k�sm� verir. Tepeye geldi�imiz an i�i durdurmam�z laz�m
			arr2[i] = s->arr[i];
		}			
		free(s->arr);
		s->arr = arr2;
		s->size /= 2;
	}
	return s->arr[--s->top];
}

void push(int a, stack* s)   // yeni bir nesne ekler.
{
	if (s->arr == NULL) // dizi bo�ken ilk kez eleman eklenmek istendi�inde dizinin tan�mlanmas� gerekiyor.
	{
		s->arr = (int*)malloc(sizeof(int)*2); // 2 boyutlu dinamik dizi tan�m�
	}
	// dizi boyutu a�ma sonucu olu�acak hatay� �nlemek i�in
	if (s->top >= s->size-1)  // dizinin i�eri�i boyuta e�it olmadan 1 �nceki durumunda dizi boyutunu 2 ye katlayal�m. 
	{                         // G�z�m�zden ka�an bir �ey olmas�n diye g�venli olsun diye
		int* arr2 = (int*)malloc(sizeof(int) * s->size * 2);  // dizi boyutunu ikiye katl�yoruz.

		// dizi ikiyi dizi bire atmadan �nce dizi birin i�indeki de�erleri kurtarmam�z gerekiyor.
		for (int i = 0; i < s->size; i++)
		{
			arr2[i] = s->arr[i];
		}
		int* temp = s->arr;
		s->arr = arr2;
		free(temp);  // dizi2 yi dizi1 e atamadan �nce dizi1 in i�eri�ini temizliyoruz. Bellekte ��p olarak kalmas�n diye. Atamadan sonra tekrar eri�imi s�z konusu olmayacak ��nk�. RAM �i�mesin diye.

		s->size *= 2;  // boyutu 2 katl�yoruz ��nk� art�k n elemanl� diziden 2n elemanl� diziye terfi etti.
	}
	s->arr[s->top++] = a;
}

void show(stack* s) {

	printf("Boyut: %d ---->	", s->size);

	for (int i = 0; i < s->top; i++)
	{
		printf("%d ", s->arr[i]);
	}
	printf("\n");
}
