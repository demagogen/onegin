#ifndef TEXT_DATA_H_
#define TEXT_DATA_H_
const int line_digits = 40;
int fill_text(FILE *fp, char text[][line_digits], int lines_numbers[], const int lines);
int print_text(char text[][line_digits], int lines_numbers[], const int lines);
int bubble_sort(char text[][line_digits], int lines_numbers[], const int lines);
int line_compare(char text[][line_digits], int lines_numbers[], const int lines);
#endif
