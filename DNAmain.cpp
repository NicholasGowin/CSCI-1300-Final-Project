//Meera Bipin and Nicholas Gowin
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DNA.h"
using namespace std;

int main(){
    DNA dna;
    int choice;
    cout << "Choose a DNA Event: Enter the number corresponding to your choice: 1 - Similar Strands of Equal Length | 2 - Similar Strands of Unequal Length | 3 - Mutation Identifier | 4 - Transcribe DNA to RNA" << endl;
    cin >> choice;
    if(choice == 1){
        dna.strandSimilarity();
    }
    else if (choice == 2){
        dna.bestStrandMatch();
    }
    else if (choice == 3){
        dna.identifyMutations();
    }
    else if (choice == 4){
        dna.transcribeDNAtoRNA();
    } 
    else{
        cout << "Invalid choice, please try again!" << endl;
    }
    return 0;
};
