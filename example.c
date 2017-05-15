#include <stdio.h>
#include <string.h>
#include "ctest.h"

int main() {
    assert("this test should pass #1", 1 < 2);
    assert("this test should pass #2", 1 < 3);
    assert("this test should pass #3", strlen("word") == 4);
    assert("this test should fail", strlen("word") == 5);
    report();
    return 0;
}