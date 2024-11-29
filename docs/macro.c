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


struct value_data mc_Z_TYPE = {
        .synopsis = "Z_TYPE() macro for retrieving the type tag",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php5/zvals/basic_structure.html",
        .examples = "zval zv;\n" \
                        "\tzval *zv_ptr;\n" \
                        "\tzval **zv_ptr_ptr;\n" \
                        "\tzval ***zv_ptr_ptr_ptr;\n" \
                        "\t\n" \
                        "\tZ_TYPE(zv);                 // = zv.type\n" \
                        "\tZ_TYPE_P(zv_ptr);           // = zv_ptr->type\n" \
                        "\tZ_TYPE_PP(zv_ptr_ptr);      // = (*zv_ptr_ptr)->type\n" \
                        "\tZ_TYPE_PP(*zv_ptr_ptr_ptr); // = (**zv_ptr_ptr_ptr)->type\n",
        .see_also = NULL
};


struct value_data mc_Z_TYPE_P = {
        .synopsis = "Z_TYPE_P() macro for retrieving the type tag of zval*",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php5/zvals/basic_structure.html",
        .examples = "zval zv;\n" \
                        "\tzval *zv_ptr;\n" \
                        "\tzval **zv_ptr_ptr;\n" \
                        "\tzval ***zv_ptr_ptr_ptr;\n" \
                        "\t\n" \
                        "\tZ_TYPE(zv);                 // = zv.type\n" \
                        "\tZ_TYPE_P(zv_ptr);           // = zv_ptr->type\n" \
                        "\tZ_TYPE_PP(zv_ptr_ptr);      // = (*zv_ptr_ptr)->type\n" \
                        "\tZ_TYPE_PP(*zv_ptr_ptr_ptr); // = (**zv_ptr_ptr_ptr)->type\n",
        .see_also = NULL
};

struct value_data mc_Z_TYPE_PP = {
        .synopsis = "Z_TYPE_PP() macro for retrieving the type tag of zval**",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php5/zvals/basic_structure.html",
        .examples = "zval zv;\n" \
                        "\tzval *zv_ptr;\n" \
                        "\tzval **zv_ptr_ptr;\n" \
                        "\tzval ***zv_ptr_ptr_ptr;\n" \
                        "\t\n" \
                        "\tZ_TYPE(zv);                 // = zv.type\n" \
                        "\tZ_TYPE_P(zv_ptr);           // = zv_ptr->type\n" \
                        "\tZ_TYPE_PP(zv_ptr_ptr);      // = (*zv_ptr_ptr)->type\n" \
                        "\tZ_TYPE_PP(*zv_ptr_ptr_ptr); // = (**zv_ptr_ptr_ptr)->type\n",
        .see_also = NULL
};

struct value_data mc_Z_LVAL_P = {
        .synopsis = "Z_LVAL_P() to get the long (integer) value",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php5/zvals/basic_structure.html",
        .examples = "zval *zv_ptr = /* ... */;\n" \
                        "\t\n" \
                        "\tif (Z_TYPE_P(zv_ptr) == IS_LONG) {\n" \
                        "\t    php_printf(\"Zval is a long with value %ld\\n\", Z_LVAL_P(zv_ptr));\n" \
                        "\t} else /* ... */\n" ,
        .see_also = NULL
};


struct value_data mc_ZSTR_VAL = {
        .synopsis = "ZSTR_VAL() get string from zend_string *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/internal_types/strings/zend_strings.html",
        .examples = "size_t len = 40;\n" \
                        "\tzend_string *str = zend_string_alloc(len, /* persistent */ 0);\n" \
                        "\tfor (size_t i = 0; i < len; i++) {\n" \
                        "\t    ZSTR_VAL(str)[i] = 'a';\n" \
                        "\t}\n" \
                        "\t// Don't forget to null-terminate!\n" \
                        "\tZSTR_VAL(str)[len] = '\0';\n" \
                        "\t\n",
        .see_also = NULL
};


struct value_data mc_ZSTR_LEN = {
        .synopsis = "ZSTR_LEN() get string length from zend_string *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/internal_types/strings/zend_strings.html",
        .examples = "zval val;\n" \
                        "\tZVAL_STRING(&val, \"foo\");\n" \
                        "\t\n" \
                        "\t// Z_STRLEN, Z_STRVAL work on zval.\n" \
                        "\tphp_printf(\"string(%zd) \\\"%s\\\"\\n\", Z_STRLEN(val), Z_STRVAL(val));\n" \
                        "\t\n" \
                        "\t// ZSTR_LEN, ZSTR_VAL work on zend_string.\n" \
                        "\tzend_string *str = Z_STR(val);\n" \
                        "\tphp_printf(\"string(%zd) \\\"%s\\\"\\n\", ZSTR_LEN(str), ZSTR_VAL(str));\n" \
                        "\t\n" \
                        "\tzval_ptr_dtor(&val);\n" \
                        "\t\n" ,
        .see_also = NULL
};



struct value_data mc_Z_PARAM_ARRAY = {
        .synopsis = "Z_PARAM_ARRAY() get array from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_ARRAY_OR_OBJECT = {
        .synopsis = "Z_PARAM_ARRAY_OR_OBJECT() get array or obj from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_BOOL = {
        .synopsis = "Z_PARAM_BOOL() get boolean from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_CLASS = {
        .synopsis = "Z_PARAM_CLASS() get class obj callee from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_DOUBLE = {
        .synopsis = "Z_PARAM_DOUBLE() get double from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_FUNC = {
        .synopsis = "Z_PARAM_FUNC() get function callee from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_ARRAY_HT = {
        .synopsis = "Z_PARAM_ARRAY_HT() get array hashtable from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_ARRAY_OR_OBJECT_HT = {
        .synopsis = "Z_PARAM_ARRAY_OR_OBJECT_HT() get array or object hashtable from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_LONG = {
        .synopsis = "Z_PARAM_LONG() get int from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_STRICT_LONG = {
        .synopsis = "Z_PARAM_STRICT_LONG() get string long from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_OBJECT = {
        .synopsis = "Z_PARAM_OBJECT() get object from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_OBJECT_OF_CLASS = {
        .synopsis = "Z_PARAM_OBJECT_OF_CLASS() get object or class from function parameters *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_PATH = {
        .synopsis = "Z_PARAM_PATH() (pending docs) *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_PATH_STR = {
        .synopsis = "Z_PARAM_PATH_STR() (pending docs) *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_RESOURCE = {
        .synopsis = "Z_PARAM_RESOURCE() (pending docs) *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_STRING = {
        .synopsis = "Z_PARAM_STRING() get string from php function *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_STR = {
        .synopsis = "Z_PARAM_STR() (pending docs) *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};

struct value_data mc_Z_PARAM_ZVAL = {
        .synopsis = "Z_PARAM_ZVAL() (pending docs) *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


struct value_data mc_Z_PARAM_VARIADIC = {
        .synopsis = "Z_PARAM_VARIADIC() get multiple param at once *",
        .param = NULL,
        .param_desc = NULL,
        .desc = NULL,
        .return_value = "void",
        .reference = "https://www.phpinternalsbook.com/php7/extensions_design/php_functions.html",
        .examples = NULL,
        .see_also = NULL
};


inline void append_macro_section(struct heap_control *ptr)
{
        add_record2_heap(ptr, "ZEND_PARSE_PARAMETERS_START", &mc_ZEND_PARSE_PARAMETERS_START);
        add_record2_heap(ptr, "ZEND_PARSE_PARAMETERS_END", &mc_ZEND_PARSE_PARAMETERS_END);
        add_record2_heap(ptr, "ZVAL_STR_COPY", &mc_ZVAL_STR_COPY);
        
        add_record2_heap(ptr, "Z_TYPE", &mc_Z_TYPE);
        add_record2_heap(ptr, "Z_TYPE_P", &mc_Z_TYPE_P);
        add_record2_heap(ptr, "Z_TYPE_PP", &mc_Z_TYPE_PP);
        
        add_record2_heap(ptr, "Z_LVAL_P", &mc_Z_LVAL_P);
        add_record2_heap(ptr, "ZSTR_VAL", &mc_ZSTR_VAL);
        add_record2_heap(ptr, "ZSTR_LEN", &mc_ZSTR_LEN);

        add_record2_heap(ptr, "Z_PARAM_ARRAY", &mc_Z_PARAM_ARRAY);
        add_record2_heap(ptr, "Z_PARAM_ARRAY_OR_OBJECT", &mc_Z_PARAM_ARRAY_OR_OBJECT);
        add_record2_heap(ptr, "Z_PARAM_BOOL", &mc_Z_PARAM_BOOL);
        add_record2_heap(ptr, "Z_PARAM_CLASS", &mc_Z_PARAM_CLASS);
        add_record2_heap(ptr, "Z_PARAM_DOUBLE", &mc_Z_PARAM_DOUBLE);
        add_record2_heap(ptr, "Z_PARAM_FUNC", &mc_Z_PARAM_FUNC);
        add_record2_heap(ptr, "Z_PARAM_ARRAY_HT", &mc_Z_PARAM_ARRAY_HT);
        add_record2_heap(ptr, "Z_PARAM_ARRAY_OR_OBJECT_HT", &mc_Z_PARAM_ARRAY_OR_OBJECT_HT);
        add_record2_heap(ptr, "Z_PARAM_LONG", &mc_Z_PARAM_LONG);
        add_record2_heap(ptr, "Z_PARAM_STRICT_LONG", &mc_Z_PARAM_STRICT_LONG);
        add_record2_heap(ptr, "Z_PARAM_OBJECT", &mc_Z_PARAM_OBJECT);
        add_record2_heap(ptr, "Z_PARAM_OBJECT_OF_CLASS", &mc_Z_PARAM_OBJECT_OF_CLASS);
        add_record2_heap(ptr, "Z_PARAM_PATH", &mc_Z_PARAM_PATH);
        add_record2_heap(ptr, "Z_PARAM_PATH_STR", &mc_Z_PARAM_PATH_STR);
        add_record2_heap(ptr, "Z_PARAM_RESOURCE", &mc_Z_PARAM_RESOURCE);
        add_record2_heap(ptr, "Z_PARAM_STRING", &mc_Z_PARAM_STRING);
        add_record2_heap(ptr, "Z_PARAM_STR", &mc_Z_PARAM_STR);
        add_record2_heap(ptr, "Z_PARAM_ZVAL", &mc_Z_PARAM_ZVAL);
        add_record2_heap(ptr, "Z_PARAM_VARIADIC" , &mc_Z_PARAM_VARIADIC);
        // add_record2_heap(ptr, "Z_TYPE_PP", &mc_Z_TYPE_PP);
        // add_record2_heap(ptr, "Z_TYPE_PP", &mc_Z_TYPE_PP);
        // add_record2_heap(ptr, "Z_TYPE_PP", &mc_Z_TYPE_PP);
        // add_record2_heap(ptr, "Z_TYPE_PP", &mc_Z_TYPE_PP);
        // add_record2_heap(ptr, "Z_TYPE_PP", &mc_Z_TYPE_PP);
        

}