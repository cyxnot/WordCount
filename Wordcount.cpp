#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_BUFFER_SIZE 1024

int countCharacters(FILE *file) {
    int count = 0;
    char c;
    
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    
    return count;
}

int countWords(FILE *file) {
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];
    
    while (fscanf(file, "%s", buffer) == 1) {
        count++;
    }
    
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: WordCount [-c | -w] [input_file_name]\n");
        return 1;
    }
    
    char *parameter = argv[1];
    char *filename = argv[2];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    int count = 0;
    
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("×Ö·ûÊý: %d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("µ¥´ÊÊý: %d\n", count);
    } else {
        printf("Invalid parameter. Please use -c or -w.\n");
        return 1;
    }
    
    fclose(file);
    
    return 0;
}
