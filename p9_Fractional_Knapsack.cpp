#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int knapsackCapacity, vector<Item> items) {
    sort(items.begin(), items.end(), compare);
    
    double maxValue = 0.0;
    for (const auto &item : items) {
        if (knapsackCapacity >= item.weight) {
            knapsackCapacity -= item.weight;
            maxValue += item.value;
        } else {
            maxValue += item.value * ((double)knapsackCapacity / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int numItems, knapsackCapacity;
    cout << "Enter number of items: ";
    cin >> numItems;
    
    cout << "Enter knapsack capacity: ";
    cin >> knapsackCapacity;
    
    vector<Item> items(numItems);
    for (int i = 0; i < numItems; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    double maxTotalValue = fractionalKnapsack(knapsackCapacity, items);
    cout << "Maximum total value in knapsack: " << maxTotalValue << endl;

    return 0;
}
