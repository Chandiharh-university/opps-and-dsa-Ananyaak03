#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) swap(xr, yr);
        parent[yr] = xr;
        if (rank[xr] == rank[yr]) rank[xr]++;
        return true;
    }
};

int main() {
    int n, m; 
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int mst_weight = 0;

    for (const auto& edge : edges) {
        if (ds.unite(edge.u, edge.v)) {
            mst_weight += edge.weight;
            cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.weight << endl;
        }
    }

    cout << "Total weight of MST: " << mst_weight << endl;
    return 0;
}
