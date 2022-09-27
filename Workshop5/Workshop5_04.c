#include <stdio.h>       //Menu check pt bac 2 vs lai ngan hang
#include <stdlib.h>
#include <math.h> 

int getchoice();

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
	printf("\n1-Quadratic equation"); //pt bac 2 
	printf("\n2-Bank deposit problem"); //lai ngan hang
	printf("\nOthers-Quit");
	printf("\nChoose: ");
	scanf("%d%*c", &choice);
	return choice;
}

void function1() {
	int a, b, c, delta;
    double x1, x2;
    printf("Nhap vao he so a,b,c cua phuong trinh: ax^2 + bx + c = 0\n");
    scanf("%d", &a); fflush(stdin);
    scanf("%d", &b); fflush(stdin);
    scanf("%d", &c); 
    delta= b*b - 4*a*c;
    if (delta >=0)
    {
    	if (delta>0) 
    	{
    		x1 = (-b +sqrt(delta))/(2*a);
    		x2 = (-b -sqrt(delta))/(2*a);
    		printf("Phuong trinh co 2 nghiem: x1= %f, x2=%f\n", x1, x2);
		}
		else
		{
			x1 = (-b)/(2*a);
			printf("Phuong trinh co nghiem kep: x1 = x2 = %f\n", x1);
		}
	}
	else printf("Phuong trinh vo nghiem\n");
}

void function2() {
	int tiengui, nam;
	float r, tile, tong;
	printf("Enter depoist: \n"); //Nhap vao tien gui
	scanf("%d", &tiengui); fflush(stdin); //Nhap so nguyen duong
	if (tiengui<=0) printf("Nhap lai\n");
	else
	{
	  printf("Yearly rate: \n"); //Ti le moi nam
	  scanf ("%f", &tile); fflush(stdin); //So duong <= 0.1
	  if (tile <=0 || tile >0.1) printf("Nhap lai\n");
	  else
	  {
	    printf("Number of years: \n"); // Nhap so nam
	    scanf("%d", &nam); //nhap so nguyen duong
	    if (nam <=0) printf("Nhap lai\n");
	    else
	    {
	      r= 1+tile;
	      tong= tiengui*pow(r,nam);
	      printf("Amount at the %d years: %lf\n", nam, tong);
	    }
      }
    }
}

