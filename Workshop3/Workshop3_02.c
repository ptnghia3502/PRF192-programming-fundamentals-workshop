#include <stdio.h>

int ngay, thang, nam;

void check(int thang, int nam) {
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
			printf("Ngay da nhap hop le");
		} else {
			printf("Khong hop le");
		}       
}

int main() {
	printf("Nhap ngay: ");
	scanf("%d", &ngay);
	printf("Nhap thang: ");
	scanf("%d", &thang);
	printf("Nhap nam: ");
	scanf("%d", &nam);
	if (ngay<1 || thang<1 || nam<0) {
		printf("Nhap lai");
	} else {
		check(thang, nam);
	}
	return 0;
}
