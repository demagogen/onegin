#ifndef TEXT_DATA_H_
#define TEXT_DATA_H_
const int line_digits = 100;

struct TEXT_DATA {
    int lines = 0;
    char **lines_pointers = NULL;
    char *text = NULL;
};

int free_text_data(TEXT_DATA *TextData);
int count_lines(TEXT_DATA *TextData, int file_size);
int symbols_in_text(FILE *fp, int file_size, TEXT_DATA *TextData);
int print_text(int file_size, TEXT_DATA *TextData);
int delete_extra_spaces(char text[line_digits]);
int bubble_sort(char text[][line_digits], int lines_numbers[], const int lines);
int line_compare(char text[][line_digits], int lines_numbers[], const int lines);
int line_ends_compare(char text[][line_digits], int lines_numbers[], const int lines);

#endif
