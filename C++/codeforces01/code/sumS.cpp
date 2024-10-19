#include <iostream>

// Correção automatica de indexes para não somar um valor a ele mesmo
int indexJcorrection(int indexN, int indexJ, int arraySize){
    if(indexN == indexJ){
        indexJ++;
    }
    if(indexJ == arraySize+1){
        indexJ = 0;
    }
    return indexJ;
}

int main(){
    int arraySize, sumToFind, auxInt;
    std::cin >> arraySize >> sumToFind;
    int nums[arraySize];
    // Adição dos números que trabalharemos no array
    for(int i=0; i <= arraySize-1; i++){
        std::cin >> auxInt;
        nums[i] = auxInt;
    }
    int indexN = 0, indexJ = 1;
    bool foundS = false;
    // Verifica se alguma soma resulta em "sumToFind"
    for(int n=0; n <= arraySize; n++){
        for(int j=1; j <= arraySize; j++){
            indexJ = indexJcorrection(indexN, indexJ, arraySize);
            if(nums[n] + nums[j] == sumToFind){
                foundS = true;
                break;
            }
        }
    }
    if(foundS){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}