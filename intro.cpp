#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;
void intro(){
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    cout << "Welcome to the Journey through the Genome!" << endl<< "If you would like the rules, please type 'yes', if not type anything other than yes"<<endl;
    string rules;
    if(cin>> rules && rules == "yes"){
        cout<< endl<< "Rules:"<< endl;
        cout<< "1. Each player will select one character with set attributes."<< endl;
        cout<< "2. These attributes will be added up and contribute to the total discovery points!"<< endl;
        cout<< "3. Players will take turns answering questions."<< endl;
        cout<< "4. If the answer is correct, the player can roll the die and move forward."<< endl;
        cout<< "5. Landing on certain tiles may have special effects."<< endl;
        cout<< "        -Green Tiles: This is a safe tile, nothing happens."<< endl;
        cout<< "        -Red Tiles: Stay away from these, or you will move back 2 spaces!"<< endl
        << "          You will also lose 50 insight points!"<< endl;
        cout<< "        -Blue Tiles: These tiles allows you to answer another question to potentially roll again."<< endl;
        cout<< "        -Pink Tiles: You get a negative random event."<< endl;
        cout<< "        -Brown Tiles: If you land on this tile you will be prompted with an aditional question." <<endl<<"          If you get this one right, you get to move forward one extra tile,"<<endl<<"          but if you get it worng you have to move back 3 spaces!"<< endl;
        cout<< "        -Purple Tiles: You get a positive random event."<<endl;
        cout<< "4. Along they way you will lose/earn different points for your attributes which willl be added together "<<endl
        << "and give a certain number of discovery points based on the expirence of the charecter"<<endl;
        cout<< "5. Any player who reaches the orange tile at the end ends the game and earns 100 additional points discovery points"<< endl;
        cout<< "6. In the case of Player 1 reaching orange first Player 2 will get one opertunity to reach it and earn the 100 points as well"<<endl;
        cout<< "7. Whoever ends with the most discovery points at the end wins!"<<endl;
    }else{
        cout<< "no worries, let's get started!"<<endl;
    }
    cout << "*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:."<<endl<< endl <<"To start decide who goes first by whos birthday is closest to today!" << endl<<endl<< "to start enter anything: ";

    string start;
    if(cin>>start && start == "anything"){
        cout<< endl<< "clever! "<< endl;
    }


    cout<< endl<< "Let the game begin!"<< endl<<endl;

}