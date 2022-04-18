#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SORT_NUM 5
#define DB

int** generateRandArrays(int size);
void deleteRandArrays(int** arrays);
void printArray(int size, int* arr);

int main(void) {
	int test_sizes[] = { 10, 15, 20, 30 /*100, 500, 1000, 5000, 10000*/ };
	int test_num = sizeof(test_sizes) / sizeof(int);
	int** rand_arrs;
	int size;

	clock_t start, end;
	double enlapsed_time;

	for (int i = 0; i < test_num; i++) {
		size = test_sizes[i];
		rand_arrs = generateRandArrays(size);

#ifdef DB
		printf("before : "); printArray(size, rand_arrs[0]);
#endif

		printf(" << exchangesort >> \n ");

		start = clock();
		exchangesort(size, rand_arrs[0]);
		end = clock();

		enlapsed_time =  (double)(end - start);
		printf("enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
		printf("after : "); printArray(size, rand_arrs[1]); printf("\n");
#endif

		printf(" << mergesort >> \n ");

		start = clock();
		mergesort(size, rand_arrs[1]);
		end = clock();

		enlapsed_time = (double)(end - start);
		printf("enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
		printf("after : "); printArray(size, rand_arrs[1]); printf("\n");
#endif

		printf(" << quicksort >> \n ");

		start = clock();
		quicksort(0, size-1, rand_arrs[2]);
		end = clock();

		enlapsed_time = (double)(end - start);
		printf("enlasped time: %f sec\n", enlapsed_time / CLOCKS_PER_SEC);

#ifdef DB
		printf("after : "); printArray(size, rand_arrs[2]); printf("\n");
#endif


		deleteRandArray(rand_arrs);
	}
}

// 난수 생성기를 통해서 배열을 동적으로 생성하는 함수
int** generateRandArrays(int size) {
	int** arrays = (int**)malloc(sizeof(int*) * SORT_NUM);
	for (int i = 0; i < SORT_NUM; i++) {
		arrays[i] = (int*)malloc(sizeof(int) * size);
	}
	
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		int rand_value = rand() % 100; //
		for (int j = 0; j < SORT_NUM; j++) {
			arrays[j][i] = rand_value;
		}
	}

	return arrays;
}

// 동적 배열을 반환하는 함수
void deleteRandArrays(int** arrays) {
	for (int i = 0; i < SORT_NUM; i++) {
		free(arrays[i]);
	}
	free(arrays);
}

// 배열의 값을 출력하는 함수
void printArray(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}