#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class CompressionStation {
public:

    CompressionStation(const std::string& new_name,int new_numberWorkshop, int new_numberWorkshopInActive,
                       double new_effiency, bool new_status_connected = 0);
    
    std::string GetName() const;
    
    int GetNumberWorkshop() const;
    
    int GetNumberWorkshopInActive() const;

    int GetPercentOfUnactiveWorkshop() const;
    
    double GetEffiency() const;
    
    bool GetStatusConnected() const;
    
    void ChangeStatusConnected(bool status);

    void ChangeNumberOfWorkstationInActive(int new_number_workshop_active);
    
private:
    std::string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
    bool is_connected;
};

std::ostream& operator<<(std::ostream& os,const CompressionStation& station);
