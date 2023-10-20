#include "FileManager.h"
#include <iostream>

using namespace std;

FileManager::FileManager(const string& filename) {
    filepath += filename;
    ifstream fin(filepath);
    if (!fin.is_open()) {
        throw string("No such file in directory");
    }
    fin.close();
}

void FileManager::fillHashTable(HashTable &table) {
    ifstream input(filepath, ios::binary);
    Specialization obj;

    long long int curShift = 0;
    while (obj.deserialize(input)) {
        table.insertElement(Item(obj.specializationCode, curShift));
        curShift = (long long int)(input.tellg());
    }
}

Specialization FileManager::readOnShift(long long int shift) {
    ifstream file(filepath, ios::binary);
    Specialization obj;
    file.seekg(shift, ios::beg);
    obj.deserialize(file);
    file.close();
    return obj;
}

void FileManager::createBinaryFile(const string& filepath_from, const string& filepath_to) {
    ifstream fin("C:/Users/Maxim/CLionProjects/siaod3/" + filepath_from);
    ofstream fout("C:/Users/Maxim/CLionProjects/siaod3/" + filepath_to, ios::binary);
    int n, cnt;
    string s;
    Specialization t;
    fin >> cnt;
    for (int i = 0; i < cnt; ++i) {
        fin >> n >> s;
        Specialization(n, s).serialize(fout);
    }
    fin.close();
    fout.close();
}

void FileManager::deleteOnShift(long long int shift) {
    string tempname = "C:/Users/Maxim/CLionProjects/siaod3/temp.bin";

    ifstream input(filepath, ios::binary);
    ofstream output(tempname, ios::binary);

    Specialization obj;
    int currObj = 0;
    while (obj.deserialize(input)) {
        if (currObj != shift) {
            obj.serialize(output);
        }
        currObj++;
    }

    input.close();
    output.close();

    std::remove(filepath.c_str());
    std::rename(tempname.c_str(), filepath.c_str());

}