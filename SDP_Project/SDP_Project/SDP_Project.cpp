#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*#include "SkipListTests.h"
#include "TrainStopsTests.h"
#include "GraphTest.h"
#include <string>*/
#include "Graph.h"
#include "TrainStops.h"

int main()
{
	Graph<int, int> graph;
	graph.addVertex(2);
	graph.addVertex(4);
	graph.addEdge(2, 4, 5);
	graph.addEdge(2, 3, 10);
	graph.addEdge(4, 5, 10);
	graph.addEdge(3, 5, 10);
	std::set<int> visited;
	graph.print(2,visited);

	return 0;
}
