#include <iostream>
#include "BigNum.h"
#include "BigNum.cpp"
#include <cstring>
#include <vector>

int main(void){
    BigNum num1;
    BigNum num2("00011122233344");
    BigNum num3(333222111);
    BigNum num4(num2);
    BigNum num5("-00011122233344");
    BigNum num6(-333222111);
    num1.print();
    num2.print();
    num3.print();
    num4.print();
    num5.print();
    num6.print();
    num6.zerofy();
    num6.print();
}