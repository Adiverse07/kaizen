#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

Node *constructTree(string postfix)
{
    stack<Node *> st;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (!isOperator(postfix[i]))
        {
            st.push(new Node(postfix[i]));
        }
        else
        {
            Node *node = new Node(postfix[i]);
            Node *rightNode = st.top();
            st.pop();
            Node *leftNode = st.top();
            st.pop();
            node->right = rightNode;
            node->left = leftNode;
            st.push(node);
        }
    }
    return st.top();
}

void inOrderNonRecursive(Node *root)
{
    stack<Node *> st;
    Node *current = root;
    while (current != NULL || !st.empty())
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    Node *root = NULL;
    int choice;
    string postfix;
    char ch;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Construct Expression Tree from Postfix\n";
        cout << "2. Display In-Order Traversal (Non-Recursive)\n";
        cout << "3. Check if a Character is an Operator\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter postfix expression: ";
            cin >> postfix;
            root = constructTree(postfix);
            cout << "Expression tree constructed.\n";
            break;

        case 2:
            if (root != NULL)
            {
                cout << "In-Order Traversal: ";
                inOrderNonRecursive(root);
                cout << endl;
            }
            else
            {
                cout << "Please construct the tree first.\n";
            }
            break;

        case 3:
            cout << "Enter character to check: ";
            cin >> ch;
            if (isOperator(ch))
                cout << ch << " is an operator.\n";
            else
                cout << ch << " is not an operator.\n";
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
