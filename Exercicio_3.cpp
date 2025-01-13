#include <iostream> //para inputs e outputs
#include <cstdlib>//para rand() e srand()
#include <ctime>//para time()
#include <bitset>//para bitset()


int main(){
    std::srand(std::time(0)); //seed aleatória

    int numero1 = std::rand() % 32; //gera um número aleatório entre 0 e 31
    int numero2 = std::rand() % 32;

    int numero1DeslocadoDireita = numero1 >> 1;
    int numero1DeslocadoEsquerda = numero1 << 1;

    int numero2DeslocadoEsquerda = numero2 << 1;
    int numero2DeslocadoDireita = numero2 >> 1;

    std::bitset<5> comparacao(numero1 & numero2);

    std::bitset<5> binario1(numero1);
    std::bitset<5> binario2(numero2);
    std::bitset<6> binario1DeslocadoDireita(numero1DeslocadoDireita);
    std::bitset<6> binario1DeslocadoEsquerda(numero1DeslocadoEsquerda);
    std::bitset<6> binario2DeslocadoDireita(numero2DeslocadoDireita);
    std::bitset<6> binario2DeslocadoEsquerda(numero2DeslocadoEsquerda);

    std::cout << "Numero 1: " << numero1 << std::endl;
    std::cout << "Numero 2: " << numero2 << std::endl;

    std::cout << std::endl;

    std::cout << "Numero 1 em binario: " << binario1 << std::endl;
    std::cout << "Numero 2 em binario: " << binario2 << std::endl;

    std::cout << std::endl;

    std::cout << "Comparacao entre os numeros (bit a bit): " << comparacao << std::endl;

    std::cout << std::endl;

    std::cout << "Numero 1 deslocado para direita: " << numero1DeslocadoDireita << ", Em binario: " << binario1DeslocadoDireita <<  std::endl;
    std::cout << "Numero 1 deslocado para esquerda: " << numero1DeslocadoEsquerda << ", Em binario: " << binario1DeslocadoEsquerda << std::endl;
    std::cout << "Numero 2 deslocado para direita: " << numero2DeslocadoDireita << ", Em binario: " << binario2DeslocadoDireita << std::endl;
    std::cout << "Numero 2 deslocado para esquerda: " << numero2DeslocadoEsquerda << ", Em binario: " << binario2DeslocadoEsquerda << std::endl;

    std::cout << std::endl;

    if(numero1 % 2 == 1){
        std::cout << "O bit mais significativo do numero 1 esta ativo, invertendo o numero..." << std::endl;
        std::cout << "Numero 1 invertido: " << binario1.flip().to_string() << std::endl;
    }else{
        std::cout << "O bit mais significativo do numero 1 nao esta ativo" << std::endl;
    }
}
