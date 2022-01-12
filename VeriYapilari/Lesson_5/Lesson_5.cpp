// Dairesel Baðlý Liste

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

void bastir(node* r) {
	node* iter = r;  // baþlangýç durumunda iter ve root birbirine eþit olduðu için while döngüsüne girmeyecek. 

	printf("%d ", iter->x); // Bu nedenle ilk deðeri bastýrýp öyle devam etmemiz gerekiyor.
	iter = iter->next;

	while (iter != r) {  // iter eþit deðildir root a o halde roota eþit olana kadar devam et.
		printf("%d ", iter->x);
		iter = iter->next;
	}
	printf("\n");
}

void ekle(node* r, int x) {
	node* iter = r;

	while (iter->next != r) { // iterin nexti rootdan farklýyken devam et
		iter = iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;
}

node* siraliEkle(node* r, int x) {
	// Eleman olamama durumu var yani Linklist boþsa
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));  // bir kutu oluþturuyoruz
		r->next = r;  // kutu kendisini gösteriyor
		r->x = x;  // eleman ekledik.
		return r;
	}
	// yeni eklenecek deðerin ilk elemandan küçük olma durumu
	if (r->x > x)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;

		node* iter = r;  // iter yapýmýz rootdan baþlayýp sona kadar tüm elemanlarý gezecek. Sondaki elemanýn nextini yeni root olarak atamak için
		while (iter->next != r)
		{
			iter = iter->next;
		}
		iter->next = temp;
		return temp;
	}

	// aralara veya sona eleman ekleme, ilk deðerden büyük olma durumu
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
	node* temp;    // bir tane silinecek elemanýn silinmesi için bir düðüm tanýmlamamýz gerekiyor.
	node* iter;    // bir tane de silinecek elemaný göstermek için bir düðüm tanýmlamamýz gerekiyor. 
	iter = r;

	if (r->x == x)  // ilk elemaný silme
	{
		while (iter->next != r) {
			iter = iter->next;
		}
		iter->next = r->next;  // rootun nextinin gösterdiði elemaný iterin nextine atýyoruz.
		free(r);  // ilk elemaný sil
		return iter->next;  // r artýk boþ bir yeri gösteriyor. Artýk yeni rootumuz iterin nexti
	}

	// silinecek deðeri bulalým
	while (iter->next != r && iter->next->x != x)    // iterin nexti null dan farklýysa ve iterin nextinin bizim aradýðýmýz x deðerinden farklýsa dön
	{
		iter = iter->next;
	}

	if (iter->next == r)  // iterin nexti root ise yani sona gelmiþsek
	{
		printf("%d sayisi bulunamadi. ", x);
		return r;
	}

	temp = iter->next;  // iter->next  silmek istediðimiz düðümü ifade ediyor. tempe atýp sileceðiz.
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




