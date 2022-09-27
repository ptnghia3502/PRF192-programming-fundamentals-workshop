#include <stdio.h>

int main() {
	char a,b;
	int d;
	char t;
	printf("Nhap 2 ky tu: \n");
	scanf("%c", &a); getchar();
	scanf("%c", &b); getchar();
	printf("%c, %c\n", a, b);
	if (a>b) {
		t=a;
		a=b;
		b=t;
	}
	d= b - a;
	printf("Hieu cua 2 ky tu: %d\n", d);
	printf("%c: %d, %o, %X\n", a, a, a, a);
	printf("%c: %d, %o, %X\n", b, b, b, b);
	return 0;
}
