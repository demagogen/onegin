#include <stdio.h>

#include "text_data.h"

int main(int argc, const char *argv[]) {
    const int lines = 20;
    const int line_digits = 40;
    char *text[lines] = {};

    FILE *fp = NULL;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
    }
    else {
        printf("error\nfile name was not entered\n");
    }

    fill_text(fp, text, lines, line_digits);

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            printf("%c", text[i][j]);
        }
    }

    for (size_t line_index = 0; line_index < lines; line_index++) {
        printf("%s", text[line_index]);
    }

    return 0;
}
