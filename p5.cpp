#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;


vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(n, INF);  
    dist[src] = 0;  
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[u])
            continue;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist; 
}

int main() {
    int n = 0, m = 0; 
    vector<pair<int, int>> adj[100];
    int source = -1, destination = -1;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Input number of nodes and edges\n";
        cout << "2. Input edges\n";
        cout << "3. Set source and destination\n";
        cout << "4. Calculate shortest path using Dijkstra's algorithm\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of nodes: ";
                cin >> n;
                cout << "Enter number of edges: ";
                cin >> m;
              
                for (int i = 0; i < n; i++) {
                    adj[i].clear();
                }
                cout << "Nodes and edges set successfully.\n";
                break;

            case 2:
                if (m <= 0) {
                    cout << "Please enter the number of edges first.\n";
                    break;
                }
                cout << "Enter edges (u, v, w):\n";
                for (int i = 0; i < m; i++) {
                    int u, v, w;
                    cout << "Edge " << (i + 1) << ": ";
                    cin >> u >> v >> w;

                 
                    if (u < 0 || u >= n || v < 0 || v >= n) {
                        cout << "Invalid node number. Please enter valid nodes.\n";
                        i--; 
                        continue;
                    }

                    adj[u].push_back({v, w});
                    adj[v].push_back({u, w});  
                }
                cout << "Edges input successfully.\n";
                break;

            case 3:
                cout << "Enter source node: ";
                cin >> source;
                cout << "Enter destination node: ";
                cin >> destination;

                
                if (source < 0 || source >= n || destination < 0 || destination >= n) {
                    cout << "Invalid source or destination. Please set them again.\n";
                    source = destination = -1; 
                }
                break;

            case 4: {
                
                if (source == -1 || destination == -1) {
                    cout << "Please set source and destination first.\n";
                    break;
                }

                vector<int> dist = dijkstra(n, adj, source);

               
                if (dist[destination] != INF) {
                    cout << "Shortest travel time from " << source << " to " << destination << " is: " << dist[destination] << " units\n";
                } else {
                    cout << "There is no path from " << source << " to " << destination << ".\n";
                }
                break; 
            }

            case 5:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
