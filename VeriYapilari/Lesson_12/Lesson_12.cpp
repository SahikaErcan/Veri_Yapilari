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
	// Oluþacak her düðümü boþ bir aðaç gibi düþünüyoruz. 
	// Bir aðaç kökü oluþturup onu saða veya sola koþula göre baðlýyoruz.
	if (tree->data < data) {
		tree->right = add(tree->right, data);
		return tree;
	}		
	tree->left = add(tree->left, data);
	return tree;
}

// AÐACI DOLAÞALIM
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
// Aðacýn en saðýndaki yaprak en büyük deðeri tutar.
int maximum(node* tree) {
	while (tree->right != NULL)	
		tree = tree->right;
	return tree->data;	
}

// Aðacýn en solundaki yaprak en küçük deðeri tutar.
int minimum(node* tree) {
	while (tree->left != NULL)
		tree = tree->left;
	return tree->data;
}

// Neden node* yaptýk? Çünkü silinmiþ hali bir aðacý temsil ediyor ve bu aðacý döndüreceðiz.
node* deletion(node* tree, int dele_value) {   
	if (tree == NULL)  // aðaç boþ ise
		return NULL;
	if (tree->data == dele_value)  // aradýðým deðeri bulduysam
	{// düðümün altýnda çocuk var mý? yok mu?
		// bulduðum deðerin saðý ve solu boþ mu kontrol et
		if (tree->left == NULL && tree->right == NULL)  
			return NULL;
		if (tree->right != NULL) // bulduðum deðerin saðýnda bir deðer varsa
		{
			// saðýndakinin en küçüðünü bulduðum düðümün yerine koy ve bulduðum düðümü sil
			tree->data = minimum(tree->right);  
			tree->right = deletion(tree->right, minimum(tree->right));
			return tree;
		}
		// solunda bir deðer varsa
		// solundaki en büyük deðeri bulunan düðümüm yerine koy ve bulunaný sil
		tree->data = maximum(tree->left);
		tree->left = deletion(tree->left, maximum(tree->left));
		return tree;
	}
	// aradýðým deðeri bulamadýysam
	if (tree->data < dele_value) // deðer büyükse düðümden aðacýn saðýnda aranacak
	{
		tree->right = deletion(tree->right, dele_value); 
		return tree;
	}
	// aðacýn soluna bak
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