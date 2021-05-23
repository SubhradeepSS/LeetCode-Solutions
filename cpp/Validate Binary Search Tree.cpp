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
    long long last=LLONG_MIN;
    bool util(TreeNode* root){
        if(!root)
            return true;
        if(!util(root->left))
            return false;
        if(root->val>last)
            last=root->val;
        else return false;
        return util(root->right);
            
    }
    bool isValidBST(TreeNode* root) {
        return util(root);
    }
};