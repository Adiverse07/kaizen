#include <bits/stdc++.h>
using namespace std;

struct Flight {
    string destination;
    int cost;
};

class FlightGraph {
public:
    unordered_map<string, vector<Flight>> adjList;

    void addFlight(string cityA, string cityB, int cost) {
        adjList[cityA].push_back({cityB, cost});
        adjList[cityB].push_back({cityA, cost});
        cout << "Flight added from " << cityA << " to " << cityB << " with cost " << cost << ".\n";
    }

    void DFS(string city, unordered_map<string, bool> &visited) {
        visited[city] = true;

        for (auto &flight : adjList[city]) {
            if (!visited[flight.destination]) {
                DFS(flight.destination, visited);
            }
        }
    }

    bool isConnected() {
        if (adjList.empty()) return true;

        unordered_map<string, bool> visited;

        for (auto &entry : adjList) {
            visited[entry.first] = false;
        }

        string startCity = adjList.begin()->first;
        DFS(startCity, visited);

        for (auto &entry : visited) {
            if (!entry.second) return false;
        }

        return true;
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Flight\n";
    cout << "2. Check if Flight Network is Connected\n";
    cout << "3. Exit\n";
}

int main() {
    FlightGraph flightNetwork;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string cityA, cityB;
            int cost;
            cout << "Enter source city: ";
            cin >> ws; // clear leading whitespace
            getline(cin, cityA);
            cout << "Enter destination city: ";
            getline(cin, cityB);
            cout << "Enter cost of the flight: ";
            cin >> cost;
            flightNetwork.addFlight(cityA, cityB, cost);
        }
        else if (choice == 2) {
            if (flightNetwork.isConnected()) {
                cout << "The flight network is connected." << endl;
            } else {
                cout << "The flight network is NOT connected." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
