#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    node *root;

    BinaryTree() {
        root = NULL;
    }

    void constructTree() {
        int n;
        cout << "Enter the number of nodes you want to insert: ";
        cin >> n;
        cout << "Enter node values: ";//3(4a + b + c) + d / 5 + (6 - e)
        for (int i = 0; i < n; i++) {
            string val;
            cout<<"Enter value "<<i+1<<": ";
            cin >> val;
            insert(val);
        }
    }

    void insert(string val) {
        if (root == NULL) {
            root = new node(val);
            return;
        }

        queue<node *> q;
        q.push(root);

        while (!q.empty()) {
            node *temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = new node(val);
                break;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = new node(val);
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    void inorder(node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    int findDepth(node *root) {
        if (root == NULL) return 0;
        int leftDepth = findDepth(root->left);
        int rightDepth = findDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    void displayLeafNodes(node *root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
        }
        if (root->left) displayLeafNodes(root->left);
        if (root->right) displayLeafNodes(root->right);
    }

    node *copyTree(node *root) {
        if (root == NULL) return NULL;
        node *newNode = new node(root->data);
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);
        return newNode;
    }

    void display(node *root) {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        queue<node *> q;
        q.push(root);

        cout << "Tree structure (level by level):\n";
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                node *temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            cout << endl; // Move to the next level
        }
    }
};

int main() {
    BinaryTree bt;
    BinaryTree bt_copy;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Construct Tree\n";
        cout << "2. Insert Node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Find Depth of Tree\n";
        cout << "5. Display Leaf Nodes\n";
        cout << "6. Copy Tree and Display Inorder of Copied Tree\n";
        cout << "7. Display Tree Structure\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bt.constructTree();
            break;
        case 2: {
            string val;
            cout << "Enter value to insert: ";
            cin >> val;
            bt.insert(val);
            break;
        }
        case 3:
            cout << "Inorder Traversal: ";
            bt.inorder(bt.root);
            cout << endl;
            break;
        case 4:
            cout << "Depth of Tree: " << bt.findDepth(bt.root) << endl;
            break;
        case 5:
            cout << "Leaf Nodes: ";
            bt.displayLeafNodes(bt.root);
            cout << endl;
            break;
        case 6:
            bt_copy.root = bt.copyTree(bt.root);
            cout << "Inorder Traversal of Copied Tree: ";
            bt.inorder(bt_copy.root);
            cout << endl;
            break;
        case 7:
            bt.display(bt.root);
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
