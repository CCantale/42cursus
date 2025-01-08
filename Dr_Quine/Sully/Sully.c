#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i = 5;
	char	file_name[10];
	char	compilation_command[50];
	char	execution_command[20];
	FILE	*dest_file;
	char	code[] = "#include <stdio.h>%c#include <stdlib.h>%c%cint	main(void)%c{%c	int	i = %d;%c	char	file_name[10];%c	char	compilation_command[50];%c	char	execution_command[20];%c	FILE	*dest_file;%c	char	code[] = %c%s%c;%c%c	sprintf(file_name, %cSully_%%d.c%c, i - 1);%c	dest_file = fopen(file_name, %cw%c);%c	fprintf(dest_file, code, 10, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 34, code, 34, 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10);%c	fclose(dest_file);%c	sprintf(compilation_command, %cgcc -Wall -Wextra -Werror %%s -o Sully_%%d%c, file_name, i - 1);%c	sprintf(execution_command, %c./Sully_%%d%c, i - 1); %c	system(compilation_command);%c	if (i - 1 >= 0)%c		system(execution_command);%c	return(0);%c}%c";

	sprintf(file_name, "Sully_%d.c", i - 1);
	dest_file = fopen(file_name, "w");
	fprintf(dest_file, code, 10, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 34, code, 34, 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10);
	fclose(dest_file);
	sprintf(compilation_command, "gcc -Wall -Wextra -Werror %s -o Sully_%d", file_name, i - 1);
	sprintf(execution_command, "./Sully_%d", i - 1); 
	system(compilation_command);
	if (i - 1 >= 0)
		system(execution_command);
	return(0);
}
