//
// Created by Will Branan on 4/9/2020.
//
#include <iostream>
#include "StockValue.h"
using namespace std;
StockValue::StockValue(){//default constructor
    date = "";
    open = -1;
    high = -1;
    low = -1;
    close = -1;
    volume = -1;
}
StockValue::StockValue(string d, double o, double h, double l, double c, double v){//alternate constructor
    date = d;
    open = o;
    high = h;
    low = l;
    close = c;
    volume = v;
}

ostream& operator<<(ostream& os, const StockValue& stock) {//overloading << operator
    os << stock.date << " open: " << stock.open << ", day high: " << stock.high << ", day low: " << stock.low << ", close: "<< stock.close << ", day volume: " << stock.volume << endl;
    return os;
}

bool StockValue::operator<=(const StockValue &v){//overloading less than or equal to operator
    return this->volume <= v.volume;
}
bool StockValue::operator>(const StockValue &v) {//overloading greater than operator
    return this->volume > v.volume;
}

bool StockValue::operator==(const StockValue &v) {//overloading equal to operator
    return this->volume == v.volume;

}

StockValue& StockValue::operator=(const StockValue &copy){
    this->date = copy.date;
    this->open = copy.open;
    this->high = copy.high;
    this->low = copy.low;
    this->close = copy.close;
    this->volume = copy.volume;
}
