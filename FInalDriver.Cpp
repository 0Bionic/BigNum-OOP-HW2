#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"
using namespace std;

int main() {
    cout << "==================== BigNum Comprehensive Test ====================\n";

    // ===== Constructors =====
    cout << "\n=== Constructor Tests ===\n";
    BigNum a;              // Default
    BigNum b("123456789"); // From string
    BigNum c(-98765);      // From int
    BigNum d(b);           // Copy constructor

    cout << "Default constructor (should be 0): ";
    a.print();

    cout << "String constructor (should be 123,456,789): ";
    b.print();

    cout << "Int constructor (should be -98,765): ";
    c.print();

    cout << "Copy constructor (should be 123,456,789): ";
    d.print();


    // ===== Assignment & Copy =====
    cout << "\n=== Copy and Assignment Tests ===\n";
    BigNum e;
    e = b;
    cout << "Assignment (should be 123,456,789): ";
    e.print();

    e.zerofy();
    cout << "After zerofy (should be 0): ";
    e.print();


    // ===== Increment / Decrement =====
    cout << "\n=== Increment & Decrement Tests ===\n";
    BigNum f("999");
    f.increment();
    cout << "999 incremented = ";
    f.print(); // Expected 1000

    BigNum g("1000");
    g.decrement();
    cout << "1000 decremented = ";
    g.print(); // Expected 999

    BigNum h("-1");
    h.increment();
    cout << "-1 incremented = ";
    h.print(); // Expected 0

    BigNum i("0");
    i.decrement();
    cout << "0 decremented = ";
    i.print(); // Expected -1


    // ===== Addition / Subtraction =====
    cout << "\n=== Addition & Subtraction Tests ===\n";
    BigNum add1("500");
    BigNum add2("-200");
    cout << "500 + (-200) = ";
    add1.add(add2).print(); // Expected 300

    BigNum sub1("1000");
    BigNum sub2("750");
    cout << "1000 - 750 = ";
    sub1.subtract(sub2).print(); // Expected 250

    BigNum sub3("-500");
    BigNum sub4("-300");
    cout << "-500 - (-300) = ";
    sub3.subtract(sub4).print(); // Expected -200


    // ===== Multiplication =====
    cout << "\n=== Multiplication Tests ===\n";
    BigNum m1("123");
    BigNum m2("456");
    cout << "123 * 456 = ";
    m1.multiply(m2).print(); // Expected 56088

    BigNum m3("-12");
    BigNum m4("12");
    cout << "-12 * 12 = ";
    m3.multiply(m4).print(); // Expected -144


    // ===== Division =====
    cout << "\n=== Division Tests ===\n";
    BigNum d1("100");
    BigNum d2("25");
    cout << "100 / 25 = ";
    d1.div(d2).print(); // Expected 4

    BigNum d3("7");
    BigNum d4("2");
    cout << "7 / 2 = ";
    d3.div(d4).print(); // Expected 3

    BigNum d5("-100");
    BigNum d6("25");
    cout << "-100 / 25 = ";
    d5.div(d6).print(); // Expected -4

    BigNum d7("0");
    BigNum d8("25");
    cout << "0 / 25 = ";
    d7.div(d8).print(); // Expected 0


    // ===== Modulo =====
    cout << "\n=== Modulo Tests ===\n";
    BigNum mod1("10");
    BigNum mod2("3");
    cout << "10 % 3 = ";
    mod1.mod(mod2).print(); // Expected 1

    BigNum mod3("15");
    BigNum mod4("4");
    cout << "15 % 4 = ";
    mod3.mod(mod4).print(); // Expected 3

    BigNum mod5("-100");
    BigNum mod6("30");
    cout << "-100 % 30 = ";
    mod5.mod(mod6).print(); // Expected -10


    // ===== Comparison =====
    cout << "\n=== Comparison Tests ===\n";
    BigNum c1("123");
    BigNum c2("456");
    BigNum c3("123");
    cout << "123 == 456 ? " << (c1.equals(c2) ? "true" : "false") << endl;
    cout << "123 == 123 ? " << (c1.equals(c3) ? "true" : "false") << endl;
    cout << "123 < 456 ? " << (c1.lessThan(c2) ? "true" : "false") << endl;
    cout << "456 > 123 ? " << (c2.greaterThan(c1) ? "true" : "false") << endl;


    // ===== Compound Add / Subtract =====
    cout << "\n=== Compound Add/Subtract Tests ===\n";
    BigNum comp1("50");
    BigNum comp2("25");
    comp1.compoundAdd(comp2);
    cout << "50 += 25 gives ";
    comp1.print(); // Expected 75

    comp1.compoundSubtract(BigNum("50"));
    cout << "75 -= 50 gives ";
    comp1.print(); // Expected 25


    // ===== File I/O Tests =====
    cout << "\n=== File I/O Tests ===\n";
    BigNum io1("12345678901234567890");
    io1.printToFile("output.txt");
    cout << "Wrote 12345678901234567890 to output.txt\n";

    BigNum io2;
    io2.inputFromFile("output.txt");
    cout << "Read from output.txt = ";
    io2.print();

    cout << "\nAll tests completed successfully.\n";
    return 0;
}
