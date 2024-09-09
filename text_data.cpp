#include <stdio.h>

#include "text_data.h"

int fill_text(FILE *fp, char **text, const int lines, const int line_digits) {
    if (!fp) {
        printf("error\nno file pointer in fill_text\n");
    }
    if (!text) {
        printf("error\nno pointer on text in fill_text\n");
    }

    for (size_t line_index = 0; line_index < lines; line_index++) {
        fgets(text[line_index], line_digits, fp);
    }

    return 0;
}
