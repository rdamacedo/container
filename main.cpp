#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include "container/Container.h"


//TODO: USE Variant in hashtable?
//TODO: Macro to logs
void print_insert_command() {
    printf("Please insert command:");
}

int main(int argc, char **argv) {
    std::vector<Container *> containers;

    print_insert_command();
    for (std::string line; std::getline(std::cin, line);) {
        if (line.empty()) {
            continue;
        }
        if (!line.compare(EXIT)) {
            printf("Exit command received, exiting");
            return 0;
        }

        std::vector<std::string> command_vector;
        unsigned long command_size = split(line, command_vector, ' ');

        if (!command_vector[0].compare(CREATE)) {
            InternalType key_type = InternalType::NOT_KNOWN;
            InternalType value_type = InternalType::NOT_KNOWN;
            int size;

            if (!parse_key_input(command_vector, key_type, line)) {
                print_insert_command();
                continue;
            }

            if (!parse_value_input(command_vector, value_type, line)) {
                print_insert_command();
                continue;
            }

            if (!parse_size_input(command_vector, size, line)) {
                print_insert_command();
                continue;
            }

            Container *_container = new Container(command_vector[1], key_type, value_type, (size_t) size);
            containers.push_back(_container);

            print_insert_command();
            continue;
        }

        Container *container = NULL;
        if (command_vector.size() > 1) {
            for (std::vector<Container *>::iterator it = containers.begin(); it != containers.end(); ++it) {
                if (!(*it)->getName().compare(command_vector[1])) {
                    container = (Container *) (*it);
                    break;
                }
            }
        }
        if (container == NULL) {
            print_container_not_found(command_vector[1], line);
            print_insert_command();
            continue;
        }

        clear_special_chars(command_vector, command_size);

        if (!command_vector[0].compare(ADD)) {
            if (!container->set_pair(line, command_vector)) {
                print_insert_command();
                continue;
            } else {
                print_insert_command();
                continue;
            }
        } else if (!command_vector[0].compare(GET)) {
            std::string value = container->get_value(command_vector[2]);
            if (value.empty()) {
                printf("Searched key: %s , not found.\n", command_vector[2].c_str());
            } else {
                printf("Searched key: %s , returned %s value.\n", command_vector[2].c_str(), value.c_str());
            }
            print_insert_command();
            continue;
        } else if (!command_vector[0].compare(DESTROY)) {

            for (std::vector<Container *>::iterator it = containers.begin(); it != containers.end(); ++it) {
                if (!(*it)->getName().compare(command_vector[1])) {
                    it = containers.erase(it);
                    break;
                }
            }
            printf("Container with name %s was erased.", command_vector[1]);
        }
        command_vector.clear();
    }

    return 0;
}

