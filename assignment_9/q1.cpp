#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
public:
    int V;                          
    vector<vector<int>> adj;        

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }

   
    void BFS(int start) {
        vector<int> visited(V, 0);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
    }

    
    void dfsRecursiveUtil(int node, vector<int>& visited) {
        visited[node] = 1;
        cout << node << " ";

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfsRecursiveUtil(nbr, visited);
            }
        }
    }

    void DFS_Recursive(int start) {
        vector<int> visited(V, 0);
        cout << "DFS Recursive Traversal: ";
        dfsRecursiveUtil(start, visited);
        cout << endl;
    }

    
    void DFS_Iterative(int start) {
        vector<int> visited(V, 0);
        stack<int> st;

        st.push(start);

        cout << "DFS Iterative Traversal: ";

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                cout << node << " ";
                visited[node] = 1;
            }

            
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int nbr = adj[node][i];
                if (!visited[nbr]) {
                    st.push(nbr);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(7);


    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.BFS(0);
    g.DFS_Recursive(0);
    g.DFS_Iterative(0);

    return 0;
}
