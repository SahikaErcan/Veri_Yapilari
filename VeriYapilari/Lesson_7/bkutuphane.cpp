#include <stdio.h>
#include <stdlib.h>
#include "bkutuphane.h"

void bastir(node* r) {
	while (r != NULL)
	{
		printf("%d ", r->x);
		r = r->next;
	}
	printf("\n");
}

node* ekle(node* r, int x) {

	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->prev = NULL;
		r->next = NULL;
		r->x = x;
		return r;
	}

	node* iter = r;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));
	temp->prev = iter;
	iter->next = temp;
	temp->next = NULL;
	temp->x = x;
	return r;
}

node* siraliEkle(node* r, int x) {

	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->prev = NULL;
		r->next = NULL;
		r->x = x;
		return r;
	}
	if (r->x > x)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;
		r->prev = temp;
		return temp;
	}

	node* iter = r;
	while (iter->next != NULL && iter->next->x < x)
	{
		iter = iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));

	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;


	if (temp->next != NULL)
		temp->next->prev = temp;
	temp->x = x;
	return r;
}

node* sil(node* r, int x) {
	node* temp;
	node* iter;
	iter = r;

	if (r->x == x)
	{
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}

	while (iter->next != NULL && iter->next->x != x)
	{
		iter = iter->next;
	}

	if (iter->next == NULL)
	{
		printf("%d sayisi bulunamadi.  -->  ", x);
		return r;
	}

	temp = iter->next;
	iter->next = iter->next->next;

	free(temp);

	if (iter->next != NULL)
	{
		iter->next->prev = iter;
	}
	return r;
}