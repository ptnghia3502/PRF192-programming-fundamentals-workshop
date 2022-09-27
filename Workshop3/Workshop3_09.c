#include <stdio.h>

int UCLN(int x, int y) {
    while (x*y!=0){
    	if(x>y) x=x%y;
    	else y= y%x;
	}
	return x+y;
}

int BCNN(int a, int b, int c) {
	int s;
	s = a*b/c;
	return s;
}

int main() {
	int a, b, c, d;
    printf("Nhap vao 2 so duong: \n");
    scanf("%d%d",&a,&b);
    c = UCLN(a,b);
    d = BCNN(a,b,c);
    if (a>0 && b>0) {
        printf("UCLN cua 2 so la: %d\n", c);
        printf("BCNN cua 2 so la: %d", d);
    }
    else printf("Nhap lai");
    return 0;
}
