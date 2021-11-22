#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

class Pipe {
public:
    Pipe(const std::string& name,int new_diametr, double new_length, bool new_status);
    
    void ChangeStatusRepair();
    
    std::string GetName() const;
    
    bool GetStatusRepair() const;
    
    int GetDiametr() const;
    
    double GetLength() const;
    
private:
    std::string name;
    int diametr;
    double length;
    bool statusRepair;
};

class DatabasePipe {
public:
    void AddPipe();
    
    void DelPipe(int id);
    
    void ChangePipe(int id);
    
    void PrintPipes(std::ostream& os) const;
    
    void LoadPipe(std::istream& is);
    
    Pipe FindById(int id) const;
    
    std::vector<int> FindByName(const std::string& name) const;
    
    std::vector<int> FindByStatusRepair(bool status) const;
    
    
private:
    static int max_id;
    std::unordered_map<int, Pipe> db;
};

std::ostream& operator<<(std::ostream& os,const Pipe& pipe);
