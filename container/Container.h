#ifndef CONTAINERS_CONTAINER_H
#define CONTAINERS_CONTAINER_H


#include <string>
#include <iostream>
#include "../hashtable/HashTable.h"
#include "../utils/Utils.h"

class Container {


public:

    Container(std::string name, InternalType keyType, InternalType valueType, size_t tableSize);

    virtual ~Container();

    bool set_pair(std::string &line, std::vector<std::string> &command_vector);

    std::string get_value(std::string &key);

    std::string &getName() {
        return _name;
    };

    InternalType getKeyType() {
        return _keyType;
    }

    InternalType getValueType() {
        return _keyType;
    }


private:
    std::string _name;
    InternalType _keyType;
    InternalType _valueType;
    size_t _tableSize;
    HashTable<std::string, std::string, KeyHash<std::string>> *stringStringTable;
    HashTable<std::string, float, KeyHash<std::string>> *stringFloatTable;
    HashTable<std::string, int, KeyHash<std::string>> *stringIntTable;
    HashTable<float, float, FloatKeyHash> *floatFloatTable;
    HashTable<float, int, FloatKeyHash> *floatIntTable;
    HashTable<float, std::string, FloatKeyHash> *floatStringTable;
    HashTable<int, float, KeyHash<int>> *intFloatTable;
    HashTable<int, int, KeyHash<int>> *intIntTable;
    HashTable<int, std::string, KeyHash<int>> *intStringTable;

    Container(const Container &p);

    Container &operator=(const Container &p);
};


#endif //CONTAINERS_CONTAINER_H
