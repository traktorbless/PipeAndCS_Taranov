#include <iostream>

using namespace std;

struct Pipe {
    int id;
    int diametr;
    double length;
    bool isInRepair  = false;
};

struct CompressionStation {
    int id = 0;
    string name;
    int countWorkshop;
    int countWorkshopInAtive;
    double effiency;
};

Pipe AddPipe() {
    Pipe p = {};
    cout << "Enter diametr: ";
    cin >> p.diametr;
    cout << "Enter length: ";
    cin >> p.length;
    return p;
}

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

CompressionStation addCS() {
    CompressionStation c = {};
    cout << "Enter name station: ";
    cin >> c.name;
    cout << "Enter number of workstaions: ";
    cin >> c.countWorkshop;
    cout << "Enter number of workstation in action: ";
    int countStationinAction = 0;
    cin >> countStationinAction;
    // zakonchil tyt   
}



int main()
{
    Pipe p = AddPipe();
    printPipe(p);
}


