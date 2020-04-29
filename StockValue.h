//
// Created by Will Branan on 4/9/2020.
//
#include <iostream>
using namespace std;

#ifndef BINARYINSERTIONSORT_STOCKVALUE_H
#define BINARYINSERTIONSORT_STOCKVALUE_H
class StockValue{
public:
    StockValue();
    StockValue(string date, double open, double high, double low, double close, int volume);
    StockValue &operator=(const StockValue &copy);
    friend ostream& operator<<(ostream& os, const StockValue& stock);
    bool operator<=(const StockValue &v);
    bool operator>(const StockValue &v);
    bool operator==(const StockValue &v);
    string date;
    double open;
    double high;
    double low;
    double close;
    int volume;
};

#endif //BINARYINSERTIONSORT_STOCKVALUE_H
