#include "p1_cprog04.h"

void sample99(int col_start, int col_end, int row_start, int row_end, int* sum) {
	for (int col = col_start; col <= col_end; ++col) {
		for (int row = row_start; row <= row_end; ++row) {
			printf("%d * %d = %d\n", col, row, col*row);
		}
	}

	int col_sum = ((col_end + col_start) * (col_end - col_start + 1)) >> 1;
	int row_sum = ((row_end + row_start) * (row_end - row_start + 1)) >> 1;
	
	if (sum != NULL) *sum = col_sum * row_sum;
}

void sample99v0() {
	sample99(1, 9, 1, 9, NULL);
}

void sample99v1(int col_end) {
	sample99(1, col_end, 1, 9, NULL);
}

void sample99v2(int col_start, int col_end) {
	sample99(col_start, col_end, 1, 9, NULL);
}

void sample99v3(int col_start, int col_end, int row_start, int row_end) {
	sample99(col_start, col_end, row_start, row_end, NULL);
}

int sample99v4(int col_start, int col_end, int row_start, int row_end) {
	int sum = 0;
	
	sample99(col_start, col_end, row_start, row_end, &sum);
	return sum;
}

void sample99v5static(int col_start, int col_end, int row_start, int row_end) {
	static int static_sum = 0;
	int sum;

	sample99(col_start, col_end, row_start, row_end, &sum);
	static_sum += sum;

	printf("총합은 %d입니다.\n",  static_sum);
}

int sample99v4_interactive() {
	int col_start, col_end, row_start, row_end;
	int sum;

	printf("- 구구단의 시작 단을 입력하세요 : ");
	scanf("%d", &col_start);
	printf("- 구구단의 끝 단을 입력하세요 : ");
	scanf("%d", &col_end);
	printf("- 각 구구단의 시작 값을 입력하세요 : ");
	scanf("%d", &row_start);
	printf("- 각 구구단의 끝 값을 입력하세요 : ");
	scanf("%d", &row_end);

	sum = sample99v4(col_start, col_end, row_start, row_end);
	return sum;
}

void p1_cprog04() {
	int sum;
	
	printf("v0\n");
	sample99v0();

	printf("\nv1\n");
	sample99v1(5);

	printf("\nv2\n");
	sample99v2(3, 5);

	printf("\nv3\n");
	sample99v3(3, 12, -1, 5);

	printf("\nv4\n");
	sum = sample99v4(3, 12, -1, 5);
	printf("총합은 %d입니다\n", sum);

	printf("\nv5\n");
	sample99v5static(3, 12, -1, 5);

	printf("\nv4 interactive\n");
	sum = sample99v4_interactive();
	printf("총합은 %d입니다\n", sum);
}
