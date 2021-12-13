#pragma once
#include <vector>
#include <unordered_map>
#include <string>

class Pipe {
public:
    Pipe(const std::string& name,int new_diametr, double new_length, bool new_status, bool new_status_connect = false);
    
    void ChangeStatusRepair();
    
    std::string GetName() const;
    
    bool GetStatusRepair() const;
    
    int GetDiametr() const;
    
    double GetLength() const;

    bool GetStatusConnect() const;

    void ChangeStatusConnect();
    
private:
    std::string name;
    int diametr;
    double length;
    bool statusRepair;
    bool is_connect;
};

std::ostream& operator<<(std::ostream& os,const Pipe& pipe);
