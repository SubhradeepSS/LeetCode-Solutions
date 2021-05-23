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
    bool util(TreeNode* root, int sum){
         if(!root)
            return (sum==0);
        else{
            bool var=false;
            int newsum=sum-root->val;
            if(newsum==0&&root->left==NULL&&root->right==NULL)
                return true;
            if(root->left)
                var=var||util(root->left,newsum);
            if(root->right)
                var=var||util(root->right,newsum);
            return var;
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        return util(root,sum);
    }
};