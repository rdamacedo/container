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


void print_command_usage();

bool check_add_command_formation(std::vector<std::string> &command, std::string &line);

unsigned long split(const std::string &txt, std::vector<std::string> &strs, char ch);

void print_not_right_type(Type &type, std::string &line);

bool is_float(std::string &myString);

bool is_int(std::string &myString);

void clear_special_chars(std::vector<std::string> &command_vector, unsigned long command_size);

bool check_value_type(Type type, std::string &value);


#endif //CONTAINERS_UTILS_H
