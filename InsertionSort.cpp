#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <ctime>
#include "StockValue.h"
#include "LinkedList.h"
#include "BinaryInsertionSort.h"

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("MTNdata.csv");//read in file
    if(!inFile.is_open())//check if the file is open
    {
        cout << "Failed to open file." << endl;//prints error message if not open
        return 1;
    }

    vector<StockValue> v(3202);
    LinkedList L = LinkedList();

    // populate the vector with the data from your data set
    string temp, date, openS, highS, lowS, closeS, volumeS;
    getline(inFile, temp);
    int index = 0;
    while(!inFile.eof()) {
        if(!inFile.fail()){
        getline(inFile, date, ',');
        getline(inFile, openS, ',');
        getline(inFile, highS, ',');
        getline(inFile, lowS, ',');
        getline(inFile, closeS, ',');
        getline(inFile, volumeS, '\n');
        double open = atof(openS.c_str());
        double high = atof(highS.c_str());
        double low = atof(lowS.c_str());
        double close = atof(closeS.c_str());
        double volume = atof(volumeS.c_str());
        StockValue stockDay(date, open, high, low, close, volume);
        v.at(index) = stockDay;
        index++;
    }}
    inFile.close();

    // binary insertion sort
    clock_t start_binaryInsertionSort = clock();
    insertionSort(v, v.size());
    clock_t end_binaryInsertionSort = clock();

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // print out sorted list
    for (int i = 0; i < v.size(); i++) {
        //you should override << to YourClass
        cout << v[i] << endl;
    }

    clock_t start_LLInsertionSort = clock();
    L.InsertionSort();
    clock_t end_LLInsertionSort = clock();
    L.printList();

    double elapsed_BinaryInsertionSort = double(end_binaryInsertionSort - start_binaryInsertionSort) / CLOCKS_PER_SEC;
    cout << elapsed_BinaryInsertionSort << endl;
    double elapsed_LLinsertionSort = double(end_LLInsertionSort - start_LLInsertionSort) / CLOCKS_PER_SEC;
    cout << elapsed_LLinsertionSort << endl;

}