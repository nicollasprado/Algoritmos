#include <iostream>
#include <iomanip>

int fat(int num){
    int factorial = 1;
    for(int i=2; i <= num; i++){
        factorial = factorial * i;
    }
    return factorial;
}

int partition(double *a, int left, int right){
    double pivot = a[right]; // pivot vai ser o ultimo valor do array
    int i = left - 1; // i não deve começar no 0

    for(int j=left; j < right; j++){
        if(a[j] <= pivot){ // se J for menor que o pivot, soma i e inverte os valores de i e j
            i++;
            double aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }

    // no final, troca o pivot com o valor de i+1 que será o maior valor do array
    double aux = a[i+1];
    a[i+1] = a[right];
    a[right] = aux;
    return i+1; // retorna o maior valor do array
}

void quickSort(double *a, int left, int right){
    if(left < right){
        int pivot = partition(a, left, right); // retornará o maior valor do array
        quickSort(a, left, pivot-1); // ordenará recursivamente a parte da esquerda do pivot
        quickSort(a, pivot+1, right); // ordenará recursivamente a parte da direita do pivot
    }
}

void reverse(double *a, int arraySize){
    int j = arraySize-1;  
    for(int i=0; i < arraySize/2; i++){
        double aux = a[j];
        a[j] = a[i];
        a[i] = aux;
        j--;
    }
}

int main(){
    int qtTests, chosenAvg;
    for(int i=0; i < 10; i++){
        std::cin >> qtTests >> chosenAvg;
        double testsRes[qtTests];
        for(int j=0; j < qtTests; j++){
            std::cin >> testsRes[j];
        }
        // testes divididos 3 em 3 -> Combinação sem repetição
        int qtSubgroups = fat(qtTests) / (fat(3) * fat(qtTests - 3));
        double averages[qtSubgroups];
        int avgsIndex = 0;
        int g = 0;  int j = g+1;  int k = j+1;
        for(; g < qtTests-1; g++){
            for(; j < qtTests-1; j++){
                for(; k < qtTests-1; k++){
                    if(g != j && g != k && j != k){
                        averages[avgsIndex] = (testsRes[i] + testsRes[j] + testsRes[k]) / 3.0;
                        std::cout << "a= " << g << " b= " << j << " c= " << k << std::endl;
                        avgsIndex++;
                    }
                }
                if(g != j && g != k && j != k){
                    averages[avgsIndex] = (testsRes[i] + testsRes[j] + testsRes[k]) / 3.0;
                    std::cout << "a= " << g << " b= " << j << " c= " << k << std::endl;
                    avgsIndex++;
                }
                k = j+1;
            }
            if(g != j && g != k && j != k){
                averages[avgsIndex] = (testsRes[i] + testsRes[j] + testsRes[k]) / 3.0;
                std::cout << "a= " << g << " b= " << j << " c= " << k << std::endl;
                avgsIndex++;
            }
            j = g+1;
        }
        
        // print
        for(int l=0; l < qtTests; l++){
            std::cout << "testsRes: " << std::setprecision(2) << testsRes[l] << std::endl;
        }
        quickSort(averages, 0, qtSubgroups); // Ordenará do menor pro maior o array das médias
        reverse(averages, qtSubgroups); // Inverte o arr
        for(int m=0; m < qtSubgroups; m++){
            std::cout << std::setprecision(2) << averages[m] << std::endl;
        }
        for(int n=0; n < qtTests; n++){
            std::cout << "testsRes: " << std::setprecision(2) << testsRes[n] << std::endl;
        }
        std::cout << std::setprecision(2) << averages[chosenAvg-1] << std::endl;

    }
    return 0;
}