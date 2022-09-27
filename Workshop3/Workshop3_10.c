#include <stdio.h>

void minmax(int n) {
   int min, max, remainder; 
   max=0;
   min=9;
   while (n>0) { 
     remainder = n%10; 
     n=n/10;
     if (min > remainder) min=remainder; 
     if (max < remainder) max=remainder;
   }
   printf("Min: %d\n", min);
   printf("Max: %d", max);
}

int main() {
	int n;
	printf("Nhap vao so nguyen duong: ");
	scanf("%d", &n);
	if (n>0) minmax(n);
	else printf("Nhap lai");
    return 0;
}


