#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>
#include <stdbool.h>

FILE* open_file(const char* filename);

char* view_file(const char* filename);

bool delete_file(const char* filename);

bool write_file(const char* filename, const char* data);

bool file_exists(const char* filename);

#endif 
