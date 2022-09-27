#include <stdio.h>

int main() {
	long int  income, n;
	long int ti,tf, incometax;
	printf("Thu nhap: \n");
	scanf("%ld", &income);
	printf("Nhap so nguoi phu thuoc: \n");
	scanf("%d", &n);
	tf = 12*(9000000 + n*3600000);
	ti = income - tf;
	if (ti <= 0) {
		incometax = 0;
		ti =0;
    } 
    if (1 <= ti <= 5000000) {
		incometax = ti*5/100;
    }
    if (5000001 <= ti <= 10000000) {
		incometax = ti*10/100;
    }
    if (10000001 <= ti <= 18000000) {
		incometax = ti*15/100;
    }
    if (ti > 18000000) {
		incometax = (ti/100)*20;
    }
    printf("Your income of this year: %ld\n", income);
    printf("Number of dependent: %ld\n", n);
    printf("Tax-free income: %ld\n", tf);
    printf("Taxable income: %ld\n", ti);
    printf("Income tax: %ld\n", incometax);
    return 0;
}
