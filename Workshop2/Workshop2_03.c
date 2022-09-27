#include<stdio.h>

int main() {
   int n, sum;
   sum = 0;
   printf("Nhap cac so: \n");
   while (n != 0) {
        scanf("%d\n", &n);
        if (n != 0) {
        	sum= sum + n;
		} 
   }
   printf("Tong cac so da nhap: %d", sum);
   return 0;
}
