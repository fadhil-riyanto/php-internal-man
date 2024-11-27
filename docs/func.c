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

inline void append_fn_section(struct heap_control *ptr)
{
        add_record2_heap(ptr, "efree", &func_efree);
}