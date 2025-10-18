#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"
#include <vector>
using namespace std;

int main() {
    cout << "=== Mixed Sign Addition/Subtraction Tests ===" << endl;

    BigNum m1("500");
    BigNum m2("-200");
    cout << "500 + (-200) = ";
    m1.add(m2).print(); // Expected: 300

    BigNum m3("200");
    BigNum m4("-500");
    cout << "200 + (-500) = ";
    m3.add(m4).print(); // Expected: -300

    BigNum m5("-200");
    BigNum m6("500");
    cout << "-200 + 500 = ";
    m5.add(m6).print(); // Expected: 300

    BigNum m7("-500");
    BigNum m8("200");
    cout << "-500 + 200 = ";
    m7.add(m8).print(); // Expected: -300

    BigNum m9("-123");
    BigNum m10("-876");
    cout << "-123 + -876 = ";
    m9.add(m10).print(); // Expected: -999

    BigNum m11("999999999");
    BigNum m12("1");
    cout << "999999999 + 1 = ";
    m11.add(m12).print(); // Expected: 1000000000

    BigNum m13("12345");
    BigNum m14("0");
    cout << "12345 + 0 = ";
    m13.add(m14).print(); // Expected: 12345

    BigNum m15("-6789");
    BigNum m16("0");
    cout << "-6789 + 0 = ";
    m15.add(m16).print(); // Expected: -6789

    BigNum zero1(0);
    BigNum zero2(0);
    cout << "0 + 0 = ";
    zero1.add(zero2).print(); // Expected: 0

    cout << "=== BigNum Subtraction Tests (1 case per condition) ===" << endl;

    // 1. Positive - Positive (result positive)
    BigNum a1("500"), b1("200");
    cout << "500 - 200 = "; a1.subtract(b1).print(); // Expected: 300

    // 2. Positive - Positive (result negative)
    BigNum a2("200"), b2("500");
    cout << "200 - 500 = "; a2.subtract(b2).print(); // Expected: -300

    // 3. Negative - Negative (result negative)
    BigNum a3("-500"), b3("-200");
    cout << "-500 - (-200) = "; a3.subtract(b3).print(); // Expected: -300

    // 4. Negative - Negative (result positive)
    BigNum a4("-200"), b4("-500");
    cout << "-200 - (-500) = "; a4.subtract(b4).print(); // Expected: 300

    // 5. Positive - Negative
    BigNum a5("200"), b5("-300");
    cout << "200 - (-300) = "; a5.subtract(b5).print(); // Expected: 500

    // 6. Negative - Positive
    BigNum a6("-200"), b6("300");
    cout << "-200 - 300 = "; a6.subtract(b6).print(); // Expected: -500

    // 7. Zero cases
    BigNum z1("0"), z2("0");
    cout << "0 - 0 = "; z1.subtract(z2).print(); // Expected: 0

    // 8. Large numbers
    BigNum a7("123456789123456789"), b7("123456789123456788");
    cout << "123456789123456789 - 123456789123456788 = "; a7.subtract(b7).print(); // Expected: 1

    cout << "0 - 0 = ";
    zero1.subtract(zero2).print(); // Expected: 0


    // ===== Multiplication Tests =====
    cout << "\n=== Multiplication Tests ===" << endl;

    BigNum mul1("12");
    BigNum mul2("3");
    cout << "12 * 3 = ";
    mul1.multiply(mul2).print(); // Expected: 36

    BigNum mul3("12345");
    BigNum mul4("0");
    cout << "12345 * 0 = ";
    mul3.multiply(mul4).print(); // Expected: 0

    BigNum mul5("1");
    BigNum mul6("9999");
    cout << "1 * 9999 = ";
    mul5.multiply(mul6).print(); // Expected: 9999

    BigNum mul7("12345");
    BigNum mul8("6789");
    cout << "12345 * 6789 = ";
    mul7.multiply(mul8).print(); // Expected: 83810205

    BigNum mul9("-123");
    BigNum mul10("-456");
    cout << "-123 * -456 = ";
    mul9.multiply(mul10).print(); // Expected: 56088

    BigNum mul11("-50");
    BigNum mul12("20");
    cout << "-50 * 20 = ";
    mul11.multiply(mul12).print(); // Expected: -1000

    BigNum mul13("999999999");
    BigNum mul14("9");
    cout << "999999999 * 9 = ";
    mul13.multiply(mul14).print(); // Expected: 8999999991

    BigNum mul15("-123456");
    BigNum mul16("0");
    cout << "-123456 * 0 = ";
    mul15.multiply(mul16).print(); // Expected: 0

    BigNum mul17("-999");
    BigNum mul18("999");
    cout << "-999 * 999 = ";
    mul17.multiply(mul18).print(); // Expected: -998001

    BigNum mul19("0");
    BigNum mul20("0");
    cout << "0 * 0 = ";
    mul19.multiply(mul20).print(); // Expected: 0


    // ===== Division Tests =====
    cout << "\n=== Division Tests ===" << endl;

    // Simple divisions
    BigNum d1("10");
    BigNum d2("2");
    cout << "10 / 2 = ";
    d1.div(d2).print(); // Expected: 5

    BigNum d3("15");
    BigNum d4("3");
    cout << "15 / 3 = ";
    d3.div(d4).print(); // Expected: 5

    BigNum d5("100");
    BigNum d6("25");
    cout << "100 / 25 = ";
    d5.div(d6).print(); // Expected: 4

    // Non-even division (integer result)
    BigNum d7("7");
    BigNum d8("2");
    cout << "7 / 2 = ";
    d7.div(d8).print(); // Expected: 3

    // Dividing by a larger number
    BigNum d9("5");
    BigNum d10("10");
    cout << "5 / 10 = ";
    d9.div(d10).print(); // Expected: 0

    // Large numbers
    BigNum d11("123456789");
    BigNum d12("12345");
    cout << "123456789 / 12345 = ";
    d11.div(d12).print(); // Expected: 10000 (approx integer division)

    // Negative divisions
    BigNum d13("-100");
    BigNum d14("25");
    cout << "-100 / 25 = ";
    d13.div(d14).print(); // Expected: -4

    BigNum d15("100");
    BigNum d16("-25");
    cout << "100 / -25 = ";
    d15.div(d16).print(); // Expected: -4

    BigNum d17("-100");
    BigNum d18("-25");
    cout << "-100 / -25 = ";
    d17.div(d18).print(); // Expected: 4

    // Division by zero test (should handle gracefully)
    BigNum d19("123");
    BigNum d20("0");
    cout << "123 / 0 = ";
    d19.div(d20).print(); // Expected: CANNOT DIVIDE BY 0! Ans = 0

    // Zero divided by something
    BigNum d21("0");
    BigNum d22("123");
    cout << "0 / 123 = ";
    d21.div(d22).print(); // Expected: 0

    // ===== Modulo Tests =====
    cout << "\n=== Modulo Tests ===" << endl;

    // Simple modulo
    BigNum mod1("10");
    BigNum mod2("3");
    cout << "10 % 3 = ";
    mod1.mod(mod2).print(); // Expected: 1

    BigNum mod3("15");
    BigNum mod4("4");
    cout << "15 % 4 = ";
    mod3.mod(mod4).print(); // Expected: 3

    // Dividend smaller than divisor
    BigNum mod5("5");
    BigNum mod6("10");
    cout << "5 % 10 = ";
    mod5.mod(mod6).print(); // Expected: 5

    // Dividend equal to divisor
    BigNum mod7("100");
    BigNum mod8("100");
    cout << "100 % 100 = ";
    mod7.mod(mod8).print(); // Expected: 0

    // Large numbers
    BigNum mod9("123456789");
    BigNum mod10("12345");
    cout << "123456789 % 12345 = ";
    mod9.mod(mod10).print(); // Expected: 6789

    // Negative dividend
    BigNum mod11("-100");
    BigNum mod12("30");
    cout << "-100 % 30 = ";
    mod11.mod(mod12).print(); // Expected: -10

    // Negative divisor
    BigNum mod13("100");
    BigNum mod14("-30");
    cout << "100 % -30 = ";
    mod13.mod(mod14).print(); // Expected: 10

    // Both negative
    BigNum mod15("-100");
    BigNum mod16("-30");
    cout << "-100 % -30 = ";
    mod15.mod(mod16).print(); // Expected: -10

    // Zero dividend
    BigNum mod17("0");
    BigNum mod18("123");
    cout << "0 % 123 = ";
    mod17.mod(mod18).print(); // Expected: 0

    // Modulo by zero
    BigNum mod19("123");
    BigNum mod20("0");
    cout << "123 % 0 = ";
    try {
        mod19.mod(mod20).print(); // Expected: CANNOT MOD BY 0! Ans = 0
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }


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
