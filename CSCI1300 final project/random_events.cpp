#include "random_events.h"
#include "UsefulFunctions.h"
#include <cstdlib>


RandomEvents:: RandomEvents(character){
  path = "";
  advisor = "";
  points = "";
  index = 0;
  this.character = character
  
}

void RandomEvents:: setRandomIndex(){
  srand(time(0)); // makes sure that its a different random line each time. 
  int i = (rand()%48) +1 // figure out how to set that random index
  index = i;
}

void RandomEvents::setPathType(string fileName){
  ifstream inputFile(fileName);
  string line;
  int currentIndex = 0;
  if(inputFile.is_open()){
      while(getline(inputFile,line)){
        if(currentIndex == index){
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
      if(currentIndex == index){
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
      if(currentIndex == index){
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
      if(currentIndex == index){
        vector<string> words;
        split(line,words,'|');
        event = words[0];
        path = words[1];
        advisor = words[2];
        points = words [3];
        break;
      }
currentIndex++;
    }
  }
inputFile.close();
}

//if the player advisor is equal to the random advisor, no points will be deducted 
// character vs player...
//create another player class.. 

// pass the character through to the random event as it's called

//have a void to set the random event -- done
//have a void to get the user path, and then the path for the event
//have a void to get the user advisor and then the advisor for the event
//have a void to get the user points and then the points added or subtracted for the event. 
//pink and purple are the random events squares
//have a class to add and subtract the points -- use from the characters 
//
