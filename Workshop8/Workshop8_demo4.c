#include <stdio.h>    //lay cac phan tu tu file1, sap xep theo thu tu, luu vao file 2

//Doc du lieu file tu mang
void fileToArray(char* fname, int*a, int *pn)
{
	FILE* f=fopen(fname,"r");
	//Doc so phan tu trong file
	fscanf(f,"%d",pn);
	//Doc cac phan tu
	int i;
	for (i=0; i<*pn;i++) fscanf(f,"%d",&a[i]);
	fclose(f);
}

//Sap xep theo thu tu tang dan
void asc_sort (int *a, int n)
{
	int i, j, t;
	for (i=0; i<n-1; i++)
	   for (j=n-1; j>i; j--)
	     if (a[j]<a[j-1])
	     {
	     	t=a[j];
	     	a[j]=a[j-1];
	     	a[j-1]=t;
		 }
}

//In mang
int print (int *a, int n)
{
	int i;
	for (i=0; i<n; i++) printf("%d ", a[i]);
}

//Viet mang vao file
int printToFile (char* fname, int *a, int n)
{
	FILE* f=fopen(fname,"w");
	fprintf(f,"%d ", n);  //In so phan tu
	int i;
	for (i=0; i<n; i++)      //In cac phan tu
	    fprintf(f,"%d ",a[i]);
	fclose(f);
}

int main()
{
	char infName[] = "demo4_array1.txt";
	char outfName[] = "demo4_array2.txt";
	int a[200];
	int n =0;
	fileToArray(infName, a, &n);
	asc_sort(a,n);
	//in mang
	print(a,n);
	//in vao file
	printToFile(outfName, a, n);
	getchar();
	return 0;
}
