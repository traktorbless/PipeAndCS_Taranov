#include "Network.h"

using namespace std;

void Network::Connect(int pipe_id, int OutCS_id, int InCS_id) {
    if (dataCS.Contains(OutCS_id) && dataCS.Contains(InCS_id) && dataPipe.Contains(pipe_id)) {
    if (!dataConnection.contains(pipe_id)) {
        dataConnection.emplace(pipe_id, PairCS(OutCS_id,InCS_id));
        dataPipe.PipeById(pipe_id).ChangeStatusConnect();
        dataCS.CsById(OutCS_id).ChangeStatusConnected(true);
        dataCS.CsById(InCS_id).ChangeStatusConnected(true);
    } else {
        cout << "Pipe is already connected" << endl;
    }
    } else {
        cout << "The pipe or the stations don't exist" << endl;
    }
}

void Network::Disconnect(int pipe_id) {
    if (dataConnection.contains(pipe_id)) {
        int outCS = dataConnection[pipe_id].outCS;
        int inCS = dataConnection[pipe_id].inCS;
        dataConnection.erase(pipe_id);
        dataPipe.PipeById(pipe_id).ChangeStatusConnect();
        for (const auto& [pipe_id, pair_cs] : dataConnection) {
            if (pair_cs.outCS == outCS || pair_cs.inCS == outCS) {
                outCS = -1;
            }
            if (pair_cs.outCS == inCS || pair_cs.inCS == inCS) {
                inCS = -1;
            }
        }
        if (outCS != -1) {
            dataCS.CsById(outCS).ChangeStatusConnected(false);
        }
        if (inCS != -1) {
            dataCS.CsById(inCS).ChangeStatusConnected(false);
        }
    } else {
        cout << "Pipe does not connected" << endl;
    }
}

void Network::topologicalSortUtil(int v,const unordered_map<int, set<int>>& graph ,unordered_map<int,bool>& visited, stack<int> &Stack) {

    visited[v] = true;

    try{
    for (const auto& i : graph.at(v)){
        if (!visited[i])
            topologicalSortUtil(i,graph,visited, Stack);
    }
    } catch (exception& e){}
  
    Stack.push(v);
}

void Network::topologicalSort(){
    stack<int> Stack;
  
    unordered_map<int, bool> visit;
    
    unordered_map<int, set<int>> graph;
    
    set<int> connected_cs;
    
    for (const auto& [pipe_id, pair_cs] : dataConnection) {
        connected_cs.insert(pair_cs.outCS);
        connected_cs.insert(pair_cs.inCS);
        graph[pair_cs.outCS].insert(pair_cs.inCS);
    }
    
    for (const auto& i : connected_cs) {
        visit[i] = false;
    }

    for (const auto& key : connected_cs)
      if (visit[key] == false)
        topologicalSortUtil(key,graph,visit, Stack);
  
    while (Stack.empty() == false)
    {
        dataCS.FindById(Stack.top());
        Stack.pop();
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
