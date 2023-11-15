//
// Created by Roman Ivanov on 13.11.2023.
//
#include "./MyGraph.h"

void MyGraph::_fillVertexesSet(MyGraph::MyVertex *start) {
    this->vertexesSet.insert(start);
    for(auto vertex: start->adjacentVertices){
        if(this->vertexesSet.find(vertex) == this->vertexesSet.end()){
            this->_fillVertexesSet(vertex);
        }
    }
}

void MyGraph::_colorVertex(MyVertex *current){
    this->checkedVertexes.insert(current);
    std::set<int> tempSet = std::set<int>();
    for(auto adjacentVertice: current->adjacentVertices){
        if(adjacentVertice->color != 0)
            tempSet.insert(adjacentVertice->color);
    }
    std::set<int> dif;
    std::set_difference(this->colors.begin(),
                        this->colors.end(),
                        tempSet.begin(),
                        tempSet.end(),
                        std::inserter(dif, dif.end())
    );

    if(dif.size() > 0) current->color = *dif.begin();
    else{
        int newColor = *std::max_element(this->colors.begin(), this->colors.end(), [](int a, int b){return a < b;}) + 1;

        this->colors.insert(newColor);
        current->color = newColor;

    }
}

void MyGraph::colorGraphBFS(MyGraph::MyVertex *current){
    this->_colorVertex(current);
    for(auto vertex: current->adjacentVertices){
        if(this->checkedVertexes.find(vertex) == this->checkedVertexes.end()){
            this->vertexQueue.push(vertex);
            this->checkedVertexes.insert(vertex);
        }
    }

    if(!this->vertexQueue.empty()){
        MyVertex* temp = this->vertexQueue.front();
        this->vertexQueue.pop();
        this->colorGraphBFS(temp);
    }
}

void MyGraph::colorGraphDFS(MyVertex *current){
    this->_colorVertex(current);
    for(auto vertex: current->adjacentVertices){
        if(this->checkedVertexes.find(vertex) == this->checkedVertexes.end())
            this->colorGraphDFS(vertex);
    }
}

void MyGraph::colorGraphGreedy(){
    for(auto vertex: this->vertexesSet)
        this->_colorVertex(vertex);
}

void MyGraph::resetColors(){
    for(auto vertex: this->vertexesSet) vertex->color = 0;
    this->colors = std::set<int>();
}