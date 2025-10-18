#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"
#include <fstream>
using namespace std;

int main() {
    cout << "=== File I/O Tests for BigNum ===\n";

    // === Test 1: Simple number ===
    {
        BigNum num;
        ofstream outFile("test1.txt");
        outFile << "123456789";
        outFile.close();

        num.inputFromFile("test1.txt");
        cout << "Read from file: ";
        num.print(); // Expected: 123,456,789

        num.printToFile("out1.txt");
        cout << "Written to file out1.txt\n";
    }

    // === Test 2: Negative number ===
    {
        BigNum num;
        ofstream outFile("test2.txt");
        outFile << "-987654321";
        outFile.close();

        num.inputFromFile("test2.txt");
        cout << "Read from file: ";
        num.print(); // Expected: -987,654,321

        num.printToFile("out2.txt");
        cout << "Written to file out2.txt\n";
    }

    // === Test 3: Zero ===
    {
        BigNum num;
        ofstream outFile("test3.txt");
        outFile << "0";
        outFile.close();

        num.inputFromFile("test3.txt");
        cout << "Read from file: ";
        num.print(); // Expected: 0

        num.printToFile("out3.txt");
        cout << "Written to file out3.txt\n";
    }

    // === Test 4: Invalid input ===
    {
        BigNum num;
        ofstream outFile("test4.txt");
        outFile << "12a34"; // Invalid
        outFile.close();

        try {
            num.inputFromFile("test4.txt");
            cout << "Read from file: ";
            num.print(); // Should not reach here
        } catch (const exception &e) {
            cout << "Caught exception for invalid input: " << e.what() << endl;
        }
    }

    // === Test 5: Read, modify, write ===
    {
        BigNum num;
        ofstream outFile("test5.txt");
        outFile << "9999";
        outFile.close();

        num.inputFromFile("test5.txt");
        cout << "Read from file: ";
        num.print(); // Expected: 9,999

        num.increment();
        cout << "After increment: ";
        num.print(); // Expected: 10,000

        num.printToFile("out5.txt");
        cout << "Written updated number to out5.txt\n";
    }

    return 0;
}
