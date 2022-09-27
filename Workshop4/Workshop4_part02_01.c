#include <stdio.h>
#include <stdlib.h>

int getchoice();

int prime(int n);
void function1();

void function2(); 

int main() {
	int userchoice;
	do {
		userchoice = getchoice();
		switch(userchoice)
		{
			case 1: function1(); break;
			case 2: function2(); break;
			default: printf("Bye\n");
		}
	}
	while (userchoice>0 && userchoice<3);
	fflush(stdin);
	getchar();
	return 0;
}

int getchoice() {
	int choice;
	printf("\n1-Number is a prime or not");
	printf("\n2-Minimum and maximum digit of number");
	printf("\nOthers-Quit");
	printf("\nChoose: ");
	scanf("%d%*c", &choice);
	return choice;
}

int prime(int n) {
	int s=1, i;
	for (i=2; i*i<=n && s==1; i++) 
	   if (n%i==0) s=0;
	return s;   
}

void function1() {
	int n;
	printf("Nhap vao so nguyen duong: ");
	scanf("%d", &n);
	if (prime(n)==1) printf("%d la so nguyen to\n", n);
	else printf("%d khong la so nguyen to\n", n);
}  

void function2() {
   int n;
   printf("Nhap vao so nguyen duong: ");
   scanf("%d", &n);
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
   printf("Max: %d\n", max);
} 
