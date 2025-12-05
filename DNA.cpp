//Meera Bipin and Nicholas Gowin
#include "DNA.h"
#include "UsefulFunctions.h"

DNA::DNA (){
    userStrand1 = "";
    userStrand2 = "";
    matchStrand1 = "";
    matchStrand2 = "";
    strand = "";
    similarityScore = 0.0;
    bestMatchIndex = -1; //set to -1 to indicate no match is found yet. 

}

void DNA :: userStrandSimilarity(){
    cout<< "Please enter a 6 digit DNA strand using only the letters A, T, C, and G: " << endl;
    cin>> userStrand1;
    cout << "Please enter another 6 digit DNA strand using only the letters A, T, C, and G: " << endl;
    cin >> userStrand2;
}

void DNA :: userStrandMatch(){
    cout << "Please enter a DNA Strand using the characters A, T, C, and G: " << endl;
    cin >> matchStrand1;
    cout << "Please enter another shorter DNA strand using the characters A, T, C, and G: " << endl;
    cin >> matchStrand2;
}

double DNA :: strandSimilarity(){
    userStrandSimilarity();
    char charStr1;
    char charStr2;
    int matches = 0;
    for(int i = 0; i < userStrand1.length(); i++){
        charStr1 = userStrand1[i];
        charStr2 = userStrand2[i];
        if(charStr1 == charStr2){
            matches++;
        }
    }
    similarityScore = matches / 6.0; // 6 is the length of the strand
    cout << "The similarity score is: " << similarityScore << endl;
    return 0;
}

int DNA :: bestStrandMatch(){ 
    userStrandMatch(); 
    string longerStrand = matchStrand1;
    string shorterStrand = matchStrand2;
    char charLong;
    char charShort;
    int maxMatches = 0;
    int maxIndex = 0;
    for(int i = 0; i <=longerStrand.length() - shorterStrand.length(); i++){// this line slides the shorter strand along the longer strand, one position at a time. 
        int currentMatches = 0;
        for(int j = 0; j < shorterStrand.length(); j++){ // this line compares each character of the shorter strand to the corresponding character of the longer strand at the current position, and updates matches. 
            charLong = longerStrand[i+j];
            charShort = shorterStrand[j]; 
            if(charLong == charShort){
                currentMatches++;
            }
        }
        if (currentMatches > maxMatches){
            maxMatches = currentMatches;
            maxIndex = i;
            bestMatchIndex = maxIndex;
        }    
        }
        cout << "The strand best matches at index: " << bestMatchIndex << endl;
        return 0;
    }
        

void DNA :: identifyMutations(){
    userStrandMatch(); // earlier void function to get the strands from the user. 
    string longerStrand = matchStrand1; // promted user to enter the longer strand first. 
    string shorterStrand = matchStrand2;
    char charLong1;
    char charShort2;
    char charLong;
    char charShort;
    int maxMatches = 0; //stores the max matches found, and is updated each time a new max is found. 
    int maxIndex = 0; // stores the index of the best match, updated each time max matches is updated. 
    for(int i = 0; i <=longerStrand.length() - shorterStrand.length(); i++){ // i <= longer.length - shorter.length to prevent out of bounds errors, we want the shorter string to fit within the longer string; slides shorter strand along longer strand.
        int currentMatches = 0; // resets the current matches every time the for loop runs. 
        for(int j = 0; j < shorterStrand.length(); j++){ // this line compares each character of the shorter strand to the corresponding character of the longer strand at the current position, and updates matches. 
            charLong = longerStrand[i+j];
            charLong1 = longerStrand[i+j]; // i+j represents the character in the longer strand
            charShort2 = shorterStrand[j]; // j represents the character in the shorter strand. 
            if(charLong1 == charShort2){
                currentMatches++; // updates current matches if there is a match. 
            }
        }
        if (currentMatches > maxMatches){ // checks to see if currentMatches is greater, and then updates the maxMatches and matchIndex
            maxMatches = currentMatches;
            maxIndex = i;
            bestMatchIndex = maxIndex;
        }    
    } 
    for(int i = 0; i < longerStrand.length(); i++){
        if(longerStrand[i] != shorterStrand[i - bestMatchIndex]){ // i - bestMatchIndex --> represents i, the current position in the longer strand subrtracted by the bestMatchIndex because the shorter strand starts that many positions into the longer strand. 
            charLong = longerStrand[i];
            charShort = shorterStrand[i - bestMatchIndex];
            if((i-bestMatchIndex) < 0 || (i - bestMatchIndex) >= shorterStrand.length()){ // i-bestMatch Index < 0 --> represents before the shorter strand starts; i-bestMatchIndex >= shorterStrand.length() --> represents after the shorter strand ends.
                cout  << "Deletion mutation at index: " << i << endl;  
            }
            else if (charLong != charShort) { // next else if checks for substitutions, and if not goes to insertions. 

                cout << "Substitution mutation at index: " << i << ": " << charLong << " --> " << charShort << endl; 
            }
            else { //insertions don't really matter in this case because it is just represented as a substitution.
                 cout << "Insertion mutation at index: " << i << ": " << charShort << " is inserted. " << endl;
            }
        } 
        else {
            cout << "No mutation at index: " << i << endl; // dont need to cout this technicaly, but it is in the right spot. 
        }
        
    }
}

void DNA :: transcribeDNAtoRNA(){
    cout << "Enter a DNA Strand using A, T, C, and G to transcribe it to RNA: " << endl;
    cin >> strand;
    char tChar = 'T';
    char uChar = 'U';
    for(int i = 0; i < strand.length(); i++){
        if(strand[i] == tChar){ // checks to see if the character is a T
            strand[i] = uChar; // replaces the T with a U
        }
    }
    cout << strand << endl;
}

