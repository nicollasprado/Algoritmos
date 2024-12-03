/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int fat(int num){
    int factorial = 1;
    for(int i=2; i <= num; i++){
        factorial = factorial * i;
    }
    return factorial;
}

int main()
{
    int qtTests, chosenAvg;
    for(int i=0; i < 10; i++){
        std::cin >> qtTests >> chosenAvg;
        double testsRes[qtTests];
        int auxInt;
        for(int j=0; j < qtTests; j++){
            std::cin >> auxInt;
            testsRes[j] = (double) auxInt;
        }
        // testes divididos 3 em 3 -> Combinação sem repetição
        int qtSubgroups = fat(qtTests) / (fat(3) * fat(qtTests - 3));
        std::cout << "Subgroups: " << qtSubgroups << std::endl;
        double averages[qtSubgroups];
        double subgroups[qtSubgroups][3];
        for(int z=0; z < qtSubgroups; z++){
            
            // NAO FINALIZADO

        } 
        
        // print
        for(int x=0; x < qtSubgroups; x++){
            std::cout << averages[x] << std::endl;
        }
    }
    

    return 0;
}