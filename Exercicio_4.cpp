#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <ctime>

#define ID_SENSOR_1 0x19
#define ID_SENSOR_2 0x76    

struct SENSOR
{
    uintptr_t id;
    float valores[5];
    float mediaTemperatua;

    void calcularMedia()
    {
        float soma = 0;
        for (int i = 0; i < 5; i++)
        {
            soma += valores[i];
        }
        mediaTemperatua = soma / 5;
    }

    void receberValores(float *valores)
    {
        for (int i = 0; i < 5; i++)
        {
            this->valores[i] = valores[i];
        }
    }

    void exebirTemperatura()
    {
        if (mediaTemperatua >= 30)
        {
            std::cout << "Temperatura do sensor 1 acima de 30 graus, temperatura normal" << std::endl;
        }
        else
        {
            std::cout << "Temperatura do sensor 1 abaixo de 30 graus, ixfrio ne kk" << std::endl;
        }
    }
};

float *gerarVetor()
{
    float *vetor = (float *)malloc(5 * sizeof(float));
    for (int i = 0; i < 5; i++)
    {
        vetor[i] = static_cast<float>(std::rand()) / RAND_MAX * 60.0;
    }
    return vetor;
}

int main()
{
    std::srand(std::time(0));
    SENSOR sensor1;
    SENSOR sensor2;

    sensor1.id = ID_SENSOR_1;
    sensor2.id = ID_SENSOR_2;

    float *valores1 = gerarVetor();
    float *valores2 = gerarVetor();

    sensor1.receberValores(valores1);
    sensor2.receberValores(valores2);

    std::cout << "Valores do sensor 1: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << sensor1.valores[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Valores do sensor 2: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << sensor2.valores[i] << " ";
    }
    std::cout << std::endl;

    sensor1.calcularMedia();
    sensor2.calcularMedia();

    sensor1.exebirTemperatura();
    sensor2.exebirTemperatura();

    std::cout << "Valor do endereco de memoria do sensor 1: " << std::showbase << std::hex << sensor1.id << std::endl;
    std::cout << "Valor do endereco de memoria do sensor 2: " << std::showbase << std::hex << sensor2.id << std::endl;

    free(valores1);
    free(valores2);
}