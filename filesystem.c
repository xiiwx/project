#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FS_SIZE 1024
char filesystem[FS_SIZE];


FILE* open_file(const char* filename) {
    FILE *file = fopen("filesystem.txt", "a+");
    return file;
}


char* view_file(const char* filename) {
    char* line = strtok(filesystem, "\n");
    while (line != NULL) {
        if (strcmp(line, filename) == 0) {
            return strtok(NULL, "\n");
        }
        line = strtok(NULL, "\n");
    }
    return NULL;
}


bool delete_file(const char* filename) {
    char temp[FS_SIZE] = "";
    char* line = strtok(filesystem, "\n");
    int found = 0;

    while (line != NULL) {
        if (found || strcmp(line, filename) == 0) {
            found = 1;
        } else {
            strcat(temp, line);
            strcat(temp, "\n");
        }
        line = strtok(NULL, "\n");
    }
    strncpy(filesystem, temp, FS_SIZE - 1);
    filesystem[FS_SIZE - 1] = '\0'; 
    return found; 
}
