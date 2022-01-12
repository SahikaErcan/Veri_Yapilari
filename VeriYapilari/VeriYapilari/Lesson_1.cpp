#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

int main() {

	// düðüm yapýyoruz
	node* root;
	root = (node*)malloc(sizeof(node)); // Gösterdiði yere boþ kutu oluþturuyoruz.
	// Bir tane node in hafýza da kapladýðý kadar alan bana ayýr. Ben bu alaný bir düðüm (node) olarak kullanacaðým ve bunu da þuan da root gösterecek
	// sonuç olarak rootun gösterdiði yer hafýzada ilk oluþturduðumuz kutu


	root->x = 10;										// ---- > 10
	root->next = (node*)malloc(sizeof(node));			// ---- > 10 next
	root->next->x = 20;									// ---- > 10 next     20
	root->next->next = (node*)malloc(sizeof(node));	    // ---- > 10 next     20 next
	root->next->next->x = 30;             	            // ---- > 10 next     20 next    30

	node* iter;
	iter = root;    

	printf("%d", iter->x);

	iter = iter->next;

	printf("%d", iter->x);

}