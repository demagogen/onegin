#include <stdio.h>

#include "text_data.h"

int main(int argc, const char *argv[]) {
    const int lines = 20;
    char text[lines][line_digits] = {};
    int lines_numbers[lines] = {};

    FILE *fp = NULL;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
    }
    else {
        printf("error\nfile name was not entered\n");
    }

    fill_text(fp, text, lines_numbers, lines);
    line_compare(text, lines_numbers, lines);
    print_text(text, lines_numbers, lines);


    return 0;
}
