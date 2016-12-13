//
// Created by Kirill Khlopko on 12/5/16.
//

#include <iostream>
#include <cmath>
#include "graph.h"

Graph::Graph(Model *model) {
    m = new Matrix();
    Model::WeightedEdgesList *list = model->getEdges();
    std::sort((*list).begin(), (*list).end(), [](Model::WeightedEdge a, Model::WeightedEdge b) {
        if (a.first.first == b.first.first) {
            if (a.first.second == b.first.second) {
                return a.second < b.second;
            }
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    });
    Vertex vertex = -1;
    std::set<Edge> a;
    count = 0;
    for (auto weighted : *list) {
        if (vertex != weighted.first.first && vertex != -1) {
            (*m)[vertex] = a;
            a.clear();
            count += 1;
        }
        vertex = weighted.first.first;
        auto e = Edge(weighted.first.second, weighted.second);
        a.insert(a.begin(), e);
    }
    (*m)[vertex] = a;
    count += 1;
    a.clear();
}

Graph::~Graph() {
    delete m;
}

Graph::Ways Graph::d(Vertex from) {
    Graph::Ways ways;
    std::map<Vertex, bool> visited;
    for (auto k : *m) {
        ways[k.first] = INT_MAX;
        visited[k.first] = false;
    }
    ways[from] = 0;
    Vertex current = from;
    Vertex min_weighted;
    Weight min_weight;
    while (!visited[current]) {
        min_weighted = -1;
        min_weight = INT_MAX;
        for (auto e : (*m)[current]) {
            if (!visited[e.first]) {
                if (e.second < min_weight) {
                    min_weighted = e.first;
                    min_weight = e.second;
                }
            }
            if (ways[current] + e.second < ways[e.first]) {
                ways[e.first] = ways[current] + e.second;
            }
        }
        visited[current] = true;
        current = min_weighted;
    }
    return ways;
}

Graph::Matrix* Graph::mst() {
    Matrix* f = new Matrix();
    std::map<Vertex, Weight> min_egdes;
    std::map<Vertex, Vertex> sel_edges;
    for (int i = 1; i <= count; ++i) {
        min_egdes[i] = INT_MAX;
        sel_edges[i] = -1;
    }
    Weight w;
    Vertex v;
    std::set<Edge> l;
    std::set< std::pair<Weight, Vertex> > queue;
    queue.insert(queue.begin(), std::pair<Weight, Vertex>(0, 1));
    for (int i = 0; i <= (*m).size(); ++i) {
        if (queue.empty()) {
            std::cout << "No minimal spanning tree!" << std::endl;
            break;
        }
        v = queue.begin()->second;
        queue.erase(queue.begin());
        if (sel_edges[v] != -1) {
            (*f)[v].insert((*f)[v].begin(), Edge(sel_edges[v], min_egdes[v]));
        }
        l = (*m)[v];
        for (auto k = l.begin(); k != l.end(); ++k) {
            auto d = *k;
            w = d.second;
            if (w < min_egdes[d.first]) {
                queue.erase(std::pair<Weight, Vertex>(min_egdes[d.first], d.first));
                min_egdes[d.first] = w;
                sel_edges[d.first] = v;
                queue.insert(queue.end(), std::pair<Weight, Vertex>(min_egdes[d.first], d.first));
            }
        }
    }
    return f;
}
