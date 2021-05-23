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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(!q.empty()){
            int util=0; 
            int n=q.size();
            while(n--){
                TreeNode* c=q.front();
                q.pop();
                util += c->val;
                if(c->left){
                    q.push(c->left);
                }
                if(c->right){
                    q.push(c->right);
                }
            }
            ans=util;
        }
        return ans;
    }
};