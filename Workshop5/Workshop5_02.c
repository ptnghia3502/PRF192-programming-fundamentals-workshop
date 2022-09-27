#include <stdio.h>     //Tong 2 qua bong
#include <stdlib.h>
#include <time.h>
 
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
 
int main(){
	srand((int)time(0));
    int x, y;
    int total, count1, count2;
	printf("Nhap vao tong: ");
	scanf("%d", &total);
    if (total<2 || total>20) printf("Nhap lai");
    else
    {	
    count1 =1;
    count2 =2;
    do
    {	
    x = random(1,10);
    y = random(1,10);
    printf("Result of picks: %d and %d, %d+%d\n", count1, count2, x, y);
    count1 +=2;
    count2 +=2;
    }
    while (x+y!=total);
    printf("You got your total in %d picks!", count2-2);
    }
}
