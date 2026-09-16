#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

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

int height(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left),
                    height(root->right));
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    Node* root = buildTree(a, 0);

    cout << "Tree Height = " << height(root);

    return 0;
}
