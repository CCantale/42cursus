#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i = 5;
	char	file_name[10];
	char	compilation_command[50];
	char	execution_command[20];
	FILE	*dest_file;
	//char	code[] = "#include <stdio.h>%c#include <string.h>%c#include <stdlib.h>%c%cint	main(void)%c{%c	int	i = 5;%cFILE	*dest_file = fopen(%cGrace_%d.c%c, %cw%c);char code[] = %c%s%c;if(dest_file == NULL){return(1);}fprintf(dest_file, code, 10, 10, 34, 34, 34, 34, 34, code, 34, 10, 10, 10, 10, 47, 47, 10);fclose(dest_file);return(0);}";

	sprintf(file_name, "Sully_%d.c", i);
	dest_file = fopen(file_name, "w");
	fprintf(dest_file, "#include<stdio.h>\nint main(){printf(\"Hello %d!\"); return(0);}", i);
	fclose(dest_file);
	sprintf(compilation_command, "gcc -Wall -Wextra -Werror %s -o Sully_%d", file_name, i); 
	sprintf(execution_command, "./Sully_%d", i); 
	system(compilation_command);
	if (i >= 0)
		system(execution_command);
	return(0);
}
