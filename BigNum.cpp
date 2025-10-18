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
// Incremenets 1
void BigNum::increment() {
    // use add in it
    BigNum one(1);
    operator=(add(one)); // Add 1 and assign the result
}

// Adding two BigNums (assuming the numbers can be either positive or negative)
BigNum BigNum::add(const BigNum& bigNum) {
    BigNum result;

    // Different Signs
    if (negative && !bigNum.negative) {
        BigNum tmpThis = *this;
        tmpThis.negative = false;
        BigNum tmpBig = bigNum;
        result = tmpBig.subtract(tmpThis);
        return result;
    }
    if (!negative && bigNum.negative) {
        BigNum tmpBig = bigNum;
        tmpBig.negative = false;
        BigNum tmpThis = *this;
        result = tmpThis.subtract(tmpBig);
        return result;
    }

    // Same Signs
    result.negative = negative; // result sign matches operands

    int i = value.size() - 1;
    int j = bigNum.value.size() - 1;
    int carry = 0;
    std::vector<char> sum; // stores the value in reverse

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
        total = total % 10;

        sum.push_back('0' + total);

        i--; j--;
    }

    // Reverse digits to get correct order
    for (int k = sum.size() - 1; k >= 0; --k) {
        result.value.push_back(sum[k]);
    }
    if (result.value.size() > 1 && result.value[0] == '0')
        result.value.erase(result.value.begin());
    return result;
}

// Adds an integer to BigNum
BigNum BigNum::add(const int num){
    BigNum temp(num);
    return add(temp);
}

// Adds a BigNum in place
void BigNum::compoundAdd(const BigNum& bigNum){
    *this = add(bigNum);
}

// Adds an integer in place
void BigNum::compoundAdd(const int num) {
    BigNum temp(num);
    *this = add(temp);
}
// ==============================================

// ===== Arithmetic Operations: Subtraction =====
// Decrements 1
void BigNum::decrement(){
    // use subtract in it
    BigNum one(1);
    operator=(subtract(one)); // Subtract 1 and assign the result
}

// Subtract another BigNum from this one
BigNum BigNum::subtract(const BigNum& bigNum) {
    BigNum result;

    // Different signs mean that subtraction becomes addition
    if (negative && !bigNum.negative) {
        BigNum tmpThis = *this;
        tmpThis.negative = false;
        result = tmpThis.add(bigNum);
        result.negative = true;
        return result;
    }
    if (!negative && bigNum.negative) {
        BigNum tmpBig = bigNum;
        tmpBig.negative = false;
        result = add(tmpBig);
        return result;
    }

    // Same signs
    const BigNum* larger;
    const BigNum* smaller;
    bool resultNeg;

    if (lessThan(bigNum)) {      // *this->value < bigNum.value
        larger = &bigNum;
        smaller = this;
        resultNeg = !negative;    // Result sign is opposite of this
    } else {
        larger = this;
        smaller = &bigNum;
        resultNeg = negative;     // Result sign same as this
    }

    result.negative = resultNeg;

    int i = larger->value.size() - 1;
    int j = smaller->value.size() - 1;
    int borrow = 0;

    while (i >= 0 || j >= 0 || borrow > 0) {
        int digitL = 0;
        if (i >= 0) digitL = larger->value[i] - '0';
        int digitS = 0;
        if (j >= 0) digitS = smaller->value[j] - '0';

        int diff = digitL - digitS - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        // Only insert digits if not a leading zero or result already has digits
        if (diff != 0 || result.value.size() > 0 || (i == 0 && j <= 0 && borrow == 0)) {
            result.value.insert(result.value.begin(), '0' + diff);
        }
        i--; j--;
    }

    // If nothing was inserted (0 - 0), add a single zero
    if (result.value.size() == 0) {
        result.value.push_back('0');
        result.negative = false;
    }

    result.value.pop_back();
    return result;
}

// Subtracts an integer from BigNum
BigNum BigNum::subtract(const int num){
    BigNum temp(num);
    return subtract(temp);
}

// Subtracts a BigNum in place
void BigNum::compoundSubtract(const BigNum& bigNum){
    *this = subtract(bigNum);
}

// Subtracts an integer in place
void BigNum::compoundSubtract(const int num) {
    BigNum temp(num);
    *this = subtract(temp);
}
// ==============================================

// ===== Arithmetic Operation: Multiplication =====

BigNum BigNum::multiply(const BigNum& bigNum) {
    // Handle multiplication by zero
    if ((value.size() == 1 && value[0] == '0') ||
        (bigNum.value.size() == 1 && bigNum.value[0] == '0')) {
        return BigNum("0");
    }

    int n = value.size();
    int m = bigNum.value.size();
    std::string product(n + m, '0');

    // Perform long multiplication
    for (int i = n - 1; i >= 0; --i) {
        int carry = 0;
        int digitA = value[i] - '0';

        for (int j = m - 1; j >= 0; --j) {
            int digitB = bigNum.value[j] - '0';
            int sum = (product[i + j + 1] - '0') + digitA * digitB + carry;

            product[i + j + 1] = (sum % 10) + '0';
            carry = sum / 10;
        }

        product[i] = ((product[i] - '0') + carry) + '0';
    }

    BigNum result(product);
    result.negative = (negative != bigNum.negative);
    return result;
}
// ==============================================

// ===== Arithmetic Operation: Division =====

BigNum BigNum::div(const BigNum& bigNum) {
    BigNum result("0");

    // Division by zero check
    if (bigNum.value.size() == 1 && bigNum.value[0] == '0') {
        throw std::runtime_error("Division by zero");
    }

    // If this < bigNum, answer is always 0
    BigNum lhs = *this;
    BigNum rhs = bigNum;
    lhs.negative = false;
    rhs.negative = false;

    if (lhs.lessThan(rhs)) {
        return result;
    }

    std::string quotient;
    BigNum remainder("0");

    // long division
    for (char digit : lhs.value) {
        // remainder = remainder * 10 + current digit
        remainder = remainder.multiply(BigNum("10"));
        remainder = remainder.add(BigNum(std::string(1, digit))); // makes a BigNum with the current digit and adds it to the remainder

        int count = 0;
        while (!remainder.lessThan(rhs) || !remainder.equals(rhs)) {
            remainder = remainder.subtract(rhs);
            count++;
        }

        quotient.push_back('0' + count);
    }

    BigNum finalResult(quotient);

    // If bot bigNums have opposite signs, then negative will be true
    finalResult.negative = (negative != bigNum.negative);

    // If answer is 0
    if (finalResult.value.size() == 1 && finalResult.value[0] == '0') {
        finalResult.negative = false;
    }

    return finalResult;
}



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
    return (!equals(bigNum) && !lessThan(bigNum));
}
// ==============================================