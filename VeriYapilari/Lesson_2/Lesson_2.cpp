#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

void bastir(node* r) {  // bir node de�erini al�p bundan null de�erini g�rene kadar ekrana bast�ran fonksiyon 
	while (r != NULL) {
		printf("%d ", r->x);
		r = r->next;
	}
}

void ekle(node* r, int x) {
	while (r->next != NULL) {
		r = r->next; 
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

int main() {

	node* root;
	root = (node*)malloc(sizeof(node));
	root->next = NULL;   // ba�lang��ta olu�turdu�umuz tek kutunun nexti NULL u g�stermeli

	root->x = 500;

	/*root->x = 10;
	root->next = (node*)malloc(sizeof(node));
	root->next->x = 20;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->x = 30;
	root->next->next->next = NULL;

	node* iter;
	iter = root;

	int i = 0;
	while (iter->next != NULL) {
		i++;
		printf("%d inci eleman %d\n", i, iter->x);
		iter = iter->next;
	}*/

	// sonuna eleman ekleyelim.

	// sona eleman eklemek i�in sondaki de�eri g�steren bir yap�ya ihtiyac�m var. B�ylece sonuna bir kutu olu�turabileyim.
	// bu nedenle   while(iter != NULL)   de�il   while(iter -> next != NULL)  dememiz gerekiyor. 


	for (int i = 0; i < 5; i++)
	{
		ekle(root, i*10);

		// Bu yap� performans a��s�ndan daha sa�l�kl�.. While de s�rekli ba�a sarma durmu var
		//iter->next = (node*)malloc(sizeof(node));   // iterin nextine bir kutu ekliyoruz.
		//iter = iter->next;		 // yeni olu�turdu�umuz kutuya eri�iyoruz.
		//iter->x = (i * 10);  // 10 dan ba�l�yacak �ekilde de�er ekliyoruz.
		//iter->next = NULL; // listenin sonunda her zaman NULL de�erinin olmas�n� sa�l�yoruz. B�ylece hata vermeyecek. 
	}
	bastir(root); // rootun g�sterdi�i de�erden ba�layarak de�er sonuna kadar ekrana bast�rmaya ba�l�yor
}