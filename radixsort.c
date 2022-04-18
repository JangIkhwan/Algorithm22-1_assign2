#include <stdlib.h>
#include "sorting.h"

void radixsort(node_pointer* masterlist, int numdigits);
void distribute(node_pointer* masterlist, node_pointer* list, int i);
void coalesce();

void radixsort(node_pointer* masterlist, int numdigits) {
	int i;
	node_pointer list[10];

	for (i = 1; i <= numdigits; i++) {
		distribute(masterlist, list, i);
		//coalesce(masterlist, list);
	}
}

void distribute(node_pointer* masterlist, node_pointer* list, int i) {
	int j;
	node_pointer p;

	for (j = 0; j <= 9; j++) {
		list[i] = NULL;
	} 
	p = masterlist;
	while (p != NULL) {
		j = getDigit(p->key, i);
		
	}
}

int getDigit(int num, int i) {
	int j, ret;

	j = 1;
	while (j <= i) {
		ret = num % 10;
		num /= 10;
		j++;
	}
	
	return ret;
}




