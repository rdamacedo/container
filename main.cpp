#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "hashtable/Hashtable.h"
#include "utils/Utils.h"

//TODO: Use template in hashtable
//TODO: USE Variant in hashtable
int main(int argc, char **argv) {

    //TODO: Create from input
    hashtable_t *hashtable = ht_create(65536, Type::STRING, Type::STRING);

    printf("Please insert command:");
    for (std::string line; std::getline(std::cin, line);) {
        if (!line.compare(EXIT)) {
            printf("Exit command received, exiting");
            return 0;
        }
        std::vector<std::string> command_vector;
        unsigned long command_size = split(line, command_vector, ' ');

        clear_special_chars(command_vector, command_size);

        if (!command_vector[0].compare(ADD)) {
            if (check_add_command_formation(command_vector, line)) {
                if (!check_value_type(hashtable->key_type, command_vector[2])) {
                    print_not_right_type(hashtable->key_type, line);
                    continue;
                }
                if (!check_value_type(hashtable->value_type, command_vector[3])) {
                    print_not_right_type(hashtable->value_type, line);
                    continue;
                }

                ht_set(hashtable, static_cast<void *>(&command_vector[2]), static_cast<void *>(&command_vector[3]));
            }
        } else if (!command_vector[0].compare(GET)) {
            printf("Searched key: %s , returned %s value.\n", command_vector[2].c_str(),
                   ht_get(hashtable, command_vector[2].c_str()));
        }

        printf("Command size: %lu\n", command_size);
        printf("Command type: %s\n", command_vector[0].c_str());
        printf("Container Name: %s\n", command_vector[1].c_str());
        printf("key: %s\n", command_vector[2].c_str());
        printf("value: %s\n", command_vector[3].c_str());

        command_vector.clear();
        printf("Please insert command:");
    }

    return 0;
}

