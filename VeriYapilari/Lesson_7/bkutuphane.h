#pragma once

// bkutuphane diye bir �ey hen�z tan�mlanmad�ysa
#ifndef bkutuphane 
#define bkutuphane  //  tan�mla

typedef struct node
{
	int x;
	node* next;
	node* prev;
};
void bastir(node* r);
node* ekle(node* r, int x);
node* siraliEkle(node* r, int x);
node* sil(node* r, int x);

#endif // !bkutuphane
