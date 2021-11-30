#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

template<typename T>
void ParseString(istream& input,T& value) {
    string line;
    getline(input,line);
    line.erase(remove_if(line.begin(),line.end(),::isalpha),line.end());
    stringstream ss(line);
    ss >> value;
}

template<typename T>
void CorrectInput(T& value) {
    while(true){
        cin >> value;
        if (cin.peek() != '\n' || !cin || value < 0) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        } else {
            break;
        }
    }
}
