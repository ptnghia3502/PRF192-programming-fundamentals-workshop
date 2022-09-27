#include <stdio.h>        //Nhap 5 so nguyen to
#include <math.h> 

int prime(int n) {
	int result=1, i;
	for (i=2; i*i<=n && result==1; i++) 
	   if (n%i==0) result=0;
	return result;   
}

int main()
{
	int i=0;
	int n;
	int a[5];
	printf("Nhap 5 so nguyen to: \n");
    do
    {
        scanf("%d", &n);
        if (prime(n) == 0) printf("\nSo vua nhap khong phai so nguyen to, vui long nhap lai!\n");
        else {
		a[i] = n;
		i++;
	    }
    }
    while (i!=5);
	printf("\nMang da nhap la: ");
	for (i=0; i<=4; i++) printf ("%d ", a[i]);
	getchar();
	return 0;
}
