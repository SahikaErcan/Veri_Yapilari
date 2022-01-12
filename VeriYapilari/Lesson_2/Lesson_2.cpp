#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

void bastir(node* r) {  // bir node deðerini alýp bundan null deðerini görene kadar ekrana bastýran fonksiyon 
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
	root->next = NULL;   // baþlangýçta oluþturduðumuz tek kutunun nexti NULL u göstermeli

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

	// sona eleman eklemek için sondaki deðeri gösteren bir yapýya ihtiyacým var. Böylece sonuna bir kutu oluþturabileyim.
	// bu nedenle   while(iter != NULL)   deðil   while(iter -> next != NULL)  dememiz gerekiyor. 


	for (int i = 0; i < 5; i++)
	{
		ekle(root, i*10);

		// Bu yapý performans açýsýndan daha saðlýklý.. While de sürekli baþa sarma durmu var
		//iter->next = (node*)malloc(sizeof(node));   // iterin nextine bir kutu ekliyoruz.
		//iter = iter->next;		 // yeni oluþturduðumuz kutuya eriþiyoruz.
		//iter->x = (i * 10);  // 10 dan baþlýyacak þekilde deðer ekliyoruz.
		//iter->next = NULL; // listenin sonunda her zaman NULL deðerinin olmasýný saðlýyoruz. Böylece hata vermeyecek. 
	}
	bastir(root); // rootun gösterdiði deðerden baþlayarak deðer sonuna kadar ekrana bastýrmaya baþlýyor
}