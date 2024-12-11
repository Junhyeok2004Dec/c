#include <iostream>
#include <windows.h>


int main() {
    HANDLE hConsole;
    int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    for(k=1; k<255; k++) {

        SetConsoleTextAttribute(hConsole, k);
        std::cout << k << "d" ;

    }

    std::cin.get(); // Pause
    return 0;
}