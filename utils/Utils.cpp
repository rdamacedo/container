#include "Utils.h"


unsigned long split(const std::string &txt, std::vector<std::string> &strs, char ch) {
    unsigned long pos = txt.find(ch);
    unsigned long initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos));

    return strs.size();
}


void print_command_usage() {
    //TODO: Implement command usage
}

void print_not_right_type(InternalType &type, std::string &line) {
    printf("You are trying to insert the wrong type you should use : %s\n", type2string(type));
    printf("Your command : %s\n", line.c_str());
}

const char *type2string(InternalType &type) {
    switch (type) {
        case InternalType::FLOAT :
            return TYPE_FLOAT_STRING;
        case InternalType::INT :
            return TYPE_INT_STRING;
        case InternalType::STRING:
            return TYPE_STRING_STRING;
        case InternalType::NOT_KNOWN:
            return "NOT_KNOWN";
    }
}

InternalType string2type(std::string &type) {
    std::transform(type.begin(), type.end(), type.begin(), ::tolower);
    if (!type.compare("string")) {
        return InternalType::STRING;
    } else if (!type.compare("int")) {
        return InternalType::INT;
    } else if (!type.compare("float")) {
        return InternalType::FLOAT;
    }
    return InternalType::NOT_KNOWN;
}

bool check_add_command_formation(std::vector<std::string> &command, std::string &line) {
    if (command.size() != 4) {
        printf("Malformed command: %s\n", line.c_str());
        print_command_usage();
        return false;
    }
    return true;
}

bool is_float(std::string &input) {
    std::istringstream iss(input);
    float f;
    iss >> f;
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

bool is_int(std::string &input) {
    std::istringstream iss(input);
    int f;
    iss >> f;
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

void clear_special_chars(std::vector<std::string> &command_vector,
                         unsigned long command_size) {
    if (command_size > 2) {
        command_vector[2].erase(remove(command_vector[2].begin(), command_vector[2].end(), '\"'),
                                command_vector[2].end());
    }
    if (command_size > 3) {
        command_vector[3].erase(remove(command_vector[3].begin(), command_vector[3].end(), '\"'),
                                command_vector[3].end());
    }
}

bool check_value_type(InternalType type, std::string &value) {
    switch (type) {
        case InternalType::FLOAT :
            if (!is_float(value)) {
                return false;
            }
            break;
        case InternalType::INT:
            if (!is_int(value)) {
                return false;
            }
            break;
        case InternalType::STRING:
            return !value.empty();
        case InternalType::NOT_KNOWN:
            return false;
    }
    return true;
}

void print_container_not_found(std::string &container_name, std::string &line) {
    printf("Requested container doesn't exist: %s\n", container_name.c_str());
    printf("Your command : %s\n", line.c_str());
}

void print_create_command_malformation(std::string &line) {
    printf("Error when parsing the following command, please double check %s\n", line.c_str());
    print_command_usage();
}

bool parse_key_input(std::vector<std::string> &command_vector,
                     InternalType &parsed_key_command, std::string &line) {

    std::vector<std::string> key_command;
    if (command_vector.size() > 2) {
        split(command_vector[2], key_command, '=');
    } else {
        print_create_command_malformation(line);
        return false;
    }

    if (key_command.size() > 1) { parsed_key_command = string2type(key_command[1]); }

    if (parsed_key_command == InternalType::NOT_KNOWN) {
        print_create_command_malformation(line);
        return false;
    }
    return true;
}

bool parse_value_input(std::vector<std::string> &command_vector,
                       InternalType &parsed_key_command, std::string &line) {

    std::vector<std::string> key_command;
    if (command_vector.size() > 3) {
        split(command_vector[3], key_command, '=');
    } else {
        print_create_command_malformation(line);
        return false;
    }

    if (key_command.size() > 1) { parsed_key_command = string2type(key_command[1]); }

    if (parsed_key_command == InternalType::NOT_KNOWN) {
        print_create_command_malformation(line);
        return false;
    }
    return true;
}

bool parse_size_input(std::vector<std::string> &command_vector,
                      int &size, std::string &line) {

    std::vector<std::string> command;
    size = -1;
    if (command_vector.size() > 4) {
        split(command_vector[4], command, '=');
    } else {
        print_create_command_malformation(line);
        return false;
    }

    if (command.size() > 1 && is_int(command[1])) {
        size = atoi(command[1].c_str());
    }

    if (size < 1) {
        print_create_command_malformation(line);
        return false;
    }
    return true;
}

