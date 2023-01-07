#ifndef _GRAPH_HPP
#define _GRAPH_HPP
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
template <class Vertex,class Weight>
class Graph
{
private:
	using Edge = std::pair<Vertex, Vertex>;
	std::set<Vertex> vertices;
	std::unordered_map<Vertex, std::set<Vertex>> neighbours;
	std::map<Edge, Weight> weights;

public:
	Graph() = default;

	void addEdge(Vertex const& vertexOne, Vertex const& vertexTwo,Weight const& weight);
	void addVertex(Vertex const& vertex);

	bool changeWeight(Vertex const& vertexOne, Vertex const& vertexTwo,Weight const& weight);
	std::set<Vertex> const& getVertices() const { return vertices; }
	Weight const& getWeight(Edge const&) const;
	std::set<Vertex> const& getNeighbours(const Vertex&);

	void print(Vertex const& begin,std::set<Vertex>& visited,std::ostream& out = std::cout);
};
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::addVertex(Vertex const& vertex)
{
	vertices.insert(vertex);
	neighbours[vertex];
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::addEdge(Vertex const& vertexOne, Vertex const& vertexTwo, Weight const& weight)
{
	addVertex(vertexOne);
	addVertex(vertexTwo);
	neighbours[vertexOne].insert(vertexTwo);
	neighbours[vertexTwo].insert(vertexOne);
	weights[std::pair<Vertex, Vertex>(vertexOne, vertexTwo)] = weight;
	weights[std::pair<Vertex, Vertex>(vertexTwo, vertexOne)] = weight;
}

template <class Vertex, class Weight>
bool Graph<Vertex, Weight>::changeWeight(Vertex const& vertexOne, Vertex const& vertexTwo, Weight const& weight)
{
	if (!(neighbours.count(vertexOne) || neighbours.count(vertexTwo)))
		return false;
	weights[(vertexOne, vertexTwo)] = weight;
	weights[(vertexTwo, vertexOne)] = weight;
}
template <class Vertex, class Weight>
Weight const& Graph<Vertex, Weight>::getWeight(Edge const& edge) const
{
	return weights[edge];
}
template <class Vertex, class Weight>
std::set<Vertex> const& Graph<Vertex, Weight>::getNeighbours(const Vertex& vertex)
{
	return neighbours[vertex];
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::print(Vertex const& begin, std::set<Vertex>& visited, std::ostream& out)
{
	if (!vertices.count(begin))
	{
		std::cout << "There is no such vertex in the graph!";
		return;
	}
	visited.insert(begin);
	for (auto neighbour : neighbours[begin])
	{
		std::cout << begin << " -> " << neighbour << '\n';
		if (!visited.count(neighbour))
			print(neighbour, visited, out);
	}
}
#endif // !_GRAPH_HPP

