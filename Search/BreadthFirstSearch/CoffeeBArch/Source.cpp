#include <iostream>
#include <list>

class Graph {
private:
	int V;				 // Number of vertices
	std::list<int>* adj; // Adjacent vertices
public:
	Graph(int v);
	~Graph();

	void addEdge(int v, int w);
	void BFS(int s);	// Breadth first search
};

Graph::Graph(int v) {
	V = v;
	adj = new std::list<int>[v];
}

Graph::~Graph() {
	delete[] adj;
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	std::list<int> queue;
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {
		s = queue.front();
		queue.pop_front();

		std::cout << "Checking adjacent vertices for vertex " << s << "\n";
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
			if (!visited[*i]) {
				std::cout << "Visit and enqueue " << *i << "\n";
				visited[*i] = true;

				queue.push_back(*i);
			}
		}
	}
	delete[] visited;
}

int main() {
	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 0);
	g.addEdge(2, 4);

	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);

	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	g.addEdge(5, 3);
	g.addEdge(5, 4);

	// Perform BFS
	g.BFS(2);

	return 0;
}