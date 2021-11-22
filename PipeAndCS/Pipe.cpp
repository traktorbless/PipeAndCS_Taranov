#include "Pipe.h"
#include "Function.h"
#include <sstream>

using namespace std;

int DatabasePipe::max_id = 1;

Pipe::Pipe(const string& new_name,int new_diametr, double new_length, bool new_status) {
    name = new_name;
    diametr = new_diametr;
    length = new_length;
    statusRepair = new_status;
}

void DatabasePipe::LoadPipe(istream& is) {
    string name;
    int diametr, id;
    double length;
    bool statusRepair;
    getline(is, name);
    ParseString(is,diametr);
    ParseString(is,length);
    ParseString(is,statusRepair);
    Pipe p(name,diametr,length,statusRepair);
    ParseString(is, id);
    db.emplace(id,p);
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

void DatabasePipe::AddPipe() {
    string name;
    int diametr;
    double length;
    cout << "Enter name: ";
    cin.ignore(1);
    getline(cin,name);
    cout << "Enter diametr: ";
    CorrectInput(diametr);
    cout << "Enter length: ";
    CorrectInput(length);
    Pipe p(name,diametr,length,true);
    while(db.contains(max_id)){
        ++max_id;
    }
    db.emplace(max_id++,p);
}

Pipe DatabasePipe::FindById(int id) const {
    return db.at(id);
}

vector<int> DatabasePipe::FindByName(const string& name) const {
    vector<int> result;
    for(auto [id,pipe] : db) {
        if (pipe.GetName() == name) {
            result.push_back(id);
        }
    }
    return result;
}

vector<int> DatabasePipe::FindByStatusRepair(bool status) const {
    vector<int> result;
    for(auto [id,pipe] : db) {
        if (pipe.GetStatusRepair() == status) {
            result.push_back(id);
        }
    }
    return result;
}

void DatabasePipe::DelPipe(int id) {
    db.erase(id);
}

void DatabasePipe::ChangePipe(int id) {
    db.at(id).ChangeStatusRepair();
}

void DatabasePipe::PrintPipes(ostream& os) const {
    for (const auto& [key,pipe] : db) {
        os << pipe;
        os << "ID " << key << endl << endl;
    }
}

ostream& operator<<(ostream& os, const Pipe& pipe) {
    os << "Pipe" << endl;
    os << pipe.GetName() << endl;
    os << "Diametr " << pipe.GetDiametr() << endl;
    os << "Length " << pipe.GetLength() << endl;
    os << "Status repair " << pipe.GetStatusRepair() << endl;
    return os;
}
