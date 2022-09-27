#include <stdio.h>    //Nhap cac chuoi vao file khi nhap chuoi NULL thi ngung
#include <string.h>
#include <ctype.h>

int exist (char* filename)
{
	int existed = 0;
	//mo file
	FILE* f= fopen (filename, "r");
	if (f!=NULL)
	{
		existed =1;
		fclose(f);
	}
	return existed;
} 

// viet vao file tu nhung dong nhap vao cho toi khi 0 dong duoc nhap
int writeFile(char* filename)
{
	if (exist (filename) == 1)
	{
		printf("The file %s existed. Override it Y/N? :", filename);
		if (toupper(getchar()) == 'N') return 0;
	}
	char line [201]; //nhap chuoi
	int length = 0; //chieu dai chuoi
	//mo file de viet
	FILE* f= fopen(filename,"w");
	fflush(stdin);
	do
	{
		gets(line);    //Nhap chuoi, neu ng dung chi nhap ENTER -> length =0
	    length = strlen(line);
	    if (length>0)
	    {
	    	fputs(line,f); //viet dong vao file
	    	fputs("\n", f);
		}
	}
	while (length>0);
	fclose(f);
	return 1;
}

int printFile(char* filename)
{
	char c;
	if (exist (filename) == 0)
	{
		printf("The file %s does not exist.\n", filename);
		return 0;
	}
	//mo file de doc
	FILE* f= fopen(filename,"r");
	while ((c=fgetc(f)) != EOF) putchar(c);
	fclose(f);
	return 1;
} 

int main (int argCount, char* arg[1])
{
	char filename[81];
	printf("Program for writing then reading a file\n");
	printf("Enter a filename:");
	gets(filename);
	printf("Write file: \n");
	if (writeFile(filename) == 1)
	{
		printf("Data in the file %s:\n", filename);
		if (printFile(filename) == 0) printf("File error!\n");
	}
	else printf("Writing file fail!\n", filename);
	getchar();
	return 0;
}
