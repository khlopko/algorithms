//
// Created by Kirill Khlopko on 12/5/16.
//

#ifndef ALGORITMSCPP_GRAPH_H
#define ALGORITMSCPP_GRAPH_H

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#include "model.h"

class Graph {
public:

    typedef int Vertex;
    typedef long Weight;
    typedef std::map<Vertex, Weight> Ways;
    typedef std::pair<Vertex, Weight> Edge;
    typedef std::map< Vertex, std::set<Edge> > Matrix;

    Graph(Model *);
    ~Graph();

    Ways d(Vertex);
    Matrix* mst();
private:

    int count;
    Matrix *m;
};


#endif //ALGORITMSCPP_GRAPH_H
