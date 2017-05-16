
typedef struct function_s {
    void (*function)();
} function_t;

#define register(func_cb)                        \
    static function_t ptr_##func_cb              \
    __attribute((used, section("suites"))) = {   \
        .function = func_cb,                     \
    }

#define foreach_entry(section_name, type_t, elem) \
    for (type_t *elem = ({ extern type_t __start_##section_name; &__start_##section_name; }); elem != ({ extern type_t __stop_##section_name; &__stop_##section_name; }); ++elem)

struct node {
    void (*function)();
    struct node *next;
};

static int __passed = 0;
static int __failed = 0;
static struct node *__head;
static struct node *__tail;

#define init() \
    __init(__DATE__, __TIME__)

#define expect(message, expression) \
    __expect(message, expression, #expression, __FILE__, __LINE__)

#define __expect(message, expression, expression_s, file, line) \
    __expect_func(message, expression, expression_s, file, line)

#define report() \
    __report()

void __init(char *date, char *time);
void __expect_func(char *message, int expression, char *expression_s, char *file, int line);
void __register_func(void (*function)());
void __run();
void __report();
