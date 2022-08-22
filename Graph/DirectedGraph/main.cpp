#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <queue>

// Directed graph
class Graph {
private:
	// Adjency list
	std::map<int, bool> visited;	
	std::map<int, bool> recStack;
	std::map<int, std::list<int> > adj;

	// Private methods
	void m_DFS(int v); // Depth first
	void m_BFS(int v);

	bool m_isCyclic(int v);

public:
	// Add edge between vertex v and w
	void addEdge(int v, int w);

	// Traversal
	void DFS(int v);
	void BFS(int v);

	bool isCyclic();
};

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::m_DFS(int v) {
	visited[v] = true;
	std::cout << "Visited " << v << "\n";

	std::list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i]) { m_DFS(*i); }
	}
}

void Graph::m_BFS(int v) {
	std::queue<int> call_queue;

	// Enqueue
	visited[v] = true;
	call_queue.push(v);

	while (!call_queue.empty()) {
		// Dequeue
		v = call_queue.front();
		std::cout << "Visited " << v << "\n";
		call_queue.pop();

		// Visit each viabel adjacent vertex to current vertex
		for (auto adjacent : adj[v]) {
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				call_queue.push(adjacent);
			}
		}
	}
}

bool Graph::m_isCyclic(int v) {
	visited[v] = true;
	recStack[v] = true;

	for (auto it = adj[v].begin();  it != adj[v].end(); it++) {
		if (!visited[*it] && m_isCyclic(*it)) {
			return true;
		}
		else if (recStack[*it]) {
			return true;
		}
	}

	recStack[v] = false;
	return false;
}

void Graph::DFS(int v) {
	// Initialize 
	for (auto& it : visited) { it.second = false; }

	// Depth first traversal
	std::cout << "Starting Depth First Traversal from vertex " << v << "\n";
	m_DFS(v);
}

void Graph::BFS(int v) {
	// Initialize
	for (auto& it : visited) { it.second = false; }

	// Depth first traversal
	std::cout << "Starting Breadth First Traversal from vertex " << v << "\n";
	m_BFS(v);
}

bool Graph::isCyclic() {
	// Initialize
	for (auto& it : visited) { it.second = false; }
	for (auto& it : recStack) { it.second = false; }

	for (int i = 0; i < adj.size(); i++) {
		if (!visited[i]) {
			if (m_isCyclic(i)) { return true; }
		}
	}
	return false;
}

int main() {
	Graph g;
	/*g.addEdge(0, 2);
	g.addEdge(0, 1);
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);*/
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	//g.addEdge(2, 0);
	//g.addEdge(2, 3);
	//g.addEdge(3, 3);

	g.DFS(0);
	g.BFS(0);

	std::cout << "Is cyclic? " << g.isCyclic() << "\n";

	return 0;
}