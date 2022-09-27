#include <stdio.h>
#include <stdlib.h>

int getchoice();

void function1();

void check(int ngay, int thang, int nam);
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
	printf("\n1-The first n Fibonacci numbers");
	printf("\n2-Check date");
	printf("\nOthers-Quit");
	printf("\nChoose: ");
	scanf("%d%*c", &choice);
	return choice;
}

void function1() {
	int n, i;
	int t1=1, t2=1, f=1;
	printf("Nhap n: ");
	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		if (i<3) printf("%d ", f);
		else {
			f= t1 +t2;
			printf ("%d ", f);
			t1=t2;
			t2=f;
		}
	}
	printf("\n");
}


void check(int ngay, int thang, int nam) {
	int n=0;
	if (nam%4==0 && nam%100!=0) n=1;
	int m=0;
	switch(thang) {
		case 1: if (ngay>31) m=1; break;
		case 3: if (ngay>31) m=1; break;
		case 5: if (ngay>31) m=1; break;
		case 7: if (ngay>31) m=1; break;
		case 8: if (ngay>31) m=1; break;
		case 10: if (ngay>31) m=1; break;
		case 12: if (ngay>31) m=1; break;
		case 4: if (ngay>30) m=1; break;
		case 6: if (ngay>30) m=1; break;
		case 9: if (ngay>30) m=1; break;
		case 11: if (ngay>30) m=1; break;
		case 2: if (n==1) {if (ngay>29) m=1; break;}
		        else {if (ngay>28) m=1; break;} 
	}
		if (m==0) {
			printf("Ngay da nhap hop le\n");
		} else {
			printf("Khong hop le\n");
		}       
}

void function2() {
	int ngay, thang, nam;
	printf("Nhap ngay: ");
	scanf("%d", &ngay);
	printf("Nhap thang: ");
	scanf("%d", &thang);
	printf("Nhap nam: ");
	scanf("%d", &nam);
	if (ngay<1 || thang<1 || nam<0) {
		printf("Khong hop le\n");
	} else {
		check(ngay, thang, nam);
	}
}
