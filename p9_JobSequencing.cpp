#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

vector<Job> jobScheduling(vector<Job>& jobs, int maxDeadline) {
    sort(jobs.begin(), jobs.end(), compare);
    vector<bool> slots(maxDeadline, false);
    vector<Job> selectedJobs;

    for (int i = 0; i < jobs.size(); i++){
        Job job = jobs[i];
        for (int j = min(maxDeadline - 1, job.deadline - 1); j >= 0; j--) {
            if (!slots[j]) { // If the slot is free
                slots[j] = true; // Mark as filled
                selectedJobs.push_back(job); // Add job to selected jobs
                break;
            }
        }
    }

    return selectedJobs;
}

int main() {
    vector<Job> jobs = {
     // {id, deadline, profit}
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int maxDeadline = 3;

    vector<Job> selectedJobs = jobScheduling(jobs, maxDeadline);

    cout << "Selected Jobs:\n";
    for (int i = 0; i < selectedJobs.size(); i++) {
        cout << "Job ID: " << selectedJobs[i].id << ", Deadline: " << selectedJobs[i].deadline << ", Profit: " << selectedJobs[i].profit << endl;
    }

    return 0;
}
