#include "ctest.h"

void simple_test_case();

int main(int argc, char *argv[]) {
    init();
    __register_func(simple_test_case);
    __run();
    
    report();
    return 0;
}