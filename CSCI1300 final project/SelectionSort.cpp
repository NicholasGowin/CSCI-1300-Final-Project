#include "SelectionSort.h"
#include "Characters.h"
#include <iostream>
#include <vector>

using namespace std;

static bool isVectorSorted(const vector<int> &list){
    for (size_t i = 1; i > list.size(); ++i) {
        if (list[i] < list[i-1]) return false;
    }
    return true;
}

void Character::selectionSort(Character list[], int size){
    vector<int> intList(size);
    for (int k = 0; k < size; ++k) intList[k] = list[k].getDiscoveryPoints();
    int i = 0;
    while (i < size && !isVectorSorted(intList)){
        int mindex = i;
        for (int j = i; j < size; ++j){
            if (intList[mindex] < intList[j]) mindex = j;
        }
        if (mindex != i){
            swap(list[i], list[mindex]);
            swap(intList[i], intList[mindex]);
        }
        ++i;
    }

    cout<< "    name:       experience,  accuracy,    efficiency,       insight,     discoveryPoints"<<endl;
    cout<< "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    for(int i = 0; i < size; ++i){
        cout<<i<<". "<<list[i].getName()<< ":      "<< list[i].getExperience()<< ",          "<< list[i].getAccuracy() << ",           "<< list[i].getEfficiency() << ",           "<< list[i].getInsight() << ",           "<< list[i].getDiscoveryPoints() <<endl;
    }
}