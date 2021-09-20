#ifndef Pipe_h
#define Pipe_h
#include <fstream>

using namespace std;

struct Pipe {
    int id = -1;
    int diametr;
    double length;
    bool isInRepair  = false;
};

int ParseStringToInt(string& line) {
    line.erase(remove_if(line.begin(),line.end(),::isalpha),line.end());
    return stoi(line);
}

Pipe AddPipe() {
    Pipe pipe = {};
    pipe.id = 1;
    cout << "Enter diametr: ";
    cin >> pipe.diametr;
    cout << "Enter length: ";
    cin >> pipe.length;
    return pipe;
}

void PrintPipe(const Pipe& pipe) {
    if (pipe.id != -1) {
    cout << "Pipe " << pipe.id << endl
        <<"Her character: " << endl;
    cout << "Diamter: " << pipe.diametr << endl;
    cout << "Length: " << pipe.length << endl;
    cout << "Repair satus: ";
    if (!pipe.isInRepair) {
        cout << "Station is work" << endl;
    }
    else {
        cout << "Station does not work" << endl;
    }
    }
}

void ChangePipe(Pipe& pipe){
    pipe.isInRepair = !pipe.isInRepair;
    if (pipe.isInRepair){
        cout << "Status of the pipe: under repair" << endl;
    } else {
        cout << "Status of the pipe: in progress" << endl;
    }
}

void SavePipe(ofstream& output,const Pipe& pipe){
    if (pipe.id != -1){
    output << "Pipe" << endl
    << "id " << pipe.id << endl
    << "diametr " << pipe.diametr << endl
    << "length " << pipe.length << endl
    << "Status repair " << pipe.isInRepair << endl;
    } else {
        output << "Pipe do not exists" << endl;
    }
}

void LoadPipe(ifstream& input,Pipe& pipe) {
    string line;
    getline(input,line);
    if (line == "Pipe") {
        getline(input,line);
        pipe.id = ParseStringToInt(line);
        getline(input,line);
        pipe.diametr = ParseStringToInt(line);
        getline(input,line);
        pipe.length = ParseStringToInt(line);
        getline(input,line);
        pipe.isInRepair = ParseStringToInt(line) == 0 ? false : true;
    } else {
        cout << "Pipe do not saved" << endl;
    }
}
#endif /* Pipe_h */
