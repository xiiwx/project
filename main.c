#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filesystem.h"

#define MAX_INPUT 1024

int main() {
    const char* fs_name = "file_system.txt";
    open_file(fs_name);
    
    char input[MAX_INPUT];
    char* command;
    char* arg1;
    char* arg2;

    printf("Введите команду:\n");

    while (1) {
        printf(">");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; 

        command = strtok(input, " ");
        arg1 = strtok(NULL, " ");
        arg2 = strtok(NULL, "");

        if (!command) continue;

        if (strcmp(command, "создать") == 0 && arg1) {
            char* content[MAX_LINES];
            int count = 0;
            printf("Введите содержимое:\n");
            while (1) {
                char line[256];
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                if (strcmp(line, "/end") == 0) break;
                content[count] = strdup(line);
                count++;
            }
            new_file(fs_name, arg1, content, count);
            for (int i = 0; i < count; i++) free(content[i]);

        } else if (strcmp(command, "удалить") == 0 && arg1) {
            delete_file(fs_name, arg1);

        } else if (strcmp(command, "изменить") == 0 && arg1) {
            char* content[MAX_LINES];
            int count = 0;
            printf("Новое содержимое:\n");
            while (1) {
                char line[256];
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                if (strcmp(line, "/end") == 0) break;
                content[count] = strdup(line);
                count++;
            }
            modify_file(fs_name, arg1, content, count);
            for (int i = 0; i < count; i++) free(content[i]);

        } else if (strcmp(command, "посмотреть") == 0 && arg1) {
            view_file(fs_name, arg1);

        } else if (strcmp(command, "выйти") == 0) {
            break;

        } else {
            printf("Неизвестная команда.\n");
        }
    }

    return 0;
}
