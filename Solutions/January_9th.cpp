/**
 * Problem: Smallest Subtree with all the Deepest Nodes (LeetCode 865 / 1123)
 * Approach: 
 * 1. Calculate the depth of all nodes and store them in a map using DFS.
 * 2. Identify the maximum depth.
 * 3. Retrieve all nodes at the maximum depth.
 * 4. Iteratively find the Lowest Common Ancestor (LCA) of these deepest nodes.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Map to store nodes at each depth level: <depth, list_of_nodes>
    unordered_map<int, vector<TreeNode*>> mp;

    // Helper function to record depth of every node
    void height(TreeNode* root, int n) {
        if (root == nullptr) return;
        mp[n].push_back(root);
        height(root->left, n + 1);
        height(root->right, n + 1);
    }

    // Standard LCA function
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        if (leftN && rightN) return root;

        if (leftN) return leftN;
        return rightN;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return root;
        
        // Clear map for fresh run if object is reused
        mp.clear(); 
        
        // Populate depths
        height(root, 0);

        // Find the maximum height
        int max_height = 0;
        for (auto x : mp) {
            max_height = max(x.first, max_height);
        }

        // Get all nodes at the deepest level
        vector<TreeNode*> vec = mp[max_height];

        // If there is only one deepest node, that is the answer
        if (vec.size() == 1) return vec[0];

        // Iteratively find LCA of the deepest nodes
        TreeNode* node = vec[0];
        for (int i = 1; i < vec.size(); i++) {
            node = lowestCommonAncestor(root, node, vec[i]);
        }
        return node;
    }
};

// --- Helper functions for testing (not part of the solution class) ---

// Function to print tree (Pre-order) to verify result
void printPreOrder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    // Constructing the following tree:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* result = sol.subtreeWithAllDeepest(root);

    cout << "Root of the smallest subtree with all deepest nodes: " << result->val << endl;
    
    // Clean up memory (simple deletion for this test case)
    // In a real application, use a proper destructor or smart pointers.
    delete root->left->right->right; // 4
    delete root->left->right->left;  // 7
    delete root->right->right;       // 8
    delete root->right->left;        // 0
    delete root->left->right;        // 2
    delete root->left->left;         // 6
    delete root->right;              // 1
    delete root->left;               // 5
    delete root;                     // 3

    return 0;
}