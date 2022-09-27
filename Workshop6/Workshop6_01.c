#include<conio.h>
#include<stdio.h>
#include <string.h>

char ch[100];

int dinhdang(int str)  //Kiem tra dinh dan
{
	int s=0;
    for (int i=0; i<= str; i++)
    {
    	if (ch[i]<48 || ch[i] >57) s++;
	}
	s -=1; 
	if (s==0) return 1; //Dung dinh dang
	else return 0; //Sai dinh dang
}

int chuyenkieu(int str)  //Chuyen tu kieu ky tu sang kieu int
{
    int res = 0;
    for(int i = 0; i < str; i++ )
    {
	    res = res*10 + (ch[i]-48);
    }
    return res;
}

void check(int n)  //Kierm tra ISBN
{
    int total=0;
    int a[100];
    int sotachra;
    for (int i=1; i<=10; i++)   //tach so
	{
        sotachra = n % 10;
        a[i]= sotachra;
        n /= 10;
    }    
    for (int i=1; i<=10; i++) a[i] = a[i] *i; //Nhan vo nguoc lai
    for (int i=1; i<=10; i++) total= total+a[i]; //tinh tong
    if (total%11==0) printf("\nThis is a valid ISBN\n");
    else printf("\nThis is not a valid ISBN");
}

int main()
{
	int n;
	printf("Nhap n: ");
    gets(ch); int str=strlen(ch);
    if (str>10) printf("Nhap lai");  //Nhap sai, hon 10 ky tu
    else
    {
    dinhdang(str);
    if (dinhdang(str)==0) printf("Sai dinh dang, vui long nhap lai");
    else 
	{
		n= chuyenkieu(str);
		check(n);
    }
    return 0; 
    }
}
