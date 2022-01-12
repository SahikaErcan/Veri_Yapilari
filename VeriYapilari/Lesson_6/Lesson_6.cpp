// Çift Yönlü Baðlý Liste

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
	node* prev;
};

void bastir(node* r) {
	while (r != NULL) 
	{
		printf("%d ", r->x);
		r = r->next;
	}
	printf("\n");
}

node* siraliEkle(node* r, int x) {
	if (r == NULL)  // eleman yoksa
	{
		r = (node*)malloc(sizeof(node));  // ilk elemaný oluþturuyoruz. // yeni düðüm  [ NULL  X   NULL ]
		r->next = NULL;
		r->prev = NULL;
		r->x = x;
		return r;
	}

	if (r->x > x)  // eklenecek deðer ilk elemandan küçükse yani baþa ekleme durumu
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;
		r->prev = temp;
		return temp;  // yeni root artýk temp		
	}

	// araya veya sona ekleme yani eklenecek deðerin rootdan büyük olmasý durumu
	// sona eleman eklemek istediðimizde sistem null'ýda kutu gibi düþünecek
	// null'ýnda previ olmadýðý için sona eklemeyi özel olarak düþünmemiz gerekiyor.
	
	node* iter = r;  // iterin rootdan baþlayýp eklenecek deðerin yerini bulmasýný istiyrouz.

	while (iter->next != NULL && iter->next->x < x) {
		iter = iter->next;
	} // iter eklenecek arayý buldu. 

	node* temp = (node*)malloc(sizeof(node));  //eklenecek olan yeni düðüm gibi düþünelim.
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;


	// tempin nexti null olmadýðý zaman yani tempin nexti dediði 1 2 3 4 5 deðerlerimiz olsun bu durum da kontrol edilen deðeri 4 olarak ele alalým 4 ün next i 5 dir. Ve 5 null deðildir. Böylece 5 deðerine yani son deðere eriþip
	// if içerisinde tempin netinin previ  yani 4ün nexti olan 5 in previ yani önündeki deðere tempi yani 4 ü atýyoruz.
	// yukarýdaki döngüde listede ki en büyük deðeri eklemek için eklenecek yer arattýrsak null olan yer de durur.
	// bu nedenle tempin nextinin NULL olmadýðý yerde iþlem yap
	if (temp->next != NULL) // durmaya gelmeden bu iþlemi yap
		// sona ekleyeceðimiz deðerin previnin baðlandýðý yer olan null un kutu olduðunu düþünelim.
		// temp in next inin null kutusunun un previne baðlandýðýný düþünürsek null kutusunun previ de temp i gösterecekti.
		temp->next->prev = temp; // böylece tempin nexti tempi gösterecektir.
	temp->x = x;
	return r;
}

node* sil(node* r, int x) {
	node* temp;
	node* iter;
	iter = r;

	if (r->x == x) // ilk deðer mi?
	{
		temp = r;  // silineceði tut.
		r = r->next;
		free(temp);
		return r;
	}

	while (iter->next != NULL && iter->next->x != x)  // silinecek deðerin yerini bul
	{
		iter = iter->next;  // NULL dan veya aradýðým deðerden farklý deðer bulana kadar ilerle
	}
	// iter aranýlan deðerde durmuyor bir önceki deðerde yani iterin nexti silinecek deðer. 
	// (iter->next == temp)  temp silinecek olaný tutar

	if (iter->next == NULL)
	{
		printf("%d sayisi bulunamadi.	-->  ",x);
		return r;
	}
	temp = iter->next;   // silinecek deðeri tempe attýk
	iter->next = iter->next->next; // silinecek deðeri atlayýp sonraki kutuya baðlandýk

	free(temp);


	// son düðümde silme iþlemi yapýldýðýnda null ile bir kutu iliþkisi kurma isteðini engellemeye çalýþýyoruz. Çünkü null ýn prev ya da next yapýlarý yok.
	if (iter->next != NULL)
		iter->next->prev = iter;
	return r;
}

int main() {
	node* root = NULL;

	root = siraliEkle(root, 4);
	root = siraliEkle(root, 400);
	root = siraliEkle(root, 40);
	root = siraliEkle(root, 50);
	root = siraliEkle(root, 450);
	bastir(root);
	root = sil(root, 50);
	bastir(root);
	root = sil(root, 999);
	bastir(root);
	root = sil(root, 4);
	bastir(root);
	root = sil(root, 450);
	bastir(root);
}