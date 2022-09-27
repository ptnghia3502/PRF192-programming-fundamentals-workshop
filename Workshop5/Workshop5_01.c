#include <stdio.h>     //tong 2 xuc xac 
#include <stdlib.h>
#include <time.h>
 
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);  //Tao ham random
}
 
int main(){
	srand((int)time(0));  //ham random theo thoi gian
    int x, y;
    int total, count;
	printf("Nhap vao tong: ");
	scanf("%d", &total);
    if (total<2 || total>12) printf("Nhap lai");
    else
    {	
    count =1;
    do
    {	
    x = random(1,6);
    y = random(1,6);
    printf("Result of throw: %d, %d+%d\n", count, x, y);
    count++;
    }
    while (x+y!=total);
    printf("You got your total in %d throws!", count-1);
    }
}
