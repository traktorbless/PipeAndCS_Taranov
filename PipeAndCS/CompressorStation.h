#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class CompressionStation {
public:

    CompressionStation(const std::string& new_name,int new_numberWorkshop, int new_numberWorkshopInActive,
                       double new_effiency);
    
    std::string GetName() const;
    
    int GetNumberWorkshop() const;
    
    int GetNumberWorkshopInActive() const;
    
    double GetEffiency() const;

    void ChangeNumberOfWorkstationInActive(int new_number_workshop_active);
    
private:
    std::string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
};

class DatabaseCS {
public:
    void AddCS();
    
    void DelCS(int id);
    
    void ChangeCS(int id);
    
    void PrintCS(std::ostream& os) const;
    
    void LoadCS(std::istream& is);
    
    CompressionStation FindById(int id) const;
    
    std::vector<int> FindByName(const std::string& name) const;
    
    std::vector<int> FindByPercent(int percent) const;
    
private:
    static int max_id;
    std::unordered_map<int, CompressionStation> db;
};

std::ostream& operator<<(std::ostream& os,const CompressionStation& station);
