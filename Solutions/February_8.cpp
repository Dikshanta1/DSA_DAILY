#include<iostream>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    int height(TreeNode* root, bool &diff){
        if(root){
            int left = height(root->left,diff) ;
            int right = height(root->right,diff) ;
            if(abs(left-right) > 1) diff = false;
            return max(left,right)+1;
        }
        return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool diff = true;
        int h = height(root,diff);
        return diff;  
    }
};