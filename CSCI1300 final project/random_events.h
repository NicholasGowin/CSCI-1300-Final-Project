#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class RandomEvents {
  public: 
    RandomEvents();
    string getPathType();
    void setPathType(string fileName);
    string getAdvisor(); 
    void setAdvisor(string fileName);
    string getPoints();
    void setPoints(string fileName);
    string getEvent();
    void setEvent(string fileName);
    int addPoints();
    void updateDiscoveryPoints(int num);
    //int setDiscoveryPoints();
    //void setPoints (string fileName);
    void setRandomIndex();
    

  private:
    string path;
    string advisor;
    string points;
    string event;
    int index1;

};

//include Character class so that we can include methods from there -- this is for the points 
//Additional thing in character class with path type -- include get path type 
//ifcharacter.name == -- pulls the index number based on the advisor chosen. checking for strings and returning ints 
