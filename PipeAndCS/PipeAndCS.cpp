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
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
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

CompressionStation AddCS() {
    CompressionStation station = {};
    cout << "Enter name station: ";
    cin >> station.name;
    cout << "Enter number of workstaions: ";
    cin >> station.numberWorkshop;
    cout << "Enter number of workstation in action: ";
    int countStationAction = 0;
    cin >> countStationAction;
    while(countStationAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
        cin >> countStationAction;
    }
    station.numberWorkshopInAtive = countStationAction;
    cout << "Enter station effiency: ";
    cin >> station.effiency;
    return station;
}

void PrintCS(const CompressionStation& station) {
    cout << "Compressor station " << station.id << endl
    << "Her character: " << endl;
    cout << "Name: " << station.name << endl;
    cout << "Number of workstations: " << station.numberWorkshop << endl;
    cout << "Number of workstations in action: " << station.numberWorkshopInAtive << endl;
    cout << "Station effiency: " << station.effiency << endl;
}

void ChangeCs(CompressionStation& station,int newNumberWorkstationInAction) {
    if(newNumberWorkstationInAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
    } else {
        station.numberWorkshopInAtive = newNumberWorkstationInAction;
        cout << "New number of workshops: " << newNumberWorkstationInAction << endl;
    }
}

void ShowAllObject(const CompressionStation& station, const Pipe& pipe){
    PrintPipe(pipe);
    PrintCS(station);
}

void PrintMenu(){
    cout << "1.Add pipe" << endl;
    cout << "2.Add compressor station" << endl;
    cout << "3.Show all object" << endl;
    cout << "4.Change pipe" << endl;
    cout << "5.Change compressor station" << endl;
    cout << "6.Save" << endl;
    cout << "7.Load" << endl;
    cout << "0.Exit" << endl;
}

int main()
{
    PrintMenu();
}


