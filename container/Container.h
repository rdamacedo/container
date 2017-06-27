#ifndef CONTAINERS_CONTAINER_H
#define CONTAINERS_CONTAINER_H


#include <string>
#include "../hashtable/Hashtable.h"
#include "../utils/Utils.h"


class Container {

public:
    std::string name;
    std::string key_type;
    std::string value_type;
    int size;

    Container(const std::string &name, const std::string &key_type, const std::string &value_type, int size);

    bool set_pair(std::string &line, std::vector<std::string> &command_vector);

    std::string get_value(std::string &key);

private:
    hashtable_t *data;

};


#endif //CONTAINERS_CONTAINER_H
