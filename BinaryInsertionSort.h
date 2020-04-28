#ifndef BINARYINSERTIONSORT_H
#define BINARYINSERTIONSORT_H

#include <vector>
#include "StockValue.h"
using namespace std;

int binarySearch(vector<StockValue> a, StockValue item, int low, int high);
void insertionSort(vector<StockValue> &a, int n);

#endif //BINARYINSERTIONSORT_H
