
/***********************************************************************
 * $Id$
 * Copyright 2009 Aplix Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ***********************************************************************/
#ifndef lex_h
#define lex_h

#define KEYWORDS \
    "DOMString\0" \
    "false\0" \
    "object\0" \
    "true\0" \
    "any\0" \
    "attribute\0" \
    "boolean\0" \
    "byte\0" \
    "caller\0" \
    "const\0" \
    "creator\0" \
    "deleter\0" \
    "dictionary\0" \
    "double\0" \
    "exception\0" \
    "float\0" \
    "getraises\0" \
    "getter\0" \
    "implements\0" \
    "in\0" \
    "interface\0" \
    "long\0" \
    "module\0" \
    "null\0" \
    "octet\0" \
    "omittable\0" \
    "optional\0" \
    "partial\0" \
    "raises\0" \
    "readonly\0" \
    "sequence\0" \
    "setraises\0" \
    "setter\0" \
    "short\0" \
    "static\0" \
    "stringifier\0" \
    "typedef\0" \
    "unsigned\0" \
    "valuetype\0" \
    "void\0"


enum toktype {
    TOK_EOF = -1,
    TOK_BLOCKCOMMENT = 0x80,
    TOK_INLINECOMMENT, TOK_INTEGER, TOK_FLOAT, TOK_IDENTIFIER,
    TOK_STRING, TOK_DOUBLECOLON, TOK_ELLIPSIS, TOK_DOUBLEBRACKET,
    /* Keywords must be in the same order as above. */
    TOK_DOMString,
    TOK_false,
    TOK_object,
    TOK_true,
    TOK_any,
    TOK_attribute,
    TOK_boolean,
    TOK_byte,
    TOK_caller,
    TOK_const,
    TOK_creator,
    TOK_deleter,
    TOK_dictionary,
    TOK_double,
    TOK_exception,
    TOK_float,
    TOK_getraises,
    TOK_getter,
    TOK_implements,
    TOK_in,
    TOK_interface,
    TOK_long,
    TOK_module,
    TOK_null,
    TOK_octet,
    TOK_omittable,
    TOK_optional,
    TOK_partial,
    TOK_raises,
    TOK_readonly,
    TOK_sequence,
    TOK_setraises,
    TOK_setter,
    TOK_short,
    TOK_static,
    TOK_stringifier,
    TOK_typedef,
    TOK_unsigned,
    TOK_valuetype,
    TOK_void,
};

struct tok {
    enum toktype type;
    const char *filename;
    unsigned int linenum;
    const char *prestart;
    const char *start;
    unsigned int len;
};

extern const char *filename;
extern const char keywords[];

struct node;

void readinput(const char *const *argv);
struct tok *lex(void);
void outputwidl(struct node *node);

#endif /* ndef lex_h */
