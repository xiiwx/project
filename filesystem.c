#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FS_SIZE 1024
char filesystem[FS_SIZE];

// открыть или создать файл
FILE* open_file(const char* filename) 
{
    return fopen("filesystem.txt", "a+");
}

// посмотреть файл
char* view_file(const char* filename) 
{
    char* line = strtok(filesystem, "\n");
    while (line != NULL) 
    {
        if (strcmp(line, filename) == 0) 
        {
            return strtok(NULL, "\n");
        }
        line = strtok(NULL, "\n");
    }
    return NULL;
}

// удалить файл
bool delete_file(const char* filename) 
{
    char temp[FS_SIZE] = "";
    char* line = strtok(filesystem, "\n");
    int found = 0;

    while (line != NULL) 
    {
        if (found || strcmp(line, filename) == 0) 
        {
            found = 1;
        } 
        else 
        {
            strcat(temp, line);
            strcat(temp, "\n");
        }
        line = strtok(NULL, "\n");
    }
    strncpy(filesystem, temp, FS_SIZE - 1);
    filesystem[FS_SIZE - 1] = '\0';
    return found;
}

// новый файл
bool create_new_file(const char* filename, const char* content) 
{
    snprintf(filesystem + strlen(filesystem), FS_SIZE - strlen(filesystem), "%s\n%s\n", filename, content);
    return true;
}

// изменить файл
bool modify_file(const char* filename, const char* new_content) 
{
    char temp[FS_SIZE] = "";
    char* line = strtok(filesystem, "\n");
    int found = 0;

    while (line != NULL) 
    {
        if (strcmp(line, filename) == 0) 
        {
            found = 1;
            strcat(temp, line);
            strcat(temp, "\n");
            strcat(temp, new_content);
            strcat(temp, "\n");
        } 
        else 
        {
            strcat(temp, line);
            strcat(temp, "\n");
        }
        line = strtok(NULL, "\n");
    }
    strncpy(filesystem, temp, FS_SIZE - 1);
    filesystem[FS_SIZE - 1] = '\0';
    return found;
}
