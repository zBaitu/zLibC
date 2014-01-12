#include "zlibc/adt/string.h"
#include <zcut.h>

/**
 * test_str_rm_suffix_suite
 */
TEST_CASE(str_rm_suffix____has_dot)
{
    const char* src = "test_string.c";
    char dest[16];
    str_rm_suffix(src, dest, 16);

    EXPECT_STR_EQ(dest, "test_string");
}

TEST_CASE(str_rm_suffix____has_no_dot)
{
    const char* src = "test_string";
    char dest[16];
    str_rm_suffix(src, dest, 16);

    EXPECT_STR_EQ(dest, "test_string");
}

TEST_CASE(str_rm_suffix____has_dot_small_len)
{
    const char* src = "test_string.c";
    char dest[10];
    str_rm_suffix(src, dest, 10);

    EXPECT_STR_EQ(dest, "test_stri");
}

TEST_CASE(str_rm_suffix____has_no_dot_small_len)
{
    const char* src = "test_string";
    char dest[10];
    str_rm_suffix(src, dest, 10);

    EXPECT_STR_EQ(dest, "test_stri");
}

TEST_CASE(str_rm_suffix____has_no_prefix)
{
    const char* src = ".c";
    char dest[10];
    str_rm_suffix(src, dest, 10);

    EXPECT_STR_EQ(dest, "");
}

TEST_SUITE(test_str_rm_suffix_suite)
{
    str_rm_suffix____has_dot,
    str_rm_suffix____has_no_dot,
    str_rm_suffix____has_dot_small_len,
    str_rm_suffix____has_no_dot_small_len,
    str_rm_suffix____has_no_prefix,
    TEST_NULL
};


TEST_RUNNER(test_string)
{
    test_str_rm_suffix_suite,
    TEST_NULL
};
