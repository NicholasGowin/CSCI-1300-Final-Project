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
    void setRandomIndex();
    

  private:
    string path;
    string advisor;
    string points;
    int index;

};

