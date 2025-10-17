#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"  // only needed if your compiler setup requires it
#include <vector>
#include <string>
using namespace std;

int main(void) {
    cout << "----- TESTING CONSTRUCTORS -----\n";

    // Default constructor
    BigNum num1;
    cout << "num1 (default): ";
    num1.print(); // expect 0

    // String constructor with leading zeros
    BigNum num2("00011122233344");
    cout << "num2 (string with leading zeros): ";
    num2.print(); // expect 11,122,233,344

    // Integer constructor
    BigNum num3(333222111);
    cout << "num3 (int constructor): ";
    num3.print(); // expect 333,222,111

    // Negative string constructor
    BigNum num4("-000987654321");
    cout << "num4 (negative string): ";
    num4.print(); // expect -987,654,321

    // Negative integer constructor
    BigNum num5(-7654321);
    cout << "num5 (negative int): ";
    num5.print(); // expect -7,654,321

    // Copy constructor
    BigNum num6(num2);
    cout << "num6 (copy of num2): ";
    num6.print(); // expect 11,122,233,344

    cout << "\n----- TESTING INPUT FUNCTION -----\n";
    BigNum num7;
    cout << "Enter a number: ";
    num7.input();
    cout << "You entered: ";
    num7.print();

    cout << "\n----- TESTING EQUALITY & COMPARISON -----\n";
    cout << "num2 == num6 : " << num2.equals(num6) << endl; // expect 1
    cout << "num2 != num6 : " << num2.notEquals(num6) << endl; // expect 0
    cout << "num2 > num4  : " << num2.greaterThan(num4) << endl; // expect 1
    cout << "num4 < num2  : " << num4.lessThan(num2) << endl; // expect 1
    cout << "num5 < num4  : " << num5.lessThan(num4) << endl; // both negative, num5 > num4? check logic

    cout << "\n----- TESTING ASSIGNMENT OPERATOR (=) -----\n";
    BigNum num8;
    num8 = num3;
    cout << "num8 (assigned from num3): ";
    num8.print(); // expect same as num3

    cout << "\n----- TESTING COPY FUNCTION -----\n";
    BigNum num9;
    num9.copy(num5);
    cout << "num9 (copied from num5): ";
    num9.print(); // expect same as num5

    cout << "\n----- TESTING ZEROFY -----\n";
    cout << "Before zerofy: ";
    num9.print();
    num9.zerofy();
    cout << "After zerofy: ";
    num9.print(); // expect 0

    cout << "\n----- TESTING INVALID STRING HANDLING -----\n";
    BigNum invalid("12a34b");
    cout << "Invalid input (12a34b) becomes: ";
    invalid.print(); // expect 0

    cout << "\n----- EDGE CASES -----\n";
    BigNum zero1("0000");
    BigNum zero2(0);
    cout << "zero1: "; zero1.print();
    cout << "zero2: "; zero2.print();
    cout << "zero1 == zero2 : " << zero1.equals(zero2) << endl; // expect 1

    BigNum negZero("-0000");
    cout << "negZero (should normalize to 0): ";
    negZero.print(); // expect 0

    cout << "\n----- ALL TESTS COMPLETE -----\n";

    return 0;
}
