#include "CompressorStation.h"
#include "Function.h"

using namespace std;

int DatabaseCS::max_id = 1;

CompressionStation::CompressionStation(const std::string& new_name,int new_numberWorkshop, int new_numberWorkshopInActive, double new_effiency) {
    name = new_name;
    numberWorkshop = new_numberWorkshop;
    numberWorkshopInAtive = new_numberWorkshopInActive;
    effiency = new_effiency;
}

string CompressionStation::GetName() const {
    return name;
}

int CompressionStation::GetNumberWorkshop() const {
    return numberWorkshop;
}

int CompressionStation::GetNumberWorkshopInActive() const {
    return numberWorkshopInAtive;
}

int CompressionStation::GetPercentOfUnactiveWorkshop() const
{
    return 100 * double(numberWorkshop - numberWorkshopInAtive) / numberWorkshop;
}

void CompressionStation::ChangeNumberOfWorkstationInActive(int new_number_workshop_active) {
        if(new_number_workshop_active > numberWorkshop){
            cout << "Invalid input" << endl;
        } else {
            numberWorkshopInAtive = new_number_workshop_active;
            cout << "New number of workshops: " << new_number_workshop_active << endl;
        }
}

double CompressionStation::GetEffiency() const {
    return effiency;
}

void DatabaseCS::AddCS() {
    string name;
    int numberWorkshop,numberWorkshopInActive;
    double effiency;
    cout << "Enter name station: ";
    cin.ignore(1);
    getline(cin,name);
    cout << "Enter number of workstaions: ";
    CorrectInput(numberWorkshop);
    cout << "Enter number of workstation in action: ";
    CorrectInput(numberWorkshopInActive);
    while (numberWorkshopInActive > numberWorkshop) {
        cout << "Invalid input" << endl;
        CorrectInput(numberWorkshopInActive);
    }
    cout << "Enter station effiency: ";
    CorrectInput(effiency);
    while(effiency > 1) {
        cout << "Invalid input" << endl;
        CorrectInput(effiency);
    }
    CompressionStation station(name,numberWorkshop,numberWorkshopInActive,effiency);
    while(db.contains(max_id)){
        ++max_id;
    }
    db.emplace(max_id++,station);
}

void DatabaseCS::LoadCS(istream& is) {
    int id, numberWorkshop,numberWorkshopInActive;
    string name;
    double effiency;
    getline(is,name);
    ParseString(is, numberWorkshop);
    ParseString(is, numberWorkshopInActive);
    ParseString(is, effiency);
    CompressionStation station(name,numberWorkshop,numberWorkshopInActive,effiency);
    ParseString(is, id);
    db.emplace(id , station);
}

void DatabaseCS::DelCS(int id) {
    db.erase(id);
}

void DatabaseCS::ChangeCS(int id) {
    cout << "Enter new workstation in active" << endl;
    int new_workstation_in_active;
    CorrectInput(new_workstation_in_active);
    db.at(id).ChangeNumberOfWorkstationInActive(new_workstation_in_active);
}

void DatabaseCS::PrintCS(ostream& os) const {
    for (const auto& [key,station] : db) {
        os << station;
        os << "ID " << key << endl << endl;
    }
}

CompressionStation DatabaseCS::FindById(int id) const {
    return db.at(id);
}

vector<int> DatabaseCS::FindByName(const string& name) const {
    vector<int> result;
    for (const auto& [id,station] : db) {
        if (station.GetName() == name) {
            result.push_back(id);
        }
    }
    return result;
}

vector<int> DatabaseCS::FindByPercent(int percent) const {
    vector<int> result;
    for (const auto& [id,station] : db) {
        if (percent == 100 * double(station.GetNumberWorkshop() - station.GetNumberWorkshopInActive())/station.GetNumberWorkshop()) {
            result.push_back(id);
        }
    }
    return result;
}

ostream& operator<<(ostream& os,const CompressionStation& station) {
    os << "Compressor station" << endl;
    os << "Name " << station.GetName() << endl;
    os << "Number of workshops " << station.GetNumberWorkshop() << endl;
    os << "Number of workshops in active " << station.GetNumberWorkshopInActive() << endl;
    os << "Effiency " << station.GetEffiency() << endl;
    return os;
}

