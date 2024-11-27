#include <stdio.h>
#include <string.h>
#include "modules/log.c-patched/src/log.h"
#include "dbref.h"
#include "docs/base.h"

static void append_dictionary(struct heap_control *heap_ctx)
{
        append_fn_section(heap_ctx);
        append_macro_section(heap_ctx);
        append_exception_section(heap_ctx);
}

static int _main(char* strname)
{
        short found = 0;

        struct heap_control heap_ctx;
        mkkeyvalue_heap(1, &heap_ctx);

        append_dictionary(&heap_ctx);

        for(int i = 0; i < heap_ctx.heap_size - 1; i++) {
                if (strcmp(heap_ctx.keyvalptr[i].key, strname) == 0 && found == 0) {
                        found = 1;

                        printf("%s\n\n", strname);
                        printf("-------\n");
                        printf("%s\n", heap_ctx.keyvalptr[i].value->param);
                } 
        }

        if (found == 0) {
                printf("%s\n", "function not found");
        }
        
        clear_heap(&heap_ctx);

        return 0;
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