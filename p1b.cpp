#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        if (root == NULL)
        {
            root = new node(val);
            return;
        }

        node *cur = root;

        while (true)
        {
            if (cur->data <= val)
            {
                if (cur->right != NULL)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new node(val);
                    break;
                }
            }
            else
            {
                if (cur->left != NULL)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new node(val);
                    break;
                }
            }
        }
    }

    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    node *search(node *root, int val)
    {
        int lv=0;
        while (root != NULL && root->data != val)
        {
            root = val < root->data ? root->left : root->right;
            lv++;
        }
        if(root->data==val)
        cout<<"Node found at level "<<lv<<endl;
        return root;
    }

    void bfs(node *root)
    {
        if (root == NULL)
        {
            return;
        }

        queue<node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp != NULL)
            {
                cout << temp->data << " ";

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (!q.empty())
            {   
                cout << endl;
                q.push(NULL);
            }
        }
    }

    node *deleteNode(node *root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }

            node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    node *minValueNode(node *root)
    {
        node *current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
};

int main()
{
    BST b;
    int choice, value,n;

    do
    {
        cout << "\n\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display In-Order Traversal\n";
        cout << "3. Display BFS (Level Order Traversal)\n";
        cout << "4. Search for a value\n";
        cout << "5. Delete a node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of values to insert: ";
            cin >> n;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter value "<<i+1<<":";
                cin>>value;
                b.insert(value);
            }
            cout << "Values inserted.\n";
            break;
        case 2:
            cout << "In-Order Traversal: ";
            b.inorder(b.root);
            cout << endl;
            break;
        case 3:
            cout << "BFS (Level Order Traversal):\n";
            b.bfs(b.root);
            cout << endl;
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            if (b.search(b.root, value) != NULL)
                cout << "Value " << value << " found in the tree.\n";
            else
                cout << "Value " << value << " not found in the tree.\n";
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            b.root = b.deleteNode(b.root, value);
            cout << "Value deleted (if existed).\n";
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
