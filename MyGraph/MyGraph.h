//
// Created by Roman Ivanov on 13.11.2023.
//

#ifndef PROJECT_MYGRAPH_H
#define PROJECT_MYGRAPH_H
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

class MyGraph{
public:
class MyVertex{
public:
    explicit MyVertex(int value): value(value), color(0){}
    int value;
    int color;
    std::vector<MyGraph::MyVertex*> adjacentVertices;
};

    explicit MyGraph(MyVertex* start): start(start){
        this->vertexesSet = std::set<MyVertex*>();
        this->_fillVertexesSet(start);
        this->checkedVertexes = std::set<MyVertex*>();
        this->colors = std::set<int>();
        this->vertexStack = std::stack<MyVertex*>();
        this->vertexQueue = std::queue<MyVertex*>();
        this->colors.insert(1);
    }

    MyVertex* start;
    std::set<MyVertex*> vertexesSet;
    std::set<MyVertex*> checkedVertexes;
    std::set<int> colors;
    std::stack<MyVertex*> vertexStack;
    std::queue<MyVertex*> vertexQueue;

    void colorGraphBFS(MyVertex *current);
    void colorGraphDFS(MyVertex *current);
    void colorGraphGreedy();
    void resetColors();
private:
    void _colorVertex(MyVertex *current);
    void _fillVertexesSet(MyVertex* start);
};

#endif //PROJECT_MYGRAPH_H
