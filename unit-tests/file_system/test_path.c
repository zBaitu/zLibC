#include "zlibc/file_system/path.h"
#include <zcut.h>

#include <unistd.h>

/**
 * test_get_dir_name_suite
 */
TEST_CASE(test_get_cur_bin_path)
{
    char bin_path[PATH_MAX];
    get_cur_bin_path(bin_path);
    char cwd[PATH_MAX];
    getcwd(cwd, PATH_MAX);
    char expected_bin_path[PATH_MAX];
    snprintf(expected_bin_path, PATH_MAX, "%s/test_path", cwd);
    EXPECT_STR_EQ(bin_path, expected_bin_path);
}

TEST_SUITE(test_get_cur_bin_path_suite)
{
    test_get_cur_bin_path,
    TEST_NULL
};


/**
 * test_get_dir_name_suite
 */
TEST_CASE(get_dir_name____has_slash)
{
    const char* path = "/bin/ls";
    char dir_name[8];
    get_dir_name(path, dir_name);

    EXPECT_STR_EQ(dir_name, "/bin");
}

TEST_CASE(get_dir_name____has_no_slash)
{
    const char* path = "bin";
    char dir_name[8];
    get_dir_name(path, dir_name);

    EXPECT_STR_EQ(dir_name, ".");
}

TEST_CASE(get_dir_name____first_slash)
{
    const char* path = "/bin";
    char dir_name[8];
    get_dir_name(path, dir_name);

    EXPECT_STR_EQ(dir_name, "");
}

TEST_CASE(get_dir_name____last_slash)
{
    const char* path = "/bin/ls/";
    char dir_name[8];
    get_dir_name(path, dir_name);

    EXPECT_STR_EQ(dir_name, "/bin/ls");
}

TEST_SUITE(test_get_dir_name_suite)
{
    get_dir_name____has_slash,
    get_dir_name____has_no_slash,
    get_dir_name____first_slash,
    get_dir_name____last_slash,
    TEST_NULL
};


/**
 * test_get_dir_name_self_suite
 */
TEST_CASE(test_get_dir_name_self)
{
    char path[] = "/bin/ls";
    get_dir_name_self(path);
    EXPECT_STR_EQ(path, "/bin");
}

TEST_SUITE(test_get_dir_name_self_suite)
{
    test_get_dir_name_self,
    TEST_NULL
};


TEST_RUNNER(test_path)
{
    test_get_cur_bin_path_suite,
    test_get_dir_name_suite,
    test_get_dir_name_self_suite,
    TEST_NULL
};
