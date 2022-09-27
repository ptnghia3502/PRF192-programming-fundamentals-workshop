#include <stdio.h>  //Menu check ngay vs check data 
#include <stdlib.h>

int getchoice();

void check(int ngay, int thang, int nam);
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
	printf("\n1-Check date");
	printf("\n2-Character data");
	printf("\nOthers-Quit");
	printf("\nChoose: ");
	scanf("%d%*c", &choice);
	return choice;
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

void function1() {
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

void function2() {
	char c1,c2;
	int d, t;
	printf("Input c1: ");
	scanf("%c", &c1);
	printf("Input c2: ");
	fflush(stdin);
	scanf("%c", &c2);
	if (c1 > c2) 
	{
		t= c1; c1=c2; c2=t;
    }
	d = c2 - c1;
	for (d = c2; d >= c1; d--)
		printf("%c: %d, %o, %X\n", d, d, d, d);
}

