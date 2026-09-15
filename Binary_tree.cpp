#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& a, int i) {
    if (i >= a.size() || a[i] == -1)
        return nullptr;

    Node* root = new Node(a[i]);

    root->left = buildTree(a, 2 * i + 1);
    root->right = buildTree(a, 2 * i + 2);

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    Node* root = buildTree(a, 0);

    if (!root)
        return 0;

    queue<Node*> q;
    q.push(root);

    cout << "Level Order:\n";

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        cout << "\n";
    }

    return 0;
}
