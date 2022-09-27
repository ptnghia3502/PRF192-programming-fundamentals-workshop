#include <stdio.h>          //Quan ly cac loai nuoc uong
#include <stdlib.h>
#include <string.h>
#define MAXN 100

int menu()            //Tao menu
{
    int choice;
    printf("Quan ly danh sach cac loai nuoc uong!\n");
    printf("1-Them nuoc uong\n");
    printf("2-In ra cac loai nuoc uong tu nha san xuat\n");
    printf("3-In ra cac loai nuoc uong co the tich trong khoang tu V1 den V2\n");
    printf("4-In danh sach nuoc uong giam dan theo the tich\n");
    printf("5-Quit\n");
    printf("Select = ");
    fflush(stdin);
    scanf("%d", &choice);
    return choice;
}

void add (char ten[][20], char nsx[][20], int thetich[], int gia[], int hsd[], int *pn)  //Nhap nuoc uong
{  
	char name[21], make[21];
	int volume, price, duration;
	
	printf("Nhap ten loai nuoc uong (20 ky tu) : ");            //Nhap ten loai nuoc uong
	fflush(stdin);
	scanf("%21[^\n]", name);	
	strcpy(ten[*pn], name);
	
	printf("Nhap ten nha san xuat (20 ky tu) : ");             //Nhap ten nha san xuat
	fflush(stdin);
	scanf("%21[^\n]", make);
	strcpy(nsx[*pn], make);
	
	printf("The tich : ");  fflush(stdin);               //Nhap the tich
	scanf("%d", &volume);    
	thetich[*pn] = volume;
	
	printf("Gia : ");    fflush(stdin);        //Nhap gia
	scanf("%d", &price);    
	gia[*pn] = price;
	
	printf("HSD : ");    fflush(stdin);        //Nhap han su dung
	scanf("%d", &duration);    
	hsd[*pn] = duration;
	
	(*pn)++;
	printf("Da them vao danh sach!\n");
}

void printNSX (char ten[][20], char nsx[][20], int thetich[], int gia[], int hsd[], int *pn)      //In ra cac loai nuoc uong tu nha san xuat
{
	char make[20];
	int i;
	int s=0;
	printf("Nhap ten nha san xuat : ");
	fflush(stdin);
    scanf("%20[^\n]", &make);
    printf("KET QUA TIM KIEM: \n");
	for (i = 0; i < *pn; i++)
		{
			if (strcmp(nsx[i],make) == 0) {
				printf("Ten: %20s, NSX: %20s, The tich: %d ml, Gia: %d VND, HSD: %d ngay\n", ten[i], nsx[i], thetich[i], gia[i], hsd[i]);
				s++;
		    }
		}
	if (s == 0) printf("Khong tim thay ten nha san xuat!\n");
}

void printVOL (char ten[][20], char nsx[][20], int thetich[], int gia[], int hsd[], int *pn)        //In ra cac loai nuoc uong co the tich trong khoang tu V1 den V2
{
	int i;
	int v1, v2;
	fflush(stdin);
	printf("From: "); scanf("%d", &v1); fflush(stdin);
	printf("\nTo: "); scanf("%d", &v2); fflush(stdin);
	for (i = 0; i<*pn; i++)
	{
		if (v1 <= thetich[i] && thetich[i] <= v2)
		{
			printf("\nTen: %20s, NSX: %20s, The tich: %d ml, Gia: %d VND, HSD: %d ngay\n", ten[i], nsx[i], thetich[i], gia[i], hsd[i]);
		}
	}
}

void print (char ten[][20], char nsx[][20], int thetich[], int gia[], int hsd[], int *pn)       //In danh sach nuoc uong giam dan theo the tich 
{	
	int i, j;
	for (i = 0; i < *pn-1; i++)
		for (j = *pn-1; j > i; j--)
			if ( thetich[j] > thetich[j-1] )
			{
				char t1[21];
	            strcpy(t1, ten[j]);
	            strcpy(ten[j], ten[j-1]);
	            strcpy(ten[j-1], t1);
				
				char t2[21];
	            strcpy(t2, nsx[j]);
	            strcpy(nsx[j], nsx[j-1]);
	            strcpy(nsx[j-1], t2);
	            
	            int t3 = thetich[j];
	            thetich[j]=thetich[j-1];
	            thetich[j-1]=t3;
	            
	            int t4 = gia[j];
	            gia[j]=gia[j-1];
	            gia[j-1]=t4;
	            
	            int t5 = hsd[j];
	            hsd[j]=hsd[j-1];
	            hsd[j-1]=t5;
			}
	for (i = 0; i < (*pn); i++)
    	printf("Ten: %20s, NSX: %20s, The tich: %d ml, Gia: %d VND, HSD: %d ngay\n", ten[i], nsx[i], thetich[i], gia[i], hsd[i]);
}

int main()
{
    int userChoice;
    char ten[MAXN][20], nsx[MAXN][20];
	int thetich[MAXN], gia[MAXN], hsd[MAXN];
    int n = 0;
    do
    {
        userChoice = menu();
        switch(userChoice)
        {
            case 1:
				if (n == MAXN) printf("Danh sach da day, khong the them!\n");
				else add(ten, nsx, thetich, gia, hsd, &n);
				break;
            case 2:
				if (n == 0) printf ("Danh sach trong, khong the in!\n");
				else printNSX(ten, nsx, thetich, gia, hsd, &n);
				break;
            case 3:
				if (n == 0) printf ("Danh sach trong, khong the in!\n");
				else printVOL(ten, nsx, thetich, gia, hsd, &n);
				break;
            case 4:
				if (n == 0) printf ("Danh sach trong, khong the in!\n");
				else print(ten, nsx, thetich, gia, hsd, &n);
				break;
            default: printf("\nGoodbye\n");
        }
        system("pause");
        system("cls");
    } while (userChoice >0 && userChoice<5);
    return 0;
}
