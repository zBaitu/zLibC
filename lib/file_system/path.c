#include "zlibc/file_system/path.h"

#include <unistd.h>

bool get_cur_bin_path(char bin_path[PATH_MAX])
{
    ssize_t size = readlink("/proc/self/exe", bin_path, PATH_MAX - 1);
    if (size == -1)
        return false;
    bin_path[PATH_MAX - 1] = '\0';
    return true;
}

char* get_dir_name(const char* path, char dir_name[PATH_MAX])
{
    char* last_slash_pos = NULL;
    char* cur = dir_name;
    while (*path)
    {
        *cur = *path++;
        if (*cur == '/')
            last_slash_pos = cur;
        cur++;
    }

    if (last_slash_pos)
        *last_slash_pos = '\0';
    else
        dir_name[0] = '.', dir_name[1] = '\0';
    return dir_name;
}

char* get_dir_name_self(char path[PATH_MAX])
{
    char* last_slash_pos = NULL;
    char* cur = path;
    while (*cur)
    {
        if (*cur == '/')
            last_slash_pos = cur;
        cur++;
    }

    if (last_slash_pos)
        *last_slash_pos = '\0';
    return path;
}
