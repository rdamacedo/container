//
// Created by Renan Macedo on 26/06/17.
//

#ifndef CONTAINERS_UTILS_H
#define CONTAINERS_UTILS_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "../hashtable/Hashtable.h"

const static std::string EXIT = "exit";
const static std::string ADD = "ADD";
const static std::string GET = "GET";
const static std::string CREATE = "CREATE";
const static std::string DESTROY = "DESTROY";


void print_command_usage();

void print_create_command_malformation(std::string &line);

void print_container_not_found(std::string &container_name, std::string &line);

bool check_add_command_formation(std::vector<std::string> &command, std::string &line);

unsigned long split(const std::string &txt, std::vector<std::string> &strs, char ch);

void print_not_right_type(Type &type, std::string &line);

bool is_float(std::string &myString);

bool is_int(std::string &myString);

void clear_special_chars(std::vector<std::string> &command_vector, unsigned long command_size);

bool check_value_type(Type type, std::string &value);

bool parse_key_input(std::vector<std::string> &command_vector,
                     std::string &parsed_key_command, std::string &line);

bool parse_value_input(std::vector<std::string> &command_vector,
                       std::string &parsed_key_command, std::string &line);

bool parse_size_input(std::vector<std::string> &command_vector,
                      int &size, std::string &line);


#endif //CONTAINERS_UTILS_H
