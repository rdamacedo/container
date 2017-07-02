#ifndef CONTAINERS_HASHKEY_H
#define CONTAINERS_HASHKEY_H

#include <cstddef>
#include <functional>

#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define FIRSTH 37 /* also prime */


template<typename K>
struct KeyHash {
    unsigned long operator()(const K &key, size_t table_size) const {
        std::hash<K> hash;
        return hash(key) % table_size;
    }
};


struct FloatKeyHash {
    unsigned long operator()(const float &k, size_t table_size) const {
        std::string s = std::to_string(k);
        std::hash<std::string> hash;
        return (unsigned long) hash(s) % table_size;
    }
};

#endif //CONTAINERS_HASHKEY_H
