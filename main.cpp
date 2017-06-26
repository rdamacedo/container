#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string>
#include "hashtable/Hashtable.h"


int main(int argc, char **argv) {

    hashtable_t *hashtable = ht_create(65536, Type::STRING, Type::STRING);


    ht_set(hashtable, static_cast<void *>(new std::string("key1")), static_cast<void *>(new std::string("inky")));
    ht_set(hashtable, static_cast<void *>(new std::string("key2")), static_cast<void *>(new std::string("pinky")));
    ht_set(hashtable, static_cast<void *>(new std::string("key3")), static_cast<void *>(new std::string("blinky")));
    ht_set(hashtable, static_cast<void *>(new std::string("key4")), static_cast<void *>(new std::string("floyd")));


    printf("Key_type: %c\n", hashtable->key_type);
    printf("Value_type: %c\n", hashtable->value_type);
    printf("%s\n", ht_get(hashtable, "key1"));
    printf("%s\n", ht_get(hashtable, "key2"));
    printf("%s\n", ht_get(hashtable, "key3"));
    printf("%s\n", ht_get(hashtable, "key4"));

    return 0;
}
