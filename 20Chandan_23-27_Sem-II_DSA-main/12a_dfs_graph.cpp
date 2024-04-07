// 12. Implement Graph Traversal techniques:
// a) Depth First Search 

// Theory:
// This code implements depth-first search (DFS) traversal on an 
// undirected graph represented using an adjacency matrix. It 
// constructs the graph by adding edges between vertices, then 
// performs DFS traversal starting from a specified vertex. DFS 
// explores as far as possible along each branch before backtracking.

#include <iostream>
#include <stack>

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

    void DFS(int v) 
    {
        bool* visited = new bool[V]; 

        for (int i = 0; i < V; ++i)
            visited[i] = false;

        stack<int> stack; 

        visited[v] = true;
        stack.push(v);

        while (!stack.empty()) 
        {
            v = stack.top(); 
            stack.pop();
            cout << v << " ";

            for (int i = 0; i < V; ++i) 
            {
                if (adj[v][i] && !visited[i]) 
                {
                    visited[i] = true;
                    stack.push(i);
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
    cout << "enter edges:" << endl;
    
    for (int i = 0; i < E; ++i) 
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int start_vertex;
    cout << "enter starting vertex: ";
    cin >> start_vertex;

    cout << "Depth First Traversal: ";
    g.DFS(start_vertex);

    return 0;
}

