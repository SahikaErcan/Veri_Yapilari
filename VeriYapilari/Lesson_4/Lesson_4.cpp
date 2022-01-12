// Baðlý Listeden Eleman Silme

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

// Baþtaki elemaný silmek isteyebiliriz. Bu durumda root un deðiþme ihtimali var. 
// Bu nedenle baþtaki elemaný düþünmemiz gerekiyor. Metodu node* ile oluþturuyoruz.

node* sil(node* r, int x) {
	node* temp;    // bir tane silinecek elemanýn silinmesi için bir düðüm tanýmlamamýz gerekiyor.
	node* iter;    // bir tane de silinecek elemaný göstermek için bir düðüm tanýmlamamýz gerekiyor. 
	iter = r;   // root dan baþlatýyoruz.

	// rootu yani baþtaki deðeri silme durumu
	if (r->x == x) // aradýðým deðer root ise
	{
		temp = r;  // silinecek deðeri tempe attýk
		r = r->next; // root artýk diðer degeri gösteriyor.
		free(temp); // sildik
		return r;
	}

	while (iter->next != NULL && iter->next->x != x)   // iterin nexti null dan farklýysa ve iterin nextinin deðeri bizim aradýðýmýz x deðerinden farklýsa dön
	{
		iter = iter->next;
	} // sileceðimiz list deðil bir öncesinde durduk. iter..

	if (iter->next == NULL) // iterden sonrasý bulunamadýysa null
	{
		printf("%d Sayisi Bulunamadi.  ->  ", x);
		return r;
	}
	// linklistin ortasýnda sayýyý bulursak
	temp = iter->next;  // iter->next silmek stediðimiz düðümü gösterir  // iter silmek stediðimiz düðümden bir önceki düðüm. // tempe silinecek düðümü attýk.
	iter->next = iter->next->next;  // iterin nexti artýk silinecek düðümden sonraki düðümü gösteriyor.
	free(temp); // silinecek düðümü sildik.
	return r; // root da bir deðiþiklik olmadý ama biz yine de root u döndürüyoruz çünkü rootu silme ihtimalimiz var.
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