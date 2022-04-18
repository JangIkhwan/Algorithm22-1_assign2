#include <stdlib.h>

void mergesort(int n, int* S);
void merge(int h, int m, int* U, int* V, int* S);

void mergesort(int n, int* S) {
	if (n > 1) {
		int h = n / 2;
		int m = n - h;
		int * U = (int*)malloc(sizeof(int) * h);
		int * V = (int*)malloc(sizeof(int) * m);
		
		int i;
		for (i = 0; i < h; i++) {
			U[i] = S[i];
		}
		for (i = h; i < n; i++) {
			V[i - h] = S[i];
		}

		mergesort(h, U);
		mergesort(m, V);
		merge(h, m, U, V, S);
		
		free(U);
		free(V);
	}
}

void merge(int h, int m, int* U, int* V, int* S) {
	int i, j, k;
	
	i = j = k = 0;
	while (i < h && j < m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
	}

	if (i >= h) {
		while (j < m) {
			S[k] = V[j];
			j++;
			k++;
		}
	}
	else {
		while (i < h) {
			S[k] = U[i];
			i++;
			k++;
		}
	}
}

