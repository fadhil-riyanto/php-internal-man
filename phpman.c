#include <stdio.h>
#include "modules/log.c-patched/src/log.h"
#include "dbref.h"

static int _main(char* strname)
{
        struct heap_control heap_ctx;
        mkkeyvalue_heap(1, &heap_ctx);

        add_record2_heap(&heap_ctx, "abc", "def");
        add_record2_heap(&heap_ctx, "abc", "def");
        add_record2_heap(&heap_ctx, "abcd", "ddef");
        
        clear_heap(&heap_ctx);
}

int main(int argc, char** argv)
{

        if (argc == 2) {
                

                /* start entry */
                _main(argv[1]);
        } else {
                log_error("%s\n", "arg is null, please spesify the function name");
        }
}