#pragma once
#include "Pipe.h"
#include "CompressorStation.h"
#include "Function.h"
#include <vector>
#include <unordered_map>
#include <set>
#include <map>

class Database {
public:
	virtual void Add() = 0;

	virtual void Delete(int id) = 0;

	virtual void Change(int id) = 0;

	virtual void Print(std::ostream& os) const = 0;

	virtual void Load(std::istream& is) = 0;

	virtual void FindById(int id) const = 0;

};

class DataPipe : public Database {
public:

	void Add() override;

	void Delete(int id) override;

	void Change(int id) override;

	void Print(std::ostream& os)const override;

	void Load(std::istream& is) override;

	void FindById(int id) const;

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

	void FindById(int id) const;

	std::vector<int> FindByName(const std::string& name) const;

	std::vector<int> FindByPercent(int percent) const;

private:
	static int max_id;
	std::unordered_map<int, CompressionStation> db;
};

struct PairCS {
	PairCS(int new_outCS, int new_inCS) : outCS(new_outCS), inCS(new_inCS) {}
	const int outCS;
	const int inCS;
};

class Network {
public:

	void Connect(int pipe_id, int OutCS_id, int InCS_id);
	
	void Disconnect(int pipe_id);

	DataCS dataCS;

	DataPipe dataPipe;

private:
	std::unordered_map<int, PairCS> dataConnection;

};