#include "Pipe.h"
#include "Function.h"
#include <sstream>

using namespace std;

int Pipe::max_id = 1;

Pipe::Pipe(int new_diametr, double new_length,bool new_status = true, int new_id = max_id++) {
    id = new_id;
    diametr = new_diametr;
    length = new_length;
    statusRepair = new_status;
}

void DatabasePipe::LoadPipe(istream& is) {
    int id,diametr;
    double length;
    bool statusRepair;
    ParseString(is, id);
    ParseString(is,diametr);
    ParseString(is,length);
    ParseString(is,statusRepair);
    Pipe p(diametr,length,statusRepair,id);
    db.push_back(p);
}

void Pipe::ChangeStatusRepair() {
    statusRepair = !statusRepair;
}

bool Pipe::GetStatusRepair() const {
    return statusRepair;
}

int Pipe::GetId() const {
    return id;
}

int Pipe::GetDiametr() const {
    return diametr;
}

double Pipe::GetLength() const {
    return length;
}

void DatabasePipe::AddPipe() {
    int diametr;
    double length;
    cout << "Enter diametr: ";
    CorrectInput(diametr);
    cout << "Enter length: ";
    CorrectInput(length);
    Pipe p(diametr,length);
    db.push_back(p);
}

vector<Pipe>::const_iterator DatabasePipe::FindById(int id) const {
    auto it = find_if(begin(db),end(db),[id](const Pipe& p){
        return id == p.GetId();
    });
    if(it == end(db)) {
        throw logic_error("Pipe does not found");
    }
    return it;
}

vector<Pipe> DatabasePipe::FindByStatusRepair(bool status) const {
    vector<Pipe> result;
    copy_if(begin(db),end(db),back_inserter(result),[status](const Pipe& pipe){
        return pipe.GetStatusRepair() == status;
    });
    return result;
}

void DatabasePipe::DelPipe(vector<Pipe>::const_iterator it) {
    db.erase(it);
}

void DatabasePipe::ChangePipe(vector<Pipe>::const_iterator it) {
    db[it - begin(db)].ChangeStatusRepair();
}

void DatabasePipe::ChangeSetById(int id1, int id2) {
    auto it1 = FindById(id1);
    auto it2 = FindById(id2);
    ChangePipe(it1);
    while (it1 != it2) {
        ++it1;
        ChangePipe(it1);
    }
}

void DatabasePipe::ChangeSetByStatus(bool status) {
    for(Pipe& pipe: db) {
        if (pipe.GetStatusRepair() == status) {
            pipe.ChangeStatusRepair();
        }
    }
}

void DatabasePipe::PrintPipes(ostream& os) const {
    for(const Pipe& pipe : db) {
        os << pipe << endl;
    }
}

ostream& operator<<(ostream& os, const Pipe& pipe) {
    os << "Pipe" << endl;
    os << "Id " << pipe.GetId() << endl;
    os << "Diametr " << pipe.GetDiametr() << endl;
    os << "Length " << pipe.GetLength() << endl;
    os << "Status repair " << pipe.GetStatusRepair() << endl;
    return os;
}
