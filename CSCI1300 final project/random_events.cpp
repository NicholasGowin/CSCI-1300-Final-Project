#include "random_events.h"
#include "UsefulFunctions.h"
#include <cstdlib>
#include "Characters.h"


RandomEvents:: RandomEvents(character){
  path = "";
  advisor = "";
  points = "";
  index1 = 0;
  this.character = character
  
}

void RandomEvents:: setRandomIndex(){
  srand(time(0)); // makes sure that its a different random line each time. 
  int i = (rand()%48) +1 // figure out how to set that random index
  index1 = i;
}

void RandomEvents::setPathType(string fileName){
  ifstream inputFile(fileName);
  string line;
  int currentIndex = 0;
  if(inputFile.is_open()){
      while(getline(inputFile,line)){
        if(currentIndex == index1){
          vector<string> words;
          split(line,words,'|');
          path = words[1];
          break;
        }
        currentIndex++;
      }
  }
inputFile.close();
}

void RandomEvents::setAdvisor(string fileName){
  ifstream inputFile(fileName);
  string line;
  int currentIndex = 0;
  if(inputFile.is_open()){
    while(getline(inputFile,line)){
      if(currentIndex == index1){
        vector<string> words;
        split(line,words,'|');
        path = words[1];
        advisor = words[2];
        break;
      }
      currentIndex++;
    }
  }
inputFile.close();
}

void RandomEvents::setPoints(string fileName){
  ifstream inputFile(fileName);
  string line;
  int currentIndex = 0;
  if(inputFile.is_open()){
    while(getline(inputFile,line)){
      if(currentIndex == index1){
        vector<string> words;
        split(line,words,'|');
        path = words[1];
        advisor = words[2];
        points = words[3];
        break;
      }
      currentIndex++;
    }
  }
inputFile.close();
}

void RandomEvents::setEvent(string fileName){
  ifstream inputFile(fileName);
  string line;
  int currentIndex = 0;
  if(inputFile.is_open()){
    while(getline(inputFile,line)){
      if(currentIndex == index1){
        vector<string> words;
        split(line,words,'|');
        event = words[0];
        path = words[1];
        advisor = words[2];
        points = words[3];
        break;
      }
currentIndex++;
    }
  }
inputFile.close();
}

if (index == words[2]){
  discoveryPoints = discoveryPoints;
  else {
    discoveryPoints = discoveryPoints + words[3];
  };
};

//if the player advisor is equal to the random advisor, no points will be deducted 
// character vs player...
//create another player class.. 

// pass the character through to the random event as it's called
//pass by value and pass by reference -- 

//have a void to set the random event -- done
//have a void to get the user path, and then the path for the event
//have a void to get the user advisor and then the advisor for the event
//have a void to get the user points and then the points added or subtracted for the event. 
//pink and purple are the random events squares
//have a class to add and subtract the points -- use from the characters 
//
