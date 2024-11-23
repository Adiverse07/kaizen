#include <bits/stdc++.h>
using namespace std;

struct User {
    string name;
    string dob;
    int comments;
    vector<int> friends;

    User(string name, string dob, int comments) : name(name), dob(dob), comments(comments) {}
};

class FacebookGraph {
public:
    vector<User> users;

    void addUser() {
        string name, dob;
        int comments;
        cout << "Enter name: ";
        cin >> ws; // To handle any whitespace issues
        getline(cin, name);
        cout << "Enter date of birth (dd-mm-yyyy): ";
        cin >> dob;
        cout << "Enter number of comments: ";
        cin >> comments;
        users.push_back(User(name, dob, comments));
        cout << "User added successfully.\n";
    }

    int findUserIndexByName(const string& name) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].name == name) {
                return i;
            }
        }
        return -1; // Return -1 if the user is not found
    }

    void addFriendship() {
        string user1Name, user2Name;
        cout << "Enter name of first user: ";
        cin >> ws; // To handle any leading whitespace
        getline(cin, user1Name);
        cout << "Enter name of second user: ";
        getline(cin, user2Name);

        int user1Idx = findUserIndexByName(user1Name);
        int user2Idx = findUserIndexByName(user2Name);

        if (user1Idx == -1 || user2Idx == -1) {
            cout << "One or both users not found.\n";
            return;
        }

        users[user1Idx].friends.push_back(user2Idx);
        users[user2Idx].friends.push_back(user1Idx);
        cout << "Friendship added successfully between " << user1Name << " and " << user2Name << ".\n";
    }

    void findMaxFriends() {
        int maxFriends = 0;
        string maxFriendUser;

        for (User &user : users) {
            if (user.friends.size() > maxFriends) {
                maxFriends = user.friends.size();
                maxFriendUser = user.name;
            }
        }

        cout << "User with the maximum friends: " << maxFriendUser << " with " << maxFriends << " friends.\n";
    }

    void findMaxMinComments() {
        if (users.empty()) return;

        int maxComments = INT_MIN, minComments = INT_MAX;
        string maxCommentUser, minCommentUser;

        for (User &user : users) {
            if (user.comments > maxComments) {
                maxComments = user.comments;
                maxCommentUser = user.name;
            }
            if (user.comments < minComments) {
                minComments = user.comments;
                minCommentUser = user.name;
            }
        }

        cout << "User with maximum comments: " << maxCommentUser << " with " << maxComments << " comments.\n";
        cout << "User with minimum comments: " << minCommentUser << " with " << minComments << " comments.\n";
    }

    void findBirthdaysInMonth() {
        int month;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Users with birthdays in month " << month << ":\n";
        for (User &user : users) {
            int userMonth = stoi(user.dob.substr(3, 2));
            if (userMonth == month) {
                cout << user.name << " has a birthday on " << user.dob << "\n";
            }
        }
    }

    void BFS(int startIdx) {
        vector<bool> visited(users.size(), false);
        queue<int> q;

        q.push(startIdx);
        visited[startIdx] = true;

        cout << "BFS traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << users[u].name << " ";

            for (int v : users[u].friends) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int idx, vector<bool> &visited) {
        visited[idx] = true;
        cout << users[idx].name << " ";

        for (int friendIdx : users[idx].friends) {
            if (!visited[friendIdx]) {
                DFSUtil(friendIdx, visited);
            }
        }
    }

    void DFS(int startIdx) {
        vector<bool> visited(users.size(), false);
        cout << "DFS traversal: ";
        DFSUtil(startIdx, visited);
        cout << endl;
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add User\n";
    cout << "2. Add Friendship\n";
    cout << "3. Find User with Maximum Friends\n";
    cout << "4. Find Users with Maximum and Minimum Comments\n";
    cout << "5. Find Birthdays in a Given Month\n";
    cout << "6. BFS Traversal\n";
    cout << "7. DFS Traversal\n";
    cout << "8. Exit\n";
}

int main() {
    FacebookGraph fb;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fb.addUser();
                break;
            case 2:
                fb.addFriendship();
                break;
            case 3:
                fb.findMaxFriends();
                break;
            case 4:
                fb.findMaxMinComments();
                break;
            case 5:
                fb.findBirthdaysInMonth();
                break;
            case 6: {
                int startIdx;
                cout << "Enter starting user index for BFS: ";
                cin >> startIdx;
                if (startIdx >= 0 && startIdx < fb.users.size()) {
                    fb.BFS(startIdx);
                } else {
                    cout << "Invalid starting index.\n";
                }
                break;
            }
            case 7: {
                int startIdx;
                cout << "Enter starting user index for DFS: ";
                cin >> startIdx;
                if (startIdx >= 0 && startIdx < fb.users.size()) {
                    fb.DFS(startIdx);
                } else {
                    cout << "Invalid starting index.\n";
                }
                break;
            }
            case 8:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
