#include "random_events.h"
#include "UsefulFunctions.h"
#include <cstdlib>
#include <ctime>
#include "Characters.h"
#include <vector>
#include <fstream>
using namespace std;


RandomEvents :: RandomEvents(){
  path = "" ;
  advisor = "";
  points = "";
  index1 = 0;
  event = "";
  
};

void RandomEvents:: setRandomIndex(){
  srand(time(0)); // makes sure that its a different random line each time. 
  int i = (rand()%48) +1; // figure out how to set that random index
  index1 = i;
  //cout << i << endl;
};


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

void RandomEvents :: updateDiscoveryPoints(int num){
    int num = stoi(words[3]);
    discoveryPoints += num;
}

string RandomEvents::getPathType(){
    return path;
}

string RandomEvents::getAdvisor(){
    return advisor;
}

string RandomEvents::getPoints(){
    return points;
}

string RandomEvents::getEvent(){
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



