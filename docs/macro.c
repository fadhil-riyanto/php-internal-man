#include "base.h"
#include <time.h>
#include "../dbref.h"

/* template */
/*

struct value_data fn_ANY = {
        .synopsis = NULL,
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = NULL,
        .reference = NULL,
        .examples = NULL,
        .see_also = NULL
};

*/

struct value_data mc_ZEND_PARSE_PARAMETERS_START = {
        .synopsis = "start function parameters parsing",
        .param = "ZEND_PARSE_PARAMETERS_START(min_argument_count, max_argument_count)",
        .param_desc = NULL,
        .desc = NULL,
        .return_value = NULL,
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = "ZEND_PARSE_PARAMETERS_END"
};

struct value_data mc_ZEND_PARSE_PARAMETERS_END = {
        .synopsis = "end the function parameters parsing",
        .param = "ZEND_PARSE_PARAMETERS_START()",
        .param_desc = NULL,
        .desc = NULL,
        .return_value = NULL,
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = "ZEND_PARSE_PARAMETERS_START"
};

struct value_data mc_ZVAL_STR_COPY = {
        .synopsis = "the ZVAL_STR_COPY macro is a combination of ZVAL_STR and zend_string_copy, where the latter increments the refcount of the string",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/zvals/memory_management.html",
        .examples = "zval val;\n" \
                        "\tZVAL_STR_COPY(&val, zstr); // Refcount will be incremented.\n" \
                        "\t// More efficient/compact version of:\n" \
                        "\tZVAL_STR(&val, zend_string_copy(zstr));\n",
        .see_also = NULL
};

inline void append_macro_section(struct heap_control *ptr)
{
        add_record2_heap(ptr, "ZEND_PARSE_PARAMETERS_START", &mc_ZEND_PARSE_PARAMETERS_START);
        add_record2_heap(ptr, "ZEND_PARSE_PARAMETERS_END", &mc_ZEND_PARSE_PARAMETERS_END);
        add_record2_heap(ptr, "ZVAL_STR_COPY", &mc_ZVAL_STR_COPY);
        

}