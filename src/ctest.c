#include <stdio.h>
#include <stdlib.h>
#include "ctest.h"

void __init(char *date, char *time) {
    printf("%s %s\n", date, time);
}

void __expect(char *message, int expression, char *expression_s, char *file, int line) {
    printf("[%s] %s (%s) %s:%d\n", expression ? "PASS": "FAIL", message, expression_s, file, line);
    expression ? __passed++ : __failed++;
}

void __register(void (*function)()) {
    printf("registering function\n");
    if (__head == NULL) {
        __head = malloc(sizeof(struct node));
        __head->function = function;
        __tail = __head;
    }
    else {
        struct node *new = malloc(sizeof(struct node));
        new->function = function;
        __tail->next = new;
        __tail = new;
    }
}

void __run() {
    // struct node *iter = __head;
    // while (iter != NULL) {
    //     (*iter->function)();
    //     iter = iter->next;
    // }
    foreach_entry(suites, function_t, entry) {
        entry->function();
    }
}

void __report() {
    printf("%d test%s passed (%d total)\n", __passed, __passed != 0 ? "s": "", __passed + __failed);
}