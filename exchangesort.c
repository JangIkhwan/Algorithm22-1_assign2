// ��ȯ ������ �����ϴ� �Լ�
void exchangesort(int n, int* S) {
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (S[j] < S[i]) {
				temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
}