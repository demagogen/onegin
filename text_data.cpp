#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "text_data.h"

int fill_text(FILE *fp, char text[][line_digits], int lines_numbers[], const int lines) {
    assert(fp);
    assert(text);

    if (!fp) {
        printf("error\nno file pointer in fill_text\n");
        return -1;
    }
    if (!text) {
        printf("error\nno pointer on text in fill_text\n");
        return -1;
    }

    for (size_t line_index = 0; line_index < lines; line_index++) {
        fgets(text[line_index], line_digits, fp);
        lines_numbers[line_index] = line_index;
    }

    return 0;
}

int print_text(char text[][line_digits], int lines_numbers[], const int lines) {
    assert(text);

    if (!text) {
        printf("error\nunknown text pointer\n");
        return -1;
    }

    if (!lines_numbers) {
        printf("error\nunknown lines_numbers pointer\n");
        return -1;
    }

    for (size_t line_index = 0; line_index < lines; line_index++) {
        printf("%s", text[lines_numbers[line_index]]);
    }

    return 0;
}

int bubble_sort(char text[][line_digits], int lines_numbers[], const int lines) {
    assert(text);
    assert(lines_numbers);

    if (!text) {
        printf("error\nunknown text pointer in bubble_sort\n");
        return -1;
    }

    if (!lines_numbers) {
        printf("error\nunknown lines_numbers pointer in bubble_sort\n");
        return -1;
    }

    for (size_t sort_index = 0; sort_index < lines; sort_index++) {
        for (size_t line_index = 0; line_index < lines - 1 - sort_index; line_index++) {
            if (strcmp(text[lines_numbers[line_index]], text[lines_numbers[line_index + 1]]) > 0) {
                int change_int_helper = lines_numbers[line_index];
                lines_numbers[line_index] = lines_numbers[line_index + 1];
                lines_numbers[line_index + 1] = change_int_helper;
            }
        }
    }

    return 0;
}

int line_compare(char text[][line_digits], int lines_numbers[], const int lines) {
    assert(text);
    assert(lines_numbers);

    if (!text) {
        printf("error\nnull pointer on text in line_compare\n");
        return -1;
    }

    if (!lines_numbers) {
        printf("error\nnull pointer on lines_numbers in line_compare\n");
        return -1;
    }

    bubble_sort(text, lines_numbers, lines);

    return 0;
}
