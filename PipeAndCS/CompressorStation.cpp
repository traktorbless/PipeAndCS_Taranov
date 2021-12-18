#include "CompressorStation.h"
#include "Function.h"

using namespace std;

CompressionStation::CompressionStation(const std::string& new_name,int new_numberWorkshop, int new_numberWorkshopInActive, double new_effiency, bool new_status_connected) {
    name = new_name;
    numberWorkshop = new_numberWorkshop;
    numberWorkshopInAtive = new_numberWorkshopInActive;
    effiency = new_effiency;
    is_connected = new_status_connected;
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
    return 100 * (1 - numberWorkshopInAtive / numberWorkshop);
}

bool CompressionStation::GetStatusConnected() const {
    return is_connected;
}

void CompressionStation::ChangeStatusConnected(bool status) {
    is_connected = status;
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

ostream& operator<<(ostream& os,const CompressionStation& station) {
    os << "Compressor station" << endl;
    os << "Name " << station.GetName() << endl;
    os << "Number of workshops " << station.GetNumberWorkshop() << endl;
    os << "Number of workshops in active " << station.GetNumberWorkshopInActive() << endl;
    os << "Effiency " << station.GetEffiency() << endl;
    os << "Status connected " << station.GetStatusConnected() << endl;
    return os;
}

