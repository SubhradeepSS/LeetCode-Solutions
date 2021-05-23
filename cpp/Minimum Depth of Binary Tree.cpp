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
    void f(int curr,int& ans,TreeNode* node){
        if(!node)
            return;
        if(!node->left&&!node->right){
            ans=min(ans,curr+1);
        }
        f(curr+1,ans,node->left);
        f(curr+1,ans,node->right);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int curr=0,ans=INT_MAX;
        f(curr,ans,root);
        return ans;
    }
};