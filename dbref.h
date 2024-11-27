#include "docs/base.h"

#ifndef DBREF_H
#define DBREF_H


struct key_value {
        char*                           key;
        struct value_data*              value;
        /* 
        int             key_len;
        int             value_len; */
};

struct heap_control 
{
        int                     heap_size;
        int                     curarr;
        struct key_value*       keyvalptr;
};

int mkkeyvalue_heap(int initial_size, struct heap_control *ptr);
void clear_heap(struct heap_control* ptr);
int add_record2_heap(struct heap_control* ptr, char* key, struct value_data* value);

/* defined in docs/func.c */
void append_fn_section(struct heap_control *ptr);
void append_macro_section(struct heap_control *ptr);
void append_exception_section(struct heap_control *ptr);

#endif