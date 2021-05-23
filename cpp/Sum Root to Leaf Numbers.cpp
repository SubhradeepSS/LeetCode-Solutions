/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int curr;
    int f(TreeNode* node,int curr){
        if(!node->left&&!node->right)
            return curr*10+node->val;
        int l=0,r=0;
        curr=curr*10+node->val;
        if(node->left)
            l=f(node->left,curr);
        if(node->right)
            r=f(node->right,curr);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        return f(root,0);
    }
};