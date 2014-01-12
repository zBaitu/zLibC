#include "zlibc/adt/string.h"

char* str_rm_suffix(const char* src, char* dest, size_t len)
{
    size_t cur_len = 0;
    char* cur = dest;
    while (*src && *src != '.' && ++cur_len < len)
        *cur++ = *src++;
    *cur = '\0';
    return dest;
}
