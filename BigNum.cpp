#include <iostream>
#include "BigNum.h"
#include <cstring>
#include <vector>

// Default Constructor
BigNum::BigNum(){
    value.push_back('0'); // push_back adds the value at the end
    negative = false;
}

// Copy Constructor
BigNum::BigNum(const BigNum& bigNum){
    value = bigNum.value;
    negative = bigNum.negative;
}

// Constructor using a string
BigNum::BigNum(const std::string& bigStr){
    if(bigStr.empty()){
        value.push_back('0');
        negative = false;
        return;
    }

    // Set negative to true if the first char is '-'
    if(bigStr[0] == '-') negative = true;
    else negative = false;
    
    int startIndex = 0;
    if(bigStr[0] == '-'){
        startIndex = 1;
    }

    // Ignore all the leading zeros to maintain representation
    int leadingZeros = startIndex;
    while(leadingZeros < bigStr.size() && bigStr[leadingZeros] == '0') leadingZeros++;

    // if leadingZeros == bigStr.size, all the numbers entered are 0
    if(leadingZeros == bigStr.size()){
        value.push_back('0');
        negative = false;
        return;
    }

    // Adds the remaining digits given through the parameter
    for( ; leadingZeros<bigStr.size(); leadingZeros++){
        if(!(bigStr[leadingZeros] >= '0' && bigStr[leadingZeros] <= '9')){
            clear();
            value.push_back('0'); // If any of the characters in the string aren't 0-9, sets the value to 0
            negative = false;
            return;
        }
        value.push_back(bigStr[leadingZeros]);
    }
}

// Constructor using integer as the parameter
BigNum::BigNum(const int num){
    // Handle sign
    if (num < 0) {
        negative = true;
    } else {
        negative = false;
    }

    int temp = num;
    if (negative) temp = -temp; // if negative, make positive

    // Handle zero
    if (temp == 0) {
        value.push_back('0');
        return;
    }

    // Find the highest power of 10 smaller than or equal to temp
    int mod = 1;
    while (temp / mod >= 10) {
        mod *= 10;
    }

    // Extract digits (most significant to least significant)
    while (mod > 0) {
        int digit = temp / mod; // get the leading digit
        value.push_back(static_cast<char>('0' + digit)); // store as char
        temp %= mod; // remove that digit
        mod /= 10;
    }
}

// Sets the value to whatever number is inputted
void BigNum::input(){
    clear();
    int num;
    std::cin>>num;
    BigNum tmp(num);
    value = tmp.value;
    negative = tmp.negative;
}

// Outputs the value stored
void BigNum::print(){
    if(negative)std::cout<<'-';
    for(int i = 0; i < value.size(); i++){
        // Printing ','
        if((value.size() - (i)) % 3 == 0 && i != 0){
            std::cout<<',';
        }
        //std::cout<<value[i];
        std::cout<<value.at(i); // Read online that using .at(index) is better
    }
    std::cout<<"\n";
}

// Destructor
BigNum::~BigNum(){
    clear();
}

// Clearing the value of a vector
void BigNum::clear(){
    value.clear(); // Clears the vector
    negative = false;
}


// Overloaded the '=' operator
void BigNum::operator=(const BigNum& bigNum) {
    if (this != &bigNum){
        value = bigNum.value;
        negative = bigNum.negative;
    }
}

// Copies a BigNum to another
void BigNum::copy(const BigNum& bigNum){
    if (this != &bigNum){
        value = bigNum.value;
        negative = bigNum.negative;
    }
}

void BigNum::zerofy(){
    clear();
    value.push_back('0');
}
// ==============================================

// ===== Arithmetic Operations: Addition =====
void BigNum::increment(){
    // Use add in it
}

// Adding two BigNums (assuming the numbers can be either positive or negative)
BigNum BigNum::add(const BigNum& bigNum){
    BigNum result;
    
    // If the signs are different use subtraction
    if (negative && !bigNum.negative) {
        // (-A) + B = B - A
        BigNum tmpThis = *this;
        tmpThis.negative = false;           // make positive for subtraction
        BigNum tmpBig = bigNum; // make a non-const copy
        //result = tmpBig.subtract(tmpThis);  // use non-const copy
        return result;
    }

    if (!negative && bigNum.negative) {
        // A + (-B) = A - B
        BigNum tmpBig = bigNum;
        tmpBig.negative = false;            // remove sign for subtraction
        BigNum tmpThis = *this; // make a non const copy
        //result = tmpThis.subtract(tmpBig);
        return result;
    }

    // If the signs are the same
    result.negative = negative;

    int i = value.size() - 1;
    int j = bigNum.value.size() - 1;
    int carry = 0;

    // Insert digits at the front
    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = 0;
        if (i >= 0) {
            digitA = value[i] - '0';
        }

        int digitB = 0;
        if (j >= 0) {
            digitB = bigNum.value[j] - '0';
        }

        int total = digitA + digitB + carry;
        carry = total / 10;
        total %= 10;

        // Insert at the front to avoid reversing and leading zeros
        result.value.insert(result.value.begin(), '0' + total);

        i--;
        j--;
    }

    return result;
}
// ==============================================

// ===== Arithmetic Operations: Subtraction =====

// ==============================================

// ===== Comparison Operations =====

bool BigNum::equals(const BigNum& bigNum){
    return(value == bigNum.value && negative == bigNum.negative);
}

bool BigNum::notEquals(const BigNum& bigNum){
    return!(value == bigNum.value && negative == bigNum.negative);
}

bool BigNum::lessThan(const BigNum& bigNum){
    // returns false if this number is positive and the other negative
    // returns true if this number is negative and the other positive
    if(negative != bigNum.negative) return negative;

    if(!negative){ // If both positive
        // Compare Size First
        if(value.size() != bigNum.value.size()){
            return (value.size() < bigNum.value.size());
        }

        for(int i = 0; i < value.size(); i++){
            if(value.at(i) != bigNum.value.at(i)){
                return(value.at(i) < bigNum.value.at(i));
            }
        }

    }else{ // If both negative
        // Compare Size First
        if(value.size() != bigNum.value.size()){
            return (value.size() > bigNum.value.size());
        }

        for(int i = 0; i < value.size(); i++){
            if(value.at(i) != bigNum.value.at(i)){
                return(value.at(i) > bigNum.value.at(i));
            }
        }
    }
}

bool BigNum::greaterThan(const BigNum& bigNum){
    // Checks if they aren't equal and if this isn't less than the parameter
    return (!equals(bigNum) && !lessThan(bigNum));
}
// ==============================================