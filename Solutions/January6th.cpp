#include<iostream>
using namespace std;


//Definition for a binary tree node.
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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right){
            return 1;
        }
        int level = 0;
        int max_sum = INT_MIN ;
        int l = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sum = 0 ;l++;
            int size = q.size();
            for(int i = 0 ;i < size ; i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                sum += node->val;
            }
            if(sum >max_sum){
                max_sum = max(max_sum,sum);
                level = l;
            }
        }
        return level;
    }
};