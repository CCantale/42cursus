#include <stdio.h>
#include <stdlib.h>

#define TYPE	int
#define CODE	main(){grace();return(0);}
#define QUINE	imlovinthisproject

void	grace(void)
{
	FILE	*dest_file = fopen("Grace_kid.c", "w");
	char	code[] = "#include <stdio.h>%c#include <stdlib.h>%c%c#define TYPE	int%c#define CODE	main(){grace();return(0);}%c#define QUINE	imlovinthisproject%c%cvoid	grace(void)%c{%c	FILE	*dest_file = fopen(%cGrace_kid.c%c, %cw%c);%c	char	code[] = %c%s%c;%c%c	if (dest_file == NULL)%c		return ;%c	fprintf(dest_file, code, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 10, 34, code, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c	fclose(dest_file);%c}%c%cTYPE CODE%c";

	if (dest_file == NULL)
		return ;
	fprintf(dest_file, code, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 10, 34, code, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10);
	fclose(dest_file);
}

TYPE CODE
