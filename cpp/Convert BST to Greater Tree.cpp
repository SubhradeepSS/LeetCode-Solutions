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
    void util(TreeNode* node,int *sum){
        if(!node)
            return;
        util(node->right,sum);
        *sum += node->val;
        node->val = *sum;
        util(node->left,sum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        util(root,&sum);
        return root;
    }
};