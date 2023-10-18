#include "Specialization.h"
#include "iostream"

Specialization::Specialization(int _specializationCode, std::string &_heeName) {
    specializationCode = _specializationCode;
    heeName = _heeName;
}

Specialization::Specialization() {
    specializationCode = -1;
    heeName = "Not found";
}

bool Specialization::operator==(const Specialization &rhs) const {
    return specializationCode == rhs.specializationCode &&
           heeName == rhs.heeName;
}

bool Specialization::operator!=(const Specialization &rhs) const {
    return !(rhs == *this);
}

bool Specialization::operator<(const Specialization &rhs) const {
    return (this->specializationCode < rhs.specializationCode);
}

std::ostream &operator<<(std::ostream &os, const Specialization &specialization) {
    os << specialization.specializationCode << " " << specialization.heeName;
    return os;
}

void Specialization::serialize(std::ostream& stream) const {
    stream.write(reinterpret_cast<const char*>(&specializationCode), sizeof(int));
    int nameSize = static_cast<int>(heeName.size());
    stream.write(reinterpret_cast<const char*>(&nameSize), sizeof(int));
    stream.write(heeName.c_str(), nameSize);
}

bool Specialization::deserialize(std::istream& stream) {
    if (!stream.read(reinterpret_cast<char*>(&specializationCode), sizeof(int))) return false;
    int nameSize;
    if (!stream.read(reinterpret_cast<char*>(&nameSize), sizeof(int))) return false;
    heeName.resize(nameSize);
    if (!stream.read(&heeName[0], nameSize)) return false;
    return true;
}
