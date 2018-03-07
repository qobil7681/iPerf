
#ifndef __IPERF_TEST_SET_H 
#define __IPERF_TEST_SET_H

#include "cjson.h"
#include "iperf.h"

#define OPT_TEST_SET 101

struct iperf_test;
    
struct test_unit
{
    int       id;
    char      *test_name;

    int       argcs;
    char      **argvs;

    cJSON     *json_test_case;

    char      *description;

    int       test_count;
    struct iperf_test **unit_tests;

    int       *test_err;
};

struct test_set
{
    int res;
    int unit_count;
    char *path;
    cJSON *json_file;
    struct test_unit **suite;
};

int ts_parse_args(struct test_unit* tu);

int ts_run_test(struct test_unit* tu, struct iperf_test* main_test);

int ts_run_bulk_test(struct iperf_test* test);

struct test_set * ts_new_test_set(char* path);

int ts_free_test_set(struct test_set* t_set);

int ts_err_output(struct test_set* t_set);

#endif
