#include <stdio.h>
#include <math.h> 

int prime(int n) {
	int result=1, i;
	for (i=2; i*i<=n && result==1; i++) 
	   if (n%i==0) result=0;
	return result;   
}

int main() {
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);
	for (int i=2; i<=n; i++) {
		if (prime(i)==1) {
			printf("%d ", i);
		}
	}
}
