#include "Item.h"

Item::Item(int specializationCode, int shift) : specializationCode(specializationCode), shift(shift) {}

Item::Item() {
    specializationCode = -1;
    shift = -1;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
    if (item.specializationCode != -1) {
        os << "(" << item.specializationCode << ", " << item.shift << "); ";
    }
    else {
        os << "Item not found";
    }
    return os;
}
