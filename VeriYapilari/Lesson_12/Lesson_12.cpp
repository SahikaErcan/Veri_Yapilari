// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	node* left;
	node* right;
};

node* add(node* tree, int data) {
	if (tree == NULL)
	{
		node* root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}
	// Olu�acak her d���m� bo� bir a�a� gibi d���n�yoruz. 
	// Bir a�a� k�k� olu�turup onu sa�a veya sola ko�ula g�re ba�l�yoruz.
	if (tree->data < data) {
		tree->right = add(tree->right, data);
		return tree;
	}		
	tree->left = add(tree->left, data);
	return tree;
}

// A�ACI DOLA�ALIM
//   Infix :  Left - Node - Right    or      Right - Node - Left
//  Prefix :  Node - Left - Right    or      Node - Right - Left
// Postfix :  Left - Right - Node    or      Right - Left - Node

void traversal(node* tree) {
	if (tree == NULL)
		return;
	// Prefix : NRL
	printf("%d ", tree->data);
	traversal(tree->right);
	traversal(tree->left);	
}

int search(node* tree, int wanted) {
	if (tree == NULL)
		return -1;
	if (tree->data == wanted)
		return 1;
	if (search(tree->left, wanted) == 1)
		return 1;
	if (search(tree->right, wanted) == 1)
		return 1;
	return -1;
}
// A�ac�n en sa��ndaki yaprak en b�y�k de�eri tutar.
int maximum(node* tree) {
	while (tree->right != NULL)	
		tree = tree->right;
	return tree->data;	
}

// A�ac�n en solundaki yaprak en k���k de�eri tutar.
int minimum(node* tree) {
	while (tree->left != NULL)
		tree = tree->left;
	return tree->data;
}

// Neden node* yapt�k? ��nk� silinmi� hali bir a�ac� temsil ediyor ve bu a�ac� d�nd�rece�iz.
node* deletion(node* tree, int dele_value) {   
	if (tree == NULL)  // a�a� bo� ise
		return NULL;
	if (tree->data == dele_value)  // arad���m de�eri bulduysam
	{// d���m�n alt�nda �ocuk var m�? yok mu?
		// buldu�um de�erin sa�� ve solu bo� mu kontrol et
		if (tree->left == NULL && tree->right == NULL)  
			return NULL;
		if (tree->right != NULL) // buldu�um de�erin sa��nda bir de�er varsa
		{
			// sa��ndakinin en k�����n� buldu�um d���m�n yerine koy ve buldu�um d���m� sil
			tree->data = minimum(tree->right);  
			tree->right = deletion(tree->right, minimum(tree->right));
			return tree;
		}
		// solunda bir de�er varsa
		// solundaki en b�y�k de�eri bulunan d���m�m yerine koy ve bulunan� sil
		tree->data = maximum(tree->left);
		tree->left = deletion(tree->left, maximum(tree->left));
		return tree;
	}
	// arad���m de�eri bulamad�ysam
	if (tree->data < dele_value) // de�er b�y�kse d���mden a�ac�n sa��nda aranacak
	{
		tree->right = deletion(tree->right, dele_value); 
		return tree;
	}
	// a�ac�n soluna bak
	tree->left = deletion(tree->left, dele_value);
	return tree;
}

int main() {

	node* tree = NULL;

	
	tree = add(tree, 56);
	tree = add(tree, 200);
	tree = add(tree, 26);
	tree = add(tree, 190);
	tree = add(tree, 213);
	tree = add(tree, 18);
	tree = add(tree, 28);
	tree = add(tree, 12);
	tree = add(tree, 24);	
	tree = add(tree, 27);

	traversal(tree);

	printf("\n%d degeri agac da var mi?  %d", 24, search(tree, 24));
	printf("\n%d degeri agac da var mi?  %d", 100, search(tree, 100));

	printf("\nAgacin maximum degeri: %d\nAgacin minumum degeri: %d", maximum(tree), minimum(tree));

	printf("\nSilinmis hali: ");
	//tree = deletion(tree, 190);
	tree = deletion(tree, 56);
	traversal(tree);
}