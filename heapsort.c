#include "sorting.h"

void heapsort(int n, Heap* h);
void makeheap(int n, Heap* h);
void removekeys(int n, Heap* h, int* s);
int root(Heap* h);
void shiftdown(Heap* h, int i);

void heapsort(int n, Heap* h) {
	makeheap(n, h);
	removekeys(n, h, h->data);
}

void makeheap(int n, Heap* h) {
	int i;
	h->heapsize = n;
	for (int i = n / 2; i >= 1; i--) {
		shiftdown(h, i);
	}
}

void removekeys(int n, Heap* h, int* s) {
	int i;
	for (i = n; i >= 1; i--) {
		s[i] = root(h);
	}
}

int root(Heap* h) {
	int keyout; 

	keyout = h->data[1];
	h->data[1] = h->data[h->heapsize];
	h->heapsize--;
	shiftdown(h, 1);

	return keyout;
}

void shiftdown(Heap* h, int i) {
	int largerchild;
	int shiftkey = h->data[i];
	int parent = i;
	int spotfound = FALSE;

	while (2 * parent <= h->heapsize && !spotfound) {
		if (2 * parent < h->heapsize && h->data[2 * parent] < h->data[2 * parent + 1]) {
			largerchild = 2 * parent + 1;
		}
		else {
			largerchild = 2 * parent;
		}
		if (shiftkey < h->data[largerchild]) {
			h->data[parent] = h->data[largerchild];
			parent = largerchild;
		}
		else {
			spotfound = TRUE;
		}
	}

	h->data[parent] = shiftkey;
}