#ifndef SIAOD3_BUCKET_H
#define SIAOD3_BUCKET_H
#include <vector>
#include "Specialization.h"
#include "Item.h"

using namespace std;

class Bucket {
public:
    vector<Item> chain;

    Bucket();
    explicit Bucket(const Item& first);

    Item getElementByKey(int key);
    void insertElement(const Item& element);
    bool deleteElementByKey(int key);

    int getIndexByKey(int key);
};


#endif //SIAOD3_BUCKET_H
