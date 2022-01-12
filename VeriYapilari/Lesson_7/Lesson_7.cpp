// Header ".h" dosyasý yazma

#include <stdio.h>
#include <stdlib.h>
#include "bkutuphane.h";

int main() {

	node* root = NULL;

	for (int i = 0; i < 5; i++)
	{
		root = ekle(root, i*10);
	}
	bastir(root);


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