#include <stdio.h>          //Quan ly danh sach nhan vien
#include <stdlib.h>
#include <string.h>
#define MAXN 100

int menu()            //Tao menu
{
    int choice;
    printf("Quan ly danh sach nhan vien!\n");
    printf("1-Them mot nhan vien\n");
    printf("2-Tim thong tin cua nhan vien\n");
    printf("3-Xoa nhan vien khoi danh sach\n");
    printf("4-In danh sach theo thu tu giam dan theo muc luong va phu cap\n");
    printf("5-Quit\n");
    printf("Select = ");
    fflush(stdin);
    scanf("%d", &choice);
    return choice;
}

void add (char code[][9], char ten[][20], double luong[],double phucap[], int *pn)
{  
	char nhanvien[21], maso[9];
	double a, b;
	int i;
	int tontai = 1;
	do 
	{ 
	printf("Nhap ma so nhan vien (8 ky tu) : ");            //Nhap ma so nhan vien
	fflush(stdin);
	scanf("%8[^\n]", maso);	
	for ( i = 0; i < *pn; i++) 
		if (strcmp(maso,code[i]) == 0)                 //Check ma so co ton tai hay ko
			{
				printf("Ma so da ton tai! Vui long nhap lai!\n");
				tontai = 0;
				i = *pn - 1;
			}
	} while (tontai != 1); 
	strcpy(code[*pn], maso);
	
	printf("Nhap ten nhan vien (20 ky tu) : ");             //Nhap ten nhan vien
	fflush(stdin);
	scanf("%20[^\n]", nhanvien);
	strcpy(ten[*pn], nhanvien);
	
	printf("Luong : ");  fflush(stdin);               //Nhap luong
	scanf("%lf", &a);    
	luong[*pn] = a;
	
	printf("Phu cap : ");    fflush(stdin);        //Nhap phu cap
	scanf("%lf", &b);    
	phucap[*pn] = b;
	(*pn)++;
	printf("Da them vao danh sach!\n");
}

void search(char code[][9], char ten[][20], double luong[],double phucap[], int *pn)       //Tim kiem nhan vien bang ten
{
	char nhanvien[21];
	int i;
	int s=0;
	printf("Nhap ten nhan vien can tim kiem : ");
	fflush(stdin);
    scanf("%20[^\n]", &nhanvien);
	for (i = 0; i < *pn; i++)
		{
			if (strcmp(ten[i],nhanvien) == 0) {
				printf("KET QUA TIM KIEM: Code: %8s, Ten: %20s, Luong: %3.3lf, Phu cap: %3.3lf \n", code[i], ten[i], luong[i], phucap[i]);
				s++;
				break;
		    }
		}
	if (s == 0) printf("Khong tim thay ten nhan vien!\n");
}

void removed(char code[][9], char ten[][20], double luong[], double phucap[], int *pn)         //Xoa nhan vien bang ma so
{
	char xoa[9];
	fflush(stdin);
	printf("Nhap ma so nhan vien de xoa : ");
	scanf("%9[^\n]", &xoa);
	int i, j;
	int s=0;
	for (i = 0; i < *pn; i++)
		if (strcmp(code[i], xoa) == 0)
		{ 
			for (j = i; j < *pn; j++)
				{ 
		            strcpy(ten[j], ten[j+1]);
		            strcpy(code[j], code[j+1]);
		            luong[j] = luong[j+1];
		            phucap[j] = phucap[j+1];
		        }
		    (*pn)--;
		    printf("Da xoa nhan vien ra khoi danh sach!\n");
		    s++;
		    break;
		}
	if (s ==0 ) printf("Ma so nhan vien khong ton tai! Xoa that bai!\n");
}

void print(char code[][9], char ten[][20], double luong[],double phucap[], int *pn)       //In danh sach 
{	
	int i, j;
	for (i = 0; i < *pn-1; i++)
		for (j = *pn-1; j > i; j--)
			if ( (luong[j] + phucap[j]) > (luong[j-1] + phucap[j-1]) )
			{
				char t1[8];
	            strcpy(t1, code[j]);
	            strcpy(code[j], code[j-1]);
	            strcpy(code[j-1], t1);
				
				char t2[21];
	            strcpy(t2, ten[j]);
	            strcpy(ten[j], ten[j-1]);
	            strcpy(ten[j-1], t2);
	            
	            double t3 = luong[j];
	            luong[j]=luong[j-1];
	            luong[j-1]=t3;
	            
	            double t4 = phucap[j];
	            phucap[j]=phucap[j-1];
	            phucap[j-1]=t4;
			}
	for (i = 0; i < (*pn); i++)
    	printf("Code: %8s, Ten: %20s, Luong: %3.3lf, Phu cap: %3.3lf \n", code[i], ten[i], luong[i], phucap[i]);
}

int main()
{
    int userChoice;
    char code[MAXN][9], ten[MAXN][20];
	double luong[MAXN], phucap[MAXN];
    int n = 0;
    do
    {
        userChoice = menu();
        switch(userChoice)
        {
            case 1:
				if (n == MAXN) printf("Danh sach da day, khong the them!\n");
				else add(code, ten, luong, phucap, &n);
				break;
            case 2:
				if (n == 0) printf ("Danh sach trong, khong the tim kiem!\n");
				else search(code, ten, luong, phucap, &n);
				break;
            case 3:
				if (n == 0) printf ("Danh sach trong, khong the xoa!\n");
				else removed(code, ten, luong, phucap, &n);
				break;
            case 4:
				if (n == 0) printf ("Danh sach trong, khong the in!\n");
				else print(code, ten, luong, phucap, &n);
				break;
            default: printf("\nGoodbye\n");
        }
        system("pause");
        system("cls");
    } while (userChoice >0 && userChoice<5);
    return 0;
}
