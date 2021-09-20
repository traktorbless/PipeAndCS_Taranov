//
//  CompressorStation.h
//  PipeAndCs
//
//  Created by Антон Таранов on 15.09.2021.
//

#ifndef CompressorStation_h
#define CompressorStation_h

struct CompressionStation {
    int id = -1;
    string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
};

double ParseStringToDouble(string& line) {
    line.erase(remove_if(line.begin(),line.end(),::isalpha),line.end());
    return stod(line);
}

CompressionStation AddCS() {
    CompressionStation station = {};
    station.id = 0;
    cout << "Enter name station: ";
    cin >> station.name;
    cout << "Enter number of workstaions: ";
    station.numberWorkshop = CorrectInputForInt();
    cout << "Enter number of workstation in action: ";
    int countStationAction = CorrectInputForInt();
    while(countStationAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
        cin >> countStationAction;
    }
    station.numberWorkshopInAtive = countStationAction;
    cout << "Enter station effiency: ";
    station.effiency = CorrectInputForDouble();
    return station;
}

void PrintCS(const CompressionStation& station) {
    if (station.id != -1) {
    cout << "Compressor station " << station.id << endl
    << "Her character: " << endl;
    cout << "Name: " << station.name << endl;
    cout << "Number of workstations: " << station.numberWorkshop << endl;
    cout << "Number of workstations in action: " << station.numberWorkshopInAtive << endl;
    cout << "Station effiency: " << station.effiency << endl;
    }
}

void ChangeCs(CompressionStation& station) {
    cout << "Enter number workstation in active" << endl;
    int newNumberWorkstationInAction = 0;
    cin >> newNumberWorkstationInAction;
    if(newNumberWorkstationInAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
    } else {
        station.numberWorkshopInAtive = newNumberWorkstationInAction;
        cout << "New number of workshops: " << newNumberWorkstationInAction << endl;
    }
}

void SaveCS(ofstream& output, const CompressionStation& station){
    if (station.id != -1){
    output << "Compressor station" << endl
    << "id " << station.id << endl
    << "name " << station.name << endl
    << "number workshop " << station.numberWorkshop << endl
    << "number workshop in action " << station.numberWorkshopInAtive << endl
    << "effiency " << station.effiency;
    } else {
        output << "Compressor station do not exists" << endl;
    }
}

void LoadCS(ifstream& input, CompressionStation& station) {
    string line;
    getline(input,line);
    if (line == "Compressor station"){
        getline(input,line);
        station.id = ParseStringToInt(line);
        getline(input,line);
        station.name = "test";
        getline(input,line);
        station.numberWorkshop = ParseStringToInt(line);
        getline(input,line);
        station.numberWorkshopInAtive = ParseStringToInt(line);
        getline(input,line);
        station.effiency = ParseStringToDouble(line);
    } else {
        cout << "Compressor station do not saved" << endl;
    }
}

#endif /* CompressorStation_h */
