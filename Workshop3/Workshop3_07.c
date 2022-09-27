#include <stdio.h>

void tinhtong() {
    int x, sum=0;	
	printf("Nhap so nguyen duong: ");
	do {
		scanf("%d", &x);
		if (x>=0) {
		    sum +=x;
		    printf("Tong: %d\n", sum);
		    printf("Nhap so nguyen duong tiep theo: "); 
		} 
		else {
			break;
		}
	}
	while (x>=0);
	if (x<0) printf("Nhap lai");
}

int main() {
	tinhtong();
	return 0;
}
