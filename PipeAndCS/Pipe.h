#ifndef Pipe_h
#define Pipe_h

using namespace std;

struct Pipe {
    int id;
    int diametr;
    double length;
    bool isInRepair  = false;
};

Pipe AddPipe() {
    Pipe pipe = {};
    cout << "Enter diametr: ";
    cin >> pipe.diametr;
    cout << "Enter length: ";
    cin >> pipe.length;
    return pipe;
}

void PrintPipe(const Pipe& pipe) {
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

void ChangePipe(Pipe& pipe){
    pipe.isInRepair = !pipe.isInRepair;
}

#endif /* Pipe_h */
