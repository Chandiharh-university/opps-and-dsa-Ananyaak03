#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>> &graph, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);

    // Add edges (u, v, weight)
    graph[0].push_back({1, 2});
    graph[0].push_back({4, 1});
    graph[1].push_back({2, 3});
    graph[4].push_back({1, 2});
    graph[4].push_back({3, 6});
    graph[3].push_back({2, 1});

    int src = 0; // Starting vertex
    dijkstra(src, graph, V);

    return 0;
}
