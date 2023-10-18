#include "FileManager.h"
#include <iostream>

using namespace std;

FileManager::FileManager(string filename) {
    filepath += filename;
}

void FileManager::fillHashTable(HashTable table) {
    ifstream input(filepath);
    Specialization obj;

    int curShift = 0;
    while (obj.deserialize(input)) {
        table.insertElement(Item(obj.specializationCode, curShift));
        curShift++;
    }
}

Specialization FileManager::readOnShift(int shift) {
    ifstream file(filepath, std::ios::binary | std::ios::in | std::ios::out);
    Specialization obj;
    file.seekg(shift * sizeof(Specialization));
    obj.deserialize(file);
    file.close();
    return obj;
}

void FileManager::createBinaryFile(const string& filepath_from, const string& filepath_to) {
    ifstream fin(filepath_from, ios::binary);
    ofstream fout(filepath_to, ios::binary);
    int n;
    string s;
    Specialization t;
    while (!fin.eof()) {
        fin >> n >> s;
        Specialization(n, s).serialize(fout);
    }
    fin.close();
    fout.close();
}

void FileManager::deleteOnShift(int shift) {
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