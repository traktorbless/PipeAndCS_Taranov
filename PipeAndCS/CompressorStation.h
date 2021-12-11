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

    int GetPercentOfUnactiveWorkshop() const;
    
    double GetEffiency() const;

    void ChangeNumberOfWorkstationInActive(int new_number_workshop_active);
    
private:
    std::string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
};

std::ostream& operator<<(std::ostream& os,const CompressionStation& station);
