#include <stdio.h>

int checkthapphan(int ps) {
	int result=1;
	if (ps<0) result = 0;
	return result;
}

double sothuc(int nguyen, double thapphan) {
	double s;
	if (checkthapphan(thapphan)==1) {
		while(thapphan>=1) {
			thapphan = thapphan/10;
		} 
		if (nguyen>=0) s= nguyen + thapphan;
		else s= nguyen - thapphan;
		printf("So thuc: %f", s);
	} else {
		printf("Nhap lai");
	}
}

int main() {
	int nguyen, thapphan;
	printf("Nhap vao phan nguyen va phan thap phan: \n");
	scanf("%d%d", &nguyen, &thapphan);
	checkthapphan(thapphan);
	sothuc(nguyen, thapphan);
}
