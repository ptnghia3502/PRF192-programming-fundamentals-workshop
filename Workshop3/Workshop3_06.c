#include <stdio.h>

void fibo(int n) {
    long i,j;
    i=1;
    j=1;
    do {
        if (j==n) {
            printf("So vua nhap thuoc day Fibonacci");
            return;
        }
        j+=i;
        i=j-i;
    }
    while(j<=n);
    printf("So vua nhap khong thuoc day Fibonacci");
}


int main() {
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);
	fibo(n);
	return 0;
}
