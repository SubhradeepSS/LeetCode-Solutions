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
    void util(TreeNode* node){
        if(!node)
            return;
        util(node->left);
        util(node->right);
        v.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        util(root);
        return v;
    }
};