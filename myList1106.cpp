//
// Created by 28943 on 2019/11/6.
//

#include "myList1106.h"
#include <iostream>
using namespace std;

int main()
{
    km::list<int> l(4, 5);
    int arr[5] = { 1, 3, 5, 7, 9 };
    km::list<int> l2(arr, arr + 5);
    km::list<int> l3 = l2;

    for (auto i = l3.Begin(); i != l3.End(); i++)
    {
        cout << *i << ' ';
    }

    return 0;
}


