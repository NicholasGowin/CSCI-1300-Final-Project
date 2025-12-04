#include "random_events.h"
#include "UsefulFunctions.h"
#include <cstdlib>
#include <ctime>
#include "Characters.h"
#include <vector>
#include <fstream>
using namespace std;


RandomEvents :: RandomEvents(int path, int advisor){
  characterPath = path;
  characterAdvisor = advisor;
  eventPath = 0 ;
  eventAdvisor = 0;
  eventPoints = 0;
  event = "";
  randomIndex = 5;
};

void RandomEvents:: setRandomIndex(){
  randomIndex = (rand()%51) +5;
};


void RandomEvents::setEvent(string fileName){
  ifstream inputFile(fileName);
  string line;
  int currentIndex = 0;
  if(inputFile.is_open()){
    while(getline(inputFile,line)){
      if(currentIndex == randomIndex){
        vector<string> words;
        split(line,words,'|');
        event = words[0];
        eventPath = stoi(words[1]);
        eventAdvisor = stoi(words[2]);
        eventPoints = stoi(words[3]);
        break;
      }
      currentIndex++;
    }
  }
inputFile.close();
} 

int RandomEvents :: updateDiscoveryPoints(string fileName){
  setEvent(fileName);
  //cout<<"test: " <<characterPath<<endl;
  if((characterAdvisor != eventAdvisor|| eventAdvisor == 0)&& characterPath == eventPath){
    return eventPoints;
  }
  return 0; 
}

int RandomEvents::getPoints(){
  return eventPoints;
}

void RandomEvents:: redefineValues(int path, int advisor){
  characterPath = path;
  characterAdvisor = advisor;
}

string RandomEvents:: getEvent(){
  return event;
}



/*int function(randome_event Object, event eventTrigger):
    if(negEvent):
        Object.addPoint(400)
    else:

main():
Object
event
function(Object,event)*/

//whatever i want to modfiy i need to add to the parameter parenthesis. 
//

/*int RandomEvents::addPoints (){
if (index1 == stoi(words[2])){ //checks the 
  discoveryPoints = discoveryPoints;
}
else {
    discoveryPoints += discoveryPoints + stoi(words[3]); //stoi converts the string to an int
  };
}; */

// int num = stoi(words[3]);
// discoveryPoints += num;


//add strings
//how to fix this...
//initalize an object -- modifying that object 



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
//9.9 
//uml diagram

//#endif



