#include "Riddle.h"
#include "UsefulFunctions.h"

Riddle:: Riddle(){
    question = "";
    answer ="";
    index = -1;
}

void Riddle:: setRandomIndex(){
    int i = rand()%25; //gives random number between 0-25 for index of riddles
    index =i;
}

void Riddle:: setQA(string fileName){
    setRandomIndex();
    ifstream inputFile(fileName);
    string line;
    int currentIndex =0;
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            if(currentIndex == index){
                vector<string> words;
                split(line,words,'|');
                question = words[0];
                answer = words[1];
                break;
            }
            currentIndex++;
        }
    }
    inputFile.close();
}

string Riddle:: getAnswer(){
    return answer;
}
string Riddle:: getQuestion(){
    return question;
}
bool Riddle:: checkAnswer(string userAnswer){
    if(userAnswer == answer){
        return true;
    }
    return false;
    
}

// split is implemented in UsefulFunctions.cpp
