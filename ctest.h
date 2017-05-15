static int __passed = 0;
static int __failed = 0;

#define assert(message, expression) \
    __assert(message, expression, #expression, __FILE__, __LINE__)

#define __assert(message, expression, expression_s, file, line) \
    __i_assert(message, expression, expression_s, file, line)

#define report() \
    __report()

void __i_assert(char *message, int expression, char *expression_s, char *file, int line);
void report();