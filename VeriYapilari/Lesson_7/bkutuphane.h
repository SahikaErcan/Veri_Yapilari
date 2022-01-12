#pragma once

// bkutuphane diye bir þey henüz tanýmlanmadýysa
#ifndef bkutuphane 
#define bkutuphane  //  tanýmla

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
