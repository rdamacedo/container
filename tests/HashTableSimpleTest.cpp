#include <iostream>
#include <assert.h>
#include "../hashtable/HashTable.h"

using namespace std;


int main() {
    HashTable<int, std::string, KeyHash<int>> hmap;
    hmap.put(1, "1");
    hmap.put(2, "2");
    hmap.put(3, "3");

    string value;
    bool result = hmap.get(2, value);
    assert(result);
    assert(value == "2");

    result = hmap.get(3, value);
    assert(result);
    assert(value == "3");

    hmap.remove(3);
    result = hmap.get(3, value);
    assert(!result);
}