#include <stdio.h>

void factorial(int n) {
	int s=1;
	for (int i=2; i<=n; i++) {
		s = s*i;
	}
	printf("Giai thua cua so da nhap: %d", s);
}

int main() {
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);
	factorial(n);
	return 0;
}
