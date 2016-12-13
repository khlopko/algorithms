
#include "graph/model.h"
#include "graph/graph.h"

#include <iostream>

using std::cout;
using std::endl;

void process(const char*);
void dijkstra(Graph&);
void prim(Graph&);

int main(int argc, char** argv) {
    auto files = { "graph.xml", "wiki.xml" };
    for (auto f : files) {
        process(f);
        cout << endl;
    }
    return 0;
}

const char* data = "../data/";

void process(const char* filename) {
    cout << "\n- PROCESSING GRAPH FROM FILE '" << filename << "'\n" << endl;
    char res[strlen(data) + strlen(filename)];
    strcpy(res, data);
    strcat(res, filename);
    Model model(res);
    Graph graph(&model);
    dijkstra(graph);
    cout << endl;
    prim(graph);
}

void dijkstra(Graph& graph) {
    cout << "Minimal ways from vertex (Dijkstra):" << endl;
    auto ways = graph.d(1);
    for (auto w : ways) {
        cout << "vertex." << w.first << " = " << w.second << endl;
    }
}

void prim(Graph& graph) {
    cout << "Minimal spanning tree (Prim):" << endl;
    auto f = graph.mst();
    for (auto row : *f) {
        for (auto item : row.second) {
            cout << "(" << row.first << "-" << item.first << ") = " << item.second << endl;
        }
    }
}
