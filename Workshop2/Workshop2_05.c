#include <stdio.h>
#include <string.h>

int main() {
	int nVowels, nConsonants, nOthers;
	char ch[100];
	nVowels=0;
	nConsonants=0;
	nOthers=0;
	printf("Nhap vao chuoi: ");
	    gets(ch);
	    strupr(ch);
	  /*printf("Chuoi viet hoa: %s", ch); */
	for (int i=0; i<= strlen(ch); i++) {
       if (ch[i]>='A' && ch[i] <='Z') {
        switch (ch[i]) {
         case 'A' : {nVowels+=1; break;}
         case 'E' : {nVowels+=1; break;}
         case 'I' : {nVowels+=1; break;}
         case 'O' : {nVowels+=1; break;}
         case 'U' : {nVowels+=1; break;}
         default:  {nConsonants+=1;}
        }
       } else nOthers++; 
	}
    printf("So nguyen am: %d\n", nVowels);
    printf("So phu am: %d\n", nConsonants);
    printf("So ky tu khac: %d\n", nOthers-1); 
    return 0;
}
