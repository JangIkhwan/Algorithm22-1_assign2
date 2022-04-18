#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

#define SORT_NUM 5 // �׽�Ʈ�� �����Լ��� ����
//#define DB         // ������ ����� ������� �����ϴ� ��ũ��

int* generateRandArray(int size);
void deleteRandArray(int* array);
void printArray(int size, int* arr);

void testExchangesort(int size, int* arr);
void testMergesort(int size, int* arr);
void testQuicksort(int size, int* arr);
void testHeapsort(int size, int* arr);
void testRadixsort(int size, int* arr);

int main(void) {
	int test_sizes[] = { /*10, 15, 20, 30*/ 100, 500, 1000, 5000, 10000 }; // �׽�Ʈ�� ����� �迭�� ũ��
	int test_num = sizeof(test_sizes) / sizeof(int); // �׽�Ʈ Ƚ��
	int* rand_arr;   // ������ �迭�� �Ҵ�޴� ����
	int size;        // ������ �迭�� ũ��

	srand((unsigned int)time(NULL));

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arr = generateRandArray(size);

		printf("input size: %d ", size);

#ifdef DB
		printf("before : "); printArray(size, rand_arr); printf("\n");
#endif

		testExchangesort(size, rand_arr);

		deleteRandArray(rand_arr);
	}

	printf("\n");

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arr = generateRandArray(size);

		printf("input size: %d ", size);

#ifdef DB
		printf("before : "); printArray(size, rand_arr); printf("\n");
#endif

		testMergesort(size, rand_arr);

		deleteRandArray(rand_arr);
	}
	printf("\n");

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arr = generateRandArray(size);

		printf("input size: %d ", size);

#ifdef DB
		printf("before : "); printArray(size, rand_arr); printf("\n");
#endif

		testQuicksort(size, rand_arr);
		
		deleteRandArray(rand_arr);
	}
	printf("\n");

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arr = generateRandArray(size);

		printf("input size: %d ", size);

#ifdef DB
		printf("before : "); printArray(size, rand_arr); printf("\n");
#endif

		testHeapsort(size, rand_arr);

		deleteRandArray(rand_arr);
	}
	printf("\n");

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arr = generateRandArray(size);

		printf("input size: %d ", size);

#ifdef DB
		printf("before : "); printArray(size, rand_arr); printf("\n");
#endif

		testRadixsort(size, rand_arr);

		deleteRandArray(rand_arr);
	}
	printf("\n");
}

// ��ȯ���� �׽�Ʈ �Լ�
void testExchangesort(int size, int* arr) {
	clock_t start, end;
	double enlapsed_time;
	
	start = clock();
	exchangesort(size, arr);
	end = clock();

	enlapsed_time = (double)(end - start);
	printf("< exchangesort > enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
	printf("after : "); printArray(size, arr); printf("\n");
#endif

}

// �պ����� �׽�Ʈ �Լ�
void testMergesort(int size, int* arr) {
	clock_t start, end;
	double enlapsed_time;

	start = clock();
	mergesort(size, arr);
	end = clock();

	enlapsed_time = (double)(end - start);
	printf("< mergesort > enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
	printf("after : "); printArray(size, arr); printf("\n");
#endif

}

// ������ �׽�Ʈ �Լ�
void testQuicksort(int size, int* arr) {
	clock_t start, end;
	double enlapsed_time;

	start = clock();
	quicksort(0, size - 1, arr);
	end = clock();

	enlapsed_time = (double)(end - start);
	printf("< quicksort > enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
	printf("after : "); printArray(size, arr); printf("\n");
#endif

}

// ������ �׽�Ʈ �Լ�
void testHeapsort(int size, int* arr) {
	clock_t start, end;
	double enlapsed_time;
	Heap heap;
	
	// �����迭�� ���� ���� �Ҵ�
	int* data = (int*)malloc(sizeof(int) * (size + 1));
	for (int i = 1; i <= size; i++) {
		data[i] = arr[i - 1];
	}
	heap.data = data;
	heap.heapsize = size;

	start = clock();
	heapsort(size, &heap);
	end = clock();

	enlapsed_time = (double)(end - start);
	printf("< heapsort > enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
	printf("after : "); 
	for (int i = 1; i <= size; i++) {
		printf("%d ", heap.data[i]);
	}
	printf("\n");
#endif

	free(data);
}

// ��� ���� �׽�Ʈ �Լ�
void testRadixsort(int size, int* arr) {
	clock_t start, end;
	double enlapsed_time;

	start = clock();
	//
	end = clock();

	enlapsed_time = (double)(end - start);
	printf("< radixsort > enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);


#ifdef DB
	printf("after : "); printArray(size, arr); printf("\n");
#endif

}

// ���� �����⸦ ���ؼ� �迭�� �������� �����ϴ� �Լ�
int* generateRandArray(int size) {
	int* array = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}

	return array;
}

// ���� �迭�� ��ȯ�ϴ� �Լ�
void deleteRandArray(int* array) {
	free(array);
}

// �迭�� ���� ����ϴ� �Լ�
void printArray(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}