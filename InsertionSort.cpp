#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <ctime>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"

using namespace std;

int main() {
    ifstream inFile;
    inFile.open ("MTNdata.csv", ios::out | ios::app);//read in file
    if(!inFile.is_open())//check if the file is open
    {
        cout << "Failed to open file" << endl;
        return 1;
    }

    // populate the vector with the data from your data set
    cout << "How many data points would you like to input?" << endl;
    int length;
    cin >> length;

    vector<string> tmp(length);
    vector<int> v(length);
    LinkedList list = LinkedList();
    int index = 0;
    string temp;
    getline(inFile, temp);//define getline
    while(index<length) {
        getline(inFile, temp, ',');//gets a line from the file
        tmp.at(index) = temp;//converts temp to int and stores in v
        getline(inFile, temp, '\n');
        index++;
    }

    for(int i = 0; i < length; i++){
      cout << tmp.at(i);}

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
}