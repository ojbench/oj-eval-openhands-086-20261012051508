#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int left;
    int right;
    TreeNode() : left(-1), right(-1) {}
    TreeNode(int l, int r) : left(l), right(r) {}
};

class BinaryTree {
private:
    vector<TreeNode> nodes;
    int n;
    
    void inorderTraversalHelper(int node, vector<int>& result) {
        if (node == -1) return;
        
        inorderTraversalHelper(nodes[node].left, result);
        result.push_back(node);
        inorderTraversalHelper(nodes[node].right, result);
    }
    
    void swapAtDepthHelper(int node, int currentDepth, int k) {
        if (node == -1) return;
        
        if (currentDepth % k == 0) {
            swap(nodes[node].left, nodes[node].right);
        }
        
        swapAtDepthHelper(nodes[node].left, currentDepth + 1, k);
        swapAtDepthHelper(nodes[node].right, currentDepth + 1, k);
    }
    
public:
    BinaryTree(int size) : n(size) {
        nodes.resize(n + 1); // 1-based indexing
    }
    
    void setChildren(int node, int left, int right) {
        nodes[node].left = left;
        nodes[node].right = right;
    }
    
    void swapAtDepth(int k) {
        swapAtDepthHelper(1, 1, k); // Start from root at depth 1
    }
    
    vector<int> inorderTraversal() {
        vector<int> result;
        inorderTraversalHelper(1, result);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    BinaryTree tree(n);
    
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        tree.setChildren(i, left, right);
    }
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        tree.swapAtDepth(k);
        
        vector<int> result = tree.inorderTraversal();
        
        for (int j = 0; j < result.size(); j++) {
            if (j > 0) cout << " ";
            cout << result[j];
        }
        cout << "\n";
    }
    
    return 0;
}