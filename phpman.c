#include <stdio.h>
#include <string.h>
#include "modules/log.c-patched/src/log.h"
#include "dbref.h"

static void append_dictionary(struct heap_control *heap_ctx)
{
        add_record2_heap(heap_ctx, "ZEND_PARSE_PARAMETERS_START", 
                "ZEND_PARSE_PARAMETERS_START(num_required_args, num_max_args)" \
                "takes two arguments minimal and maximal parameters count."
                );
        
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

                        printf("%s\n", heap_ctx.keyvalptr[i].value);
                } 
        }

        if (found == 0) {
                printf("%s\n", "function not found");
        }
        
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