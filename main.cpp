#include <iostream>
#include <fstream>
#include "Specialization.h"
#include <vector>
#include <algorithm>
#include <chrono>
#include <unistd.h>
#include "FileManager.h"

using namespace std;


void readAndInsert(int shift, HashTable &table, FileManager &manager) {
    table.insertElement(Item(manager.readOnShift(shift).specializationCode, shift));
}

void deleteByKey(int key, HashTable &table, FileManager &manager) {
    int shift = table.findElementByKey(key).shift;
    if (shift != -1) {
        manager.deleteOnShift(shift);
        table.deleteElementByKey(key);
    }
}

Specialization findInFile(int key, HashTable &table, FileManager &manager) {
    cout << table.findElementByKey(key).shift << endl;
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
    cout << table;
}

void testFileManager() {
    cout << "Creating bin file from txt file (input.txt)\n";
    FileManager::createBinaryFile("input.txt", "input.bin");

    try {
        cout << "Creating file manager on file abc.bin: ";
        FileManager fileManager("abc.bin");
    }
    catch (string e) {
        cout << e << endl;
    }

    try {
        cout << "Creating file manager on file input.bin: ";
        FileManager fileManager("input.bin");
        cout << "File manager created\n";
    }
    catch (string e) {
        cout << e << endl;
    }

    FileManager fileManager("input.bin");

    cout << "Try read object on shift 0: " << fileManager.readOnShift(0) << endl;
    cout << "Try read object on shift 14: " << fileManager.readOnShift(14) << endl;
    cout << "Try read object on shift 50000: " << fileManager.readOnShift(50000) << endl;

    cout << "Deleting element on shift 0\n";
    fileManager.deleteOnShift(0);
    cout << "Try read object on shift 0: " << fileManager.readOnShift(0) << endl;
}

void test() {
    FileManager::createBinaryFile("input.txt", "input.bin");

    FileManager fileManager("input.bin");
    HashTable table;

    fileManager.fillHashTable(table);
    cout << table;

    cout << "Searching in file by key 931: ";
    cout << findInFile(931, table, fileManager) << endl;

    cout << "Searching in file by key 22: ";
    cout << findInFile(22, table, fileManager) << endl;

    cout << "Try delete by key from table and from file:\n";
    deleteByKey(1897, table, fileManager);

    cout << "Searching in file by key 1897: ";
    cout << findInFile(1897, table, fileManager) << endl;

    cout << "Searching in hash table by key 1897: " << table.findElementByKey(1897) << endl;
    cout << "Reading file on shift 0: " << fileManager.readOnShift(14) << endl;
}

void bigDataTest() {
    FileManager fileManager("big_input.bin");
    HashTable table;
    fileManager.fillHashTable(table);

//    cout << table;

//    cout << table.elementsCount << endl;
//    cout << table.bucketsCount;

    cout << "Searching in file by key 18874390: ";
    cout << findInFile(18874390, table, fileManager) << endl;
}

int main() {
//    FileManager::createBinaryFile("file1000.txt", "file1000.bin");
//    testHashTable();
//    testFileManager();
//    test();
    bigDataTest();
}
