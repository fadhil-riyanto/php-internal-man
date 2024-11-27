#include <stdio.h>
#include <string.h>
#include "modules/log.c-patched/src/log.h"
#include "dbref.h"

static void append_dictionary(struct heap_control *heap_ctx)
{
        /* ===========
        *  exception section
        */
        add_record2_heap(heap_ctx, "zend_argument_type_error", 
                "throw TypeError class\n\n" \
                "see: https://www.php.net/manual/en/class.typeerror.php"
        );

        add_record2_heap(heap_ctx, "zend_zval_value_name", 
                "zend_zval_value_name(src): return the type of zval, whatever string, int, float, etc"
        );
        

        /* ===========
        *  macro section
        */
        add_record2_heap(heap_ctx, "ZEND_PARSE_PARAMETERS_START", 
                "ZEND_PARSE_PARAMETERS_START(num_required_args, num_max_args)" \
                "takes two arguments minimal and maximal parameters count."
                );
        
        add_record2_heap(heap_ctx, "Z_PARAM_VARIADIC", 
                "Z_PARAM_VARIADIC(dest, ptr, num)\n" \
                "dest:\n" \
                "- '+' for zero or more parameters\n" \
                "- '*' for one or more parameters\n" \
                "\n\n" \
                "ptr: ptr of zval*\n" \
                "num: a pointer of uint32" 
                
        );

        add_record2_heap(heap_ctx, "ZEND_PARSE_PARAMETERS_END", 
                "end the ZEND_PARSE_PARAMETERS_START section"
        );

        add_record2_heap(heap_ctx, "ZVAL_STR_COPY", 
                "ZVAL_STR_COPY: the ZVAL_STR_COPY macro is a combination of " \
                "ZVAL_STR and zend_string_copy, where the latter increments the refcount of the string."\
                "\n\n"\

                "example: \n" \
                "zval val;\n" \
                "ZVAL_STR_COPY(&val, zstr); // Refcount will be incremented.\n"
                "// More efficient/compact version of:\n"
                "ZVAL_STR(&val, zend_string_copy(zstr));"
        );

        /* ===========
        *  function section
        */
        add_record2_heap(heap_ctx, "efree", 
                "free the memory created by ZendMM (request allocation)"
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
                        printf("-------\n");
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