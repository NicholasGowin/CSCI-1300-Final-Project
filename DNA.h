//Meera Bipin and Nicholas Gowin
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DNA{
    public:
        DNA();
        double strandSimilarity(); // userStrand1 and userStrand 2
        int bestStrandMatch(); // matchStrand1 and matchStrand2
        void identifyMutations(); // matchStrand1 and matchStrand2
        void transcribeDNAtoRNA(); // strand
        void userStrandSimilarity();
        void userStrandMatch();
        
    private:
        string userStrand1;
        string userStrand2;
        string matchStrand1;
        string matchStrand2; 
        string strand;
        double similarityScore;
        int bestMatchIndex;
};
