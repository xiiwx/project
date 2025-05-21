#include <stdio.h>
#include "filesystem.h"

int main() {
    const char* filename = "text.txt";
    const char* content = "Hello, World!";

    // Создаем новый файл и записываем данные
    if (write_file(filename, content)) {
        printf("Файл создан и данные записаны.\n");
    } else {
        printf("Ошибка при создании файла.\n");
    }

    // Выводим содержимое файла
    char* file_content = view_file(filename);
    if (file_content) {
        printf("Содержимое файла: %s\n", file_content);
        free(file_content); 
    } else {
        printf("Ошибка при просмотре файла.\n");
    }

    return 0;
}
