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
    riddle.setQA("riddles.txt");
    cout << riddle.getAnswer()<<endl;
    cout<< riddle.getQuestion()<<endl;
    cin>>guess;
    if(guess == riddle.getAnswer()){
        cout<< "That's Correct! Now you can roll!"<<endl;
        roll = rollDie();
        cout<< "you rolled a "<< roll <<"!"<<endl;

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

    Character player1;
    player1.displayAllCharacters("characters.txt",-1);
    int choice1;
    cin>> choice1;
    int prevous = player1.setCharacterInfo("characters.txt", choice1-1,0, 100);
    cout<< endl<< "Player 2, choose your character by entering the corresponding number:"<< endl;
    Character player2;
    player2.displayAllCharacters("characters.txt", choice1-1);
    int choice2;
    cin>> choice2;
    cout<< "This is the value of prevous"<<prevous<<endl;
    player2.setCharacterInfo("characters.txt",choice2-1,1,prevous);
    cout<< endl<< "Great choices! "<< endl<< endl;
    
    
    int path1;
    int path2;
    cout<< endl<< "Next please select your desired path"<<endl
    <<"Player 1, choose your desired path by entering the corresponding number:"<<endl
    <<"1. Fellowship Training (Less events, meaning less opertunity for struggle, but also less opertunity for reward!)"<<endl
    <<"2. Direct Lab Assignment (More chance for rewards, but more struggles along the way)"<<endl;
    cin>>path1;

    cout<< endl<< "Next please select your desired path"<<endl
    <<"Player 2, choose your desired path by entering the corresponding number:"<<endl
    <<"1. Fellowship Training (Less events, meaning less opertunity for struggle, but also less opertunity for reward!)"<<endl
    <<"2. Direct Lab Assignment (More chance for rewards, but more struggles along the way)"<<endl;
    cin>>path2;
    Board gameBoard(path1 == path2);
    // map player choices to lanes: 1 -> lane 0 (top), 2 -> lane 1 (bottom)
    gameBoard.assignPlayerToLane(0, (path1==1) ? 0 : 1);
    gameBoard.assignPlayerToLane(1, (path2==1) ? 0 : 1);
    gameBoard.displayBoard();
    

//start of all the gameplay

    
    char color;
    while(gameBoard.getPlayerPosition(0) < 51 && gameBoard.getPlayerPosition(1) < 51){
        //initialize attribute modifiers
        int roll;
        int luck = 0;
        bool ansCorrect;
        //player 1's turn
        cout<< "Player 1's turn!"<< endl;
        roll = playTurn();
        if(roll>-1){
            ansCorrect = true;
            for(int i =0;i<roll;i++){
                if(gameBoard.getPlayerPosition(0)<51){
                    gameBoard.movePlayer(0);
                }
            }
            color = gameBoard.getTileColor(0);

        }else{
            ansCorrect = false;
        }
        
        gameBoard.displayBoard();
        color = gameBoard.getTileColor(0);

        //special tile colors
        while(color!= 'G'&& color!= 'O' && color!= 'Y'&& color!= 'P'&& color!= 'U'){ //when tile isn't green and the game's not over see if there is any action to be taken.
            while(color == 'B'){ //color blue
                gameBoard.setTileColorGreen(0);
                string placeHolder;
                cout<< "Landed on blue! You get another turn."<<endl;
                roll = playTurn();
                if(roll>-1){
                    player1.setAnswerStreak(true);
                    for(int i =0;i<roll;i++){
                        if(gameBoard.getPlayerPosition(0)<51){
                            gameBoard.movePlayer(0);
                        }
                    }
                    color = gameBoard.getTileColor(0);
                

                }else{
                    player1.setAnswerStreak(false);
                }
                
                gameBoard.displayBoard();
            }
            while(color == 'R'){ // color red
                gameBoard.setTileColorGreen(0);
                luck = -1;
                string placeHolder;
                cout<< "Landed on red, move back 2 spaces"<<endl<<"type anything to continue"<<endl;
                cin>> placeHolder;
                placeHolder="";
                gameBoard.movePlayerBack(0);
                gameBoard.movePlayerBack(0);
                gameBoard.displayBoard();
                color = gameBoard.getTileColor(0);
            }
            while(color =='T'){ //color brown
                gameBoard.setTileColorGreen(0);
                string guess;
                Riddle riddle;
                riddle.setQA("riddles.txt");
                cout << riddle.getAnswer()<<endl;
                cout<< riddle.getQuestion()<<endl;
                cin>>guess;
                if(guess == riddle.getAnswer()){
                    cout<< "That's Correct! Move forward a space!"<<endl;
                    player1.setAnswerStreak(true);
                    gameBoard.movePlayer(0);
                    gameBoard.displayBoard();

                }else{
                    cout<< "That is unfortunately worng. Move back 3 spaces!"<<endl;
                    player1.setAnswerStreak(false);
                    gameBoard.movePlayerBack(0);
                    gameBoard.movePlayerBack(0);
                    gameBoard.movePlayerBack(0);
                    gameBoard.displayBoard();
                }
                color = gameBoard.getTileColor(0);
                
            }
        
        }
        player1.tallyUpPoints(ansCorrect, roll, luck);
        luck = 0; //resets luck as value doesn't always change
        
        //player 2's turn
        cout<< "Player 2's turn!"<< endl;
        roll = playTurn();
        if(roll>-1){
            ansCorrect = true;
            for(int i =0;i<roll;i++){
                if(gameBoard.getPlayerPosition(1)<51){
                    gameBoard.movePlayer(1);
                }
            }
            color = gameBoard.getTileColor(1);

        }else{
            ansCorrect = false;
        }
        
        gameBoard.displayBoard();
        color = gameBoard.getTileColor(1);

        //special tile colors
        while(color!= 'G'&& color!= 'O' && color!= 'Y'&& color!= 'P'&& color!= 'U'){ //when tile isn't green and the game's not over see if there is any action to be taken.
            while(color == 'B'){ //color blue
                gameBoard.setTileColorGreen(1);
                string placeHolder;
                cout<< "Landed on blue! You get another turn."<<endl;
                roll = playTurn();
                if(roll>-1){
                    player2.setAnswerStreak(true);
                    for(int i =0;i<roll;i++){
                        if(gameBoard.getPlayerPosition(1)<51){
                            gameBoard.movePlayer(1);
                        }
                    }
                    color = gameBoard.getTileColor(1);
                    gameBoard.displayBoard();
                

                }else{
                    player2.setAnswerStreak(false);
                    gameBoard.displayBoard();
                }
                
                
            }
            while(color == 'R'){ // color red
                gameBoard.setTileColorGreen(1);
                luck = -1;
                string placeHolder;
                cout<< "Landed on red, move back 2 spaces"<<endl<<"type anything to continue"<<endl;
                cin>> placeHolder;
                placeHolder="";
                gameBoard.movePlayerBack(1);
                gameBoard.movePlayerBack(1);
                gameBoard.displayBoard();
                color = gameBoard.getTileColor(1);
            }
            while(color =='T'){ //color brown
                gameBoard.setTileColorGreen(1);
                string guess;
                Riddle riddle;
                riddle.setQA("riddles.txt");
                cout << riddle.getAnswer()<<endl;
                cout<< riddle.getQuestion()<<endl;
                cin>>guess;
                if(guess == riddle.getAnswer()){
                    cout<< "That's Correct! Move forward a space!"<<endl;
                    player2.setAnswerStreak(true);
                    gameBoard.movePlayer(1);
                    gameBoard.displayBoard();

                }else{
                    cout<< "That is unfortunately worng. Move back 3 spaces!"<<endl;
                    player2.setAnswerStreak(false);
                    gameBoard.movePlayerBack(1);
                    gameBoard.movePlayerBack(1);
                    gameBoard.movePlayerBack(1);
                    gameBoard.displayBoard();
                }
                color = gameBoard.getTileColor(1);
                
            }
        
        }
        player2.tallyUpPoints(ansCorrect, roll, luck);
    }
    Character list[2];
    list[0] = player1;
    list[1] = player2;
    player1.getFinalPoints();
    player2.getFinalPoints();
    cout<< player1.getDiscoveryPoints()<<endl;
    cout<< player2.getDiscoveryPoints()<<endl;
    if(player1.getFinalPoints()>player2.getFinalPoints()){
        cout<< "Player 1 wins!!"<<endl;
        player1.selectionSort(list,2);
        cout<< player1.getName()<< "- \"Thanks for the Win Player 1!\""<<endl;
    }else if(player2.getFinalPoints()>player1.getFinalPoints()){
        cout<< "Player 2 wins!!"<<endl;
        player1.selectionSort(list,2);
        cout<< player1.getName()<< "- \"Thanks for the Win Player 2!\""<<endl;
    }else{
        cout<< "It's a tie!"<<endl;
        player1.selectionSort(list,2);
        cout<< player1.getName()<< ", "<< player2.getName() << "- \"I'll get you next time!\""<<endl;
    }
    cout<< "GAME OVER!";
    
    


    return 0;
}



// split implemented in UsefulFunctions.cpp