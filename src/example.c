#include <stdio.h>
#include <string.h>
#include "ctest.h"


static void simple_test_case() {
    expect("this test should pass #1", 1 < 2);
    expect("this test should pass #2", 1 < 3);
    expect("this test should pass #3", strlen("word") == 4);
    expect("this test should fail", strlen("word") == 5);
}
register(simple_test_case);
