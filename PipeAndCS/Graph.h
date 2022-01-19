#pragma once
#include <unordered_map>
#include <vector>
#include <map>
#include <stack>
#include <numeric>
#include <algorithm>
#include <queue>

const auto INF = std::numeric_limits<int>::max();

struct Edge {
    int weight;
    int indexTo;
};

struct Node {
    int id;
    std::vector<Edge> edges;
    
    std::size_t prevIndex;
    int weight;
    bool visited;
};

struct Graph {
    std::unordered_map<size_t, Node> nodes;
    
    void clear();
    
    void clear_edges();
    
    void init_start_values();
}
;

void AlgorithmDeikstra(Graph& graph,int start_index, int end_index);

int MaxStream(Graph& graph, int start_index, int end_index);

std::vector<size_t> short_path(Graph& graph,int start_index, int end_index);
