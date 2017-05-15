#include <stdio.h>
#include "ctest.h"

void __i_assert(char *message, int expression, char *expression_s, char *file, int line) {
    printf("[%s] %s (%s) %s:%d\n", expression ? "PASS": "FAIL", message, expression_s, file, line);
    expression ? __passed++ : __failed++;
}

void __report() {
    printf("%d test%s passed (%d total)\n", __passed, __passed != 0 ? "s": "", __passed + __failed);
}