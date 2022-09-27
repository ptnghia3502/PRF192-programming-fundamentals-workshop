#include <stdio.h>

int main() {
	int a,b,c;
	printf("Nhap 2 so a va b: \n");
	scanf("%d%d", &a, &b);
	if (a!=0 && b!=0) {
		c=a;
		a=b;
		b=c;
		printf("Gia tri cua a va b sau khi doi la: %d, %d\n", a, b);
	} else {
		printf("Nhap lai");
	}
	return 0;
}
