#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <malloc.h>

#include "text_data.h"

int free_text_data(TEXT_DATA *TextData) {
    assert(TextData);

    if (!TextData) {
        printf("error\nnull pointer on TextData struct in free_TEXT_DATA\n");
        return -1;
    }

    free(TextData->lines_pointers);
    free(TextData->text);

    return 0;
}

int count_lines(TEXT_DATA *TextData, int file_size) {
    if (!TextData) {
        printf("error\nnull pointer on struct TextData in count_lines\n");
    }

    for (size_t text_digit = 0; text_digit < file_size; text_digit++) {
        if (TextData->text[text_digit] == '\n') {
            TextData->lines++;
        }
    }

    TextData->lines_pointers = (char**) calloc(TextData->lines, sizeof(char*));

    size_t lines_pointers_index = 0;
    TextData->lines_pointers[lines_pointers_index] = TextData->text;
    lines_pointers_index++;

    for (size_t text_digit = 0; text_digit < file_size; text_digit++) {
        if (TextData->text[text_digit] == '\n') {
            TextData->lines_pointers[lines_pointers_index++] = &(TextData->text[text_digit + 1]);
        }
    }

    return 0;
}

int symbols_in_text(FILE* fp, int file_size, TEXT_DATA *TextData) {
    if (!TextData) {
        printf("error\nnull pointer on struct TextData in symbols_in_text\n");
        return -1;
    }

    TextData->text = (char*) calloc(file_size, sizeof(char));
    fread(TextData->text, sizeof(char), file_size + 1, fp);

    return 0;
}

int print_text(int file_size, TEXT_DATA *TextData) {
    if (!TextData) {
        printf("error\nnull pointer on struct TextData in print_text\n");
        return -1;
    }

    fwrite(TextData->text, sizeof(char), file_size + 1, stdout);

    return 0;
}

int delete_extra_spaces(char text[line_digits]) {
    assert(text);

    if (!text) {
        printf("error\nnull pointer on text in delete_extra_spaces\n");
        return -1;
    }

    size_t new_char_index = 0;
    for (size_t digit_index = 0; text[digit_index] != '\0'; digit_index++) {

        if (text[digit_index] != ' ' ||
           (text[digit_index] == ' ' &&
            text[digit_index + 1] != ' ') ||
            text[digit_index] != ' ' && digit_index == 1) {

            text[new_char_index++] = text[digit_index];
        }
    }

    text[new_char_index] = '\0';

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
                //swap(lines_numbers[line_index], lines_numbers[line_index + 1]);
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

int line_ends_compare(char text[][line_digits], int lines_numbers[], const int lines) {
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

    for (size_t sort_index = 0; sort_index < lines; sort_index++) {
        for (size_t line_index = 0; line_index < lines - 1 - sort_index; line_index++) {

            int line1_size = strlen(text[lines_numbers[line_index]]);
            int line2_size = strlen(text[lines_numbers[line_index + 1]]);

            if (strcmp(text[lines_numbers[line_index]] + line1_size - 1,
                       text[lines_numbers[line_index + 1]] + line2_size - 1) < 0) {

                //swap(lines_numbers[line_index], lines_numbers[line_index + 1]);
                int change_int_helper = lines_numbers[line_index];
                lines_numbers[line_index] = lines_numbers[line_index + 1];
                lines_numbers[line_index + 1] = change_int_helper;
            }
        }
    }

    return 0;
}
