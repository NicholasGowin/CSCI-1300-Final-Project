#include <iostream>
#include <fstream>
#include <vector>
#include "UsefulFunctions.h"


using namespace std;

#pragma once

#ifndef CHARACTERS_H
#define CHARACTERS_H

class Character { 
   public:
   Character();
   int setCharacterInfo(string fileName, int index, int playerNum, int previousInt);
   //takes items from a file and sets the character's info accordingly
   void addDiscoveryPoints(bool questionCorrect);
   //determines whether to add discovery points based on if the question was answered correctly

  
   void setAnswerStreak(bool questionCorrect);
   //determines how many questions are correct
   
    void displayAllCharacters(string fileName,int index);
    void tallyUpPoints(bool ansCorrect, int roll, int luck);
    

   string getName();
   int getExperience();
   int getAccuracy();
   int getEfficiency();
   int getInsight();
   int getDiscoveryPoints();
   int getFinalPoints();

   void selectionSort(Character list[],int size);
   
   private:
    string name;
    int experience;
    int accuracy;
    int efficiency;
    int insight;
    int discoveryPoints;

    int correctStreak;
    int incorrectStreak;
    int indexOfChosenCharacter;

    void addAccuracy();
    //if the player gets a streak of correct answers, their accuracy increases
    void addEfficiency(int eff);
    //if the player rolls above a certain number, their efficiency increases
    //if the player rolls below a certain number, their efficiency decreases
    void addInsight(int ins);
    //if the player lands on certain tiles, their insight increases
    //if the player lands on certain tiles, their insight decreases

    bool isSorted(double list[],int size);
};

#endif