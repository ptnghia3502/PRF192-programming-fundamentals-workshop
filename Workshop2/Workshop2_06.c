#include <stdio.h>

int main() {
	char c;
	for (int i=0; i<256; i++) {
		printf("%c", c);
		c = c+1;
		if (c!=0 && c%20==0) getchar(); 
	}
	return 0;
}
