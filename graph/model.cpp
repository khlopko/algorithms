//
// Created by Kirill Khlopko on 12/3/16.
//

#include "Model.h"

#include <fstream>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;

void read(std::ifstream& in, std::stringstream& ss, string *from, int *to, size_t s_pos) {
    in >> *from;
    ss << from->substr(s_pos, from->size() - s_pos - 1);
    ss >> *to;
    ss.clear();
    ss.str("");
}

Model::Model(const char* filename) {
    std::ifstream in(filename, std::ios_base::in);
    edges = new WeightedEdgesList();
    if (in.fail()) {
        return;
    }
    string line;
    string *from_str = new string(10, ' '), *to_str = new string(8, ' '), *weight_str = new string(13, ' ');
    in.seekg(0);
    while (!in.eof()) {
        in >> line;
        if (!line.compare("<lines>")) {
            break;
        }
    }
    int from, to, weight;
    while (!in.eof()) {
        std::stringstream ss;
        in >> line;
        if (!line.compare("</lines>")) {
            break;
        }
        in >> line;
        read(in, ss, from_str, &from, 6);
        read(in, ss, to_str, &to, 4);
        read(in, ss, weight_str, &weight, 8);
        in >> line;
        edges->push_back(WeightedEdge(Edge(from, to), weight));
    }
}

Model::~Model() {
    delete edges;
}

Model::WeightedEdgesList *Model::getEdges() const {
    return edges;
}
