#include "Network.h"

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
    CompressionStation station(name, numberWorkshop, numberWorkshopInActive, effiency);
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
    db.erase(id);
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
    is.ignore(5);
    is >> name;
    is.ignore(1);
    ParseString(is, numberWorkshop);
    ParseString(is, numberWorkshopInActive);
    ParseString(is, effiency);
    CompressionStation station(name, numberWorkshop, numberWorkshopInActive, effiency);
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

bool DataCS::Contains(int id) const {
    return db.contains(id);
}

bool DataPipe::Contains(int id) const {
    return db.contains(id);
}

void Network::Connect(int pipe_id, int OutCS_id, int InCS_id) {
    if (dataCS.Contains(OutCS_id) && dataCS.Contains(InCS_id) && dataPipe.Contains(pipe_id)) {
    if (!dataConnection.contains(pipe_id)) {
        dataConnection.emplace(pipe_id, PairCS(OutCS_id,InCS_id));
        graph[OutCS_id].insert(InCS_id);
        connected_cs.insert(OutCS_id);
        connected_cs.insert(InCS_id);
        dataPipe.PipeById(pipe_id).ChangeStatusConnect();
    } else {
        cout << "Pipe is already connected" << endl;
    }
    } else {
        cout << "Error" << endl;
    }
}

void Network::Disconnect(int pipe_id) {
    if (dataConnection.contains(pipe_id)) {
        dataConnection.erase(pipe_id);
        bool flag = true;
        for(const auto& [pipe,pair] : dataConnection) {
            if (pair == dataConnection[pipe_id]) {
                flag = false;
            };
        }
        if (flag) {
        graph[dataConnection[pipe_id].outCS].erase(dataConnection[pipe_id].inCS);
        }
        dataPipe.PipeById(pipe_id).ChangeStatusConnect();
    } else {
        cout << "Pipe does not connected" << endl;
    }
}

bool Network::CheckGraph(){
    for (const auto& [outCS, inCS] : graph) {
        for (auto i : inCS) {
            for (auto m : graph[i]) {
                if (outCS == m) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Network::topologicalSortUtil(int v, unordered_map<int,bool>& visited, stack<int> &Stack) {
    // Помечаем текущий узел как посещенный
    visited[v] = true;
  
    // Рекурсивно вызываем функцию для всех смежных вершин
    for (const auto& i : graph[v])
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);
  
    // Добавляем текущую вершину в стек с результатом
    Stack.push(v);
}

void Network::topologicalSort(){
    stack<int> Stack;
  
    // Помечаем все вершины как непосещенные
    unordered_map<int, bool> visit;
    
    for (const auto& i : connected_cs) {
        visit[i] = false;
    }
    // Вызываем рекурсивную вспомогательную функцию
    // для поиска топологической сортировки для каждой вершины
    for (const auto& key : connected_cs)
      if (visit[key] == false)
        topologicalSortUtil(key, visit, Stack);
  
    // Выводим содержимое стека
    while (Stack.empty() == false)
    {
        dataCS.FindById(Stack.top());
        Stack.pop();
    }
}

void DataPipe::PrintFreePipe() const {
    for (const auto& [id, pipe] : db) {
        if (!pipe.GetStatusConnect()) {
            cout << "ID " << id << endl;
            cout << pipe << endl;
        }
    }
}

void Network::PrintAllConnection(ostream& os) const {
    for (const auto& [pipe_id, pairCS] : dataConnection) {
        os << "Connection" << endl;
        os << "Pipe ID " << pipe_id << endl;
        os << "OutCS " << pairCS.outCS << endl;
        os << "InputCS " << pairCS.inCS << endl;
        os << endl;
    }
}

void Network::LoadConnection(istream& is) {
    int pipe_id, outCS_id,inCS_id;
    ParseString(is, pipe_id);
    ParseString(is, outCS_id);
    ParseString(is, inCS_id);
    Connect(pipe_id, outCS_id, inCS_id);
}

bool operator==(const PairCS& lhs, const PairCS& rhs) {
    return lhs.outCS == rhs.outCS && lhs.inCS == rhs.inCS;
}
