//
//  CompressorStation.h
//  PipeAndCs
//
//  Created by Антон Таранов on 15.09.2021.
//

#ifndef CompressorStation_h
#define CompressorStation_h

struct CompressionStation {
    int id = 0;
    string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
};


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

#endif /* CompressorStation_h */
