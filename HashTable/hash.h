#ifndef HASH_H
#define HASH_H

#include <string>

using std::string;

class Hash {
private:
    static const int table_size = 10;

    // TODO: change to std::pair
    typedef struct item {
        string name;
        string color;
        item* next;
    } item;

    item* hash_table[table_size];

public:
    // Constructor: initializes hash_table to empty values
    Hash();

    // Destructor: frees memory
    ~Hash();

    // Simple hash function: returns index based on key param
    int hash(string key);

    // Inserts item into proper slot in hash_table
    void insert(string name, string item);

    // Check if name is in hash_table
    bool search(string name);

    // Removes the first instance of an item from list
    bool remove(string name);

    // Helper functions

    // Returns a pointer to an allocated and initialized item struct
    item* createItem(string name, string color);

    // Release allocated memory from item struct
    void destroyItem(item* myitem);
};


#endif