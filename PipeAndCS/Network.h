#pragma once
#include "Database.h"
#include "Function.h"
#include <set>

struct PairCS {
	PairCS(int outCS, int inCS) {
        this->outCS = outCS;
        this->inCS = inCS;
    }
    PairCS() = default;
    int outCS;
	int inCS;
};

class Network {
public:

	void Connect(int pipe_id, int OutCS_id, int InCS_id);
	
	void Disconnect(int pipe_id);
    
    void PrintAllConnection(std::ostream& os) const;
    
    void LoadConnection(std::istream& os);
    
    void topologicalSort();

	DataCS dataCS;

	DataPipe dataPipe;

private:
    
	std::unordered_map<int, PairCS> dataConnection;
    
    void topologicalSortUtil(int v,const unordered_map<int, set<int>>& graph ,unordered_map<int,bool>& visited, stack<int> &Stack);

};

bool operator==(const PairCS& lhs, const PairCS& rhs);
