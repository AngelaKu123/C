#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	long long int counter = 0;

	setvbuf(stdin, NULL, _IONBF, BUFSIZ);
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	
	while( (fgets(buf,MAXLINE,stdin)) != NULL ) {
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");

		counter++;
	}
		
	if(ferror(stdin))
		err_sys("input error");

	printf("Loop Iterations: %lld\n", counter);

	exit(0);
}