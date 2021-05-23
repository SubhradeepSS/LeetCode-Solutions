/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void util(TreeNode* root){
        if(!root)
            return;
        v.push_back(root->val);
        util(root->left);
        util(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        util(root);
        return v;
    }
};