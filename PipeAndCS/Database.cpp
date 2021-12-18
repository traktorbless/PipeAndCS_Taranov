//
//  Database.cpp
//  PipeAndCs
//
//  Created by Антон Таранов on 14.12.2021.
//

#include "Database.h"
#include "Function.h"
#include "iostream"

using namespace std;

int DataPipe::max_id = 1;

int DataCS::max_id = 1;

void DataPipe::Add() {
    string name;
    int diametr;
    double length;
    cout << "Enter name: ";
    cin.ignore(1);
    getline(cin, name);
    cout << "Enter diametr: ";
    CorrectInput(diametr);
    cout << "Enter length: ";
    CorrectInput(length);
    Pipe p(name, diametr, length, true);
    while (db.contains(max_id)) {
        ++max_id;
    }
    db.emplace(max_id++, p);
}

void DataCS::Add() {
    string name;
    int numberWorkshop, numberWorkshopInActive;
    double effiency;
    cout << "Enter name station: ";
    cin.ignore(1);
    getline(cin, name);
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
    while (effiency > 1) {
        cout << "Invalid input" << endl;
        CorrectInput(effiency);
    }
    CompressionStation station(name, numberWorkshop, numberWorkshopInActive, effiency, 0);
    while (db.contains(max_id)) {
        ++max_id;
    }
    db.emplace(max_id++, station);
}

void DataPipe::Delete(int id) {
    if (!db.at(id).GetStatusConnect()) {
        db.erase(id);
    }
    else {
        cout << "Pipe with ID " << id << " can't be removed, because it connects the compressor stations" << endl;
    }
}

void DataCS::Delete(int id) {
    if (!db.at(id).GetStatusConnected())
    {
        db.erase(id);
    } else {
        cout << "CS " << id << " cant't be removed, because it connected" << endl;
    }
}

void DataPipe::Change(int id) {
    db.at(id).ChangeStatusRepair();
}

void DataCS::Change(int id) {
    cout << "Enter new workstation in active" << endl;
    int new_workstation_in_active;
    CorrectInput(new_workstation_in_active);
    db.at(id).ChangeNumberOfWorkstationInActive(new_workstation_in_active);
}

void DataPipe::Print(ostream& os) const {
    for (const auto& [key, pipe] : db) {
        os << pipe;
        os << "ID " << key << endl << endl;
    }
}

void DataCS::Print(ostream& os) const {
    for (const auto& [key, station] : db) {
        os << station;
        os << "ID " << key << endl << endl;
    }
}

void DataPipe::Load(istream& is) {
    string name;
    int diametr, id;
    double length;
    bool statusRepair,statusConnect;
    getline(is, name);
    ParseString(is, diametr);
    ParseString(is, length);
    ParseString(is, statusRepair);
    ParseString(is, statusConnect);
    Pipe p(name, diametr, length, statusRepair);
    ParseString(is, id);
    db.emplace(id, p);
}

void DataCS::Load(istream& is)
{
    int id, numberWorkshop, numberWorkshopInActive;
    string name;
    double effiency;
    bool statusConnect;
    is.ignore(5);
    is >> name;
    is.ignore(1);
    ParseString(is, numberWorkshop);
    ParseString(is, numberWorkshopInActive);
    ParseString(is, effiency);
    ParseString(is, statusConnect);
    CompressionStation station(name, numberWorkshop, numberWorkshopInActive, effiency, statusConnect);
    ParseString(is, id);
    db.emplace(id, station);
}

void DataPipe::FindById(int id) const {
    std::cout << db.at(id) << std::endl;
}

void DataCS::FindById(int id) const {
    std::cout << db.at(id) << std::endl;
}

vector<int> DataPipe::FindByName(const string& name) const {
    vector<int> result;
    for (auto [id, pipe] : db) {
        if (pipe.GetName() == name) {
            result.push_back(id);
        }
    }
    return result;
}

vector<int> DataPipe::FindByStatusRepair(bool status) const {
    vector<int> result;
    for (auto [id, pipe] : db) {
        if (pipe.GetStatusRepair() == status) {
            result.push_back(id);
        }
    }
    return result;
}

vector<int> DataCS::FindByName(const string& name) const {
    vector<int> result;
    for (const auto& [id, station] : db) {
        if (station.GetName() == name) {
            result.push_back(id);
        }
    }
    return result;
}

vector<int> DataCS::FindByPercent(int percent) const {
    vector<int> result;
    for (const auto& [id, station] : db) {
        if (percent == 100 * double(station.GetNumberWorkshop() - station.GetNumberWorkshopInActive()) / station.GetNumberWorkshop()) {
            result.push_back(id);
        }
    }
    return result;
}

Pipe& DataPipe::PipeById(int id) {
    return db.at(id);
}

CompressionStation& DataCS::CsById(int id) {
    return db.at(id);
}

bool DataCS::Contains(int id) const {
    return db.contains(id);
}

bool DataPipe::Contains(int id) const {
    return db.contains(id);
}

void DataPipe::PrintFreePipe() const {
    for (const auto& [id, pipe] : db) {
        if (!pipe.GetStatusConnect()) {
            cout << "ID " << id << endl;
            cout << pipe << endl;
        }
    }
}
