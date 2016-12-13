//
// Created by Kirill Khlopko on 12/3/16.
//

#ifndef ALGORITMSCPP_MODEL_H
#define ALGORITMSCPP_MODEL_H

#include <vector>

class Model {
public:

    typedef std::pair<int, int> Edge;
    typedef std::pair<Edge, int> WeightedEdge;
    typedef std::vector<WeightedEdge> WeightedEdgesList;

    Model(const char* filename);
    ~Model();

    WeightedEdgesList *getEdges() const;

private:

    WeightedEdgesList* edges;
};


#endif //ALGORITMSCPP_MODEL_H
