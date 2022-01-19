#pragma once
#include "Database.h"
#include "Function.h"
#include "Graph.h"
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
    
    bool CheckCycleInGraph() const;
    
    void topologicalSort() const;
    
    void FindShortcut(int firstCS, int lastCS);
    
    int FindMaxStream(int firstCS, int lastCS);

	DataCS dataCS;

	DataPipe dataPipe;

private:
    
	std::unordered_map<int, PairCS> dataConnection;
    
    Graph CreateGraph();
    
    
    void topologicalSortUtil(int v,const unordered_map<int, set<int>>& graph ,unordered_map<int,bool>& visited, stack<int> &Stack) const;
    
    bool dfc(int v,set<int> g, unordered_map<int, int>& color);

};

bool operator==(const PairCS& lhs, const PairCS& rhs);
