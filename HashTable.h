#ifndef SIAOD3_HASHTABLE_H
#define SIAOD3_HASHTABLE_H
#include <vector>
#include <ostream>
#include "Bucket.h"

using namespace std;

class HashTable {
public:
    vector<int> tableSizes = {101, 211, 431, 863, 1733, 3467, 6947, 13901, 27803, 55609, 111227, 222461, 444929, 889871, 1779761, 3559537};
    int bucketsCount = tableSizes[0];
    int elementsCount = 0;
    vector<Bucket> buckets;

    HashTable();
    explicit HashTable(int bucketsCount);

    int getHash(int key) const;
    int getBucketsCount() const;

    void insertElement(const Item& element);
    Item findElementByKey(int key);
    void deleteElementByKey(int key);

    void resize(int newSize);

    int getNewBucketsNumber();

    friend ostream &operator<<(ostream &os, const HashTable &table);
};

#endif //SIAOD3_HASHTABLE_H
