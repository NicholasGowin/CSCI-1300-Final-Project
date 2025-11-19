#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class RandomEvents {
  public: 
    RandomEvents();
    string getAnswer();
    void setAnswer(string fileName);
    string getQuestion ();
    void setQuestion(string fileName);
    void setRandomIndex();
    bool checkAnswer(string userAnswer);

  private:
    string answer;
    string question;
    int index;

};

