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
    clear(); // Ensure a clean state
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
    if(num < 0){
        negative = true;
    }else negative = false;

    int temp = num;
    if (negative) temp = -temp; // making num positive

    if (temp == 0) {
        value.push_back('0');
        return;
    }

    // Calculation for finding individual digits
    int mod = 10, n = 0;
    while(!(temp / mod < 10)){
        mod *= 10;
        n++;
    }

    // Extract digits (most significant to least significant)
    for(int i = 0; i <= n; i++){
        int digit = temp / mod; // get the leading digit
        value.push_back(static_cast<char>('0' + digit)); // store as char
        temp = temp % mod; // remove that digit
        mod /= 10;
        if (mod == 0) break;
    }
}

// Sets the value to whatever number is inputted
void BigNum::input(){
    clear();
    int num;
    std::cin>>num;
    BigNum tmp(num);
    *this = tmp;
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
    if (this != &bigNum) {
        value = bigNum.value;
        negative = bigNum.negative;
    }
}

// Copies a BigNum to another
void BigNum::copy(const BigNum& bigNum){
    if (this != &bigNum) {
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
    int carry = 0;
}

// Adding two BigNums (assuming the numbers can be either positive or negative)
BigNum BigNum::add(const BigNum& bigNum){
    BigNum result;
    result.negative = (negative && bigNum.negative); // If both numbers are negative

}
// ==============================================

// ===== Arithmetic Operations: Subtraction =====

// ==============================================

// ===== Compariso Operations =====

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