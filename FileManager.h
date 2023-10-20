#ifndef SIAOD3_FILEMANAGER_H
#define SIAOD3_FILEMANAGER_H
#include <string>
#include "HashTable.h"
#include <fstream>

using namespace std;

class FileManager {
private:
    string filepath = "C:/Users/Maxim/CLionProjects/siaod3/";
public:
    explicit FileManager(const string& filename);

    void fillHashTable(HashTable &table);
    Specialization readOnShift(long long int shift);
    static void createBinaryFile(const string& filepath_from, const string& filepath_to);

    void deleteOnShift(long long int shift);
};


#endif //SIAOD3_FILEMANAGER_H
