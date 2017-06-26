//
// Created by Renan Macedo on 26/06/17.
//

#include <string>
#include "Hashtable.h"


/* Create a new hashtable. */
hashtable_t *ht_create(int size, Type key_type, Type value_type) {

    hashtable_t *hashtable = NULL;
    int i;

    if (size < 1) return NULL;

    /* Allocate the table itself. */
    if ((hashtable = (hashtable_t *) malloc(sizeof(hashtable_t))) == NULL) {
        return NULL;
    }

    /* Allocate pointers to the head nodes. */
    if ((hashtable->table = (entry_s **) malloc(sizeof(entry_t *) * size)) == NULL) {
        return NULL;
    }
    for (i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }

    hashtable->size = size;
    hashtable->key_type = key_type;
    hashtable->value_type = value_type;

    return hashtable;
}

/* Hash a string for a particular hash table. */
int ht_hash(hashtable_t *hashtable, const char *key) {

    int hashval;
    int i = 0;

    /* Convert our string to an integer */
    while (hashval < INT_MAX && i < strlen(key)) {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }

    return hashval % hashtable->size;
}


/* Create a key-value pair. */
entry_t *ht_newpair(hashtable_t *hashtable, void *_key, void *_value) {
    entry_t *newpair;

    const char *key = from_void_pointer_to_const_char(_key, hashtable->key_type);
    const char *value = from_void_pointer_to_const_char(_value, hashtable->value_type);

    if ((newpair = (entry_t *) malloc(sizeof(entry_t))) == NULL) {
        return NULL;
    }

    if ((newpair->key = strdup(key)) == NULL) {
        return NULL;
    }

    if ((newpair->value = strdup(value)) == NULL) {
        return NULL;
    }

    newpair->next = NULL;

    return newpair;
}

const char *from_void_pointer_to_const_char(void *_key, const Type &key_type) {
    const char *key;
    switch (key_type) {
        case Type::STRING: {
            std::string *s_key = static_cast<std::string *>(_key);
            key = s_key->c_str();
        }
            break;
        case Type::FLOAT: {
            float *f_key = static_cast<float *>(_key);
            key = std::to_string(*f_key).c_str();
        }
            break;
        case Type::INT:
            int *i_key = static_cast<int *>(_key);
            key = std::to_string(*i_key).c_str();
            break;
    }
    return key;
}

/* Insert a key-value pair into a hash table. */
void ht_set(hashtable_t *hashtable, void *_key, void *_value) {
    int bin = 0;
    entry_t *newpair = NULL;
    entry_t *next = NULL;
    entry_t *last = NULL;

    const char *key = from_void_pointer_to_const_char(_key, hashtable->key_type);
    const char *value = from_void_pointer_to_const_char(_value, hashtable->value_type);

    bin = ht_hash(hashtable, key);

    next = hashtable->table[bin];

    while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0) {
        last = next;
        next = next->next;
    }

    /* There's already a pair.  Let's replace that string. */
    if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0) {

        free(next->value);
        next->value = strdup(value);

        /* Nope, could't find it.  Time to grow a pair. */
    } else {
        newpair = ht_newpair(hashtable, _key, _value);

        /* We're at the start of the linked list in this bin. */
        if (next == hashtable->table[bin]) {
            newpair->next = next;
            hashtable->table[bin] = newpair;

            /* We're at the end of the linked list in this bin. */
        } else if (next == NULL) {
            last->next = newpair;

            /* We're in the middle of the list. */
        } else {
            newpair->next = next;
            last->next = newpair;
        }
    }
}

/* Retrieve a key-value pair from a hash table. */
char *ht_get(hashtable_t *hashtable, const char *key) {
    int bin = 0;
    entry_t *pair;

    bin = ht_hash(hashtable, key);

    /* Step through the bin, looking for our value. */
    pair = hashtable->table[bin];
    while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0) {
        pair = pair->next;
    }

    /* Did we actually find anything? */
    if (pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0) {
        return NULL;

    } else {
        return pair->value;
    }
}

const char *type_to_string(Type type) {
    switch (type) {
        case Type::STRING:
            return "string";
        case Type::FLOAT:
            return "float";
        case Type::INT:
            return "int";
    }
    return "NOT IMPLEMENTED";
}