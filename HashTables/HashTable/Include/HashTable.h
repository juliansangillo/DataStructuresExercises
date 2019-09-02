#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <iterator>
#include <vector>

#include "TableExceptions.h"

/**
 * @brief A structure that stores a pair of variables, a string key and some value associated with
 * the key. The value could be of any type.
 * 
 * @tparam T the type of the value in the KeyValuePair
 **/
template<class T>
struct KeyValuePair {

    std::string key;
    T value;

};

/**
 * @brief A HashTable implementation that will store key-value pairs in memory and can read
 * back the values when given the key. Keys are strings and must be unique. Values can be
 * of any type.
 * 
 * @tparam T the data type of the values in the HashTable
 **/
template<class T>
class HashTable {
    private:
        const int SIZE = 5000;
        
        std::list<KeyValuePair<T>>* buckets;

        const int hash(std::string key) const {

            int hashValue = 0;
            
            for(const char &c : key)
                hashValue += c;

            return hashValue % SIZE;
        }

    public:
        /**
         * @brief Constructor that reserves the memory space needed by the HashTable.
         **/
        HashTable() {

            this->buckets = new std::list<KeyValuePair<T>>[this->SIZE];

        }

        ~HashTable() {

            delete[] buckets;

        }

        /**
         * @brief Adds a new key-value pair to the HashTable.
         * 
         * @param key a string that uniquely identifies the value and its location in the HashTable
         * @param value the data to be stored at the location identified by the key
         * @throws DuplicateKey
         **/
        void add(std::string key, T value) {

            KeyValuePair<T> pair = {key, value};
            const int address = hash(key);

            for(KeyValuePair<T> pair : this->buckets[address])
                if(pair.key == key)
                    throw DuplicateKey(key);

            this->buckets[address].push_back(pair);

        }

        /**
         * @brief Deletes a key-value pair from the HashTable.
         * 
         * @param key the unique key of the data to remove
         * @throws ElementDoesNotExist
         **/
        void remove(std::string key) {

            const int address = hash(key);

            for(auto i = this->buckets[address].begin(); i != this->buckets[address].end(); i++)
                if(i->key == key) {
                    this->buckets[address].erase(i);
                    return;
                }

            throw ElementDoesNotExist(key);
        }

        /**
         * @brief Assigns a new value to the given unique key in the HashTable.
         * 
         * @param key the unique key of the data to change
         * @param value the new value to reassign to the given key
         * @throws ElementDoesNotExist
         **/
        void set(std::string key, T value) {

            const int address = hash(key);

            for(auto i = this->buckets[address].begin(); i != this->buckets[address].end(); i++)
                if(i->key == key) {
                    i->value = value;
                    return;
                }

            throw ElementDoesNotExist(key);
        }

        /**
         * @brief Retrieves the value stored in the HashTable at the given key.
         * 
         * @param key the unique key of the data to be retrieved
         * @returns the value at the location of the given key
         * @throws ElementDoesNotExist
         **/
        T get(std::string key) {

            const int address = hash(key);

            for(KeyValuePair<T> pair : this->buckets[address])
                if(pair.key == key)
                    return pair.value;

            throw ElementDoesNotExist(key);
        }

        /**
         * @brief Checks whether data for a particular key exists in the HashTable.
         * 
         * @param key the unique key to check if it exists
         * @returns true if the key exists in the HashTable or false otherwise
         **/
        bool exists(std::string key) {

            const int address = hash(key);

            for(KeyValuePair<T> pair : this->buckets[address])
                if(pair.key == key)
                    return true;
            return false;
        }

        /**
         * @brief Retrieves all the keys that exist in the HashTable.
         * 
         * @returns a vector holding all the keys in the HashTable
         **/
        std::vector<std::string> keys() {

            std::vector<std::string> _keys;

            for(int i = 0; i < SIZE; i++)
                for(KeyValuePair<T> pair : this->buckets[i])
                    _keys.push_back(pair.key);

            return _keys;
        }

        /**
         * @brief Retrieves all the values that exist in the HashTable.
         * 
         * @returns a vector holding all the values in the HashTable
         **/
        std::vector<T> values() {

            std::vector<T> _values;

            for(int i = 0; i < SIZE; i++)
                for(KeyValuePair<T> pair : this->buckets[i])
                    _values.push_back(pair.value);

            return _values;
        }

        /**
         * @brief Overloaded '[]' that performs a get operation on the given key and returns
         * a constant. This version is read-only.
         * 
         * @param key the unique key to retrieve the value for
         * @returns the value at the given key
         **/
        const T operator[] (std::string key) const {

            return get(key);
        }

        /**
         * @brief Overloaded '[]' that retrieves a reference to the value at the given key in
         * the HashTable. The reference allows the value to be set by other operators.
         * 
         * @param key the unique key to access
         * @returns a reference to the value at the given key
         * @throws ElementDoesNotExist
         **/
        T& operator[] (std::string key) {

            const int address = hash(key);

            for(KeyValuePair<T>& pair : this->buckets[address])
                if(pair.key == key)
                    return pair.value;

            throw ElementDoesNotExist(key);
        }
};

#endif