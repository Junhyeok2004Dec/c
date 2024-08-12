// 2588
// acmicpc

#include <iostream>

int main() {

    int i1, i2;
    int l1, l2, l3, result;
    int digit;

    std::cin >> i1;
    std::cin >> i2;

    result = i1 * i2;
    
    digit = i2 / 100;
    l3 = i1 * digit; // 

    i2 -= digit * 100;
    
    digit = (i2 / 10);
    l2 = i1 * digit;

    i2 -= digit * 10;

    
    l1 = i2 * i1;

    std::cout << l1 << "\n" << l2 << "\n" << l3 << "\n" << result ;



}