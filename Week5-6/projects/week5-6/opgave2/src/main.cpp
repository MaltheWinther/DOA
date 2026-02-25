#include <iostream>

void triangle(int m, int n){
    if (m > n){
    return;
    }
    else {
        for (int i = 0; i < m; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
        triangle(m+1,n);
        for (int i = 0; i < m; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
   

    triangle(3,6);
    return 0;
}