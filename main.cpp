#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "text_data.h"

int main(int argc, const char *argv[]) {
    TEXT_DATA TextData;

    const int lines = 100;
    int file_size = 0;
    char text[lines][line_digits] = {};
    int lines_numbers[lines] = {};

    FILE *fp = NULL;

    if (argc == 2) {
        fp = fopen(argv[1], "rb");
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
    }
    else {
        printf("error\nfile name was not entered\n");
    }

    symbols_in_text(fp, file_size, &TextData);
    print_text(file_size, &TextData);
    free_text_data(&TextData);

    //fill_text(fp, text, lines_numbers, lines);
    ////line_compare(text, lines_numbers, lines);
    //line_ends_compare(text, lines_numbers, lines);
    //print_text(text, lines_numbers, lines);


    return 0;
}
