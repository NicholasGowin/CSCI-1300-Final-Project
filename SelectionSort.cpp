#include "SelectionSort.h"
#include "Characters.h"
#include <iostream>
#include <vector>

using namespace std;

bool isSorted(Character list[],int size){
    for(int i=1; i<size;i++){
        if(list[i].getDiscoveryPoints()>list[i-1].getDiscoveryPoints()){
            return false;
        }
    }
    return true;
}



void Character::selectionSort(Character list[],int size){
    
    
    Character placeHolder;
    int i=0;
    while(!isSorted(list,size)){
        int mindex= i;
        for(int j =i;j<size;j++){
            if(list[mindex].getDiscoveryPoints()<list[j].getDiscoveryPoints()){
                mindex=j;
            }
        }
        placeHolder=list[i];
        list[i]=list[mindex];
        list[mindex]=placeHolder;
        i++;
    }
    cout<< "    name:       exdiscoveryPoints"<<endl;
    cout<< "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    
    for(int i = 0;i<size;i++){
        cout<<i+1<<".   "<<list[i].getPlayerName()<< "       "<< list[i].getDiscoveryPoints() <<endl<<endl;
    }
}