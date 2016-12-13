//
// Created by Kirill Khlopko.
//

#include <iostream>

using std::cout;
using std::endl;

#include "enables.h"

void post();
void nam();
void sorting();
void graph();

int main(int argc, char** argv) {

#ifdef POST
    post();
#endif

#ifdef NAM
    nam();
#endif

#ifdef SORTING
    sorting();
#endif

#ifdef GRAPH
    graph();
#endif

    return 0;
}

#pragma mark post

void post() {
}

#pragma mark nam

void nam_test_1();
void nam_test_2();
void nam_test_word(string*);

void nam() {
    cout << "~~~ NAM ~~~" << endl;
    nam_test_1();
    nam_test_2();
    nam_test_word(new string("bdkdkaadb"));
    nam_test_word(new string("kbdabkadbd"));
}

#pragma mark sorting

template<typename T>
void print_array(T* a, const int size);

void sorting() {
}

#pragma mark graph

void process(const char*);
void dijkstra(Graph&);
void prim(Graph&);

void graph() {
    cout << "~~~ GRAPH ~~~" << endl;
    auto files = {"graph.xml", "wiki.xml"};
    for (auto f : files) {
        process(f);
        cout << endl;
    }
}

#pragma mark implementations

void nam_test_1() {
}

void nam_test_2() {
}

void nam_test_word(string* s) {
}

template<typename T>
void print_array(T* a, const int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
