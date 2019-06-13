#include<stdio.h>
#include<stdlib.h>

#define MAX_INDEX 1000

int fibonacci(int k, int m);

int main() {
	
	int i = fibonacci(2, 5);
	printf("%d\n", i);
	system("pause");
	return 0;
}

int fibonacci(int k, int m) {
	int result = 0;
	int a[MAX_INDEX];

	if (m < 0 || k < 2) {
		printf("输入参数错误，请检查！");
		return -1;
	}

	if (m < k - 1) {
		return 0;
	}

	if (m == k - 1) {
		return 1;
	}

	for (int i = 0; i < k - 1; i++) {
		a[i] = 0;
	}
	a[k - 1] = 1;

	for (int i = k; i < m; i++) {
		int sum = 0;
		for (int j = i - k; j < i; j++) {
			sum += a[j];
		}
		a[i] = sum;
	}

	result = a[m - 1];

	return result;

}