#include <iostream>
#include "./MyGraph/MyGraph.h"
#include "utilits.h"

int main() {
    MyGraph* graph = generateGraph();
    graph->colorGraphGreedy();

    return 0;
}
