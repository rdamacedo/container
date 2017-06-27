
#include "Container.h"


Container::Container(const std::string &name, const std::string &key_type, const std::string &value_type, int size)
        : name(name), key_type(key_type), value_type(value_type), size(size) {

    Type _key_type = string_to_type(key_type);
    Type _value_type = string_to_type(value_type);

    data = ht_create(size, _key_type, _value_type);

    printf("Containter created: %s key=%s value=%s N=%d\n", name.c_str(), key_type.c_str(), value_type.c_str(), size);
}

bool Container::set_pair(std::string &line, std::vector<std::string> &command_vector) {
    if (check_add_command_formation(command_vector, line)) {
        if (!check_value_type(data->key_type, command_vector[2])) {
            print_not_right_type(data->key_type, line);
            return false;
        }
        if (!check_value_type(data->value_type, command_vector[3])) {
            print_not_right_type(data->value_type, line);
            return false;
        }

        ht_set(data, static_cast<void *>(&command_vector[2]), static_cast<void *>(&command_vector[3]));
    }
    printf("Entry inserted in container: %s key=%s value=%s\n", name.c_str(), command_vector[2].c_str(),
           command_vector[3].c_str());
    return true;
}

std::string Container::get_value(std::string &key) {
    char *str = ht_get(data, key.c_str());
    if (!str)
        return std::string("");
    else
        return ht_get(data, key.c_str());
}
