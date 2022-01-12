// Dairesel Ba�l� Liste

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

void bastir(node* r) {
	node* iter = r;  // ba�lang�� durumunda iter ve root birbirine e�it oldu�u i�in while d�ng�s�ne girmeyecek. 

	printf("%d ", iter->x); // Bu nedenle ilk de�eri bast�r�p �yle devam etmemiz gerekiyor.
	iter = iter->next;

	while (iter != r) {  // iter e�it de�ildir root a o halde roota e�it olana kadar devam et.
		printf("%d ", iter->x);
		iter = iter->next;
	}
	printf("\n");
}

void ekle(node* r, int x) {
	node* iter = r;

	while (iter->next != r) { // iterin nexti rootdan farkl�yken devam et
		iter = iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;
}

node* siraliEkle(node* r, int x) {
	// Eleman olamama durumu var yani Linklist bo�sa
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));  // bir kutu olu�turuyoruz
		r->next = r;  // kutu kendisini g�steriyor
		r->x = x;  // eleman ekledik.
		return r;
	}
	// yeni eklenecek de�erin ilk elemandan k���k olma durumu
	if (r->x > x)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;

		node* iter = r;  // iter yap�m�z rootdan ba�lay�p sona kadar t�m elemanlar� gezecek. Sondaki eleman�n nextini yeni root olarak atamak i�in
		while (iter->next != r)
		{
			iter = iter->next;
		}
		iter->next = temp;
		return temp;
	}

	// aralara veya sona eleman ekleme, ilk de�erden b�y�k olma durumu
	node* iter = r;

	while (iter->next != r && iter->next->x < x)
	{
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
	return r;
}

node* sil(node* r, int x) {
	node* temp;    // bir tane silinecek eleman�n silinmesi i�in bir d���m tan�mlamam�z gerekiyor.
	node* iter;    // bir tane de silinecek eleman� g�stermek i�in bir d���m tan�mlamam�z gerekiyor. 
	iter = r;

	if (r->x == x)  // ilk eleman� silme
	{
		while (iter->next != r) {
			iter = iter->next;
		}
		iter->next = r->next;  // rootun nextinin g�sterdi�i eleman� iterin nextine at�yoruz.
		free(r);  // ilk eleman� sil
		return iter->next;  // r art�k bo� bir yeri g�steriyor. Art�k yeni rootumuz iterin nexti
	}

	// silinecek de�eri bulal�m
	while (iter->next != r && iter->next->x != x)    // iterin nexti null dan farkl�ysa ve iterin nextinin bizim arad���m�z x de�erinden farkl�sa d�n
	{
		iter = iter->next;
	}

	if (iter->next == r)  // iterin nexti root ise yani sona gelmi�sek
	{
		printf("%d sayisi bulunamadi. ", x);
		return r;
	}

	temp = iter->next;  // iter->next  silmek istedi�imiz d���m� ifade ediyor. tempe at�p silece�iz.
	iter->next = iter->next->next;
	free(temp);
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




