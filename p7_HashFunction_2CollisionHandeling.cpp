#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class LinearProbingHashTable {
    vector<pair<string, string>> table;
    int size;

public:
    LinearProbingHashTable(int tableSize) {
        size = tableSize;
        table.resize(tableSize, {"", ""});
    }

    int hashFunction(const string &key) {
        int hashValue = 0;
        for (char ch : key)
            hashValue += ch;
        return hashValue % size;
    }

    void insert(const string &name, const string &phoneNumber) {
        int index = hashFunction(name);
        while (table[index].first != "") {
            index = (index + 1) % size;
        }
        table[index] = {name, phoneNumber};
    }

    string search(const string &name, int &comparisons) {
        int index = hashFunction(name);
        comparisons = 0;
        while (table[index].first != name && table[index].first != "") {
            index = (index + 1) % size;
            comparisons++;
        }
        return table[index].first == name ? table[index].second : "Not Found";
    }
};


class SeparateChainingHashTable {
    vector<list<pair<string, string>>> table;
    int size;

public:
    SeparateChainingHashTable(int tableSize) {
        size = tableSize;
        table.resize(tableSize);
    }

    int hashFunction(const string &key) {
        int hashValue = 0;
        for (char ch : key)
            hashValue += ch;
        return hashValue % size;
    }

    void insert(const string &name, const string &phoneNumber) {
        int index = hashFunction(name);
        table[index].push_back({name, phoneNumber});
    }

    string search(const string &name, int &comparisons) {
        int index = hashFunction(name);
        comparisons = 0;
        for (auto &entry : table[index]) {
            comparisons++;
            if (entry.first == name)
                return entry.second;
        }
        return "Not Found";
    }
};


int main() {
    int numClients;
    cout << "Enter number of clients: ";
    cin >> numClients;

    LinearProbingHashTable linearHashTable(5);
    SeparateChainingHashTable chainingHashTable(5);

    for (int i = 0; i < numClients; i++) {
        string name, phoneNumber;
        cout << "Enter name and phone number: ";
        cin >> name >> phoneNumber;
        linearHashTable.insert(name, phoneNumber);
        chainingHashTable.insert(name, phoneNumber);
    }

    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    int linearComparisons, chainingComparisons;

    string linearResult = linearHashTable.search(searchName, linearComparisons);
    string chainingResult = chainingHashTable.search(searchName, chainingComparisons);

    cout << "Linear Probing -> Phone Number: " << linearResult << ", Comparisons: " << linearComparisons << endl;
    cout << "Separate Chaining -> Phone Number: " << chainingResult << ", Comparisons: " << chainingComparisons << endl;

    return 0;
}

// Num clients = 5

// Alice 12345
// Bob 23456
// Carol 34567
// Dave 45678
// Eve 56789

// Search: Eve
