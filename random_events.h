#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class RandomEvents {
  public: 
    RandomEvents(int path, int advisor);
    string getPathType();
    void setPathType(string fileName);
    int getAdvisor(); 
    void setAdvisor(string fileName);
    int getPoints();
    void setPoints(string fileName);
    string getEvent();
    void setEvent(string fileName);
    int addPoints();
    int updateDiscoveryPoints(string fileName);
    //int setDiscoveryPoints();
    //void setPoints (string fileName);
    void setRandomIndex();

    void redefineValues(int path, int advisor);
    

  private:
    int characterPath;
    int characterAdvisor;
    int eventPath;
    int eventAdvisor;
    int eventPoints;
    string event;
    int randomIndex;

};

//include Character class so that we can include methods from there -- this is for the points 
//Additional thing in character class with path type -- include get path type 
//ifcharacter.name == -- pulls the index number based on the advisor chosen. checking for strings and returning ints 
