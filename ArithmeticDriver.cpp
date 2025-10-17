#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"
#include <vector>
using namespace std;

int main() {
    // Test 1: Both positive, same number of digits
    BigNum a1("1234");
    BigNum b1("5678");
    BigNum sum1 = a1.add(b1);
    cout << "1234 + 5678 = ";
    sum1.print();  // Expected: 6912

    // Test 2: Different lengths
    BigNum a2("999");
    BigNum b2("1");
    BigNum sum2 = a2.add(b2);
    cout << "999 + 1 = ";
    sum2.print();  // Expected: 1000

    // Test 3: Both negative, same length
    BigNum a3("-123");
    BigNum b3("-877");
    BigNum sum3 = a3.add(b3);
    cout << "-123 + -877 = ";
    sum3.print();  // Expected: -1000

    // Test 4: Both negative, different length
    BigNum a4("-999");
    BigNum b4("-1");
    BigNum sum4 = a4.add(b4);
    cout << "-999 + -1 = ";
    sum4.print();  // Expected: -1000

    // Test 5: Large numbers
    BigNum a5("999999999");
    BigNum b5("1");
    BigNum sum5 = a5.add(b5);
    cout << "999999999 + 1 = ";
    sum5.print();  // Expected: 1000000000

    // Test 6: Adding zero
    BigNum a6("12345");
    BigNum b6("0");
    BigNum sum6 = a6.add(b6);
    cout << "12345 + 0 = ";
    sum6.print();  // Expected: 12345

    return 0;
}
