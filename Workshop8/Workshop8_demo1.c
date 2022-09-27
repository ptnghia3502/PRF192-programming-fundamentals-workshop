#include <stdio.h>       //Viet chuoi vao file khi nhap Ctrl+Z va nhan Enter thi ngung
#include <ctype.h>
#define TRUE 1
#define FALSE 0

int exist (char* filename)   //kiem tra file co ton tai hay ko
{
	int existed = FALSE;
	//Mo file
	FILE* f = fopen(filename,"r");
	if (f!=NULL)
	{
		existed = TRUE;
		fclose(f);
	}
	return existed;
}

//viet file bang cac ky tu nhap vao cho toi khi ctrl+Z duoc nhap
int writeFile(char* filename)
{
	char c; //nhap ky tu
	int CTRL_Z = -1;
	if (exist (filename) == TRUE)
	{
		printf("The file %s existed. Override it Y/N? :", filename);
		if (toupper(getchar())=='N') return FALSE;
	}
	// Mo file de viet file
	FILE* f=fopen(filename, "w");
	fflush(stdin); //xoa bo dem
	do
	{
		c = getchar();
		if (c!=CTRL_Z) fputc(c,f);
	}
	while (c!=CTRL_Z);
	fclose(f);
	return TRUE;
}

int printFile(char* filename)
{
	char c;
	if (exist (filename) == FALSE)
	{
		printf("The file %s dose not exist.\n", filename);
		return FALSE;
	}
	//Mo file
	FILE* f= fopen(filename,"r");
	while ((c=fgetc(f)) != EOF) putchar(c);
	fclose(f);
	return TRUE;
}

int main(int argCount, char* args[])
{
/*	if (argCount!=2) printf("Syntax: copy_con filename\n");
    else if (writeFile(args[1])==TRUE)
	        printf("Writing the file %s: done\n", args[1]);
	     else printf ("Can not write the file %s\n", args[1]); 
	return 0; */
	char filename[81];
	printf("Syntax: copy_con filename\n");
	printf("Program for writing then reading a file\n");
	printf("Enter a filename:");
	gets(filename);
	printf("Write file: \n");
	if (writeFile(filename) == 1)
	{
		printf("\nWriting the file %s: done\n", filename);
		printf("\nData in file: \n");
		if (printFile(filename) == 0) printf("File error!\n");
	}
	else printf("Can not write the file %s\n", filename);
	getchar();
	return 0;
}
