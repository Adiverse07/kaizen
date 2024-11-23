#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

int findParent(int u, vector<int> &parent) {
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void kruskalMST(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Initialize parent array for disjoint sets
    }

    int totalWeight = 0;
    vector<Edge> mst;

    for (Edge &e : edges) {
        int u = findParent(e.u, parent);
        int v = findParent(e.v, parent);

        if (u != v) {
            mst.push_back(e);
            totalWeight += e.weight;
            unionSets(u, v, parent, rank);
        }
    }

    cout << "Edges in the MST:\n";
    for (Edge &e : mst) {
        cout << e.u + 1 << " - " << e.v + 1 << " (weight: " << e.weight << ")\n";
    }
    cout << "Total weight of the MST: " << totalWeight << endl;
}

int main() {
    int choice;
    vector<Edge> edges;
    int n, m;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input number of nodes and edges\n";
        cout << "2. Input edges\n";
        cout << "3. Calculate MST using Kruskal's algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of nodes: ";
                cin >> n;
                cout << "Enter number of edges: ";
                cin >> m;
                edges.resize(m); // Resize the edges vector based on number of edges
                break;

            case 2:
                if (edges.empty()) {
                    cout << "Please input the number of nodes and edges first.\n";
                } else {
                    cout << "Enter edges (u, v, weight):\n";
                    for (int i = 0; i < m; i++) {
                        cout << "Edge " << i + 1 << ": ";
                        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

                        // Convert 1-based input to 0-based indexing
                        edges[i].u--; // Subtract 1 to make nodes 0-indexed
                        edges[i].v--; // Subtract 1 to make nodes 0-indexed
                    }
                }
                break;

            case 3:
                if (edges.empty()) {
                    cout << "Please input the edges first.\n";
                } else {
                    kruskalMST(n, edges);
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
