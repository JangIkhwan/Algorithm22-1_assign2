#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

#define SORT_NUM 5 // �׽�Ʈ�� �����Լ��� ����
#define DB         // ���� ���� ��½�ų���� �����ϴ� ��ũ��

int** generateRandArrays(int size);
void deleteRandArrays(int** arrays);
void printArray(int size, int* arr);

void testExchangesort(int size, int* arr);
void testMergesort(int size, int* arr);
void testQuicksort(int size, int* arr);
void testHeapsort(int size, int* arr);
void testRadixsort(int size, int* arr);

int main(void) {
	int test_sizes[] = { 10, 15, 20, 30 /*100, 500, 1000, 5000, 10000*/ }; // �׽�Ʈ�� ����� �迭�� ũ��
	int test_num = sizeof(test_sizes) / sizeof(int); // �׽�Ʈ Ƚ��
	int** rand_arrs; // ������ �迭�� �Ҵ�޴� ����
	int size;        // ������ �迭�� ũ��

	srand((unsigned int)time(NULL));

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arrs = generateRandArrays(size); // 2���� �迭�� ��ȯ����

		printf("%d. input size: %d\n\n", i + 1, size);

#ifdef DB
		printf("before : "); printArray(size, rand_arrs[0]); printf("\n");
#endif

		testExchangesort(size, rand_arrs[0]);
		testMergesort(size, rand_arrs[1]);
		testQuicksort(size, rand_arrs[2]);
		testHeapsort(size, rand_arrs[3]);
		//testRadixsort(size, rand_arrs[4]);

		printf("\n");

		deleteRandArrays(rand_arrs);

	}
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
int** generateRandArrays(int size) {
	int** arrays = (int**)malloc(sizeof(int*) * SORT_NUM); // ��ȯ�� �迭�� 2���� �迭
	for (int i = 0; i < SORT_NUM; i++) {
		arrays[i] = (int*)malloc(sizeof(int) * size);
	}
	
	// ���� ������ ���� �������� ������
	for (int i = 0; i < size; i++) {
		int rand_value = rand() % 100;
		for (int j = 0; j < SORT_NUM; j++) {
			arrays[j][i] = rand_value;
		}
	}

	return arrays;
}

// ���� �迭�� ��ȯ�ϴ� �Լ�
void deleteRandArrays(int** arrays) {
	for (int i = 0; i < SORT_NUM; i++) {
		free(arrays[i]);
	}
	free(arrays);
}

// �迭�� ���� ����ϴ� �Լ�
void printArray(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}