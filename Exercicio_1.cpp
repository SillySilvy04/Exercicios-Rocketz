#include <iostream> //para inputs e outputs
#include <cstdlib>//para rand() e srand()
#include <ctime>//para time()
#include <typeinfo>//para typeid()
#include <iomanip>//para setprecision()

int main(){
    std::srand(std::time(0)); //seed aleatória

    float nota1 = static_cast<float>(std::rand()) / RAND_MAX * 10.0; //gera um número aleatório entre 0 e 10
    float nota2 = static_cast<float>(std::rand()) / RAND_MAX * 10.0; //gera um número aleatório entre 0 e 10
    float media = (nota1+nota2)/2;

    std::cout << std::fixed << std::setprecision(2); //fixa a precisão de casas decimais
    std::cout << "Nota 1: " << nota1 << std::endl;
    std::cout << "Nota 2: " << nota2 << std::endl;
    std::cout << "O tipo de dados utilizado e " << typeid(nota1).name() << " e seu tamanho em bytes e: " << sizeof(nota1) << std::endl;
    std::cout << "Media: " << media << std::endl;
    if(media > 5){
        std::cout << "Status: Aprovado" << std::endl;
    }else{
        std::cout << "Status: Reprovado" << std::endl;
    }
}