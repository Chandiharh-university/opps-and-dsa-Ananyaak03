#include <iostream>
#include <vector>

using namespace std;

void createAdjMatrix(int n, int edges[][2], int m) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

    cout << "Adjacency Matrix:\n";
    for (const auto& row : adjMatrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

void createAdjList(int n, int edges[][2], int m) {
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adjList[i])
            cout << v << " ";
        cout << endl;
    }
}

int main() {
    int n = 5; 
    int edges[][2] = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {3, 4}}; // Edge list
    int m = sizeof(edges) / sizeof(edges[0]); // Number of edges

    createAdjMatrix(n, edges, m);
    cout << endl;
    createAdjList(n, edges, m);

    return 0;
}
