#include <stdio.h>      //lay cac so thuc tu file, tinh trung binh cong

void processFile(char* fname, int* pCount, double* pSum)
{
	FILE* f= fopen(fname,"r");
	*pCount = 0; //reset count
	*pSum = 0; //reset sum
	double x; //gia tri trong file
	while (fscanf(f,"%lf", &x)==1)
	{
		(*pCount)++;
		(*pSum) += x;
	}
	fclose(f);
}

int main() {
	char infName[] = "demo5.txt";
	int count = 0; //so gia tri trong file
	double sum = 0; //tong cac gia tri trong file
	processFile(infName, &count, &sum);
	printf("Number of values in the file:%d\n", count);
	printf("Average of values in the file:%lf\n", sum/count);
	getchar();
	return 0;
}
