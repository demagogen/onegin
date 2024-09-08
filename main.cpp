#include <stdio.h>

int main(int argc, const char *argv[]) {
    const int lines = 20;
    const int line_digits = 30;
    char text[lines][line_digits] = {};

    FILE *fp = NULL;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
    }
    else {
        printf("error\nfile name was not entered\n");
    }

    for (size_t line_index = 0; line_index < lines; line_index++) {
        scanf("%s[^\n]", text[line_index]);
        printf("yes\n");
    }

    return 0;
}
