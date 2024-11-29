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

struct value_data func_efree = {
        .synopsis = "free the memory area in ZendMM",
        .param = "efree(void *)",
        .param_desc = NULL,
        .desc = NULL,
        .return_value = NULL,
        .reference = "https://github.com/php/php-src/blob/c3b910370c5c92007c3e3579024490345cb7f9a7/Zend/zend_alloc.h#L163",
        .examples = NULL,
        .see_also = "emalloc(size_t)"
};

struct value_data fn_zend_argument_type_error = {
        .synopsis = "throw TypeError class",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = NULL,
        .reference = "https://www.php.net/manual/en/class.typeerror.php",
        .examples = NULL,
        .see_also = NULL
};


struct value_data fn_zend_zval_value_name = {
        .synopsis = "return the type of zval, whatever string, int, float, etc",
        .param = "zend_zval_value_name(src);",
        .param_desc = "src of zval*",
        .desc = NULL,
        .return_value = NULL,
        .reference = NULL,
        .examples = NULL,
        .see_also = NULL
};

struct value_data fn_zend_argument_count_error = {
        .synopsis = "throw ArgumentCountError related class, example: variadic function",
        .param = "zend_argument_count_error(fmt, ...);",
        .param_desc = NULL,
        .desc = NULL,
        .return_value = NULL,
        .reference = "https://github.com/php/php-src/blob/2473f57ba7c0ceeb6c08dfe335995925d0497028/ext/standard/formatted_print.c#L719C4-L719C29",
        .examples = NULL,
        .see_also = NULL
};

void append_fn_section(struct heap_control *ptr)
{
        add_record2_heap(ptr, "efree", &func_efree);
        add_record2_heap(ptr, "zend_argument_type_error", &fn_zend_argument_type_error);
        add_record2_heap(ptr, "zend_zval_value_name", &fn_zend_zval_value_name);
        add_record2_heap(ptr, "zend_argument_count_error", &fn_zend_argument_count_error);
        
}