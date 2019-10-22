//
// Created by 28943 on 2019/10/23.
//

#ifndef CPLUSPLUS_CPP_1022_H
#define CPLUSPLUS_CPP_1022_H

#include <iostream>
using namespace std;

class Datexx{
public:
    void SetDate(int year, int month, int day){
        _year = year;
        _month = month;
        _day = day;
    }

    void Display(int year, int month, int day){
        cout << _year <<"-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

#endif //CPLUSPLUS_CPP_1022_H
