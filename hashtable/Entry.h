#ifndef CONTAINERS_ENTRY_H
#define CONTAINERS_ENTRY_H
#include <cstddef>

template <typename K, typename V>
class Entry
{
public:
    Entry(const K &key, const V &value) :
        _key(key), _value(value), _next(NULL)
    {
    }

    K getKey() const
    {
        return _key;
    }

    V getValue() const
    {
        return _value;
    }

    void setValue(V value)
    {
        _value = value;
    }

    Entry *getNext() const
    {
        return _next;
    }

    void setNext(Entry *next)
    {
        _next = next;
    }

private:
    // key-value pair
    K _key;
    V _value;
    // next bucket with the same key
    Entry *_next;
    // disallow copy and assignment
    Entry(const Entry &);
    Entry & operator=(const Entry &);
};
#endif //CONTAINERS_ENTRY_H
