#include <iostream>

using namespace std;

struct Pipe {
    int id;
    int diametr;
    double length;
    bool isInRepair  = false;
};


void printPipe(const Pipe& p) {
    cout << "Pipe " << p.id << endl
        <<"Her character: " << endl;
    cout << "Diamter: " << p.diametr << endl;
    cout << "Length: " << p.length << endl;
    cout << "Repair satus: ";
    if (!p.isInRepair) {
        cout << "Station is work" << endl;
    }
    else {
        cout << "Station does not work" << endl;
    }
}

Pipe AddPipe() {
    Pipe p = {};
    cout << "Enter diametr: ";
    cin >> p.diametr;
    cout << "Enter length: ";
    cin >> p.length;
    return p;
}

int main()
{
    Pipe p = AddPipe();
    printPipe(p);
}


