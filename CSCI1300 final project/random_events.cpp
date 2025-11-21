#include "random_events.h"
#include "UsefulFunctions.h"

RandomEvents:: RandomEvents(){
  path = "";
  advisor = "";
  points = "";
  index = 0;
}

void RandomEvents:: setRandomIndex(){
  int i = rand()// figure out how to set that random index
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

//have a void to set the random event
//have a void to get the user path, and then the path for the event
//have a void to get the user advisor and then the advisor for the event
//have a void to get the user points and then the points added or subtracted for the event. 
//pink and purple are the random events squares
//have a class to add and subtract the points -- use from the characters 
