#ifndef SIAOD3_ITEM_H
#define SIAOD3_ITEM_H


#include <ostream>

class Item {
public:
    int specializationCode;
    long long int shift;

    Item(int specializationCode, long long int shift);

    Item();

    friend std::ostream &operator<<(std::ostream &os, const Item &item);
};


#endif //SIAOD3_ITEM_H
