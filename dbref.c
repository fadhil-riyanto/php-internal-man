#include "dbref.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "docs/base.h"

int mkkeyvalue_heap(int initial_size, struct heap_control *ptr)
{
        ptr->heap_size = initial_size;
        void* tmp = malloc(sizeof(struct key_value) * ptr->heap_size);

        if (tmp == NULL) {
                printf("enomem\n");
                return -ENOMEM;
        } else {
                ptr->keyvalptr = tmp;
        }
        
        ptr->curarr = 0;
}

void clear_heap(struct heap_control* ptr)
{
        for(int i = 0; i < ptr->heap_size - 1; i++) {

                if (ptr->heap_size != 1) {
                        free(ptr->keyvalptr[i].key);
                        // free(ptr->keyvalptr[i].value);
                }
                
        }
        free(ptr->keyvalptr);
}

int add_record2_heap(struct heap_control* ptr, char* key, struct value_data* value)
{
        
        void *tmp = realloc(
                ptr->keyvalptr, sizeof(struct key_value) * ptr->heap_size + 1);

        ptr->heap_size = ptr->heap_size + 1;

        if (tmp == NULL) {
                return -ENOMEM;
        } else {
                ptr->keyvalptr = (struct key_value*)tmp;

                // ptr->keyvalptr[ptr->curarr].key = (char*)malloc(strlen(key) + 1);
                // ptr->keyvalptr[ptr->curarr].value = (char*)malloc(strlen(value) + 1);

                ptr->keyvalptr[ptr->curarr].key = strdup(key);
                

                /* copy memory to the heap */
                ptr->keyvalptr[ptr->curarr].value = value;
                // (ptr->keyvalptr + ptr->curarr)->value = strdup(value);


                ptr->curarr = ptr->curarr + 1;
                return 0;
        }
}