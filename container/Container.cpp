
#include "Container.h"

bool Container::set_pair(std::string &line, std::vector<std::string> &command_vector) {
    if (check_add_command_formation(command_vector, line)) {
        if (!check_value_type(_keyType, command_vector[2])) {
            print_not_right_type(_keyType, line);
            return false;
        }
        if (!check_value_type(_valueType, command_vector[3])) {
            print_not_right_type(_valueType, line);
            return false;
        }
    }

    if (_keyType == InternalType::FLOAT && _valueType == InternalType::INT) {
        floatIntTable->put((const float &) atof(command_vector[2].c_str()), atoi(command_vector[3].c_str()));
    } else if (_keyType == InternalType::FLOAT && _valueType == InternalType::STRING) {
        floatStringTable->put((const float &) atof(command_vector[2].c_str()), command_vector[3]);
    } else if (_keyType == InternalType::FLOAT && _valueType == InternalType::FLOAT) {
        floatFloatTable->put((const float &) atof(command_vector[2].c_str()),
                             (const float &) atof(command_vector[3].c_str()));
    } else if (_keyType == InternalType::INT && _valueType == InternalType::STRING) {
        intStringTable->put(atoi(command_vector[2].c_str()), command_vector[3]);
    } else if (_keyType == InternalType::INT && _valueType == InternalType::FLOAT) {
        intFloatTable->put(atoi(command_vector[2].c_str()), (const float &) atof(command_vector[3].c_str()));
    } else if (_keyType == InternalType::INT && _valueType == InternalType::INT) {
        intIntTable->put(atoi(command_vector[2].c_str()), atoi(command_vector[3].c_str()));
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::STRING) {
        stringStringTable->put(command_vector[2], command_vector[3]);
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::FLOAT) {
        stringFloatTable->put(command_vector[2], (const float &) atof(command_vector[3].c_str()));
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::INT) {
        stringIntTable->put(command_vector[2], atoi(command_vector[3].c_str()));
    }

    printf("Entry inserted in container: %s key=%s value=%s\n", _name.c_str(), command_vector[2].c_str(),
           command_vector[3].c_str());
    return true;
}

std::string Container::get_value(std::string &key) {

    if (_keyType == InternalType::FLOAT && _valueType == InternalType::INT) {
        float _key = (float) atof(key.c_str());
        int _val = -1;
        if (floatIntTable->get(_key, _val)) {
            return std::to_string(_val);
        }
        return "";
    } else if (_keyType == InternalType::FLOAT && _valueType == InternalType::STRING) {
        float _key = (float) atof(key.c_str());
        std::string _val = "";
        floatStringTable->get(_key, _val);
        return _val;
    } else if (_keyType == InternalType::FLOAT && _valueType == InternalType::FLOAT) {
        float _key = (float) atof(key.c_str());
        float _val = -1;
        if (floatFloatTable->get(_key, _val)) {
            return std::to_string(_val);
        }
        return "";
    } else if (_keyType == InternalType::INT && _valueType == InternalType::STRING) {
        int _key = atoi(key.c_str());
        std::string _val = "";
        intStringTable->get(_key, _val);
        return _val;
    } else if (_keyType == InternalType::INT && _valueType == InternalType::FLOAT) {
        int _key = atoi(key.c_str());
        float _val = -1;
        if (intFloatTable->get(_key, _val)) {
            return std::to_string(_val);
        }
        return "";
    } else if (_keyType == InternalType::INT && _valueType == InternalType::INT) {
        int _key = atoi(key.c_str());
        int _val = -1;
        if (intIntTable->get(_key, _val)) {
            return std::to_string(_val);
        }
        return "";
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::STRING) {
        std::string _val = "";
        stringStringTable->get(key, _val);
        return _val;
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::FLOAT) {
        float _val = -1;
        if (stringFloatTable->get(key, _val)) {
            return std::to_string(_val);
        }
        return "";
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::INT) {
        int _val = -1;
        if (stringIntTable->get(key, _val)) {
            return std::to_string(_val);
        }
        return "";
    }
    return "";
}

Container::Container(std::string name, InternalType keyType, InternalType valueType, size_t tableSize) :
        _name(name),
        _keyType(keyType),
        _valueType(valueType),
        _tableSize(tableSize) {

    stringStringTable = NULL;
    stringFloatTable = NULL;
    stringIntTable = NULL;
    floatFloatTable = NULL;
    floatIntTable = NULL;
    floatStringTable = NULL;
    intFloatTable = NULL;
    intIntTable = NULL;
    intStringTable = NULL;

    if (_keyType == InternalType::FLOAT && _valueType == InternalType::INT) {
        floatIntTable = new HashTable<float, int, FloatKeyHash>(tableSize);
    } else if (_keyType == InternalType::FLOAT && _valueType == InternalType::STRING) {
        floatStringTable = new HashTable<float, std::string, FloatKeyHash>(tableSize);
    } else if (_keyType == InternalType::FLOAT && _valueType == InternalType::FLOAT) {
        floatFloatTable = new HashTable<float, float, FloatKeyHash>(tableSize);
    } else if (_keyType == InternalType::INT && _valueType == InternalType::STRING) {
        intStringTable = new HashTable<int, std::string, KeyHash<int>>(tableSize);
    } else if (_keyType == InternalType::INT && _valueType == InternalType::FLOAT) {
        intFloatTable = new HashTable<int, float, KeyHash<int>>(tableSize);
    } else if (_keyType == InternalType::INT && _valueType == InternalType::INT) {
        intIntTable = new HashTable<int, int, KeyHash<int>>(tableSize);
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::STRING) {
        stringStringTable = new HashTable<std::string, std::string, KeyHash<std::string>>(tableSize);
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::FLOAT) {
        stringFloatTable = new HashTable<std::string, float, KeyHash<std::string>>(tableSize);
    } else if (_keyType == InternalType::STRING && _valueType == InternalType::INT) {
        stringIntTable = new HashTable<std::string, int, KeyHash<std::string>>(tableSize);
    }

    printf("Containter created: %s key=%s value=%s N=%d\n", name.c_str(), type2string(_keyType),
           type2string(_valueType), (int) tableSize);
}

Container::~Container() {
    if (stringStringTable != NULL) {
        delete stringStringTable;
    }
    if (stringFloatTable != NULL) {
        delete stringFloatTable;
    }
    if (stringIntTable != NULL) {
        delete stringIntTable;
    }
    if (floatFloatTable != NULL) {
        delete floatFloatTable;
    }
    if (floatIntTable != NULL) {
        delete floatIntTable;
    }
    if (floatStringTable != NULL) {
        delete floatStringTable;
    }

    if (intFloatTable != NULL) {
        delete intFloatTable;
    }
    if (intIntTable != NULL) {
        delete intIntTable;
    }

    if (intStringTable != NULL) {
        delete intStringTable;
    }

}
