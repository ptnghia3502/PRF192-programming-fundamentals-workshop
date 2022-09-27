#include <stdio.h>        //Quan ly danh sach 100 hoc sinh
#include <stdlib.h>
#include <string.h>
#define MAXN 100

int menu()      //Tao menu
{
    int choice;
    printf("Quan ly danh sach 100 hoc sinh!\n");
    printf("1-Them mot hoc sinh\n");
    printf("2-Xoa mot hoc sinh\n");
    printf("3-Tim kiem hoc sinh\n");
    printf("4-Sap xep danh sach theo thu tu tang dan\n");
    printf("5-Quit\n");
    printf("Select: ");
    fflush(stdin);
    scanf("%d", &choice);
    return choice;
}

void check(char s[100])             //Xoa khoang trang va viet hoa ten
{
    int n=strlen(s); 
    for(int i=0;i<n;i++)
    if(s[i]==32)
    {
        for(int j=i;j<n;j++)
        {
            s[j]=s[j+1];
            i--;
        }
    }
    for(int i=0;i<strlen(s);i++)
    {
        strupr(s);
	    break;
    }
}

int isFull(char list[MAXN][30], int *pn) {        //Dung luong day
	return ((*pn) == MAXN);
}

int isEmpty(char list[MAXN][30], int *pn) {       //Dung luong trong
	return ((*pn) == 0);
}

void add(char list[MAXN][30], int *pn) {         //Them hoc sinh
	char hocsinh[30];
	int i;
	printf("Nhap ten hoc sinh : ");
	fflush(stdin);
	scanf("%20[^\n]", hocsinh);	
    strcpy(list[*pn], hocsinh);
    (*pn)++;
    printf("Da them vao danh sach!\n");
}

void removed(char list[MAXN][30], int *pn)       //Xoa hoc sinh (theo so thu tu)
{
	printf("Nhap STT de xoa ten hoc sinh khoi danh sach : ");
	int xoa, i;
	scanf("%d", &xoa);
	if (xoa >= 0 && xoa < *pn) 
	{
	for (i = xoa + 1; i < *pn; i++)
		strcpy(list[i-1], list[i]);
	printf("Da xoa ten hoc sinh ra khoi danh sach!\n");
	(*pn)--;
	}
	else printf("Khong tim thay ten hoc sinh, xoa that bai!\n");
}

void search(char list[MAXN][30], int *pn)           //Tim kiem hoc sinh
{
	int i;
	int s=0;
	printf("Nhap ten hoc sinh can tim kiem : ");
	char hocsinh[30];
	fflush(stdin);
    scanf("%20[^\n]", hocsinh); check(hocsinh);
	for (i = 0; i < *pn; i++)
		{	
			if(strcmp(list[i],hocsinh) == 0)  {
			printf("KET QUA TIM KIEM: STT[%d] : %s\n", i, list[i]);
			s++; 
			break;
			} 			
		}
	if (s == 0) printf("Khong tim thay ten hoc sinh!\n");
}

void print(char list[MAXN][30], int *pn)           //In danh sach ten hoc sinh theo thu tu tang dan
{
	int i, j;
   	for (i = 0 ; i < *pn-1; i++)
     	for (j = *pn-1; j > i; j--)
     		if (strcmp(list[j] , list[j-1]) < 0)
     			{
     				char t[30];
		            strcpy(t, list[j]);
		            strcpy(list[j], list[j-1]);
		            strcpy(list[j-1], t);
				}
	for (i = 0; i < (*pn); i++)
		{
		    check(list[i]);
			printf("STT[%d] : %s \n", i, list[i]);
		}
}

int main()
{
    int userChoice;
    char list[MAXN][30];
    int n = 0;
    do
    {
        userChoice = menu();
        switch(userChoice)
        {
            case 1:
				if (isFull(list, &n)) printf("Danh sach da day, khong the them!\n");
				else add(list, &n);
				break;
            case 2:
				if (isEmpty(list, &n)) printf("Danh sach trong, khong the xoa!\n");
				else removed(list, &n);
				break;
            case 3:
				if (isEmpty(list, &n)) printf("Danh sach trong, khong the tim kiem!\n");
				else search(list, &n);
				break;
            case 4:
				if (isEmpty(list, &n)) printf("Danh sach trong, khong the in!\n");
				else print(list, &n);
				break;
            default: printf("\nGoodbye\n");
        }
        system("pause");
        system("cls");
    } while (userChoice >0 && userChoice<5);
    return 0;
}
