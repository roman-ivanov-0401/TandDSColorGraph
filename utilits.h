//
// Created by Roman Ivanov on 14.11.2023.
//

#ifndef PROJECT_UTILITS_H
#define PROJECT_UTILITS_H

#include "./MyGraph/MyGraph.h"

MyGraph* generateGraph(){
    MyGraph::MyVertex* start = new MyGraph::MyVertex(1);
    MyGraph::MyVertex* two = new MyGraph::MyVertex(2);
    MyGraph::MyVertex* three = new MyGraph::MyVertex(3);
    MyGraph::MyVertex* four = new MyGraph::MyVertex(4);
    MyGraph::MyVertex* five = new MyGraph::MyVertex(5);
    MyGraph::MyVertex* six = new MyGraph::MyVertex(6);
    MyGraph::MyVertex* seven = new MyGraph::MyVertex(7);
    MyGraph::MyVertex* eight = new MyGraph::MyVertex(8);

    start->adjacentVertices.push_back(two);
    start->adjacentVertices.push_back(three);

    two->adjacentVertices.push_back(start);
    two->adjacentVertices.push_back(four);

    three->adjacentVertices.push_back(start);
    three->adjacentVertices.push_back(four);

    four->adjacentVertices.push_back(two);
    four->adjacentVertices.push_back(three);
    four->adjacentVertices.push_back(five);
    four->adjacentVertices.push_back(seven);
    four->adjacentVertices.push_back(eight);

    five->adjacentVertices.push_back(four);
    five->adjacentVertices.push_back(six);

    six->adjacentVertices.push_back(five);
    six->adjacentVertices.push_back(seven);

    seven->adjacentVertices.push_back(six);
    seven->adjacentVertices.push_back(four);
    seven->adjacentVertices.push_back(eight);

    eight->adjacentVertices.push_back(three);
    eight->adjacentVertices.push_back(four);
    eight->adjacentVertices.push_back(seven);

    MyGraph* graph = new MyGraph(start);
    return graph;
}

#endif //PROJECT_UTILITS_H
