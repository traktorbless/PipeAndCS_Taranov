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


Pipe AddPipe() {
    Pipe pipe = {};
    pipe.id = 0;
    cout << "Enter diametr: ";
    pipe.diametr = CorrectInputForInt();
    cout << "Enter length: ";
    pipe.length = CorrectInputForInt();
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
        ParseStringToInt(input, pipe.id);
        ParseStringToInt(input, pipe.diametr);
        ParseStringToDouble(input, pipe.length);
        ParseStringToBool(input, pipe.isInRepair);
    } else {
        cout << "Pipe do not saved" << endl;
    }
}
#endif /* Pipe_h */
