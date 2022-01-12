
#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

// globalde deðiþken tanýmlayýp rootu güncelleme yöntemi yerine baþka bir yol deniyoruz.
// yeni gelecek deðeri sona ekleyelim ve sondan silelim böylece roota dokunmamýþ olacaðýz.

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
	if (root->next == NULL)  // rootun nexti null ise þayet tek bir düðüm kaldý demektir
	{
		int r_value = root->data;
		free(root);
		return r_value;
	}
	node* iter = root; // iter rootdan baþlayacak elemanlarý dolaþacak
	// eðer iter->next deseydik son elemaný gidecekti bu durumda son elemaný silemezdik. 
	// Bu nedenle son elemandan bir önceki düðümü bulduðu an duracak.
	while (iter->next->next != NULL) 
		iter = iter->next; // son elemaný buldu

	node* temp = iter->next;  // sileceðimiz kutuyu tempe atýyrouz.
	// bu deðeri return edeceðimiz için bir deðiþkene attýk free(data) yaptýktan sonra bir daha ulaþamayýz diye
	int r_value = temp->data;  
	iter->next = NULL;
	free(temp);
	return r_value;
}

node* push(node* root, int data) {  // baðlý listelerde sona eleman ekleme kodunu uyguluyoruz
	total++;
	if (root == NULL)   // linklist boþ olabilir. ilk elemaný eklemek için kutu oluþturalým
	{
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->next = NULL;
		return root;
	}

	node* iter = root;
	while (iter->next != NULL)
		iter = iter->next;  // iter son düðümü gösteriyor.

	node* temp = (node*)malloc(sizeof(node));  // datayý eklemek için kutu oluþturuyoruz.
	temp->data = data;
	temp->next = NULL;  // yeni kutunun nexti NULL gösteriyor
	iter->next = temp;  // son kutunun nexti artýk null göstermiyor yeni kutu ekledik.
	return root;
}


