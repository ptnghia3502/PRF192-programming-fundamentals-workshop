#include <stdio.h>              //Tao menu giai quyet cac yeu cau ve mang
#include <stdlib.h>
#define MAXN 100

int menu() 
{
	printf("\nOne-Deimensional Array of Integers:");
	printf("\n1- Add a value");
	printf("\n2- Search a value");
	printf("\n3- Remove the first existence of a value");
	printf("\n4- Remove all existence of a value");
	printf("\n5- Print out the array");
	printf("\n6- Print out the array in ascending order");
	printf("\n7- Print out the array in descending order");
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

int removeOne (int pos, int*a, int*pn) {        //Remove the first existence of a value
	if (pos<0 || pos >=*pn) return 0;
	for (int i=pos; i<*pn-1; i++) a[i]=a[i+1];
	(*pn)--;
	return 1;
}

int removeAll (int x, int*a, int *pn) {       //Remove all existence of a value
	int result =0;
	int i,j;
	for(i=(*pn)-1; i>=0; i--)
	  if (a[i]==x) {
	  	result =1;
	  	for(j=i; j<(*pn)-1; j++) a[j]=a[j+1];
	  	(*pn)--;
	  }
	return result;
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

void printDesc(int*a, int n) {        //Print out the array in descending order
	int** adds=(int**)calloc(n, sizeof(int*));
	int i,j;
	for(i=0; i<n; i++) adds[i]=&a[i];
	int*t;
	for (i=0; i<n-1;i++)
	  for (j=n-1; j>i; j--)
	    if (*adds[j]> *adds[j-1])
	    {
	    	t= adds[j];
	    	adds[j]= adds[j-1];
	    	adds[j-1]= t;
		}
	for (i=0; i<n; i++) printf("%d ", *adds[i]);
	free(adds);
}

void print (int*a, int n) {     //Print out the array
	int i;
	for  (i=0; i<n; i++) printf("%d ", a[i]);
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
				   if (isEmpty(a,n)) printf("\nSorry! The array is empty.\n");
			       else
			       {
			       	printf ("Input the removed value:");
			       	scanf("%d", &value);
			       	int pos = search(value, a, n);
			       	if (pos<0) printf("Not found\n");
			       	else {
			       		removeOne (pos, a, &n);
			       		printf("Removed\n");
					   }
				   }
				   break;
			case 4:
				   if (isEmpty(a,n)) printf("\nSorry! The array is empty.\n");
			       else
			       {
			       	printf ("Input a value that will be remove all:");
			       	scanf("%d", &value);
			        if (removeAll(value, a, &n)==0) printf("Not found\n");
			        else printf("Removed\n");
				   }
				   break;
			case 5: 
			       print(a, n);
			       break;
			case 6: 
			       printAsc(a, n);
			       break;
			case 7: 
			       printDesc(a, n);
			       break;
			default: printf("\nGoodbye\n");
		}
	}
	while (userChoice >0 && userChoice<8);
	getchar();
	return 0;
}
