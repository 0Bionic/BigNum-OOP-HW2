#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"
#include <vector>
using namespace std;

int main() {
    cout << "=== Mixed Sign Addition/Subtraction Tests ===" << endl;

    // Positive + Negative (result positive)
    BigNum m1("500");
    BigNum m2("-200");
    cout << "500 + (-200) = ";
    m1.add(m2).print(); // Expected: 300

    // Positive + Negative (result negative)
    BigNum m3("200");
    BigNum m4("-500");
    cout << "200 + (-500) = ";
    m3.add(m4).print(); // Expected: -300

    // Negative + Positive (result positive)
    BigNum m5("-200");
    BigNum m6("500");
    cout << "-200 + 500 = ";
    m5.add(m6).print(); // Expected: 300

    // Negative + Positive (result negative)
    BigNum m7("-500");
    BigNum m8("200");
    cout << "-500 + 200 = ";
    m7.add(m8).print(); // Expected: -300

    // Negative + Negative
    BigNum m9("-1234");
    BigNum m10("-876");
    cout << "-1234 + -876 = ";
    m9.add(m10).print(); // Expected: -2110

    // Positive + Positive (large numbers)
    BigNum m11("999999999");
    BigNum m12("1");
    cout << "999999999 + 1 = ";
    m11.add(m12).print(); // Expected: 1000000000

    // Mixed with zero
    BigNum m13("12345");
    BigNum m14("0");
    cout << "12345 + 0 = ";
    m13.add(m14).print(); // Expected: 12345

    BigNum m15("-6789");
    BigNum m16("0");
    cout << "-6789 + 0 = ";
    m15.add(m16).print(); // Expected: -6789

    // Adding zeros
    BigNum zero1(0);
    BigNum zero2(0);
    cout << "0 + 0 = ";
    zero1.add(zero2).print(); // Expected: 0

    // Subtract zeros
    cout << "0 - 0 = ";
    zero1.subtract(zero2).print(); // Expected: 0

    // ===== Increment Tests =====
    cout << "\n=== Increment Tests ===" << endl;

    BigNum inc1(0);
    inc1.increment();
    cout << "0 incremented = ";
    inc1.print(); // Expected: 1

    BigNum inc2(7);
    inc2.increment();
    cout << "7 incremented = ";
    inc2.print(); // Expected: 8

    BigNum inc3(129);
    inc3.increment();
    cout << "129 incremented = ";
    inc3.print(); // Expected: 130

    BigNum inc4(999);
    inc4.increment();
    cout << "999 incremented = ";
    inc4.print(); // Expected: 1000

    BigNum inc5("123456789");
    inc5.increment();
    cout << "123456789 incremented = ";
    inc5.print(); // Expected: 123456790

    BigNum inc6(0);
    inc6.increment();
    cout << "0 incremented = ";
    inc6.print(); // Expected: 1

    return 0;
}
