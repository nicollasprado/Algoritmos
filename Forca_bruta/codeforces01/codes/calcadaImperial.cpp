#include <iostream>
#include <vector>

int main(){
    int seqSize;
    std::cin >> seqSize;
    int nums[seqSize];
    for(int i=0; i < seqSize; i++){
        std::cin >> nums[i];
    }

    std::vector<int> finalSeqs;
    if(seqSize == 1){
        finalSeqs.push_back(1);
    }else if(seqSize == 2){
        finalSeqs.push_back(2);
    }else{
        int actualSeq[2];
        int aux = 0;
        int nextShouldBeThis = actualSeq[aux];
        int seqCounter = 2;
        for(int j= 0; j < seqSize; j++){
            for(int k= j + 1; k < seqSize; k++){
                for(int z= k + 1; z < seqSize; z++){
                    if(nums[j] == nums[k]){
                            continue;
                    }else{
                        if(z == k + 1){ // if is the first iteration
                            actualSeq[0] = nums[j]; 
                            actualSeq[1] = nums[k];
                            nextShouldBeThis = actualSeq[aux];
                        }
                        if(nums[z] == actualSeq[(aux * -1) + 1]){ // If two consecutive breaks
                            finalSeqs.push_back(seqCounter);
                            aux = 0;
                            seqCounter = 2;
                            break;
                        }
                        if(nums[z] == nextShouldBeThis){ // Checks if we found the next number alternating between our actualSeq arr
                            seqCounter++;
                            aux = (aux * -1) + 1;
                            nextShouldBeThis = actualSeq[aux];
                        }
                        if(z == seqSize-1){
                            finalSeqs.push_back(seqCounter);
                            aux = 0;
                            seqCounter = 2;
                            break;
                        }
                    }
                }
            }
        }
    }

    int highest;
    if(static_cast<int>(finalSeqs.size()) > 0){
        highest = finalSeqs[0];
        if(seqSize > 2){
            for(int p = 1; p < static_cast<int>(finalSeqs.size()); p++){
                if(finalSeqs[p] > highest){
                    highest = finalSeqs[p];
                }
            }
        }
    }else{
        int buffer = nums[0];
        for(int l=1; l < seqSize; l++){
            if(nums[l] != buffer){
                highest = 2;
            }else{
                buffer = nums[l];
            }
        }
    }
    
    std::cout << highest << std::endl;
    return 0;
}