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
    void f(TreeNode* node,int curr,int l){
        if(!node)
            return;
        if(!node->left&&!node->right){
            ans+=curr*2+node->val;
            // cout<<ans<<endl;
            return;
        }
        f(node->left,curr*2+node->val,l*2);
        f(node->right,curr*2+node->val,l*2);
    }
    int sumRootToLeaf(TreeNode* root) {
        ans=0;
        int curr=0,l=1;
        f(root,curr,l);
        return ans;
    }
};