#include <stdio.h>    //Tim so lon nhat va so lan xuat hien cua so

int main() {
	int i, n;
	int a[10];
	for (i=1; i<=10; i++) 
	{
		printf("Nhap vao phan tu thu %d : ", i);          //Nhap mang
		scanf("%d", &a[i]);
	}
	printf("\nMang da nhap la: ");
	for (i=1; i<=10; i++) printf ("%d ", a[i]);          //In mang
	printf("\n");
	int max = a[1];
	int min = a[1];
	int s=0; int x=0;
	for (i=1; i<=10; i++)                        //Tim max min 
	{
		if (max <= a[i]) max = a[i];
		if (min >= a[i]) min = a[i];
	}
	for (i=1; i<=10; i++)                  //So lan xuat hien cua max min  
	{
		if (max == a[i]) s++;
		if (min == a[i]) x++;
	} 
	
	printf("So lon nhat la: %d ", max);
	printf("So lan xuat hien: %d\n", s);
	printf("So nho nhat la: %d ", min);
	printf("So lan xuat hien: %d\n", x);
	getchar();
	return 0;
}
