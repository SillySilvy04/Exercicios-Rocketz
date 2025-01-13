#include <iostream>

int main(){
    int N;

    std::cout << "Digite o numero da piramide: " << std::endl;
    std::cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}