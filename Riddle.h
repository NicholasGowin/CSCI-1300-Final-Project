#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Riddle{
    public:
        Riddle();
        string getAnswer();
        string getQuestion();
        void setQA(string fileName);
        bool checkAnswer(string userAnswer);

        
    private:
        string answer;
        string question;
        int index;

        void setRandomIndex();
};