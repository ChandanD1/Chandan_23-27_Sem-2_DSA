// 12. Implement Graph Traversal techniques:
// b) Breadth First Search

// Theory:
// This code implements breadth-first search (BFS) traversal on an 
// undirected graph using an adjacency matrix, starting from a 
// specified vertex. It marks visited vertices and explores adjacent 
// vertices iteratively, maintaining a queue for traversal.

#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 100;

class Graph 
{
    int V; 
    int** adj; 

public:
    Graph(int V) 
    {
        this->V = V;
        adj = new int*[V];
        
        for (int i = 0; i < V; ++i) 
        {
            adj[i] = new int[V];
            
            for (int j = 0; j < V; ++j) 
            {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w) 
    {
        adj[v][w] = 1; 
        adj[w][v] = 1;
    }

    void BFS(int start) 
    {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i)
            visited[i] = false;

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < V; ++i) 
            {
                if (adj[v][i] && !visited[i]) 
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
    }
};

int main() 
{
    int V, E;
    cout << "enter number of vertices & edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "enter edges: " << endl;
    
    for (int i = 0; i < E; ++i) 
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int start_vertex;
    cout << "enter starting vertex: ";
    cin >> start_vertex;

    cout << "Breadth First Traversal: ";
    g.BFS(start_vertex);

    return 0;
}

// Conclusion:
// In conclusion, the code efficiently performs BFS traversal on an 
// undirected graph represented using an adjacency matrix, 
// demonstrating a fundamental graph traversal algorithm for exploring 
// connected components in a graph.