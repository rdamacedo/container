#ifndef CONTAINERS_HASHTABLE_H
#define CONTAINERS_HASHTABLE_H

#include <cstddef>
#include <cstdlib>
#include "Entry.h"
#include "HashKey.h"


// Hash map class template
template<typename K, typename V, typename F>
class HashTable {
public:
    HashTable(size_t tableSize) :
        table(),
        hashFunc(),
        tableSize(tableSize) {

        table = (Entry<K, V> **) malloc(sizeof(Entry<K, V> *) * tableSize);
        for (int i = 0; i < (int) tableSize; i++) {
            table[i] = NULL;
        }

    }

    ~HashTable() {
        // destroy all buckets one by one
        for (size_t i = 0; i < tableSize; ++i) {
            Entry<K, V> *entry = table[i];

            while (entry != NULL) {
                Entry<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }

            table[i] = NULL;
        }

        free(table);
    }

    bool get(const K &key, V &value) {
        unsigned long hashValue = hashFunc(key, tableSize);

        int i = 0;
        while (table[hashValue] != NULL && i < (int) tableSize) {
            if (table[hashValue]->getKey() == key) {
                value = table[hashValue]->getValue();
                return true;
            }

            hashValue = (hashValue + 1) % tableSize;
            i++;
        }

        return false;
    }

    void put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key, tableSize);

        int i = 0;
        while (table[hashValue] != NULL && table[hashValue]->getKey() != key && i < (int) tableSize) {
            hashValue = (hashValue + 1) % tableSize;
            i++;
        }

        if (table[hashValue] != NULL)
            delete table[hashValue];

        table[hashValue] = new Entry<K, V>(key, value);
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key, tableSize);
        Entry<K, V> *prev = NULL;
        Entry<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            // key not found
            return;

        } else {
            if (prev == NULL) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();

            } else {
                prev->setNext(entry->getNext());
            }

            delete entry;
        }
    }

private:
    HashTable(const HashTable &other);

    const HashTable &operator=(const HashTable &other);

    Entry<K, V> **table;
    F hashFunc;
    size_t tableSize;
};

#endif //CONTAINERS_HASHTABLE_H
