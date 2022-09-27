#include <stdio.h>       //Viet hoa 10 ky tu nhap tu ban phim
#include <string.h>

int main() 
{
	int i;
    char a[10];
    for (i=1; i<= 10; i++) 
	{
		printf("Ky tu thu %d : ", i);
		fflush(stdin);
	    scanf("%c", &a[i]);
    }
    for (i = 1; i <= 10; i++)                 //Viet hoa ky tu
	{
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= 32;
        }
    }
    printf("Cac ky tu sau khi duoc in hoa: \n");
    for (i=1; i<= 10; i++) printf("%c ", a[i]);
    return 0;
}
