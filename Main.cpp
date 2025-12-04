#include "Board.h"

// forward declaration; intro() is implemented in intro.cpp
void intro();
int rollDie();
int playTurn();

using namespace std;






int main(){
    
    intro();
    Character player1;
    cout<<"Player one please type in your name: "<<endl;
    player1.setPlayerName();
    player1.displayAllCharacters("characters.txt",-1);
    int choice1;
    cin>> choice1;
    int previous = player1.setCharacterInfo("characters.txt", choice1-1,0, 100); //(100) number outside of bounds of character
    cout<<"Player two please type in your name: "<<endl;
    
    
    Character player2;
    player2.setPlayerName();
    cout<< endl<< "Player 2, choose your character by entering the corresponding number:"<< endl;
    player2.displayAllCharacters("characters.txt", previous);
    int choice2;
    cin>> choice2;
    player2.setCharacterInfo("characters.txt",choice2-1,1,previous);
    cout<< endl<< "Great choices! "<< endl<< endl;
    cout<< "Player 1! ";
    player1.setAdvisor("advisor.txt");
    cout<< "Player 2! ";
    player2.setAdvisor("advisor.txt");
    
    
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
    Board gameBoard;// map player choices to lanes: 1 -> lane 0 (top), 2 -> lane 1 (bottom)
    gameBoard.assignPlayerToLane(0, path1-1);
    player1.setPath(path1-1);
    gameBoard.assignPlayerToLane(1, path2-1);
    player2.setPath(path2-1);
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
        while(color!= 'G'&& color!= 'Y'&& color!= 'P'){ //when tile isn't green and the game's not over see if there is any action to be taken.
            if(color == 'O'){
                player1.addDiscoveryPoints(1,500);
                break;
            }
            
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
            while(color == 'U'){ // color purple
                int pointsAdded;
                gameBoard.setTileColorGreen(0);
                gameBoard.displayBoard();
                RandomEvents randomEvent(player1.getPath(), player1.getAdvisor());
                randomEvent.setRandomIndex();
                pointsAdded = randomEvent.updateDiscoveryPoints("random_events.txt");
                cout<< randomEvent.getEvent()<<endl;
                player1.addDiscoveryPoints(1, pointsAdded);
                if(pointsAdded <= 0){
                    randomEvent.redefineValues(player2.getAdvisor(),player2.getPath());
                    pointsAdded = randomEvent.updateDiscoveryPoints("random_events.txt");
                    player2.addDiscoveryPoints(2, pointsAdded);
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
        while(color!= 'G'&& color!= 'Y'&& color!= 'P'){ //when tile isn't green and the game's not over see if there is any action to be taken.
            if(color == 'O'){
                player2.addDiscoveryPoints(2,500);
                break;
            }
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
            while(color == 'U'){ // color purple
                int pointsAdded;
                gameBoard.setTileColorGreen(1);
                gameBoard.displayBoard();
                RandomEvents randomEvent(player2.getPath(), player2.getAdvisor());
                randomEvent.setRandomIndex();
                pointsAdded = randomEvent.updateDiscoveryPoints("random_events.txt");
                cout<< randomEvent.getEvent()<<endl;
                player2.addDiscoveryPoints(2, pointsAdded);
                if(pointsAdded <= 0){
                    randomEvent.redefineValues(player1.getAdvisor(),player1.getPath());
                    pointsAdded = randomEvent.updateDiscoveryPoints("random_events.txt");
                    player1.addDiscoveryPoints(1, pointsAdded);
                }
                color = gameBoard.getTileColor(1);
            }
        
        }
        player2.tallyUpPoints(ansCorrect, roll, luck);
    }
    // finalize players' points before creating the array used for sorting
    player1.getFinalPoints();
    player2.getFinalPoints();
    Character list[2];
    list[0] = player1;
    list[1] = player2;
    cout<< player1.getDiscoveryPoints()<<endl;
    cout<< player2.getDiscoveryPoints()<<endl;
    if(player1.getDiscoveryPoints()>player2.getDiscoveryPoints()){
        cout<< "Player 1 wins!!"<<endl;
        player1.selectionSort(list,2);
        cout<< player1.getName()<< "- \"Thanks for the Win "<< player1.getPlayerName() <<"!\""<<endl;
    }else if(player2.getDiscoveryPoints()>player1.getDiscoveryPoints()){
        cout<< "Player 2 wins!!"<<endl;
        player1.selectionSort(list,2);
        cout<< player2.getName()<< "- \"Thanks for the Win "<< player2.getPlayerName() <<"!\""<<endl;
    }else{
        cout<< "It's a tie!"<<endl;
        player1.selectionSort(list,2);
        cout<< player1.getName()<< ", "<< player2.getName() << "- \"I'll get you next time!\""<<endl;
    }
    cout<< "GAME OVER!";
    player1.addPlayerToFile();
    player2.addPlayerToFile();
    
    


    return 0;
}



// split implemented in UsefulFunctions.cpp