// �ift Y�nl� Ba�l� Liste

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
		r = (node*)malloc(sizeof(node));  // ilk eleman� olu�turuyoruz. // yeni d���m  [ NULL  X   NULL ]
		r->next = NULL;
		r->prev = NULL;
		r->x = x;
		return r;
	}

	if (r->x > x)  // eklenecek de�er ilk elemandan k���kse yani ba�a ekleme durumu
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;
		r->prev = temp;
		return temp;  // yeni root art�k temp		
	}

	// araya veya sona ekleme yani eklenecek de�erin rootdan b�y�k olmas� durumu
	// sona eleman eklemek istedi�imizde sistem null'�da kutu gibi d���necek
	// null'�nda previ olmad��� i�in sona eklemeyi �zel olarak d���nmemiz gerekiyor.
	
	node* iter = r;  // iterin rootdan ba�lay�p eklenecek de�erin yerini bulmas�n� istiyrouz.

	while (iter->next != NULL && iter->next->x < x) {
		iter = iter->next;
	} // iter eklenecek aray� buldu. 

	node* temp = (node*)malloc(sizeof(node));  //eklenecek olan yeni d���m gibi d���nelim.
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;


	// tempin nexti null olmad��� zaman yani tempin nexti dedi�i 1 2 3 4 5 de�erlerimiz olsun bu durum da kontrol edilen de�eri 4 olarak ele alal�m 4 �n next i 5 dir. Ve 5 null de�ildir. B�ylece 5 de�erine yani son de�ere eri�ip
	// if i�erisinde tempin netinin previ  yani 4�n nexti olan 5 in previ yani �n�ndeki de�ere tempi yani 4 � at�yoruz.
	// yukar�daki d�ng�de listede ki en b�y�k de�eri eklemek i�in eklenecek yer aratt�rsak null olan yer de durur.
	// bu nedenle tempin nextinin NULL olmad��� yerde i�lem yap
	if (temp->next != NULL) // durmaya gelmeden bu i�lemi yap
		// sona ekleyece�imiz de�erin previnin ba�land��� yer olan null un kutu oldu�unu d���nelim.
		// temp in next inin null kutusunun un previne ba�land���n� d���n�rsek null kutusunun previ de temp i g�sterecekti.
		temp->next->prev = temp; // b�ylece tempin nexti tempi g�sterecektir.
	temp->x = x;
	return r;
}

node* sil(node* r, int x) {
	node* temp;
	node* iter;
	iter = r;

	if (r->x == x) // ilk de�er mi?
	{
		temp = r;  // silinece�i tut.
		r = r->next;
		free(temp);
		return r;
	}

	while (iter->next != NULL && iter->next->x != x)  // silinecek de�erin yerini bul
	{
		iter = iter->next;  // NULL dan veya arad���m de�erden farkl� de�er bulana kadar ilerle
	}
	// iter aran�lan de�erde durmuyor bir �nceki de�erde yani iterin nexti silinecek de�er. 
	// (iter->next == temp)  temp silinecek olan� tutar

	if (iter->next == NULL)
	{
		printf("%d sayisi bulunamadi.	-->  ",x);
		return r;
	}
	temp = iter->next;   // silinecek de�eri tempe att�k
	iter->next = iter->next->next; // silinecek de�eri atlay�p sonraki kutuya ba�land�k

	free(temp);


	// son d���mde silme i�lemi yap�ld���nda null ile bir kutu ili�kisi kurma iste�ini engellemeye �al���yoruz. ��nk� null �n prev ya da next yap�lar� yok.
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