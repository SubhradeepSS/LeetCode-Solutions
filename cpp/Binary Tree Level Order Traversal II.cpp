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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(!root)
            return ans;
        
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            vector<int> curr;
            while(s--){
                TreeNode* f=q.front();
                q.pop();
                curr.push_back(f->val);
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            ans.push_back(curr);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};