#pragma once

#define TRUE 1
#define FALSE 0

typedef struct Heap {
	int* data;
	int heapsize;
}Heap;

struct Node {
	int key;
	struct Node* link;
};
typedef struct Node* node_pointer;

void exchangesort(int n, int* S);
void mergesort(int n, int* S);
void quicksort(int low, int high, int* list);
void heapsort(int n, Heap* h);

