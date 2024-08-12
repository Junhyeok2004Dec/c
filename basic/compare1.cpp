// 10430
// acmicpc

#include <iostream>

int main()

{
int A, B, C;
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    std::cout << (A+B)%C << "\n" <<  ((A%C) + (B%C))%C << "\n" << (A*B)%C << "\n" << ((A%C) * (B%C))%C;
    return 0;
}