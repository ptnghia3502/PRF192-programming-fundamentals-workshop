#include <stdio.h>

int main() {
	double a,b,result;
	char c;		
	printf("Nhap vao bieu thuc: \n");
	scanf("%c", &c);
	printf("Nhap vao a va b: \n");
	scanf("%lf%lf", &a, &b);
 	switch(c) {
		case '+': result= a + b;
		          printf("a+b= %lf", result);
		          break;
		case '-': result= a - b;
		          printf("a-b= %lf", result);
		          break;
		case '*': result= a + b;
		          printf("a*b= %lf", result);
		          break;
		case '/': {
		            if (b==0) {
		                printf("No solution\n");
		           } else {
		          result= a / b;
		          printf("a+b= %lf", result);}
		          break; 
				  }
		default: printf("Nhap lai phep toan");         
	} 
	return 0;
} 
