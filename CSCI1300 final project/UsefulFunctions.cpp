#include "UsefulFunctions.h"

void split(const string &line, vector<string> &words, char symbol){
    words.clear();
    int start = 0;
    for (int i = 0; i < (int)line.size(); ++i) {
        if (line[i] == symbol) {
            words.push_back(line.substr(start, i - start));
            start = i + 1;
        }
    }
    if (start <= (int)line.size()) {
        words.push_back(line.substr(start));
    }
}

