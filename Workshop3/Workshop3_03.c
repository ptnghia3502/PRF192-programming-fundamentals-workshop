#include <stdio.h>

int x,y,r;

void getRelPos(int x,int y)
{
    double d, R;
    d = x*x+y*y;
    R = r*r;
    if (d > R) printf("Diem x,y nam ngoai duong tron");
    if (d == R) printf("Diem x,y nam tren duong tron");
    if (d < R) printf("Diem x,y nam trong duong tron");
}

int main()
{
    printf("Nhap toa do: \n");
    scanf("%d%d",&x,&y); 
    printf("Nhap ban kinh duong tron: ");
    scanf("%d",&r);
    if (r>0) getRelPos(x,y);
    else printf("Nhap lai");
    return 0;
}
