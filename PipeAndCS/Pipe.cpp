#include "Pipe.h"
#include "Function.h"


using namespace std;

Pipe::Pipe(const string& new_name,int new_diametr, double new_length, bool new_status) {
    name = new_name;
    diametr = new_diametr;
    length = new_length;
    statusRepair = new_status;
}

void Pipe::ChangeStatusRepair() {
    statusRepair = !statusRepair;
}

bool Pipe::GetStatusRepair() const {
    return statusRepair;
}

int Pipe::GetDiametr() const {
    return diametr;
}

string Pipe::GetName() const {
    return name;
}

double Pipe::GetLength() const {
    return length;
}

ostream& operator<<(ostream& os, const Pipe& pipe) {
    os << "Pipe" << endl;
    os << pipe.GetName() << endl;
    os << "Diametr " << pipe.GetDiametr() << endl;
    os << "Length " << pipe.GetLength() << endl;
    os << "Status repair " << pipe.GetStatusRepair() << endl;
    return os;
}
