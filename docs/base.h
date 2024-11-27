#ifndef BASE_H
#define BASE_H

struct value_data {

        char*                   synopsis;
        char*                   param;
        char*                   param_desc;

        char*                   desc;

        char*                   return_value;
        char*                   reference;

        /* optional */
        char*                   examples;
        char*                   see_also;

};



#endif