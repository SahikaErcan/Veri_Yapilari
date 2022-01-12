
#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

// globalde de�i�ken tan�mlay�p rootu g�ncelleme y�ntemi yerine ba�ka bir yol deniyoruz.
// yeni gelecek de�eri sona ekleyelim ve sondan silelim b�ylece roota dokunmam�� olaca��z.

int total = 0;

void show(node* root) {
	if (total < 0)
	{
		printf("Stak bos. \n");
	}

	node* index = root;
	while (index != NULL)
	{
		printf("%d    ", index->data);
		index = index->next;
	}
	printf("\n");
}

int pop(node* root) {
	total--;
	if (total < 0)
	{
		printf("Stack bos.  ");
		return -1;
	}
	if (root->next == NULL)  // rootun nexti null ise �ayet tek bir d���m kald� demektir
	{
		int r_value = root->data;
		free(root);
		return r_value;
	}
	node* iter = root; // iter rootdan ba�layacak elemanlar� dola�acak
	// e�er iter->next deseydik son eleman� gidecekti bu durumda son eleman� silemezdik. 
	// Bu nedenle son elemandan bir �nceki d���m� buldu�u an duracak.
	while (iter->next->next != NULL) 
		iter = iter->next; // son eleman� buldu

	node* temp = iter->next;  // silece�imiz kutuyu tempe at�yrouz.
	// bu de�eri return edece�imiz i�in bir de�i�kene att�k free(data) yapt�ktan sonra bir daha ula�amay�z diye
	int r_value = temp->data;  
	iter->next = NULL;
	free(temp);
	return r_value;
}

node* push(node* root, int data) {  // ba�l� listelerde sona eleman ekleme kodunu uyguluyoruz
	total++;
	if (root == NULL)   // linklist bo� olabilir. ilk eleman� eklemek i�in kutu olu�tural�m
	{
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->next = NULL;
		return root;
	}

	node* iter = root;
	while (iter->next != NULL)
		iter = iter->next;  // iter son d���m� g�steriyor.

	node* temp = (node*)malloc(sizeof(node));  // datay� eklemek i�in kutu olu�turuyoruz.
	temp->data = data;
	temp->next = NULL;  // yeni kutunun nexti NULL g�steriyor
	iter->next = temp;  // son kutunun nexti art�k null g�stermiyor yeni kutu ekledik.
	return root;
}


