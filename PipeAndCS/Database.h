#pragma once
#include "Pipe.h"
#include "CompressorStation.h"

class Database {
public:
    virtual void Add() = 0;

    virtual void Delete(int id) = 0;

    virtual void Change(int id) = 0;

    virtual void Print(std::ostream& os) const = 0;

    virtual void Load(std::istream& is) = 0;

    virtual void FindById(int id) const = 0;
    
    virtual bool Contains(int id) const = 0;

};

class DataPipe : public Database {
public:

    void Add() override;

    void Delete(int id) override;

    void Change(int id) override;

    void Print(std::ostream& os)const override;

    void Load(std::istream& is) override;

    void FindById(int id) const override;
    
    bool Contains(int id) const override;
    
    void PrintFreePipe() const;

    std::vector<int> FindByName(const std::string& name) const;

    std::vector<int> FindByStatusRepair(bool status) const;

    Pipe& PipeById(int id);

private:
    static int max_id;
    std::unordered_map<int, Pipe> db;
};

class DataCS : public Database {
public:

    void Add() override;

    void Delete(int id) override;

    void Change(int id) override;

    void Print(std::ostream& os) const override;

    void Load(std::istream& is) override;
    
    bool Contains(int id) const override;

    void FindById(int id) const override;
    
    CompressionStation& CsById(int id);

    std::vector<int> FindByName(const std::string& name) const;

    std::vector<int> FindByPercent(int percent) const;

private:
    static int max_id;
    std::unordered_map<int, CompressionStation> db;
};
