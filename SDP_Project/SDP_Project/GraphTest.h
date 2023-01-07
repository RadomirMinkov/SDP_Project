#ifndef _GRAPH_TEST_HPP
#define _GRAPH_TEST_HPP
#include "doctest.h"
#include "Graph.h"

TEST_CASE("Добавяне на върхове в графа")
{
	Graph<int, int> graph;
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(2);
	graph.addVertex(5);
	graph.addVertex(1);
	unsigned i{ 0 };
	for (int vertex : graph.getVertices())
	{
		CHECK(((vertex == 2) || (vertex == 3) || (vertex == 5) || (vertex == 1)));
		i++;
	}
	CHECK_EQ(i, 4);

}
TEST_CASE("Взимане на всички съседи на даден връх")
{
	Graph<int, int> graph;
	graph.addEdge(1, 3,3);
	graph.addEdge(1, 6,1);
	graph.addEdge(1, 3,2);
	graph.addEdge(1, 4,2);
	graph.addEdge(2, 1, 5);
	graph.addEdge(2, 3, 4);
	graph.addVertex(5);
	unsigned i{ 0 };
	for (int neighbour : graph.getNeighbours(1))
	{
		CHECK((neighbour == 3 || neighbour == 6 || neighbour == 4 || neighbour == 2));
		i++;
	}
	CHECK_EQ(i, 4);
}
TEST_CASE("Добавяне на върхове и ребра ")
{
	Graph<int, int> graph;
	graph.addVertex(2);
	graph.addVertex(4);
	graph.addEdge(2, 4, 5);
	graph.addEdge(2, 3, 10);
	unsigned i{ 0 };
	for (int vertex : graph.getVertices())
	{
		CHECK((vertex == 2 || vertex == 3 || vertex == 4));
		i++;
	}
	CHECK_EQ(i, 3);

}
#endif // !_GRAPH_TEST_HPP

