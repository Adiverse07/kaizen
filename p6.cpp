#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter the marks obtained by the students: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(marks[i]);
        maxHeap.push(marks[i]);
    }

    int minMarks = minHeap.top();
    int maxMarks = maxHeap.top();

    cout << "Minimum marks obtained: " << minMarks << endl;
    cout << "Maximum marks obtained: " << maxMarks << endl;

    return 0;
}
