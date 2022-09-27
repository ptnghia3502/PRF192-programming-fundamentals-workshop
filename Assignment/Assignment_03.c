#include <stdio.h>      //20 phan tu dau tien cua day fibonacci
#include <stdlib.h>

int main() {
	int i;
	int t1=1, t2=1, f=1;
	int a[20];
	for (i=1; i<=20; i++) {           //Tinh so fibo
		if (i<3) a[i] = f;	    
		else 
		{
			f= t1 + t2;
			a[i] = f;
			t1=t2;
			t2=f;
		}
	}
	printf("20 phan tu dau tien cua day fibonacci la: \n");
	for (i=1; i<=20; i++) printf ("%d ", a[i]);
	printf("\n");
	system("pause");
	return 0;
}
