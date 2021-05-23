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
    TreeNode* util(vector<int> nums,int l,int h){
        if(l>h)
            return NULL;
        int m=(h-l)/2+l;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=util(nums,l,m-1);
        root->right=util(nums,m+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return util(nums,0,nums.size()-1); 
    }
};