#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int rollDie(){
    return (rand() % 6) + 1; // Returns a number between 1 and 6
}

int playTurn(){
    int roll;
    string guess;
    Riddle riddle;
    riddle.setQuestion("riddles.txt");
    cout << riddle.getAnswer()<<endl;
    cout<< riddle.getQuestion()<<endl;
    cin>>guess;
    if(guess == riddle.getAnswer()){
        cout<< "That's Correct! Now you can roll!"<<endl;
        roll = rollDie();
        cout<<"you rolled a "<< roll <<"!"<<endl;
    }else{
        cout<< riddle.getAnswer()<< guess <<endl;
        cout<< "That is unfortunately worng"<<endl;
        roll = -1;
        
    }
    return roll;
}


int main(){
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
        cout<< "        -Pink Tiles: You have to skip your next turn."<< endl;
        cout<< "        -Brown Tiles: If you land on this tile you will be prompted with an aditional question." <<endl<<"          If you get this one right, you get to move forward one extra tile,"<<endl<<"          but if you get it worng you have to move back 3 spaces!"<< endl;
        cout<< "        -Purple Tiles: If you land on this tile you will be prompted with a random event that will either help or hinder your progress."<<endl;
        cout<< "4. The first player to reach the orange tile at the end ends the game and earns 100 additional points"<< endl;
        cout<< "5. In the case of Player 1 reaching orange first Player 2 will get one opertunity to reach it as well"<<endl;
        cout<< "6. Whoever ends with the most points at the end wins!"<<endl;
    }else{
        cout<< "no worries, let's get started!"<<endl;
    }
    cout << "*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:."<<endl<< endl <<"To start decide who goes first by whos birthday is closest to today!" << endl<<endl<< "to start enter anything: ";
    Board gameBoard;
    string start;
    if(cin>>start && start == "anything"){
        cout<< endl<< "clever! "<< endl;
        
    }
    cout<< endl<< "Let the game begin!"<< endl<<endl;

    Character player1;
    player1.displayCharacters("characters.txt");
    int choice1;
    cin>> choice1;
    player1.setCharacterInfo("characters.txt", choice1-1);
    cout<< endl<< "Player 2, choose your character by entering the corresponding number:"<< endl;
    Character player2;
    player2.displayCharacters("characters.txt");
    int choice2;
    cin>> choice2;
    player2.setCharacterInfo("characters.txt",choice2-1);
    cout<< endl<< "Great choices! "<< endl<< endl;
    gameBoard.displayBoard();

    char color;
    while(gameBoard.getPlayerPosition(0) < 51 && gameBoard.getPlayerPosition(1) < 51){
        int roll;
        
        cout<< "Player 1's turn!"<< endl;
        roll = playTurn();
        if(roll>-1){
            for(int i =0;i<roll;i++){
                if(gameBoard.getPlayerPosition(0)<51){
                    gameBoard.movePlayer(0);
                }
            }
            color = gameBoard.getTileColor(0);

        }
        gameBoard.displayBoard();
        color = gameBoard.getTileColor(0);
        while(color == 'R'){
            string placeHolder;
            cout<<"Landed on red, move back 2 spaces"<<endl<<"type anything to continue"<<endl;
            cin>> placeHolder;
            placeHolder="";
            gameBoard.movePlayerBack(0);
            gameBoard.movePlayerBack(0);
            gameBoard.displayBoard();
        }
        while(color == 'B'){
            string placeHolder;
            cout<<"Landed on blue!"<<endl<<"roll again"<<endl;
            cin>> placeHolder;
            placeHolder="";
            roll = playTurn();
            if(roll>-1){
                for(int i =0;i<roll;i++){
                    if(gameBoard.getPlayerPosition(0)<51){
                        gameBoard.movePlayer(0);
                    }
                }
                color = gameBoard.getTileColor(0);

            }
        }
        
        
        
        
        cout<< "Player 2's turn!"<< endl;
        roll = playTurn();
        if(roll>-1){
            for(int i =0;i<roll;i++){
                if(gameBoard.getPlayerPosition(1)<51){
                    cout<<gameBoard.getPlayerPosition(1)<<endl;
                    gameBoard.movePlayer(1);
                }
                
            }
        }
        gameBoard.displayBoard();
        color =gameBoard.getTileColor(1);
        if(color == 'R'){
            string placeHolder;
            cout<<"Landed on red, move back 2 spaces"<<endl;
            cin>> placeHolder;
            placeHolder = "";
            gameBoard.movePlayerBack(1);
            gameBoard.movePlayerBack(1);
            gameBoard.displayBoard();
        }
    }


    return 0;
}



// split implemented in UsefulFunctions.cpp