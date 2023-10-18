#include "Bucket.h"

Bucket::Bucket() = default;

Bucket::Bucket(const Item& first) {
    chain.push_back(first);
}

bool Bucket::deleteElementByKey(int key) {
    int index = getIndexByKey(key);
    if (index != -1) {
        chain.erase(next(chain.begin(), getIndexByKey(key)));
        return true;
    }
    return false;
}

void Bucket::insertElement(const Item& element) {
    chain.push_back(element);
}

Item Bucket::getElementByKey(int key) {
    int ind = getIndexByKey(key);
    if (ind == -1) return {};
    return chain[ind];
}

int Bucket::getIndexByKey(int key) {
    for (int i = 0; i < chain.size(); ++i) {
        if (chain[i].specializationCode == key)
            return i;
    }
    return -1;
}
