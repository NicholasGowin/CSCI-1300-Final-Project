#include "Characters.h"
#include "UsefulFunctions.h"
Character:: Character(){
    name = "";
    experience = 0;
    accuracy = 0;
    efficiency = 0;
    insight = 0;
    discoveryPoints = 0;
    correctStreak = 0;
    incorrectStreak = 0;
    indexOfChosenCharacter=-1;
}
void Character:: setCharacterInfo(string fileName, int index){
    
    ifstream inputFile(fileName);
    string line;
    int currentIndex =0;
    //In the case of an index that is not a value in between 1 and 5 function asks for another value and calls itself
    while(index < 0 || index > 4){
        cout<<"Please enter a number between 1 and 5."<<endl;
        cin >> index;
        setCharacterInfo(fileName,index);
    }
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            if(currentIndex == index){
                vector<string> words;
                split(line,words,'|');
                name = words[0];
                experience = stoi(words[1]);
                accuracy = stoi(words[2]);
                efficiency = stoi(words[3]);
                insight = stoi(words[4]);
                discoveryPoints = stoi(words[5]);
                break;
            }
            currentIndex++;
        }
    }else{
        cout<<"file is not open"<<endl;
    }
    inputFile.close();
    indexOfChosenCharacter = index+1;
    cout<<indexOfChosenCharacter<<endl;
}
void Character:: addDiscoveryPoints(bool ans){
    if(ans){
        discoveryPoints+=50;
    }else{
        discoveryPoints-=75;
    }
}

void Character:: setAnswerStreak(bool ans){
    if(ans){
        correctStreak++;
        incorrectStreak = 0;
    }else{
        correctStreak = 0;
        incorrectStreak++;
    }
}

void Character:: addAccuracy(){
    if(correctStreak>0){
        accuracy += (correctStreak*10);
    }else if(incorrectStreak>0){
        accuracy -= (correctStreak*10);
    }
}

void Character:: addEfficiency(int eff){
    if(eff>3){
        efficiency += ((eff-1)*10);
    }else if(eff<3){
        efficiency -= ((6-eff)*10);
    }
}

void Character:: addInsight(int ins){
    if(ins ==1){
        insight += 50;
    }else if(ins == -1){
        insight -=50;
    }
}

void Character:: displayCharacters(string fileName){
    cout<<"Enter number of desired charecter!"<<endl;
    cout<< "    name:   experience,     accuracy,   efficiency,     insight,    discoveryPoints"<<endl;
    int i =1;
    ifstream inputFile(fileName);
    string line ="";
    if(indexOfChosenCharacter==-1){
        while(getline(inputFile, line)){
            vector <string> words;
            split(line, words,'|');
            cout<< i << ". "<<words[0]<< ":      "<< words[1]<< ",          "<< words[2]<< ",           "<< words[3]<< ",           "<< words[4]<< ",           "<< words[5]<<endl;
            i++;
        }
        cout<< indexOfChosenCharacter<<endl;
    }else{
        int currentIndex = 0;
        while(getline(inputFile, line)){
            if(currentIndex != indexOfChosenCharacter){
                vector <string> words;
                split(line, words,'|');
                cout<< words[0]<< ":      "<< words[1]<< ",          "<< words[2]<< ",           "<< words[3]<< ",           "<< words[4]<< ",           "<< words[5]<<endl;
                cout<<"test"<<endl;
            }
            
            currentIndex++;   
        }
    }
}

string Character:: getName(){
    return name;
}
int Character:: getExperience(){
    return experience;
}
int Character:: getAccuracy(){
    return accuracy;
}
int Character:: getEfficiency(){
    return efficiency;
}
int Character:: getInsight(){
    return insight;
}
int Character:: getDiscoveryPoints(){
    return discoveryPoints;
}