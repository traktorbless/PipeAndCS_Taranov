//
//  Funtional.h
//  PipeAndCs
//
//  Created by Антон Таранов on 20.09.2021.
//

#ifndef Funtional_h
#define Funtional_h
#include <vector>

using namespace std;

void PrintMenu(){
    cout << "1.Add pipe" << endl;
    cout << "2.Add compressor station" << endl;
    cout << "3.Show all object" << endl;
    cout << "4.Change pipe" << endl;
    cout << "5.Change compressor station" << endl;
    cout << "6.Save" << endl;
    cout << "7.Load" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter command number: " << endl;
}

int ParseStringToInt(string& line) {
    line.erase(remove_if(line.begin(),line.end(),::isalpha),line.end());
    return stoi(line);
}

bool CorrectInput(string& s) {
    if (s[0] == '.') {
        return false;
    }
    vector<char> correctNumbers = {'1','2','3','4','5','6','7','8','9','0','.'};
    for (auto i : s) {
        if(count(begin(correctNumbers),end(correctNumbers),i) == 1) {
            continue;
        } else {
            cout << "Invalid input" << endl;
            return false;
        }
    }
    return true;
}

int CorrectInputForInt(){
    string value;
    cin >> value;
    while(!CorrectInput(value)){
        cin >> value;
    }
    return stoi(value);
}

double CorrectInputForDouble(){
    string value;
    cin >> value;
    while(!CorrectInput(value)){
        cin >> value;
    }
    return stod(value);
}

#endif /* Funtional_h */
