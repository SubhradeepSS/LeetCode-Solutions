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
    int ans;
    void f(TreeNode* node,int l,int h){
        if(!node)
            return;
        if(node->val>=l&&node->val<=h)
            ans+=node->val;
        f(node->left,l,h);
        f(node->right,l,h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans=0;
        f(root,low,high);
        return ans;
    }
};