#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

#define SORT_NUM 5 // 테스트할 정렬함수의 개수
//#define DB         // 정렬한 결과를 출력할지 결정하는 매크로

int* generateRandArray(int size);
void deleteRandArray(int* array);
void printArray(int size, int* arr);

void testExchangesort(int size, int* arr);
void testMergesort(int size, int* arr);
void testQuicksort(int size, int* arr);
void testHeapsort(int size, int* arr);
void testRadixsort(int size, int* arr);

int main(void) {
	int test_sizes[] = { /*10, 15, 20, 30*/ 100, 500, 1000, 5000, 10000 }; // 테스트에 사용할 배열의 크기
	int test_num = sizeof(test_sizes) / sizeof(int); // 테스트 횟수
	int* rand_arr;   // 정렬할 배열을 할당받는 변수
	int size;        // 정렬할 배열의 크기

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

// 교환정렬 테스트 함수
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

// 합병정렬 테스트 함수
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

// 퀵정렬 테스트 함수
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

// 힙정렬 테스트 함수
void testHeapsort(int size, int* arr) {
	clock_t start, end;
	double enlapsed_time;
	Heap heap;
	
	// 동적배열을 만들어서 힙에 할당
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

// 기수 정렬 테스트 함수
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

// 난수 생성기를 통해서 배열을 동적으로 생성하는 함수
int* generateRandArray(int size) {
	int* array = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}

	return array;
}

// 동적 배열을 반환하는 함수
void deleteRandArray(int* array) {
	free(array);
}

// 배열의 값을 출력하는 함수
void printArray(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}