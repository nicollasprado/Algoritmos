#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>


int * increase_capacity(int * data, int &capacity, int &size){
    int* new_array = new int[capacity+10];
    for (int i=0 ; i<size ; ++i)
    new_array[i] = data[i];
    int* old_array = data;
    delete [] old_array;
    capacity = capacity+10;
    return new_array;
}

int *push_back(int * data, int &capacity, int &size, int value){
    if (size==capacity)
        data = increase_capacity(data, capacity, size);
    data[size++]=value;
    return data;
}

int main(){
    int *data, size=0, capacity=10, qtTest=100;
    auto beg = std::chrono::high_resolution_clock::now();
    data = new int[capacity];

    std::ifstream testFile("testsFiles/teste-01.txt");
    
    for(int x=0; x < qtTest; x++){
        std::string line;
        std::getline(testFile, line);
        data = push_back(data, capacity, size, stoi(line));
        std::cout << "buffer= " << line << std::endl;
        line = "";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Quantidade de números lidos: " << size << std::endl;
    std::cout << "Tamanho do vetor: " << capacity << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cerr << "Tempo de processamento: " << duration.count() << " microseconds(s)"<< std::endl;
        /* ... */
    delete [] data;
    return 0;
}