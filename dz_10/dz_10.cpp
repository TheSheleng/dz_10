#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date test_1(1, 2, 1);
    Date test_2(1, 1, 1);

    ++test_1; // 2 1 1
    --test_2; // 31 12 0

    test_1 = test_2 + 9; // 10 1 1
    test_2 = test_1 - 5; // 5 1 1

    test_1 += 10; // 20 1 1
    test_2 -= 4; // 1 1 1

    test_1.print(); cout << endl;
    test_2.print(); cout << endl;

    cout << (test_1 > test_2) << endl; //true
    cout << (test_1 < test_2) << endl; //false
    cout << (test_1 >= test_2) << endl; //true
    cout << (test_1 <= test_2) << endl; //true
    cout << (test_1 == test_2) << endl; //false
    cout << (test_1 != test_2) << endl; //true
}