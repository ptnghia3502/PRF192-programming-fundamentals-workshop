#include <stdio.h>

void fibo(int n) {
   int t1=1, t2=1, f=1;
   for (int i=1; i<=n; i++) {
		if (i<3) f=f+1;
		else {
			f= t1 +t2;
			t1=t2;
			t2=f;
		}
	}
	printf("Gia tri cua so thu %d trong day: %d", n, f);
} 

int main() {
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);
	fibo(n);
	return 0;
}
