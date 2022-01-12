// Ba�l� Listeden Eleman Silme

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
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
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}

	if (r->x > x)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = r;
		temp->x = x;
		r = temp;
		return r;
	}

	node* iter = r;

	while (iter->next != NULL && iter->next->x < x) {
		iter = iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));
	temp->x = x;
	temp->next = iter->next;      
	iter->next = temp;
	return r;
}

// Ba�taki eleman� silmek isteyebiliriz. Bu durumda root un de�i�me ihtimali var. 
// Bu nedenle ba�taki eleman� d���nmemiz gerekiyor. Metodu node* ile olu�turuyoruz.

node* sil(node* r, int x) {
	node* temp;    // bir tane silinecek eleman�n silinmesi i�in bir d���m tan�mlamam�z gerekiyor.
	node* iter;    // bir tane de silinecek eleman� g�stermek i�in bir d���m tan�mlamam�z gerekiyor. 
	iter = r;   // root dan ba�lat�yoruz.

	// rootu yani ba�taki de�eri silme durumu
	if (r->x == x) // arad���m de�er root ise
	{
		temp = r;  // silinecek de�eri tempe att�k
		r = r->next; // root art�k di�er degeri g�steriyor.
		free(temp); // sildik
		return r;
	}

	while (iter->next != NULL && iter->next->x != x)   // iterin nexti null dan farkl�ysa ve iterin nextinin de�eri bizim arad���m�z x de�erinden farkl�sa d�n
	{
		iter = iter->next;
	} // silece�imiz list de�il bir �ncesinde durduk. iter..

	if (iter->next == NULL) // iterden sonras� bulunamad�ysa null
	{
		printf("%d Sayisi Bulunamadi.  ->  ", x);
		return r;
	}
	// linklistin ortas�nda say�y� bulursak
	temp = iter->next;  // iter->next silmek stedi�imiz d���m� g�sterir  // iter silmek stedi�imiz d���mden bir �nceki d���m. // tempe silinecek d���m� att�k.
	iter->next = iter->next->next;  // iterin nexti art�k silinecek d���mden sonraki d���m� g�steriyor.
	free(temp); // silinecek d���m� sildik.
	return r; // root da bir de�i�iklik olmad� ama biz yine de root u d�nd�r�yoruz ��nk� rootu silme ihtimalimiz var.
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