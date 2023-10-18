#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int bucketsCount) : bucketsCount(bucketsCount) {
    buckets = vector<Bucket>(bucketsCount);
};

int HashTable::getHash(int key) const {
    return key % bucketsCount;
}

int HashTable::getBucketsCount() const {
    return bucketsCount;
}

void HashTable::insertElement(const Item& element) {
    buckets[getHash(element.specializationCode)].insertElement(element);
    elementsCount++;

    if (double(elementsCount) / bucketsCount > 0.75) resize(getNewBucketsNumber());
}

Item HashTable::findElementByKey(int key) {
    return buckets[getHash(key)].getElementByKey(key);
}

void HashTable::deleteElementByKey(int key) {
    if (buckets[getHash(key)].deleteElementByKey(key)) elementsCount--;
}

int HashTable::getNewBucketsNumber() {
    for (int tableSize : tableSizes) {
        if (tableSize > bucketsCount) return tableSize;
    }
    return tableSizes[15];
}

void HashTable::resize(int newSize) {
    vector<Bucket> newBuckets(newSize);
    bucketsCount = newSize;
    for (const auto& bucket : buckets) {
        for (const auto& element : bucket.chain) {
            newBuckets[getHash(element.specializationCode)].insertElement(element);
        }
    }
    buckets = newBuckets;
}

HashTable::HashTable() {
    buckets = vector<Bucket>(bucketsCount);
}

ostream &operator<<(ostream &os, const HashTable &table) {

    for (int i = 0; i < table.bucketsCount; ++i) {
        if (!table.buckets[i].chain.empty()) {
            os << i << ": ";
            for (auto item : table.buckets[i].chain) {
                os << item << " ";
            }

            std::cout << endl;
        }
    }
}
