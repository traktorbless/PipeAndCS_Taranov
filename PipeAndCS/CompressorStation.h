#pragma once
#include <string>
#include <vector>


class CompressionStation {
public:

    CompressionStation(const std::string& new_name,int new_numberWorkshop, int new_numberWorkshopInActive,
                       double new_effiency, int new_id);
    
    int GetId() const;
    
    std::string GetName() const;
    
    int GetNumberWorkshop() const;
    
    int GetNumberWorkshopInActive() const;
    
    double GetEffiency() const;

    void ChangeNumberOfWorkstationInActive(int new_number_workshop_active);
    
private:
    int id;
    static int max_id;
    std::string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
};

class DatabaseCS {
public:
    void AddCS();
    
    void DelCS(std::vector<CompressionStation>::const_iterator it);
    
    void ChangeCS(std::vector<CompressionStation>::const_iterator it);
    
    void PrintCS(std::ostream& os) const;
    
    void LoadCS(std::istream& is);
    
    void ChangeSetById(int id1, int id2);
    
    std::vector<CompressionStation>::const_iterator FindById(int id) const;
    
    std::vector<CompressionStation> FindByName(const std::string& name) const;
    
    std::vector<CompressionStation> FindByPercent(int percent) const;
    
private:
    std::vector<CompressionStation> db;
};

std::ostream& operator<<(std::ostream& os,const CompressionStation& station);

//CompressionStation AddCS() {
//    CompressionStation station = {};
//    station.id = 1;
//    cout << "Enter name station: ";
//    cin.ignore(1);
//    getline(cin,station.name);
//    cout << "Enter number of workstaions: ";
//    CorrectInput(station.numberWorkshop);
//    cout << "Enter number of workstation in action: ";
//    CorrectInput(station.numberWorkshopInAtive);  // vernytsa syda
//    while (station.numberWorkshopInAtive > station.numberWorkshop) {
//        cout << "Invalid input" << endl;
//        CorrectInput(station.numberWorkshopInAtive);
//    }
//    cout << "Enter station effiency: ";
//    CorrectInput(station.effiency);
//    while(station.effiency > 1) {
//        cout << "Invalid input" << endl;
//        CorrectInput(station.effiency);
//    }
//    return station;
//}
//
//void PrintCS(const CompressionStation& station) {
//    if (station.id != -1) {
//    cout << "Compressor station " << station.id << endl
//    << "Its character: " << endl;
//    cout << "Name: " << station.name << endl;
//    cout << "Number of workstations: " << station.numberWorkshop << endl;
//    cout << "Number of workstations in action: " << station.numberWorkshopInAtive << endl;
//    cout << "Station effiency: " << station.effiency << endl;
//    } else {
//        cout << "Compressor station does not exist" << endl;
//    }
//}
//
//void ChangeCs(CompressionStation& station) {
//    cout << "Enter number workstation in active" << endl;
//    int newNumberWorkstationInAction = 0;
//    CorrectInput(newNumberWorkstationInAction);
//    if(newNumberWorkstationInAction > station.numberWorkshop){
//        cout << "Invalid input" << endl;
//    } else {
//        station.numberWorkshopInAtive = newNumberWorkstationInAction;
//        cout << "New number of workshops: " << newNumberWorkstationInAction << endl;
//    }
//}
//
//void SaveCS(ofstream& output, const CompressionStation& station){
//    if (station.id != -1){
//    output << "Compressor station" << endl
//    << "id " << station.id << endl
//    << "name " << station.name << endl
//    << "number workshop " << station.numberWorkshop << endl
//    << "number workshop in action " << station.numberWorkshopInAtive << endl
//    << "effiency " << station.effiency;;
//    } else {
//        output << "Compressor station does not exist" << endl;
//    }
//}
//
//void LoadCS(ifstream& input, CompressionStation& station) {
//    string line;
//    getline(input,line);
//    if (line == "Compressor station"){
//        ParseString(input, station.id);
//        getline(input,station.name);
//        ParseString(input, station.numberWorkshop);
//        ParseString(input, station.numberWorkshopInAtive);
//        ParseString(input, station.effiency);
//    } else {
//        cout << "Compressor station did not save" << endl;
//    }
//}

