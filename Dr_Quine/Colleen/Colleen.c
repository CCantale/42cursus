#include <stdio.h>

/*
	This is a comment outside the main function
*/
void print_source(char *source) {
    printf(source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10);
    fflush(stdout);
}

int main() {
/*
	This is a comment inside the main function
*/
    char *source = "#include <stdio.h>%c%c/*%c	This is a comment outside the main function%c*/%cvoid print_source(char *source) {%c    printf(source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10);%c    fflush(stdout);%c}%c%cint main() {%c/*%c	This is a comment inside the main function%c*/%c    char *source = %c%s%c;%c    print_source(source);%c    return 0;%c}%c";
    print_source(source);
    return 0;
}
