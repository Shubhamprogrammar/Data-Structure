#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V; 
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);
        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto adjNode : adj[s]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true;
                    queue.push_back(adjNode);
                }
            }
        }
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto adjNode : adj[v]) {
            if (!visited[adjNode])
                DFSUtil(adjNode, visited);
        }
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);

    cout << "\nDepth First Traversal (starting from vertex 2): ";
    g.DFS(2);

    return 0;
}

