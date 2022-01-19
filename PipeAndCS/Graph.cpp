#include "Graph.h"

using namespace std;

void Graph::init_start_values() {
    for (auto& [id, node]: nodes) {
        node.weight = INF;
        node.visited = false;
        node.prevIndex = INF;
    }
}

void Graph::clear() {
    nodes.clear();
}

void Graph::clear_edges() {
    for (auto& [id, node]: nodes) {
        node.edges.clear();
    }
}

void AlgorithmDeikstra(Graph& graph, int start_index, int end_index) {
    graph.init_start_values();
    std::multimap<int, std::size_t> min_weigth_map;
    graph.nodes[start_index].weight = 0;
    min_weigth_map.insert({ 0, start_index });
    while (!min_weigth_map.empty())
    {
        int current_weight = min_weigth_map.begin()->first;
        size_t current_index = min_weigth_map.begin()->second;
        min_weigth_map.erase(min_weigth_map.begin());
        if (graph.nodes[current_index].visited)
        {
            continue;
        }
        graph.nodes[current_index].visited = true;

        for (const auto& i : graph.nodes[current_index].edges) {
            std::size_t index_to = i.indexTo;
            int edged_weight = i.weight;
            if (!graph.nodes[index_to].visited)
            {
                if (current_weight + edged_weight < graph.nodes[index_to].weight)
                {
                    graph.nodes[index_to].weight = current_weight + edged_weight;
                    graph.nodes[index_to].prevIndex = current_index;
                    min_weigth_map.insert({ graph.nodes[index_to].weight, index_to });
                }
            }
        }
    }
}

vector<size_t> short_path(Graph& graph, int start_index, int end_index) {
    std::vector<std::size_t> result;
    std::stack<std::size_t> tmp_path;
    std::size_t current_node = end_index;
    while (current_node != INF)
    {
        tmp_path.push(current_node);
        current_node = graph.nodes[current_node].prevIndex;
    }
    while (!tmp_path.empty())
    {
        result.push_back(tmp_path.top());
        tmp_path.pop();
    }
    return result;
}

void ReturnStream(Graph& graph, int end_index) {
    size_t current_node = graph.nodes[end_index].prevIndex;
    size_t index_to = end_index;
    while(current_node != INF) {
        for(auto& i : graph.nodes[current_node].edges) {
            if (i.indexTo == index_to) {
                i.weight = i.weight - graph.nodes[end_index].weight;
            }
        }
        index_to = current_node;
        current_node = graph.nodes[current_node].prevIndex;
    }
}

int MaxStream(Graph& graph, int start_index, int end_index) {
    int max_stream = 0;
    while(true) {
        graph.init_start_values();
        queue<int> check_index;
        check_index.push(start_index);
    while(!check_index.empty())
    {
        int current_index = check_index.front();
        for (auto& edge : graph.nodes[current_index].edges) {
            if(graph.nodes[edge.indexTo].visited || edge.weight == 0) {
                continue;
            }
            graph.nodes[edge.indexTo].visited = true;
            graph.nodes[edge.indexTo].prevIndex = current_index;
            graph.nodes[edge.indexTo].weight = min(edge.weight,graph.nodes[current_index].weight);
            check_index.push(edge.indexTo);
        }
        check_index.pop();
    }
    if (graph.nodes[end_index].weight == INF) {
        return max_stream;
    }
        max_stream += graph.nodes[end_index].weight;
        ReturnStream(graph,end_index);
    }
}
