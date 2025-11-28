#include "Characters.h"
#include "UsefulFunctions.h"
#include <unordered_set>
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
int Character:: setCharacterInfo(string fileName, int index, int playerNum, int previousIndex){
    
    ifstream inputFile(fileName);
    string line;
    int currentIndex =0;
    //In the case of an index that is not a value in between 1 and 5 function asks for another value and calls itself
    if(playerNum == 0){
        while(index < 0 || index > 4){
            cout<<"Please enter a number between 1 and 5."<<endl;
            cin >> index;
            setCharacterInfo(fileName, index, playerNum, previousIndex);
        }   
    }else{
        while(index < 0 || index > 3){
            cout<<"Please enter a number between 1 and 4."<<endl;
            cin >> index;
            setCharacterInfo(fileName, index, playerNum, previousIndex);
        }
    }
    
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            if(index<previousIndex){
                if(currentIndex == index){
                    vector<string> words;
                    split(line,words,'|');
                    name = words[0];
                    experience = stoi(words[1]);
                    accuracy = stoi(words[2]);
                    efficiency = stoi(words[3]);
                    insight = stoi(words[4]);
                    discoveryPoints = stoi(words[5]);
                }
                currentIndex++;
            }else{
                if(currentIndex == index+1){
                    vector<string> words;
                    split(line,words,'|');
                    name = words[0];
                    experience = stoi(words[1]);
                    accuracy = stoi(words[2]);
                    efficiency = stoi(words[3]);
                    insight = stoi(words[4]);
                    discoveryPoints = stoi(words[5]);
                }
                currentIndex++;
            }
                
        }
    }else{
        cout<<"file is not open"<<endl;
    }
    inputFile.close();
    return index;
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

void Character:: displayAllCharacters(string fileName, int index){
    indexOfChosenCharacter = index;
    cout<<"Enter number of desired charecter!"<<endl;
    cout<< "    name:       experience,  accuracy,    efficiency,       insight,     discoveryPoints"<<endl;
    cout<< "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    int i =1;
    unordered_set<string> seen;
    ifstream inputFile(fileName);
    string line ="";
    if(indexOfChosenCharacter==-1){
        while(getline(inputFile, line)){
            vector <string> words;
            split(line, words,'|');
            if (words.size() < 1) continue;
            if (seen.count(words[0])) continue; // skip duplicate name
            seen.insert(words[0]);
            cout<< i << ". "<<words[0]<< "      "<< words[1]<< ",          "<< words[2]<< ",           "<< words[3]<< ",           "<< words[4]<< ",           "<< words[5]<<endl;
            i++;
        }
        
    }else{
        int currentIndex = 0;
        while(getline(inputFile, line)){
            if(currentIndex != indexOfChosenCharacter){
                vector <string> words;
                split(line, words,'|');
                if (words.size() < 1) { currentIndex++; continue; }
                if (seen.count(words[0])) { currentIndex++; continue; }
                seen.insert(words[0]);
                cout<< i << ". "<<words[0]<< "       "<< words[1]<< ",          "<< words[2]<< ",           "<< words[3]<< ",           "<< words[4]<< ",           "<< words[5]<<endl;
                i++;
            }
            
            currentIndex++;   
        }
    }
}

void Character:: tallyUpPoints(bool ansCorrect, int roll, int luck){
    setAnswerStreak(ansCorrect);
    addAccuracy();
    addEfficiency(roll);
    addInsight(luck);


    cout<< "    name:       experience,  accuracy,    efficiency,       insight,     discoveryPoints"<<endl;
    cout<< "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    cout<<"   "<<name<< "       "<< experience<< ",          "<< accuracy << ",           "<< efficiency << ",           "<< insight << ",           "<< discoveryPoints <<endl<<endl;

}

int Character:: getFinalPoints(){
    discoveryPoints+= int((experience*(accuracy + efficiency + insight + discoveryPoints))/1.75);
    return discoveryPoints;
}
int Character:: getDiscoveryPoints(){
    return discoveryPoints;
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
