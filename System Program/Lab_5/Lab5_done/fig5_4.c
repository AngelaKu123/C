#include "apue.h"

int main(void)
{

	int c;
	long long int counter = 0;
	
	while( (c = getc(stdin)) != EOF ) {
		if(putc(c,stdout) == EOF)
			err_sys("output error");

		counter++;
	}
		
	if(ferror(stdin))
		err_sys("input error");

	printf("Loop Iterations: %lld\n", counter);

	exit(0);
}