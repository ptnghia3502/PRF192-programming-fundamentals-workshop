#include <stdio.h>
#include <string.h>

const int MAXN = 100;
// In danh sach
void print(char names[][20], char adds[][40], int * marks, int n)
{
	int i;
	for ( i = 0; i < n; i++)
		printf ("%-20s%-40s%4d\n", names[i], adds[i], marks[i]);
}

//Doc file
void printFile(char * filename, char names[][20], char adds[][40], int * marks, int *pn)
{
	*pn = 0;
	FILE * f = fopen(filename, "r");
	if (f != '\0')
	{
		while ( fscanf(f, "%20[^;];%40[^;];%d%*c", names[*pn], adds[*pn], &marks[*pn]) == 3 )
			(*pn)++;
		fclose(f);
	}
}

//Viet vao file
void writeFile(char * filename, char names[][20], char adds[][40], int * marks, int n)
{
	FILE * f = fopen(filename, "w");
	int i;
	for ( i = 0; i < n; i++)
		fprintf(f, "%s;%s;%d\n", names[i], adds[i], marks[i]);
	fclose(f);
}

//sap xep danh sach theo diem tang dan
void sortAsc (char names[][20], char adds[][40], int * marks, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for ( j = n - 1; j > i; j--)
			if (marks[j] > marks[j - 1])     //check diem lon nhat
				{
					char tName[41];
					strcpy(tName, names[j]);
					strcpy(names[j], names[j - 1]);
					strcpy(names[j - 1], tName);
					
					char tAdd[41];
					strcpy(tAdd, adds[j]);
					strcpy(adds[j], adds[j - 1]);
					strcpy(adds[j - 1], tAdd);
					
					int tMark = marks[j];
					marks[j] = marks[j - 1];
					marks[j - 1] = tMark;
				}
}

int main()
{
	char fileIn[] = "demo6_students1.txt";
	char fileOut[] = "demo6_students2.txt";
	char names[MAXN][20];
	char adds[MAXN][40];
	int marks[MAXN];
	int n = 0;
	printFile(fileIn, names, adds, marks ,&n);
	sortAsc(names,adds,marks,n);
	printf("Danh sach da sap xep : \n");
	print(names, adds, marks, n);
	writeFile(fileOut, names, adds, marks, n);
	getchar();
}
