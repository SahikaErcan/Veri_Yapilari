#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

int main() {

	// d���m yap�yoruz
	node* root;
	root = (node*)malloc(sizeof(node)); // G�sterdi�i yere bo� kutu olu�turuyoruz.
	// Bir tane node in haf�za da kaplad��� kadar alan bana ay�r. Ben bu alan� bir d���m (node) olarak kullanaca��m ve bunu da �uan da root g�sterecek
	// sonu� olarak rootun g�sterdi�i yer haf�zada ilk olu�turdu�umuz kutu


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