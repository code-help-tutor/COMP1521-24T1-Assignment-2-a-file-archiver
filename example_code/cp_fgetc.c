WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// cp <file1> <file2>
// implemented with fgetc

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    FILE *input_stream = fopen(argv[1], "r");
    if (input_stream == NULL) {
        perror(argv[1]);  // prints why the open failed
        return 1;
    }

    FILE *output_stream = fopen(argv[2], "w");
    if (output_stream == NULL) {
        perror(argv[2]);
        return 1;
    }

    int c; // not char!
    while ((c = fgetc(input_stream)) != EOF) {
        fputc(c, output_stream);
    }


    fclose(input_stream);  // optional here as fclose occurs
    fclose(output_stream); // automatically on exit

    return 0;
}
