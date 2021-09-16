#ifndef Pipe_h
#define Pipe_h

using namespace std;

struct Pipe {
    int id = -1;
    int diametr;
    double length;
    bool isInRepair  = false;
};

bool operator==(const Pipe& lhs,const Pipe& rhs){
    if (lhs.id == rhs.id){
        return true;
    }
    return false;
}

Pipe AddPipe() {
    Pipe pipe = {};
    pipe.id = 0;
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

#endif /* Pipe_h */
