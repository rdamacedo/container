#ifndef CONTAINERS_UTILS_H
#define CONTAINERS_UTILS_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

const static std::string EXIT = "exit";
const static std::string ADD = "ADD";
const static std::string GET = "GET";
const static std::string CREATE = "CREATE";
const static std::string DESTROY = "DESTROY";

const static char *TYPE_FLOAT_STRING = "FLOAT";
const static char *TYPE_STRING_STRING = "STRING";
const static char *TYPE_INT_STRING = "INT";

enum class InternalType {
    FLOAT,
    INT,
    STRING,
    NOT_KNOWN
};


void print_command_usage();

void print_create_command_malformation(std::string &line);

void print_container_not_found(std::string &container_name, std::string &line);

bool check_add_command_formation(std::vector<std::string> &command, std::string &line);

const char *type2string(InternalType &type);

InternalType string2type(std::string &type);

unsigned long split(const std::string &txt, std::vector<std::string> &strs, char ch);

void print_not_right_type(InternalType &type, std::string &line);

bool is_float(std::string &input);

bool is_int(std::string &input);

void clear_special_chars(std::vector<std::string> &command_vector, unsigned long command_size);

bool check_value_type(InternalType type, std::string &value);

bool parse_key_input(std::vector<std::string> &command_vector,
                     InternalType &parsed_key_command, std::string &line);

bool parse_value_input(std::vector<std::string> &command_vector,
                       InternalType &parsed_key_command, std::string &line);

bool parse_size_input(std::vector<std::string> &command_vector,
                      int &size, std::string &line);


#endif //CONTAINERS_UTILS_H
