#include<iostream>
using namespace std;

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
    long long modulo = 1e9 + 7;
    unordered_map<TreeNode * , long long > mp;
    long long getsum(TreeNode * root){
        if(root){
            long long left = getsum(root->left);
            long long right = getsum(root->right);
            long long result = left + right + root->val;
            mp[root] = result;
            return result;
        }
        return 0;
    }
    int maxProduct(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return 0;
        queue<TreeNode *> q;
        q.push(root);
        long long prod = 0;
        long long totalsum = getsum(root);
        while(!q.empty()){
            TreeNode * node = q.front(); 
            q.pop();
            if(node -> left){
                q.push(node->left);
                long long left = mp[node->left];
                long long right = totalsum - left;
                long long product = left * right;
                prod = max(product,prod);
            }
            if(node -> right){
                q.push(node->right);
                long long right = mp[node->right];
                long long left = totalsum - right;
                long long product = left * right;
                prod = max(product, prod);
            }
        }
        return prod % modulo;
    }
};