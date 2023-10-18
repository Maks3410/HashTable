#ifndef SIAOD3_SPECIALIZATION_H
#define SIAOD3_SPECIALIZATION_H
#include <string>
#include <ostream>

class Specialization {
public:
    int specializationCode;
    std::string heeName;

    Specialization(int _specializationCode, std::string& _heeName);
    Specialization();

    bool operator==(const Specialization &rhs) const;
    bool operator!=(const Specialization &rhs) const;
    bool operator<(const Specialization &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Specialization &specialization);

    void serialize(std::ostream &stream) const;

    bool deserialize(std::istream &stream);
};


#endif //SIAOD3_SPECIALIZATION_H
