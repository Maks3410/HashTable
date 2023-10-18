#include <iostream>
#include <fstream>
#include "Specialization.h"
#include <vector>
#include <algorithm>
#include <chrono>
#include <unistd.h>
#include "FileManager.h"

using namespace std;


class FileDoesntExistException{};

void readAndInsert(int shift, HashTable table, FileManager manager) {
    table.insertElement(Item(manager.readOnShift(shift).specializationCode, shift));
}

void deleteByKey(int key, HashTable table, FileManager manager) {
    table.deleteElementByKey(key);
    manager.deleteOnShift(table.findElementByKey(key).shift);
}

Specialization findInFile(int key, HashTable table, FileManager manager) {
    return manager.readOnShift(table.findElementByKey(key).shift);
}

void testHashTable() {
    HashTable table;
    cout << "Creating hash table, inserting elements:"
            "(0, 1), (101, 2), (50, 3), (151, 4), (202, 5)\n";
    table.insertElement(Item(0, 1));
    table.insertElement(Item(101, 2));
    table.insertElement(Item(50, 3));
    table.insertElement(Item(151, 4));
    table.insertElement(Item(202, 5));
    cout << table;

    cout << "Get element by key 0: " << table.findElementByKey(0) << endl;
    cout << "Get element by key 101: " << table.findElementByKey(101) << endl;
    cout << "Get element by key 50: " << table.findElementByKey(50) << endl;
    cout << "Get element by key 151: " << table.findElementByKey(151) << endl;
    cout << "Get element by key 202: " << table.findElementByKey(202) << endl;
    cout << "Get element by key 505: " << table.findElementByKey(505) << endl;

    cout << "Deleting by key 0, 151 and 1323" << endl;
    table.deleteElementByKey(0);
    table.deleteElementByKey(151);
    table.deleteElementByKey(1323);
    cout << table;

    cout << "Old buckets number: " << table.bucketsCount << endl;
    cout << "Resizing\n";
    table.resize(table.getNewBucketsNumber());
    cout << "New buckets number: " << table.bucketsCount << endl;

    cout << "Check elements after delete and resize:\n";
}

void testFileManager() {

}

int main() {

    testHashTable();
}
