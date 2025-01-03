#include <stdio.h>

#define MAIN() int main(void){FILE *dest_file=fopen("Grace_kid.c", "w");char code[] = "#include <stdio.h>%c%c#define MAIN() int main(void){FILE *dest_file=fopen(%cGrace_kid.c%c, %cw%c);char code[] = %c%s%c;if(dest_file == NULL){return(1);}fprintf(dest_file, code, 10, 10, 34, 34, 34, 34, 34, code, 34, 10, 10, 10, 10, 47, 47, 10);fclose(dest_file);return(0);}%c%cMAIN()%c%c%c%c This is a comment%c";if(dest_file == NULL){return(1);}fprintf(dest_file, code, 10, 10, 34, 34, 34, 34, 34, code, 34, 10, 10, 10, 10, 47, 47, 10);fclose(dest_file);return(0);}

MAIN()

// This is a comment
