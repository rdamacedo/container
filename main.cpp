#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "hashtable/Hashtable.h"


int main(int argc, char **argv) {

    hashtable_t *hashtable = ht_create(65536, Type::FLOAT, Type::STRING);


    ht_set(hashtable, "key1", "inky");
    ht_set(hashtable, "key2", "pinky");
    ht_set(hashtable, "key3", "blinky");
    ht_set(hashtable, "key4", "floyd");


    printf("Key_type: %c\n", hashtable->key_type);
    printf("Value_type: %c\n", hashtable->value_type);
    printf("%s\n", ht_get(hashtable, "key1"));
    printf("%s\n", ht_get(hashtable, "key2"));
    printf("%s\n", ht_get(hashtable, "key3"));
    printf("%s\n", ht_get(hashtable, "key4"));

    return 0;
}
