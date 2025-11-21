#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class RandomEvents {
  public: 
    RandomEvents();
    int getPathType();
    void setPathType(string fileName);
    int getAdvisor(); 
    void setAdvisor(string fileName);
    double getPoints();
    void setPoints(string fileName);
    void setRandomIndex();
    

  private:
    string path;
    string advisor;
    string points;
    int index;

};

//include Character class so that we can include methods from there -- this is for the points 
//Additional thing in character class with path type -- include get path type 
//ifcharacter.name == -- pulls the index number based on the advisor chosen. checking for strings and returning ints
