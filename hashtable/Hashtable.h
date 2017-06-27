//
// Created by Renan Macedo on 26/06/17.
//

#ifndef CONTAINERS_HASHTABLE_H
#define CONTAINERS_HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

//FIXME: Bad name
enum class Type : char {
    FLOAT = 'f',
    INT = 'i',
    STRING = 's'
};

struct entry_s {
    char *key;
    char *value;
    struct entry_s *next;
};

typedef struct entry_s entry_t;
//TODO: SHOULD USE LINKED LIST?
struct hashtable_s {
    int size;
    Type key_type;
    Type value_type;
    struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;

const char *type_to_string(Type type);

Type string_to_type(const std::string &type);

hashtable_t *ht_create(int size, Type key_type, Type value_type);

int ht_hash(hashtable_t *hashtable, const char *key);

entry_t *ht_newpair(hashtable_t *hashtable, void *_key, void *_value);

void ht_set(hashtable_t *hashtable, void *_key, void *_value);

char *ht_get(hashtable_t *hashtable, const char *key);

const char *from_void_pointer_to_const_char(void *_key, const Type &key_type);

#endif //CONTAINERS_HASHTABLE_H
