#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices in the graph

int findMinVertex(vector<int>& key, vector<bool>& inMST) {
    int minValue = INT_MAX, minIndex;
    for (int v = 0; v < V; ++v) {
        if (!inMST[v] && key[v] < minValue) {
            minValue = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]) {
    vector<int> parent(V, -1); // To store the resulting MST
    vector<int> key(V, INT_MAX); // Minimum weight edge for each vertex
    vector<bool> inMST(V, false); // To track included vertices

    key[0] = 0; // Start from the first vertex

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinVertex(key, inMST);
        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices in the graph

int findMinVertex(vector<int>& key, vector<bool>& inMST) {
    int minValue = INT_MAX, minIndex;
    for (int v = 0; v < V; ++v) {
        if (!inMST[v] && key[v] < minValue) {
            minValue = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]) {
    vector<int> parent(V, -1); // To store the resulting MST
    vector<int> key(V, INT_MAX); // Minimum weight edge for each vertex
    vector<bool> inMST(V, false); // To track included vertices

    key[0] = 0; // Start from the first vertex

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinVertex(key, inMST);
        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
