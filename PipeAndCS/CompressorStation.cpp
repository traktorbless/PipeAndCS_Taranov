#include "CompressorStation.h"
#include "Function.h"

using namespace std;

int CompressionStation::max_id = 1;

CompressionStation::CompressionStation(const std::string& new_name,int new_numberWorkshop, int new_numberWorkshopInActive, double new_effiency, int new_id = max_id++) {
    id = new_id;
    name = new_name;
    numberWorkshop = new_numberWorkshop;
    numberWorkshopInAtive = new_numberWorkshopInActive;
    effiency = new_effiency;
}

int CompressionStation::GetId() const {
    return id;
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
    db.push_back(station);
}

void DatabaseCS::LoadCS(istream& is) {
    int id, numberWorkshop,numberWorkshopInActive;
    string name;
    double effiency;
    ParseString(is, id);
    getline(is,name);
    ParseString(is, numberWorkshop);
    ParseString(is, numberWorkshopInActive);
    ParseString(is, effiency);
    CompressionStation station(name,numberWorkshop,numberWorkshopInActive,effiency,id);
    db.push_back(station);
}

void DatabaseCS::DelCS(vector<CompressionStation>::const_iterator it) {
    db.erase(it);
}

void DatabaseCS::ChangeCS(vector<CompressionStation>::const_iterator it) {
    cout << "Enter new workstation in active" << endl;
    int new_workstation_in_active;
    CorrectInput(new_workstation_in_active);
    db[it - begin(db)].ChangeNumberOfWorkstationInActive(new_workstation_in_active);
}

void DatabaseCS::PrintCS(ostream& os) const {
    for (const CompressionStation& station : db) {
        os << station << endl;
    }
}

vector<CompressionStation>::const_iterator DatabaseCS::FindById(int id) const {
    auto it = find_if(begin(db),end(db),[id](const CompressionStation& station){
        return id == station.GetId();
    });
    if (it == end(db)) {
        throw logic_error("Pipe does not found");
    }
    return it;
}

vector<CompressionStation> DatabaseCS::FindByName(const string& name) const {
    vector<CompressionStation> result;
    copy_if(begin(db),end(db),back_inserter(result),[name](const CompressionStation& station){
        return name == station.GetName();
    });
    return result;
}

void DatabaseCS::ChangeSetById(int id1, int id2) {
    auto it1 = FindById(id1);
    auto it2 = FindById(id2);
    ChangeCS(it1);
    while (it1 != it2) {
        ++it1;
        ChangeCS(it1);
    }
}

vector<CompressionStation> DatabaseCS::FindByPercent(int percent) const {
    vector<CompressionStation> result;
    copy_if(begin(db),end(db),back_inserter(result),[percent](const CompressionStation& station){
        return percent == 100 * double(station.GetNumberWorkshop() - station.GetNumberWorkshopInActive())/station.GetNumberWorkshop();
    });
    return result;
}

ostream& operator<<(ostream& os,const CompressionStation& station) {
    os << "Compressor station" << endl;
    os << "Id " << station.GetId() << endl;
    os << station.GetName() << endl;
    os << "Number of workshops " << station.GetNumberWorkshop() << endl;
    os << "Number of workshops in active " << station.GetNumberWorkshopInActive() << endl;
    os << "Effiency " << station.GetEffiency() << endl;
    return os;
}

