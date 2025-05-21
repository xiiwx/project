#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>

FILE* open_file(const char* filename);

void view_file(const char* fs_filename, const char* target_filename);

void delete_file(const char* fs_filename, const char* target_filename);

void new_file(const char* fs_filename, const char* new_filename, const char* content_lines[], int content_count);

void modify_file(const char* fs_filename, const char* target_filename, const char* new_content[], int new_count);

#endif
