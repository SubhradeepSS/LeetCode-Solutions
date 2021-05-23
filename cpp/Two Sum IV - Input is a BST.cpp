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
    bool util(TreeNode* root,int sum,unordered_set<int> &s){
        if(!root)
            return false;
        if(util(root->left,sum,s))
            return true;
        if(s.find(sum-root->val)!=s.end())
            return true;
        s.insert(root->val);
        return util(root->right,sum,s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return util(root,k,s);
    }
};