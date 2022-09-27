#include <stdio.h>           //Quan ly cac phan tu trong mang
#include <stdlib.h>
#define MAXN 100

int menu() 
{
	printf("\nOne-Deimensional Array of Integers:");
	printf("\n1- Add a value");
	printf("\n2- Search a value");
	printf("\n3- Print out the array");
	printf("\n4- Print out values in a range");
	printf("\n5- Print out the array in ascending order");
	printf("\nOthers- Quit");
	printf("\nSelect: ");
	int choice;
	scanf("%d", &choice);
	return choice;
}

int isFull (int*a, int n) {
	return n==MAXN;
}

int isEmpty (int*a, int n) {
	return n==0;
}

void add(int value, int *a, int *pn) {      //Add a value
	a[*pn] = value;
	(*pn)++;
}

int search (int x, int *a, int n) {         //Search a value
	int i;
	for (i=0; i<n; i++) if (a[i]==x) return i;
	return -1;
}

void print (int*a, int n) {     //Print out the array
	int i;
	for  (i=0; i<n; i++) printf("%d ", a[i]);
}

void range (int*a, int n, int x, int y) {     //Print out the array in range
	int i;
	for  (i=0; i<n; i++) 
	{  if (x<=a[i] && a[i]<=y)
	   printf("%d ", a[i]);
	}
}

void printAsc(int*a, int n) {        //Print out the array in ascending order
	int** adds=(int**)calloc(n, sizeof(int*));
	int i,j;
	for(i=0; i<n; i++) adds[i]=&a[i];
	int*t;
	for (i=0; i<n-1;i++)
	  for (j=n-1; j>i; j--)
	    if (*adds[j]< *adds[j-1])
	    {
	    	t= adds[j];
	    	adds[j]= adds[j-1];
	    	adds[j-1]= t;
		}
	for (i=0; i<n; i++) printf("%d ", *adds[i]);
	free(adds);
}

int main() 
{
	int a[MAXN];
	int n=0;
	int value;
	int userChoice;
	do
	{
		userChoice= menu();
		switch (userChoice)
		{
			case 1: 
			       if (isFull(a,n)) printf("\nSorry! The array is full.\n");
			       else
			       {
			       	printf ("Input an added value:");
			       	scanf("%d", &value);
			       	add(value, a, &n);
			       	printf("Added\n");
				   }
				   break;
			case 2:
				   if (isEmpty(a,n)) printf("\nSorry! The array is empty.\n");
			       else
			       {
			       	printf ("Input the searched value:");
			       	scanf("%d", &value);
			       	int pos = search(value, a, n);
			       	if (pos<0) printf("Not found\n");
			       	else printf("Position is found: %d\n", pos);
				   }
				   break;			
			case 3: 
			       print(a, n);
			       break;
			case 4:
				   int x, y;
			       printf("Input a range: \n");
			       printf("From: \n"); scanf("%d", &x);
			       printf("To: \n"); scanf("%d", &y);
			       range(a, n, x, y);
				   break;    
			case 5: 
			       printAsc(a, n);
			       break;
			default: printf("\nGoodbye\n");
		}
	}
	while (userChoice >0 && userChoice<6);
	getchar();
	return 0;
}
