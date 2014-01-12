#ifndef _ZLIBC_FILE_SYSTEM_PATH_H_
#define _ZLIBC_FILE_SYSTEM_PATH_H_

#include <limits.h>
#include <stdbool.h>

bool    get_cur_bin_path(char bin_path[PATH_MAX]);
char*   get_dir_name(const char* path, char dir_name[PATH_MAX]);
char*   get_dir_name_self(char path[PATH_MAX]);

#endif
