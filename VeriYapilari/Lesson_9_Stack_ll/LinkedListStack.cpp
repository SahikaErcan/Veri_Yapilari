#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"


int main() {
	node* s = NULL;
	s = push(s, 10);
	s = push(s, 20);
	show(s);

	printf("%d   ", pop(s));
	s = push(s, 30);
	show(s);
	printf("%d   ", pop(s));
	printf("%d   ", pop(s));
	printf("%d   ", pop(s));
	printf("%d   ", pop(s));
}