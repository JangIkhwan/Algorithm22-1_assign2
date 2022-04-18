void quicksort(int low, int high, int* list);
void partition(int low, int high, int* pivot, int* list);

// 퀵정렬을 수행하는 함수
void quicksort(int low, int high, int* list) {
	int pivot;
	if (high > low) {
		partition(low, high, &pivot, list);
		quicksort(low, pivot - 1, list);
		quicksort(pivot + 1, high, list);
	}
}

void partition(int low, int high, int* pivot, int* list) {
	int i, j, pivot_item, temp;

	pivot_item = list[low];
	j = low;
	for (i = j + 1; i <= high; i++) {
		if (list[i] < pivot_item) {
			j++;
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
	*pivot = j;
	temp = list[low];
	list[low] = list[*pivot];
	list[*pivot] = temp;
}