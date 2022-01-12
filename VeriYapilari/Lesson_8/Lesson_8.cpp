 // ARRAY STACK

#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

/* Dolu bir yýðýna yeni bir nesne eklemeye çalýþmak istisnai durumlara sebep olabilir.push iþlemi esnasýnda dizi dolu ise
bir istisnai durum bildirimi geri döndermektense yýðýnýn tutulduðu dizi daha büyük bir dizi ile yer deðiþtirilir.Dizi 
boyutu ya yýðýn büyüklüðü kadar sabit bir x deðeri kadar arttýrýlýr ya da önceki dizi boyutu ikiye katlanýr.Baðlý liste 
ile stack iþlemlerinde bu tür problemler yoktur.
*/
stack* definition() {
	stack* s = (stack*)malloc(sizeof(stack)); // RAM de bir tane stack oluþturuyoruz
	s->arr = NULL;
	s->size = 2;  // depolanan nesne sayýsýný geri döndürür. Baþlangýçta dizi boyutu 2 
	s->top = 0;  // en üstteki deðeri tutar. en son eklenen nesneyi çýkarmadan geri döndürür.
	return s;
}

int pop(stack* s)   // en son eklenen nesneyi çýkartýr.
{
	if (s->top <= 0 ||  s->arr == NULL) 
	{
		printf("dizi boþ");
		return -1;
	}		

	/* dizi içinde silme iþlemi gerçekleþtikçe dizi boyutunun küçülmesi lazým. Dizi belli bir boyutun altýna girdiði anda dizinin 
	fazla olan kýsmýný boþ yere yer kaplamasýn diye RAM den silmemiz gerekiyor. Örneðin dizi boyutu dizinin 4 de 1 ine indiði anda 
	dizi boyutu 4 de 2 olsun yani 8 eleman olduðunu düþünelim 6 eleman silindiðinde dizi boyutu 4 olsun. Ýçindeki deðerin 2 katý kadar.
	*/
	if (s->top <= s->size / 4)
	{
		int* arr2 = (int*)malloc(sizeof(int) * s->size / 2);
		for (int i = 0; i < s->top; i++) { // tepe ye kadar aldýk çünkü tepe bize dolu kýsmý verir. Tepeye geldiðimiz an iþi durdurmamýz lazým
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
	if (s->arr == NULL) // dizi boþken ilk kez eleman eklenmek istendiðinde dizinin tanýmlanmasý gerekiyor.
	{
		s->arr = (int*)malloc(sizeof(int)*2); // 2 boyutlu dinamik dizi tanýmý
	}
	// dizi boyutu aþma sonucu oluþacak hatayý önlemek için
	if (s->top >= s->size-1)  // dizinin içeriði boyuta eþit olmadan 1 önceki durumunda dizi boyutunu 2 ye katlayalým. 
	{                         // Gözümüzden kaçan bir þey olmasýn diye güvenli olsun diye
		int* arr2 = (int*)malloc(sizeof(int) * s->size * 2);  // dizi boyutunu ikiye katlýyoruz.

		// dizi ikiyi dizi bire atmadan önce dizi birin içindeki deðerleri kurtarmamýz gerekiyor.
		for (int i = 0; i < s->size; i++)
		{
			arr2[i] = s->arr[i];
		}
		int* temp = s->arr;
		s->arr = arr2;
		free(temp);  // dizi2 yi dizi1 e atamadan önce dizi1 in içeriðini temizliyoruz. Bellekte çöp olarak kalmasýn diye. Atamadan sonra tekrar eriþimi söz konusu olmayacak çünkü. RAM þiþmesin diye.

		s->size *= 2;  // boyutu 2 katlýyoruz çünkü artýk n elemanlý diziden 2n elemanlý diziye terfi etti.
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
