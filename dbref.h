#ifndef DBREF_H
#define DBREF_H


struct key_value {
        char*           key;
        char*           value;
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

void mkkeyvalue_heap(int initial_size, struct heap_control *ptr);
void clear_heap(struct heap_control* ptr);
int add_record2_heap(struct heap_control* ptr, char* key, char* value);


#endif